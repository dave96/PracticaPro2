#include "menu.h"
using namespace std;

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::anadirTarea(map<Fecha, Tarea, less<Fecha> >::iterator& it) {
  entrada iterador;
  iterador.it = it;
  iterador.valido = true;
  iteradores.push_back(iterador);
}

map<Fecha, Tarea, less<Fecha> >::iterator Menu::consultarTarea(const int& num, bool& error) const {
  if(num <= iteradores.size() and iteradores[num-1].valido) {
      return iteradores[num-1].it;
  } else {
    error = true;
    map<Fecha, Tarea, less<Fecha> >::iterator itvacio;
    return itvacio;
  }
}

void Menu::eliminarTarea(const int& num) {
    if(num <= iteradores.size()) iteradores[num-1].valido = false;
}
