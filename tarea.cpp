#include "tarea.h"
#include <iostream>

Tarea::Tarea(const string& title) {
    (*this).title = title;
    etiquetas = vector<string>(INITIAL_SIZE);
}

Tarea::~Tarea() {

}

void Tarea::write() const {
    cout << title;
    //imprimir todas las etiquetas cuando se implemente bien
    cout << endl;
}

void Tarea::addEtiqueta(const string &e) {
    etiquetas.push_back(e);
}

string Tarea::getTitle() const {}


bool Tarea::contieneEtiquetas() const {}

vector<string> Tarea::getEtiquetas() const {}


void Tarea::setTitle(const string& s) {}


bool Tarea::tieneExpresion(string expresion) const {}


bool Tarea::tieneEtiquetas(const vector<string>& etiquetas) const {}
