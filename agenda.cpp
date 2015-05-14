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
        imprimirTareas();
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
    // Empezamos por la fecha
    int tasca = comanda.tasca();

}

void Agenda::tareasOut(const Fecha& inicio, const Fecha& fin) {
    int comptador = 1;
    map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(inicio);
    while (it != tareas.end() and ((*it).first < fin or ((not comanda.es_passat() and (*it).first == fin)))) {
        if ((comanda.nombre_etiquetes() == 0 and not comanda.te_expressio()) or (comanda.te_expressio() and (*it).second.tieneExpresion(comanda.expressio())) or ((comanda.nombre_etiquetes() == 1) and (*it).second.hasEtiqueta(comanda.etiqueta(1)))) {
             menu.anadirTarea(it);
             cout << comptador << " ";
             (*it).second.write((*it).first);
             ++comptador;
         }
        ++it;
     }
}

void Agenda::imprimirTareas() {
    if (comanda.es_passat()) {
      map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.begin();
      Fecha inicio = (*it).first;
      Fecha fin = reloj.getFecha();
      tareasOut(inicio, fin);
      // Tareas futuras
    } else {
        if(comanda.nombre_dates() == 0) {
          // Todas las futuras
          menu = Menu();
          Fecha inicio = reloj.getFecha();
          map <Fecha, Tarea, less<Fecha> >::reverse_iterator it = tareas.rbegin();
          // Aquí este if no se puede ir, porque necesito saber si puedo sacar una fecha o no.
          if (tareas.begin() != tareas.end()) {
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
