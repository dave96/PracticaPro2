#include "agenda.h"

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
    error = reloj.getFecha() < f;
    if (!error) {
        Tarea t(comanda.titol());
        map <Fecha, Tarea, less<Fecha> >::iterator i = tareas.find(f);
        error = i != tareas.end();
        if(!error) {
            tareas.insert(t);
        }
    }
}
