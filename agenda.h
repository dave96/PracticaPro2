/** @file agenda.h
    @brief Classe Agenda
 */

#ifndef AGENDA_H
#define AGENDA_H

#include "comanda.h"
#include "reloj.h"
#include "tarea.h"
#include "Fecha.h"
#include <list>
#include <map>
#include <iostream>

using namespace std;

/** @class Agenda dfsdfsdfsdfsdfsd
    @brief Representa una agenda.

    Estructura en la que almacena tareas (Tarea) pasadas y futuras, con Reloj y con Comanda
    para ejecutar sobre sus tareas.
    Se utilizará básicamente a través de comandas.
    De acceso público solo tiene dos métodos, uno para mandarle leer una comanda y otra para ejecutarla. Todos los
    cálculos y operaciones se harán de forma privada en función de la comanda leída.*/

class Agenda {
private:
    Comanda comanda;
    Reloj reloj;
    map <Fecha, Tarea, less<Fecha> > tareas;
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
