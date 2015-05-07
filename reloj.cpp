#include "reloj.h"

Reloj::Reloj() {
    fecha = Fecha("20.04.15", "00:00");
}

Reloj::~Reloj() {

}

bool Reloj::update(const Fecha& f) {
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
}
