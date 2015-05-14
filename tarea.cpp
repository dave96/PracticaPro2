#include "tarea.h"
#include <iostream>

Tarea::Tarea(const string& title) {
    (*this).title = title;
}

Tarea::~Tarea() {

}

void Tarea::write() const {
    cout << title;
    //imprimir todas las etiquetas cuando se implemente bien
    cout << endl;
}

void Tarea::addEtiqueta(const string &e) {
    int i = hasEtiqueta(e);
    if(i != -1) {
        etiquetas.push_back(e);
        int j = etiquetas.size()-1;
        while(j > i) {
            etiquetas[j] = etiquetas[j-1];
            ++j;
        }
        etiquetas[i] = e;
    }
}

int Tarea::hasEtiqueta(const string &e) const {

}

string Tarea::getTitle() const {
    return title;
}


bool Tarea::contieneEtiquetas() const {
    return n_etiquetas != 0;
}

vector<string> Tarea::getEtiquetas() const {
    return etiquetas;
}


void Tarea::setTitle(const string& title) {
    (*this).title = title;
}


bool Tarea::tieneExpresion(string expresion) const {

}

