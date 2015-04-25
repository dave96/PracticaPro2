#include <iostream>
#include "agenda.h"
using namespace std;

int main() {
    Agenda agenda;
    while(agenda.readComanda()) {
        agenda.runComanda();
    }
    cout << "Fin de programa, gracias por usarme. Gon mola" << endl;
}

