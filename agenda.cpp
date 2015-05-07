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
        if (comanda.es_consulta()) {
            reloj.write();
        } else {
            Fecha f(comanda.data(1), comanda.hora());
            error = !reloj.update(f);
        }
    } else if() {

    }
    if (error) {
        cout << "No s'ha realitzat" << endl;
    }
}

