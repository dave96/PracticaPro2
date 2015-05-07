#ifndef MENU_H
#define MENU_H


class Menu {
    vector<map<Fecha, Tarea, less<Fecha> >::iterator> iteradores;

public:
    Menu();
    ~Menu();
};

#endif // MENU_H
