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

int Tarea::i_hasEtiqueta(const string& e, int i, int j) const {
    if(i > j) {
        return -1;
    } else {
        int k = (i+j)/2;
        if(e < etiquetas[k]) {
            return i_hasEtiqueta(e, i, k-1);
        } else if( e > etiquetas[k]) {
            return i_hasEtiqueta(e, k+1, j);
        } else {
            return k;
        }
    }
}

int Tarea::hasEtiqueta(const string&e) const {
    i_hasEtiqueta(e, 0, etiquetas.size()-1);
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
    int size = etiquetas.size();
    for(int i = 0; i < size; ++i) {
        if(i != 0) {
            cout << " ";
        }
        cout << etiquetas[i];
    }
}

bool Tarea::tieneEtiquetas(const vector<string> &etiquetas) const {
    int size = etiquetas.size();
    for(int i = 0; i < size; ++i) {
        if(hasEtiqueta(etiquetas[i])) {
            return true;
        }
    }
    return false;
}

