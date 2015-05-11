#ifndef MENU_H
#define MENU_H

#include <map>
#include <vector>
#include "fecha.h"
#include "tarea.h"
using namespace std;



class Menu {
private:
    vector< map<Fecha, Tarea, less<Fecha> >::iterator > iteradores;

public:
    //pre Cierto.
    Menu();
    ~Menu();

    /* Modificadoras */
    //pre Iterador it apunta a la tarea en el map.
    void anadirTarea (map<Fecha, Tarea, less<Fecha> >::iterator& it);

    //pre Int num <= numTareas.
    //post Eliminada la tarea numero num
    void eliminarTarea (const int& num, bool& error);

    map<Fecha, Tarea, less<Fecha> >::iterator consultarTarea(const int& num, bool& error);

};

#endif // MENU_H
