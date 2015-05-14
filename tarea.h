/** @file tarea.h
    @brief Classe Tarea
 */

#ifndef TAREA_H
#define TAREA_H

#include <vector>
#include <string>
using namespace std;

/** @class Tarea
    @brief Representa una tarea, es decir una estructura de datos en la que se guarda una acción.

    Representada con un título y con una lista de etiquetas descriptivas.
 */

class Tarea {

private:
    string title;
    vector<string> etiquetas;
public:
    /** @brief Crea una tarea con título.
    \pre Cierto.
    \post  Inicializa el p.i. con title.*/
    Tarea(const string& title);
    ~Tarea();

    /** @brief Imprime por pantalla la tarea.
    \pre Cierto.
    \post Se imprime la tarea por pantalla en orden: title, etiquetas (si hay).*/
    void write() const;

    /** @brief Devuelve el título de la tarea.
    \pre Cierto.
    \post Devuelve title.*/
    string getTitle() const;


    /** @brief Dice si el p.i. contiene etiquetas.
    \pre etiquetas inicializadas.
    \post Devuelve true si la tarea contiene alguna etiqueta, false de lo contrario. */
    bool contieneEtiquetas() const;

    /** @brief Devuelve la lista de las etiquetas descriptivas del p.i..
    \pre Cierto.
    \post Devuelve una lista de las etiquetas del p.i. Vacía si no tiene etiquetas.*/
    vector<string> getEtiquetas() const;

    /** @brief Dice si el p.i. contiene etiquetas.
    \pre e es una etiqueta válida.
    \post Devuelve la posición de la etiqueta si la tarea contiene la etiqueta e (0 <= pos < n_etiquetas), -1 si no la contiene. */
    int hasEtiqueta(const string& e) const;

    /** @brief .
    \pre s está inicializado.
    \post El p.i. tiene s como title. */
    void setTitle(const string& s);

    /** @brief Añade una etiqueta a la tarea.
    \pre e está inicializada y etiquetas está ordenada crecientemente.
    \post El p.i. tiene la etiqueta e añadida a etiquetas, manteniéndola ordenada.*/
    void addEtiqueta(const string& e);

    /** @brief Comprueva si el p.i. tiene alguna etiqueta del vector.
    \pre etiquetas están inicializadas.
    \post Devuelve true si el p.i. tiene alguna etiqueta del vector. Falso si no.*/
    bool tieneExpresion(const string& expresion) const;

    /** @brief Imprime las etiquetas del p.i. en orden lexicográfico.
    \pre  Cierto.
    \post Se han imprimido las etiquetas del p.i. en orden lexicográfico, si tiene.*/
    void writeEtiquetas() const;

    /** @brief Comprueva si el p.i. tiene alguna etiqueta del vector.
    \pre etiquetas tiene al menos un elemento (etiqueta) y con valores válidos.
    \post Devuelve true si el p.i. tiene alguna etiqueta del vector. Falso si no.*/
    bool tieneEtiquetas(const vector<string>& etiquetas) const;

};

#endif // TAREA_H
