/** @file fecha.h
    @brief Classe Fecha
 */

#ifndef FECHA_H
#define FECHA_H

/** @class Fecha
    @brief Representa un momento específico, mediante una hora y mediante un día (structs).
 */

#include <string>
using namespace std;

class Fecha {
private:
    string hora;
    string dia;
    static string invertirDia(string dia);
public:

    /** @brief Crea una fecha nueva, con dia y hora asignados.
    \pre dia y hora están inicializados.
    \post El p.i. tiene dia y hora asignados.*/
    Fecha(const string& dia, const string& hora);
    Fecha();
    ~Fecha();

    /** @brief Imprime por pantalla el p.i.
    \pre Cierto.
    \post Imprime por pantalla el dia y la hora asignados, en este orden.*/
    void write() const;

    /** @brief Devuelve hora del p.i.
    \pre Cierto.
    \post Devuelve la hora que el p.i. tiene asignado.*/
    string getHora() const;

    /** @brief Devuelve dia del p.i.
    \pre Cierto.
    \post Devuelve el dia que el p.i. tiene asignado.*/
    string getDia() const;

    /** @brief Modifica hora del p.i. por la que se pasa por parámetro.
    \pre hora representa una hora válida o un string vacío.
    \post El p.i. tiene hora asignado*/
    void setHora(const string& hora);

    /** @brief Modifica dia del p.i. por el que se pasa por parámetro.
    \pre dia representa un día válido o un string vacío.
    \post El p.i. tiene dia asignado*/
    void setDia(const string& dia);

    /** @brief Compara el p.i. por otra fecha por parámetro. Devuelve true si el p.i. es anterior a f.
    \pre fecha es una fecha inicializada.
    \post Devuelve true si f es posterior al p.i., false si no.*/
    bool operator<(const Fecha& f) const;

    /** @brief Compara el p.i. por otra fecha por parámetro. Devuelve true si el p.i. es igual a f.
    \pre fecha es una fecha inicializada.
    \post Devuelve true si f es igual al p.i., false si no.*/
    bool operator==(const Fecha& f) const;

};

#endif // FECHA_H
