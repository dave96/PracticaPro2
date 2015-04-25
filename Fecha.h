/** @file fecha.h
    @brief Classe Fecha
 */

#ifndef FECHA_H
#define FECHA_H

#include "hora.h"
#include "dia.h"

/** @class Fecha
    @brief Representa un momento específico, mediante una hora y mediante un día.
 */

class Fecha {
private:
    Hora hora;
    Dia dia;
public:
    Fecha();
    ~Fecha();

    void write();
    Hora getHora();
    Dia getDia();

    void setHora(Hora hora);
    void setDia(Dia dia);

    bool compare(const Fecha& fecha);
};

#endif // FECHA_H
