/** @file agenda.h
    @brief Classe Agenda
 */

#ifndef AGENDA_H
#define AGENDA_H

#include "comanda.h"
#include "reloj.h"
#include "tarea.h"
#include <list>

/** @class Agenda
    @brief Representa una agenda (Estructura en la que almacenas tareas pasadas y futuras, con reloj y con comanda
    para ejecutar sobre sus tareas.
    Se utilizará básicamente a través de comandas.
 */

class Agenda {
private:
    Comanda comanda;
    Reloj reloj;
    list<Tarea> tareas;
public:
    /** @brief Crea una agenda vacía con un reloj que se iniciará con fecha inicial.
    \pre Cierto.
    \post  Agenda vacía creada*/
    Agenda();
    ~Agenda();

    /** @brief Lee una comanda nueva y la sustituye por la anterior ya que ya está ejecutada.
    \pre Cierto.
    \post Devuelve true si la comanda no es "sortir". False si lo es. */
    bool readComanda();

    /** @brief Ejecuta la comanda almacenada.
    \pre El p.i. tiene una comanda que no es "sortir".
    \post Devuelve true si la comanda se ha podido ejecutar. False si no. */
    bool runComanda();

};

#endif // AGENDA_H
