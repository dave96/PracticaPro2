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
    bool a = comanda.llegir(formato);
    cout << "te_expresio = " << comanda.te_expressio() << endl;
    cout << "n_etiquetas = " << comanda.nombre_etiquetes() << endl;
    cout << "expresio = " << comanda.expressio() << endl;
    return a;
}

bool Agenda::runComanda() {
    bool error = false;
    if (comanda.es_rellotge()) {
        tratar_reloj(error);
    } else if (comanda.es_insercio()) {
        insertar_tarea(error);
    } else if(comanda.es_consulta()) {
        imprimirTareas(error);
    } else if(comanda.es_modificacio()) {
        modificarTarea(error);
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

void Agenda::modificarFecha(map <Fecha, Tarea, less<Fecha> >::iterator it, const Fecha& final) {
    Tarea temp = (*it).second;
    tareas.erase(it);
    tareas.insert(make_pair(final, temp));
}

void Agenda::modificarTarea(bool& error) {

}

void Agenda::tareasOut(const Fecha& inicio, const Fecha& fin) {
    int comptador = 1;
    map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(inicio);
    vector<string> etiquetas(comanda.nombre_etiquetes());
    if (comanda.nombre_etiquetes() != 0 and not comanda.te_expressio()) {
        //ESTO NO HACE NADA, ? #a #b devuelve error de formato.
        //las consultas con etiqutas son de dos tipos, PUEDEN SER LAS DOS A LA VEZ:
        //   -etiqueta suelta (comanda.te_expresio = false, comanda.nombre_etiquetes = 1) ? #a
        //   -expresion etiquetas, rodeada de paréntesis (comanda.te_expresio = false, comanda.nombre_etiquetes = 0) ? (#a,(#b.#c))
        //   -? #a (#a,(#b.#c))
        //De forma que deberias de comprobar con comanda.te_expresio() y comanda.nombre_etiquetes() para arreglar
        //el bucle while. El for de justo debajo por lo tanto no hace nada, ya que como máximo, nombre_etiquetes = 1
        //deberías utilizar mi funcion hasEtiqueta para el while de abajo. tieneEtiquetas queda inútil.
        for(int i = 0; i < comanda.nombre_etiquetes(); ++i) {
            etiquetas[i] = comanda.etiqueta(i+1);
        }
    }
    while (it != tareas.end() and ((*it).first < fin or ((not comanda.es_passat() and (*it).first == fin)))) {
        if ((comanda.nombre_etiquetes() == 0) or ((not comanda.te_expressio()) and (*it).second.tieneEtiquetas(etiquetas)) or (comanda.te_expressio() and (*it).second.tieneExpresion(comanda.expressio()))) {
             menu.anadirTarea(it);
             cout << comptador << " ";
             (*it).second.write((*it).first);
             ++comptador;
         }
        ++it;
     }
}

void Agenda::imprimirTareas(bool& error) {
    if (comanda.es_passat()) {
      map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.begin();

      //REPASA ESTE IF, CUANDO NO HAY TAREAS PARA IMPRIMIR, NO DEBERIA DE SALTAR EL ERROR
      //SIMPLEMENTE NO SE MUESTRA NADA

      //POR QUÉ NO HACES QUE SE ENCARGUE tareasOut de determinar que imprima o no? Tú llámala
      //igualmente y si resulta que en tramo de fechas que le pasas no hay tarea, pues ya
      //saldrá del bucle con el menu y pantalla vacio.
      if (it == tareas.end() or (reloj.getFecha() < (*it).first)) error = true;
      else {
          Fecha inicio = (*it).first;
          Fecha fin = reloj.getFecha();
          tareasOut(inicio, fin);
      }
      // Tareas futuras
    } else {
        if(comanda.nombre_dates() == 0) {
          // Todas las futuras
                  menu = Menu();
                  Fecha inicio = reloj.getFecha();
                  map <Fecha, Tarea, less<Fecha> >::reverse_iterator it = tareas.rbegin();
                  //REPASA ESTE IF, CUANDO NO HAY TAREAS PARA IMPRIMIR, NO DEBERIA DE SALTAR EL ERROR
                  //SIMPLEMENTE NO SE MUESTRA NADA

                  //POR QUÉ NO HACES QUE SE ENCARGUE tareasOut de determinar que imprima o no? Tú llámala
                  //igualmente y si resulta que en tramo de fechas que le pasas no hay tarea, pues ya
                  //saldrá del bucle con el menu y pantalla vacio.
                  if (tareas.begin() == tareas.end()) error = true;
                  else {
                      Fecha fin = (*it).first;
                      tareasOut(inicio, fin);
                  }

        } else if(comanda.nombre_dates() == 1) {
            Fecha inicio (comanda.data(1), "00:00");
            Fecha fin (comanda.data(1), "23:59");
            // Una fecha concreta.
            menu = Menu();
            tareasOut(inicio, fin);

        } else {
            // De una fecha a otra.
            Fecha inicio (comanda.data(1), "00:00");
            Fecha fin (comanda.data(2), "23:59");
            menu = Menu();
            tareasOut(inicio, fin);
        }
    }
}
