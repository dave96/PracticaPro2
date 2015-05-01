/** @file fecha.h
    @brief Classe Fecha
 */

#ifndef FECHA_H
#define FECHA_H

/** @class Fecha
    @brief Representa un momento específico, mediante una hora y mediante un día (structs).
 */

struct Hora {
    int hour, min;
};

struct Dia {
    int day, month, year;
};


class Fecha {
private:
    Hora hora;
    Dia dia;
public:

    /** @brief Crea una fecha nueva, con dia y hora asignados.
    \pre dia y hora están inicializados.
    \post El p.i. tiene dia y hora asignados.*/
    Fecha(const Dia& dia, const Hora& hora);
    Fecha();
    ~Fecha();

    /** @brief Imprime por pantalla el p.i.
    \pre Cierto.
    \post Imprime por pantalla el dia y la hora asignado.*/
    void write() const;

    /** @brief Devuelve hora del p.i.
    \pre Cierto.
    \post Devuelve la hora que el p.i. tiene asignado.*/
    Hora getHora() const;

    /** @brief Devuelve dia del p.i.
    \pre Cierto.
    \post Devuelve el dia que el p.i. tiene asignado.*/
    Dia getDia() const;

    /** @brief Modifica hora del p.i. por la que se pasa por parámetro.
    \pre hora está inicializado.
    \post El p.i. tiene hora asignado*/
    void setHora(Hora hora);

    /** @brief Modifica dia del p.i. por el que se pasa por parámetro.
    \pre dia está inicializado.
    \post El p.i. tiene dia asignado*/
    void setDia(Dia dia);

    /** @brief Compara el p.i. por otra fecha por parámetro. Devuelve true si el p.i. es anterior o igual al parámetro.
    \pre fecha es una fecha inicializada.
    \post Devuelve true si f es posterior al p.i., false si no.*/
    bool compare(const Fecha& f) const;
};

#endif // FECHA_H
