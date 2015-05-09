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
