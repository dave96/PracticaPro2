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
    int n_etiquetas;
    static const int INITIAL_SIZE = 20;
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

    /** @brief .
    \pre s está inicializado.
    \post El p.i. tiene s como title.*/
    void setTitle(const string& s);

    /** @brief .
    \pre e está inicializada.
    \post El p.i. tiene una etiqueta más en la lista etiquetas.*/
    void addEtiqueta(const string& e);

    /** @brief Comprueva si el p.i. concide con la expresión de etiquetas dada.
    \pre etiquetas están inicializadas.
    \post Devuelve true si el p.i. coincide con la expresión booleana de etiquetas. Falso si no.*/
    bool tieneEtiqueta(string expresion) const;
};

#endif // TAREA_H
