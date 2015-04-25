/** @file reloj.h
    @brief Classe Reloj
 */

#ifndef RELOJ_H
#define RELOJ_H

#include "Fecha.h"

/** @class Reloj
    @brief Representa un reloj, una estructura que almacena una fecha y que la modifica (hacia futuro) y la lee.
 */

class Reloj {
    Fecha fecha;
public:
    Reloj();
    ~Reloj();
};

#endif // RELOJ_H
