#include "agenda.h"

Agenda::Agenda() {

}

Agenda::~Agenda() {

}

bool Agenda::readComanda(bool& formato) {
    comanda.llegir(formato);
    //prueba
    cout << "formato = " << formato << endl;
    cout << "es_rellotge = " << comanda.es_rellotge() << endl;
    cout << "es_consulta = " << comanda.es_consulta() << endl;
    cout << "nombre_dates = " << comanda.nombre_dates() << endl;
    cout << "data = " << comanda.data(1) << endl;
    cout << "hora = " << comanda.hora() << endl;
    return true;
}

bool Agenda::runComanda() {
    bool error = false;
    if(comanda.es_rellotge()) {
        if(comanda.es_consulta()) {
            reloj.write();
            cout << endl;
        } else {
            //completar
            Fecha f(comanda.data(0), "");
            error = !reloj.update(f);
        }
    }
}

