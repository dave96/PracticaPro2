#include "agenda.h"
#include "menu.h"
#include "Fecha.h"
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
          if(comanda.nombre_etiquetes() == 0) {
              
          }
        }
    }
}
