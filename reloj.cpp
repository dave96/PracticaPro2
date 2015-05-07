#include "reloj.h"

Reloj::Reloj() {

}

Reloj::~Reloj() {

}

bool Reloj::update(const Fecha& f) {
    if(compare(f)) {
        fecha = f;
        return true;
    } else {
        return true;
    }
}

bool Reloj::compare(const Fecha& f) const {
    return fecha < f;
}


void Reloj::write() const {
    fecha.write();
}
