#include "tarea.h"
#include <iostream>

Tarea::Tarea(string title, const Fecha& fecha) {
    this->title = title;
    this->fecha = fecha;
}

Tarea::~Tarea() {

}

void Tarea::write() const {
    cout << title << " ";
    fecha.write();
    cout << endl;
}
