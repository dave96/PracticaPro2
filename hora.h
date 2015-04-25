/** @file hora.h
    @brief Classe Hora
 */

#ifndef HORA_H
#define HORA_H

/** @class Hora
    @brief Representa un momento del día, mediante una hora y unos minutos.
 */

class Hora {
    int hour, min;
public:
    Hora();
    ~Hora();

    bool compare(const Hora& hora);
    void write();
};

#endif // HORA_H
