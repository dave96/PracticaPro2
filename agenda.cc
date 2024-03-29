#include "agenda.hh"

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
        error = modificarTarea();
    } else if(comanda.es_esborrat()) {
        eliminarTarea(error);
    }
    if (error) {
        cout << "No s'ha realitzat" << endl;
    }
    return error;
}

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
    // Per modificar una data del map eliminem la tasca guardant un temporal i la tornem a inserir amb la nova data.
    Tarea temp = (*it).second;
    tareas.erase(it);
    tareas.insert(make_pair(final, temp));
}


void Agenda::eliminarTarea(bool& error) {
    map<Fecha, Tarea, less<Fecha> >::iterator it = menu.consultarTarea(comanda.tasca(), error);
    if(!error and (reloj.getFecha() < (*it).first or reloj.getFecha() == (*it).first)) {
        if (comanda.tipus_esborrat() == "tasca") {
            tareas.erase(it);
            menu.eliminarTarea(comanda.tasca());
        } else if(comanda.tipus_esborrat() == "etiqueta") {
            error = (*it).second.deleteEtiqueta(comanda.etiqueta(1));
        } else {
            (*it).second.deleteEtiquetas();
        }
    } else error = true;
}

bool Agenda::modificarTarea() {
    // Empezamos por la fecha
    int tasca = comanda.tasca();
    bool error = false;
    map <Fecha, Tarea, less<Fecha> >::iterator it = menu.consultarTarea(tasca, error);
    if (error) return true;
    if (not (reloj.getFecha() < (*it).first or reloj.getFecha() == (*it).first)) return true;
        // La tarea con el numero existe.
        if (comanda.nombre_dates() > 0 or comanda.te_hora()) {
            // Hem de canviar la data o la hora.
            Fecha nuevo;
            if (comanda.nombre_dates() > 0) nuevo.setDia(comanda.data(1));
            if (comanda.te_hora()) nuevo.setHora(comanda.hora());
            nuevo.rellenar((*it).first);
            if (nuevo < reloj.getFecha() or (tareas.find(nuevo) != tareas.end())) return true;
            else {
                modificarFecha(it, nuevo);
                it = tareas.find(nuevo);
                menu.modificarTarea(tasca, it);
            }
        }
        if (comanda.nombre_etiquetes() > 0) {
            // Afegim etiquetes
            for(int i = 1; i <= comanda.nombre_etiquetes(); ++i) (*it).second.addEtiqueta(comanda.etiqueta(i));
        }
        if (comanda.te_titol()) {
            // Canviem títol
            (*it).second.setTitle(comanda.titol());
        }
    return false;
}

void Agenda::tareasOut(const Fecha& inicio, const Fecha& fin) {
    int comptador = 1;
    map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.lower_bound(inicio);
    while (it != tareas.end() and ((*it).first < fin or ((not comanda.es_passat() and (*it).first == fin)))) {
        // La condició de l'if comprova si, en cas de que la consulta tingui etiquetes o expressio booleana, les compleix.
        if ((comanda.nombre_etiquetes() == 0 and not comanda.te_expressio()) or (comanda.te_expressio() and (*it).second.tieneExpresion(comanda.expressio())) or ((comanda.nombre_etiquetes() == 1) and (*it).second.tieneExpresion(comanda.etiqueta(1)))) {
             if (not comanda.es_passat()) menu.anadirTarea(it);
             cout << comptador << " ";
             (*it).second.write((*it).first);
             ++comptador;
        }
        ++it;
     }
}

void Agenda::imprimirTareas() {
    Fecha inicio;
    Fecha fin;
    menu = Menu();
    if (comanda.es_passat()) {
      // Tasques passades
      map <Fecha, Tarea, less<Fecha> >::iterator it = tareas.begin();
      if (it != tareas.end()) {
        inicio = (*it).first;
        fin = reloj.getFecha();
        tareasOut(inicio, fin);
      }
    } else {
        if(comanda.nombre_dates() == 0) {
          // Totes les futures
          inicio = reloj.getFecha();
          map <Fecha, Tarea, less<Fecha> >::reverse_iterator it = tareas.rbegin();
          if (tareas.begin() != tareas.end()) {
              fin = (*it).first;
              tareasOut(inicio, fin);
          }
        } else if(comanda.nombre_dates() == 1) {
            // Futures en una data concreta
            inicio = Fecha(comanda.data(1), "00:00");
            if (inicio < reloj.getFecha()) inicio = reloj.getFecha();
            fin = Fecha(comanda.data(1), "23:59");
            tareasOut(inicio, fin);
        } else {
            // Futures en un interval.
            inicio = Fecha(comanda.data(1), "00:00");
            if (inicio < reloj.getFecha()) inicio = reloj.getFecha();
            fin = Fecha(comanda.data(2), "23:59");
            tareasOut(inicio, fin);
        }
    }
}
