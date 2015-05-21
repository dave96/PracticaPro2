#ifndef MENU_H
#define MENU_H

#include <map>
#include <vector>
#include "fecha.hh"
#include "tarea.hh"
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
    /** @brief Crea un menú vacío.
    \pre Cierto.
    \post  Menú vacío creado.*/
    Menu();
    ~Menu();

    /** @brief Añade una tarea al menú actual.
    \pre Iterator válido apuntando a la tarea.
    \post Tarea añadida al p.i. */
    void anadirTarea (map<Fecha, Tarea, less<Fecha> >::iterator& it);

    /** @brief Marca como no válida una tarea del menú, para que no se pueda acceder a ella.
    \pre Número de la tarea en el menú.
    \post  Tarea inhabilitada (el iterator no se puede recuperar) */
    void eliminarTarea (const int& num);

    /** @brief Cambia el iterador que apunta a la tarea num.
    \pre iterador it válido, número de tarea en el menú.
    \post  La tarea numero num ahora apunta al iterator it */
    void modificarTarea(const int& num, map<Fecha, Tarea, less<Fecha> >:: iterator& it);

    /** @brief Devuelve el iterador de la tarea número num del menú.
    \pre Número de tarea en el menú, error falso.
    \post Devuelve el iterador a la tarea y error falso si hay es correcta la consulta, y error verdadero y un iterador vacío si no es correcta. */
    map<Fecha, Tarea, less<Fecha> >::iterator consultarTarea (const int& num, bool& error) const;

};

#endif // MENU_H
