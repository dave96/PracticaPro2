#include "tarea.h"
#include <iostream>

Tarea::Tarea(const string& title) {
    (*this).title = title;
}

Tarea::~Tarea() {

}

void Tarea::write() const {
    cout << title;
    writeEtiquetas();
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
    return etiquetas.size() != 0;
}

vector<string> Tarea::getEtiquetas() const {
    return etiquetas;
}


void Tarea::setTitle(const string& title) {
    (*this).title = title;
}


bool Tarea::tieneExpresion(const string& expresion) const {

}

void Tarea::writeEtiquetas() const {
    for(int i = 0; i < etiquetas.size(); ++i) {
        if(i != 0) {
            cout << " ";
        }
        cout << etiquetas[i];
    }
}

