#include "agenda.h"
#include "menu.h"
#include "fecha.h"
#include "comanda.h"
#include "tarea.h"
#include "token.h"
#include <map>
#include <string>

// Público

Agenda::Agenda() {
}

Agenda::~Agenda() {
}

bool Agenda::readComanda(bool& formato) {
    comanda = Comanda();
    return comanda.llegir(formato);
}

bool Agenda::runComanda() {
    bool error = false;
    if (comanda.es_rellotge()) {
        tratar_reloj(error);
    } else if (comanda.es_insercio()) {
        insertar_tarea(error);
    } else if(comanda.es_consulta()) {
        imprimirTareas(error);
    }
    if (error) {
        cout << "No s'ha realitzat" << endl;
    }
    return error;
}

// Privado

void Agenda::tratar_reloj(bool& error) {
    if (comanda.es_consulta()) {
        reloj.write();
    } else {
        Fecha f(comanda.data(1), comanda.hora());
        error = !reloj.update(f);
    }
}

void Agenda::insertar_tarea(bool& error) {
    Fecha f(comanda.data(1), comanda.hora());
    f.rellenar(reloj.getFecha());
    map <Fecha, Tarea, less<Fecha> >::iterator i = tareas.find(f);
    error = f < reloj.getFecha() || i != tareas.end();
    if (!error) {
        Tarea t(comanda.titol());
        for (int j = 1; j <= comanda.nombre_etiquetes(); ++j) {
            t.addEtiqueta(comanda.etiqueta(j));
        }
        tareas.insert(make_pair(f, t));
    }
}

