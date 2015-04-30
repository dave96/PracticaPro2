/** @file etiqueta.h
    @brief Classe Etiqueta
 */

#ifndef ETIQUETA_H
#define ETIQUETA_H

#include <string>
using namespace std;

/** @class Etiqueta
    @brief Representa una palabra descriptiva para una tarea. Se utilizan para filtrar tareas.
 */

class Etiqueta {
    string etiqueta;
public:
    Etiqueta(string etiqueta);
    ~Etiqueta();

    string getEtiqueta() const;
};

#endif // ETIQUETA_H
