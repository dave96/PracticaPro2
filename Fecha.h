/** @file fecha.h
    @brief Classe Fecha
 */

#ifndef FECHA_H
#define FECHA_H

/** @class Fecha
    @brief Representa un momento específico, mediante una hora y mediante un día.
 */

struct Hora;

class Fecha {
private:
    //No se si esto estaria bien, que piensas? Quiero separar la especificacion de la implementacion, si esto funciona
    //que es asi, pero es cierto que puede ser que los campos de un struct se consideren especificaion, no implementacion.
    //dime que piensas.
    struct Hora;
    struct Dia;
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
