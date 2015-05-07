#ifndef MENU_H
#define MENU_H

#include <map>
#include <vector>
#include "fecha.h"
#include "tarea.h"
using namespace std;

class Menu {
    vector<map<Fecha, Tarea, less<Fecha> >::iterator> iteradores;

public:
    Menu();
    ~Menu();
};

#endif // MENU_H
