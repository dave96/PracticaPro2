/** @file main.cpp
    @brief Programa principal del gestor de tareas.

    Crea un objeto Agenda, al que le hace leer una nueva Comanda y la ejecuta hasta que la comanda sea salir.
 */

#include "agenda.hh"
#include <iostream>
using namespace std;


int main() {
    Agenda agenda;
    bool formato = false;
    while(agenda.readComanda(formato)) {
        if(formato) {
            agenda.runComanda();
        }
    }
}
