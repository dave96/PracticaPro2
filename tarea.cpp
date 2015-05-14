#include "tarea.h"
#include <iostream>

Tarea::Tarea(const string& title) {
    (*this).title = title;
}

Tarea::~Tarea() {

}

void Tarea::write(const Fecha& f) const {
    cout << title << " ";
    f.write();
    cout << " ";
    writeEtiquetas();
    cout << endl;
}

void Tarea::addEtiqueta(const string &e) {
    int i;
    if(!hasEtiqueta(e, i)) {
        etiquetas.push_back(e);
        int j = etiquetas.size()-1;
        while(j > i) {
            etiquetas[j] = etiquetas[j-1];
            --j;
        }
        etiquetas[i] = e;
    }
}

bool Tarea::i_hasEtiqueta(const string& e, int i, int j, int& pos) const {
    if(i > j) {
        pos = i;
        return false;
    } else {
        int k = (i+j)/2;
        if(e < etiquetas[k]) {
            return i_hasEtiqueta(e, i, k-1, pos);
        } else if( e > etiquetas[k]) {
            return i_hasEtiqueta(e, k+1, j, pos);
        } else {
            pos = k;
            return true;
        }
    }
}

bool Tarea::hasEtiqueta(const string& e, int& pos) const {
    return i_hasEtiqueta(e, 0, etiquetas.size()-1, pos);
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


//esto parece ser que no sirve para nadaaaaaaaaa
bool Tarea::tieneEtiquetas(const vector<string> &etiquetas) const {
    int size = etiquetas.size();
    for(int i = 0; i < size; ++i) {
        int pos;
        if(hasEtiqueta(etiquetas[i], pos)) {
            return true;
        }
    }
    return false;
}

