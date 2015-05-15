/** @file tarea.h
    @brief Classe Tarea
 */

#ifndef TAREA_H
#define TAREA_H

#include "fecha.h"
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
    bool i_hasEtiqueta(const string& e, int i, int j, int& pos) const;
    bool i_tieneExpresion(const string& expresion, int i, int j) const;
    static char getOperator(const string& e, int i, int& k);
public:
    /** @brief Crea una tarea con título.
    \pre Cierto.
    \post  Inicializa el p.i. con title.*/
    Tarea(const string& title);
    ~Tarea();

    /** @brief Imprime por pantalla la tarea.
    \pre Se le pasa la fecha de la tarea, inicializada y válida.
    \post Se imprime la tarea por pantalla en orden: title, f, etiquetas (si hay).*/
    void write(const Fecha& f) const;

    /** @brief Devuelve el título de la tarea.
    \pre Cierto.
    \post Devuelve title.*/
    string getTitle() const;

    /** @brief Dice si el p.i. contiene etiquetas.
    \pre Cierto.
    \post Devuelve true si la tarea contiene alguna etiqueta, false de lo contrario. */
    bool contieneEtiquetas() const;

    /** @brief Devuelve la lista de las etiquetas descriptivas del p.i..
    \pre Cierto.
    \post Devuelve una lista de las etiquetas del p.i. Vacía si no tiene etiquetas.*/
    vector<string> getEtiquetas() const;

    /** @brief Dice si el p.i. contiene una etiqueta.
    \pre e es una etiqueta válida, etiquetas está en orden lexicográfico.
    \post Devuelve true si e está en etiquetas, false si no. pos vale la posición de la etiqueta si está o la posición en
    la que debería de estar si no está. (0 <= pos <= etiquetas.size()). */
    bool hasEtiqueta(const string& e, int& pos) const;

    /** @brief Dice si el p.i. contiene una etiqueta.
    \pre e es una etiqueta válida, etiquetas está en orden lexicográfico.
    \post Devuelve true si e está en etiquetas, false si no. */
    bool hasEtiqueta(const string& e) const;

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

    /** @brief Elimina una etiqueta del p.i.
    \pre Cierto.
    \post El p.i. ha eliminado la etiqueta e del p.i. si estaba y devuelve true. Deja el p.i. intacto y devuelve false si no estaba.*/
    bool deleteEtiqueta(const string& e);

};

#endif // TAREA_H
