#include "tarea.h"

Tarea::Tarea() {
    Dia dia;
    Hora hora;
    fecha = Fecha(dia, hora);
}

Tarea::~Tarea() {

}
