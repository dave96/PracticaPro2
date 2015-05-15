#include "fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(const string& dia, const string& hora) {
    (*this).dia = dia;
    (*this).hora = hora;
}

Fecha::Fecha() {}

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

void Fecha::rellenar(const Fecha& f) {
    if(dia == "") {
        setDia(f.getDia());
    }
    if(hora == "") {
        setHora(f.getHora());
    }
}

bool Fecha::operator <(const Fecha& f) const {
    if(invertirDia(dia) < invertirDia(f.getDia())) return true;
    if (dia == f.getDia()) return hora < f.getHora();
    return false;
}

bool Fecha::operator ==(const Fecha& f) const {
    return dia == f.getDia() && hora == f.getHora();
}


string Fecha::invertirDia(string dia) {
    int length = dia.size();
    dia[0] = dia[0]+dia[length-2];
    dia[1] = dia[1]+dia[length-1];
    dia[length-2] = dia[0]-dia[length-2];
    dia[length-1] = dia[1]-dia[length-1];
    dia[0] = dia[0]-dia[length-2];
    dia[1] = dia[1]-dia[length-1];
    return dia;
}
