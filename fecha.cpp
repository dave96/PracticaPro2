#include "fecha.h"
#include <iostream>
using namespace std;

struct Hora {
    int hour, min;
};

struct Dia {
    int day, month, year;
};

Fecha::Fecha(Dia dia, Hora hora) {

}

Fecha::~Fecha() {

}

void Fecha::write() const {
    cout << hora.hour << ':' << hora.min << " " << dia.day << '-' << dia.month << '-' << dia.year;
}

Dia Fecha::getDia() const {
    return dia;
}

Hora Fecha::getHora() const {
    return hora;
}

void Fecha::setDia(Dia dia) {
    this->dia = dia;
}

void Fecha::setHora(Hora hora) {
    this->dia = hora;
}

bool Fecha::compare(const Fecha &f) const {
    Dia dia2 = f.getDia();
    if(dia.year < dia2.year) {
        return true;
    } else {
        if(dia.month < dia2.month) {
            return true;
        } else {
            if(dia.day < dia2.day) {
                return true;
            } else {
                Hora hora2 = f.getHora();
                if(hora.hour < hora2) {
                    return true;
                } else {
                    if(hora.min < hora2.min) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
}
