/** @file tarea.h
    @brief Classe Tarea
 */

#ifndef TAREA_H
#define TAREA_H

#include <list>
#include <string>
#include "fecha.h"
#include "etiqueta.h"
using namespace std;

/** @class Tarea
    @brief Representa una tarea, es decir una estructura de datos en la que se guarda una acción. Representada
    con un título, con una fecha y con una lista de etiquetas descriptivas.
 */

class Tarea {

private:
    string title;
    Fecha fecha;
    list<Etiqueta> etiquetas;

public:

    Tarea();
    ~Tarea();

    void write() const;
    Fecha getFecha() const;
    string getTitle() const;
    list<Etiqueta> getEtiquetas() const;

    void setFecha();
    void setTitle();
    void addEtiqueta();

    bool tieneEtiqueta(list<Etiqueta> etiquetas) const;

};

#endif // TAREA_H
