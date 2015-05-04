/** @file tarea.h
    @brief Classe Tarea
 */

#ifndef TAREA_H
#define TAREA_H

#include <list>
#include <string>
#include "fecha.h"
using namespace std;

/** @class Tarea
    @brief Representa una tarea, es decir una estructura de datos en la que se guarda una acción.

    Representada con un título, con una Fecha y con una lista de etiquetas descriptivas.
 */

class Tarea {

private:
    string title;
    Fecha fecha;
    list<string> etiquetas;

public:
    /** @brief Crea una tarea con título y fecha.
    \pre Cierto.
    \post  Inicializa el p.i. con title y fecha. Faltarán las etiquetas, si tiene.*/
    Tarea(string title, const Fecha& fecha);
    ~Tarea();

    /** @brief Imprime por pantalla la tarea.
    \pre Cierto.
    \post Se imprime la tarea por pantalla en orden: title, fecha.*/
    void write() const;

    /** @brief Devuelve la fecha de la tarea.
    \pre Cierto.
    \post Devuevle fecha.*/
    Fecha getFecha() const;

    /** @brief Devuelve el título de la tarea.
    \pre Cierto.
    \post Devuelve title.*/
    string getTitle() const;

    /** @brief Devuelve la lista de las etiquetas descriptivas del p.i..
    \pre Cierto.
    \post Devuelve una lista de las etiquetas del p.i. Vacía si no tiene etiquetas.*/
    list<string> getEtiquetas() const;

    /** @brief .
    \pre f está inicilizada.
    \post El p.i. tiene f como fecha.*/
    void setFecha(const Fecha& f);

    /** @brief .
    \pre s está inicializado.
    \post El p.i. tiene s como title.*/
    void setTitle(const string& s);

    /** @brief .
    \pre e está inicializada.
    \post El p.i. tiene una etiqueta más en la lista etiquetas.*/
    void addEtiqueta(const string& e);

    /** @brief Comprueva si el p.i. tiene al menos una etiqueta de etiquetas.
    \pre etiquetas están inicializadas.
    \post Devuelve true si el p.i. tiene al menos una etiqueta igual que alguna de etiquetas. Falso si no.*/
    bool tieneEtiqueta(list<string> etiquetas) const;
};

#endif // TAREA_H
