/** @file reloj.h
    @brief Classe Reloj
 */

#ifndef RELOJ_H
#define RELOJ_H

#include "fecha.h"

/** @class Reloj
    @brief Representa un reloj, una estructura que almacena una Fecha y que la modifica (hacia futuro).
 */

class Reloj {
    Fecha fecha;
public:
    /** @brief Crea un reloj vacío que se iniciará con fecha inicial.
    \pre Cierto.
    \post  Reloj con fecha inicial*/
    Reloj();
    ~Reloj();

    /** @brief Actualiza la fecha del reloj, si la nueva fecha es posterior a la del p.i.
    \pre f es una fecha con hora y dia inicializados y válidos.
    \post Devuelve true si se ha realizado la actualización de la hora (la nueva fecha es posterior) o si la nueva fecha es
    igual (no ha cambiado el p.i.). False si la fecha es anterior.*/
    bool update(Fecha& f);

    /** @brief Devuelve la fecha del reloj.
    \pre Cierto.
    \post Se devuelve la fecha del reloj. */
    Fecha getFecha() const;

    /** @brief Imprime por pantalla el reloj. Básicamente imprime su fecha.
    \pre Cierto.
    \post Se imprime la fecha del reloj. */
    void write() const;
};

#endif // RELOJ_H
