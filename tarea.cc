#include "tarea.hh"
#include <iostream>

Tarea::Tarea(const string& title) {
    (*this).title = title;
}

Tarea::~Tarea() {

}

void Tarea::write(const Fecha& f) const {
    cout << title << " ";
    f.write();
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

void Tarea::setTitle(const string& title) {
    (*this).title = title;
}

char Tarea::getOperator(const string& e, int& i) {
    //Devuelve el tipo de operador (. o ,) de una expresión que comienza en i. También deja en i su posición.
    ++i;
    if (e[i] == '#') {
        //En el caso en el que la primera parte es un a etiqueta, se recorre hasta que acaba (y llega al operador)
        ++i;
        while(e[i] != '.' && e[i] != ',') {
            ++i;
        }
    } else {
        //En el caso en el que la primera parte es otra expresión, se recorre contando paréntesis abiertos hasta que se cierran todos
        //(y llega al operador)
        int cont = 1;
        ++i;
        while (cont != 0) {
            if(e[i] == '(') {
                ++cont;
            } else if (e[i] == ')') {
                --cont;
            }
            ++i;
        }
    }
    return e[i];
}

bool Tarea::i_tieneExpresion(const string& expresion, int i, int j) const {
    if(expresion[i] == '#') {
        //Caso base en el que la expresión es una etiqueta suelta (no es expresión)
        int pos;
        return hasEtiqueta(expresion.substr(i, j-i+1), pos);
    } else {
        //Caso recursivo en el que es una expresión
        int k = i;
        if(getOperator(expresion, k) == '.') {
            return i_tieneExpresion(expresion, i+1, k-1) && i_tieneExpresion(expresion, k+1, j-1);
        } else {
            return i_tieneExpresion(expresion, i+1, k-1) || i_tieneExpresion(expresion, k+1, j-1);
        }
    }
}

bool Tarea::tieneExpresion(const string& expresion) const {
    //Se le llama a la función de inmersión para hacer la recursividad
    return i_tieneExpresion(expresion, 0, expresion.size()-1);
}

bool Tarea::deleteEtiqueta(const string& e) {
    int pos;
    if(hasEtiqueta(e, pos)) {
        etiquetas.erase(etiquetas.begin()+pos);
        return false;
    } else {
        return true;
    }
}

void Tarea::deleteEtiquetas() {
    etiquetas = vector<string>();
}

void Tarea::writeEtiquetas() const {
    int size = etiquetas.size();
    for(int i = 0; i < size; ++i) {
        cout << " ";
        cout << etiquetas[i];
    }
}
