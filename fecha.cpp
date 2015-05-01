#include "fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(const string& dia, const string& hora) {
    this->dia = dia;
    this->hora = hora;
}

//Constructor vacío necesario para que otras clases puedan tener una fecha como atributo privado. Si no pongo esto, el
//compilador no sabe como construirlo en el Fecha fecha;
Fecha::Fecha() {

}

Fecha::~Fecha() {

}

void Fecha::write() const {
    cout << dia << " " << hora;
}

string Fecha::getDia() const {
    return dia;
}

string Fecha::getHora() const {
    return hora;
}

void Fecha::setDia(const string& dia) {
    this->dia = dia;
}

void Fecha::setHora(const string& hora) {
    this->hora = hora;
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
                if(hora.hour < hora2.hour) {
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
