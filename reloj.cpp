#include "reloj.h"
#include <iostream>
using namespace std;

Reloj::Reloj() {
    fecha = Fecha("20.04.15", "00:00");
}

Reloj::~Reloj() {

}

bool Reloj::update(Fecha& f) {
    if(f.getDia() == "") {
        f.setDia(fecha.getDia());
    }
    if(f.getHora() == "") {
        f.setHora(fecha.getHora());
    }
    if(compare(f)) {
        fecha = f;
        return true;
    } else {
        return false;
    }
}

bool Reloj::compare(const Fecha& f) const {
    return fecha < f || fecha == f;
}


void Reloj::write() const {
    fecha.write();
    cout << endl;
}
