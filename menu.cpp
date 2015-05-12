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

void Menu::eliminarTarea (const int& num, bool& error) {
  error = false;
  if(num <= iteradores.size()) iteradores[num-1] = NULL;
  else error = true;
}

map<Fecha, Tarea, less<Fecha> >::iterator Menu::consultarTarea(const int& num, bool& error) {
  if(num <= iteradores.size()) {
    if(iteradores[num-1] != NULL) {
      error = false;
      return iteradores[num-1];
    } else {
      error = true;
      return NULL;
    }
  } else {
    error = true;
    return NULL
  }
}
