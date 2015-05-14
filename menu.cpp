#include <map>
#include <vector>
#include "menu.h"
#include "fecha.h"
#include "tarea.h"

using namespace std;

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::anadirTarea(map<Fecha, Tarea, less<Fecha> >::iterator& it) {
  iteradores.push_back(it);
}

map<Fecha, Tarea, less<Fecha> >::iterator Menu::consultarTarea(const int& num, bool& error) const {
  if(num <= iteradores.size()) {
      error = false;
      return iteradores[num-1];
  } else {
    error = true;
    map<Fecha, Tarea, less<Fecha> >::iterator itvacio;
    return itvacio;
  }
}
