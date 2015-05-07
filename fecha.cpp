#include "fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(const string& dia, const string& hora) {
    (*this).dia = dia;
    (*this).hora = hora;
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
    (*this).dia = dia;
}

void Fecha::setHora(const string& hora) {
    (*this).hora = hora;
}

bool Fecha::compare(const Fecha &f) const {
    if(invertirDia(dia) < invertirDia(f.getDia())) {
        return true;
    } else {
        if(hora < f.getHora()) {
            return true;
        } else {
            return false;
        }
    }
}

string Fecha::invertirDia(string dia) {
    int length = dia.size();
    dia[0] = dia[0]+dia[length-2];
    dia[1] = dia[1]+dia[length-1];
    dia[length-2] = dia[0]-dia[length-2];
    dia[length-1] = dia[1]-dia[length-1];
    return dia;
}
