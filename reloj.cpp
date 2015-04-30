#include "reloj.h"

Reloj::Reloj() {

}

Reloj::~Reloj() {

}

bool Reloj::update(const Fecha& f) {

}

bool Reloj::compare(const Fecha& f) const {
    return fecha.compare(f);
}
