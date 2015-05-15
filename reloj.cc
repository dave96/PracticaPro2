#include "reloj.hh"
#include <iostream>
using namespace std;

Reloj::Reloj() {
    fecha = Fecha("20.04.15", "00:00");
}

Reloj::~Reloj() {

}

Fecha Reloj::getFecha() const {
    return fecha;
}

bool Reloj::update(Fecha& f) {
    f.rellenar(fecha);
    if(fecha < f || fecha == f) {
        fecha = f;
        return true;
    } else {
        return false;
    }
}

void Reloj::write() const {
    fecha.write();
    cout << endl;
}
