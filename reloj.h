/** @file reloj.h
    @brief Classe Reloj
 */

#ifndef RELOJ_H
#define RELOJ_H

#include "Fecha.h"

/** @class Reloj
    @brief Representa un reloj, una estructura que almacena una fecha y que la modifica (hacia futuro).
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
    \pre f es una fecha inicializada.
    \post Devuelve true si se ha realizado la actualización de la hora (la nueva fecha es posterior). False si no lo es.*/
    bool update(const Fecha& f);

    /** @brief Compara la fecha del p.i. con otra fecha como parámetro.
    \pre f es una fecha inicializada.
    \post Devuelve true si f es posterior a la fecha del p.i., false si no.*/
    bool compare(const Fecha& f) const;

    /** @brief Imprime por pantalla el reloj. Básicamente imprime su fecha.
    \pre Cierto.
    \post Se imprime la fecha del reloj. */
    void write() const;
};

#endif // RELOJ_H
