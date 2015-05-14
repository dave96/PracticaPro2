#ifndef MENU_H
#define MENU_H

#include <map>
#include <vector>
#include "fecha.h"
#include "tarea.h"
using namespace std;


/** @class Menu
    @brief Gestiona el menú de la agenda.

    Es una estructura de datos que permite a la agenda saber que número está asociado con que tarea en todo momento.
    Se usa en las comandas de modificación y eliminación, y crea en las consultas.
    Los métodos de acceso público sirven para añadir y consultar tareas, porque el objeto se borra a cada consulta.
*/



class Menu {
private:

    struct entrada {
         map<Fecha, Tarea, less<Fecha> >::iterator it;
         bool valido;

    };

    vector<entrada> iteradores;


public:
    //pre Cierto.
    Menu();
    ~Menu();

    /* Modificadoras */
    //pre Iterador it apunta a la tarea en el map.
    void anadirTarea (map<Fecha, Tarea, less<Fecha> >::iterator& it);

    void eliminarTarea (const int& num);

    map<Fecha, Tarea, less<Fecha> >::iterator consultarTarea (const int& num, bool& error) const;

};

#endif // MENU_H