void Agenda::imprimirTareas(bool& error) {
    // Tareas pasadas.
    if (comanda.es_passat()) {
      map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.begin();
      if (it == tareas.end() or ((*it).first < reloj.getFecha())) error = true;
      else {
          int comptador = 1;
          while (it != tareas.end() and ((*it).first < reloj.getFecha())) {
            cout << comptador << " " << (*it).second.getTitle() << " ";
            (*it).first.write();
            if ((*it).second.contieneEtiquetas()) {
              vector<string> etiquetas = (*it).second.getEtiquetas();
              for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
            }
            cout << endl;
          }
      }
      // Tareas futuras
    } else {
        if(comanda.nombre_dates() == 0) {
          // Todas las futuras
                  int comptador = 1;
                  menu = Menu();
                  if (comanda.nombre_etiquetes() == 0) {
                      for (map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(reloj.getFecha()); it != tareas.end(); ++it) {
                          menu.anadirTarea(it);
                          cout << comptador << " " << (*it).second.getTitle() << " ";
                          if ((*it).second.contieneEtiquetas()) {
                            vector<string> etiquetas = (*it).second.getEtiquetas();
                            for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                          }
                          ++comptador;
                          cout << endl;
                      }
                  } else if (comanda.te_expressio()) {
                    for (map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(reloj.getFecha()); it != tareas.end(); ++it) {
                      if ((*it).second.tieneExpresion(comanda.expressio())) {
                        menu.anadirTarea(it);
                        cout << comptador << " " << (*it).second.getTitle() << " ";
                        if ((*it).second.contieneEtiquetas()) {
                          vector<string> etiquetas = (*it).second.getEtiquetas();
                          for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                        }
                        ++comptador;
                        cout << endl;
                      }
                    }
                  } else {
                    for (map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(reloj.getFecha()); it != tareas.end(); ++it) {
                      vector<string> vetiquetas(comanda.nombre_etiquetes());
                      for (int i = 0; i < vetiquetas.size(); ++i) vetiquetas[i] = comanda.etiqueta(i+1);
                      if ((*it).second.tieneEtiquetas(vetiquetas)) {
                        menu.anadirTarea(it);
                        cout << comptador << " " << (*it).second.getTitle() << " ";
                        if ((*it).second.contieneEtiquetas()) {
                          vector<string> etiquetas = (*it).second.getEtiquetas();
                          for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                        }
                        ++comptador;
                        cout << endl;
                      }
                    }
                  }

        } else if(comanda.nombre_dates() == 1) {
          Fecha consulta;
          consulta.setDia(comanda.data(1));
          // Una fecha concreta.
          int comptador = 1;
          menu = Menu();
          map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(consulta);
          if (comanda.nombre_etiquetes() == 0) {
              while(it != tareas.end() and (*it).first == consulta) {
                  menu.anadirTarea(it);
                  cout << comptador << " " << (*it).second.getTitle() << " ";
                  if ((*it).second.contieneEtiquetas()) {
                    vector<string> etiquetas = (*it).second.getEtiquetas();
                    for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                  }
                  ++comptador;
                  ++it;
                  cout << endl;
              }
          } else if (comanda.te_expressio()) {
            while(it != tareas.end() and (*it).first == consulta) {
              if ((*it).second.tieneExpresion(comanda.expressio())) {
                menu.anadirTarea(it);
                cout << comptador << " " << (*it).second.getTitle() << " ";
                if ((*it).second.contieneEtiquetas()) {
                  vector<string> etiquetas = (*it).second.getEtiquetas();
                  for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                }
                ++comptador;
                cout << endl;
              }
              ++it;
            }
          } else {
            while(it != tareas.end() and (*it).first == consulta) {
              vector<string> vetiquetas(comanda.nombre_etiquetes());
              for (int i = 0; i < vetiquetas.size(); ++i) vetiquetas[i] = comanda.etiqueta(i+1);
              if ((*it).second.tieneEtiquetas(vetiquetas)) {
                menu.anadirTarea(it);
                cout << comptador << " " << (*it).second.getTitle() << " ";
                if ((*it).second.contieneEtiquetas()) {
                  vector<string> etiquetas = (*it).second.getEtiquetas();
                  for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                }
                ++comptador;
                cout << endl;
              }
              ++it;
            }
          }

        } else {
          // De una fecha a otra.
          Fecha consulta;
          consulta.setDia(comanda.data(1));
          Fecha limite;
          limite.setDia(comanda.data(2));
          // Una fecha concreta.
          int comptador = 1;
          menu = Menu();
          map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(consulta);
          if (comanda.nombre_etiquetes() == 0) {
              while(it != tareas.end() and ((*it).first < limite or (*it).first == limite)) {
                  menu.anadirTarea(it);
                  cout << comptador << " " << (*it).second.getTitle() << " ";
                  if ((*it).second.contieneEtiquetas()) {
                    vector<string> etiquetas = (*it).second.getEtiquetas();
                    for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                  }
                  ++comptador;
                  ++it;
                  cout << endl;
              }
          } else if (comanda.te_expressio()) {
            while(it != tareas.end() and ((*it).first < limite or (*it).first == limite)) {
              if ((*it).second.tieneExpresion(comanda.expressio())) {
                menu.anadirTarea(it);
                cout << comptador << " " << (*it).second.getTitle() << " ";
                if ((*it).second.contieneEtiquetas()) {
                  vector<string> etiquetas = (*it).second.getEtiquetas();
                  for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                }
                ++comptador;
                cout << endl;
              }
              ++it;
            }
          } else {
            while(it != tareas.end() and ((*it).first < limite or (*it).first == limite)) {
              vector<string> vetiquetas(comanda.nombre_etiquetes());
              for (int i = 0; i < vetiquetas.size(); ++i) vetiquetas[i] = comanda.etiqueta(i+1);
              if ((*it).second.tieneEtiquetas(vetiquetas)) {
                menu.anadirTarea(it);
                cout << comptador << " " << (*it).second.getTitle() << " ";
                if ((*it).second.contieneEtiquetas()) {
                  vector<string> etiquetas = (*it).second.getEtiquetas();
                  for(int i = 0; i < etiquetas.size(); ++i) cout << " " << etiquetas[i];
                }
                ++comptador;
                cout << endl;
              }
              ++it;
            }
          }

        }
    }
}
