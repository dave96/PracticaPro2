/** @file main.cpp
    @brief Programa principal del gestor de tareas.

    Crea un objeto Agenda, al que le hace leer una nueva Comanda y la ejecuta hasta que la comanda sea salir.
 */

#include <iostream>
#include "agenda.h"
using namespace std;


int main() {
    Agenda agenda;
    while(agenda.readComanda()) {
        agenda.runComanda();
    }
    cout << "Fin de programa, gracias por usarme." << endl;
}
