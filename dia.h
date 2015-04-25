/** @file dia.h
    @brief Classe Dia
 */

#ifndef DIA_H
#define DIA_H

/** @class Dia
    @brief Representa un dia del año a través de un día, un mes, y un año (el año son las últimas dos cifras de 20**).
 */

class Dia {
    int day, month, year;
public:
    Dia();
    ~Dia();

    bool compare(const Dia& dia);
    void write();
};

#endif // DIA_H
