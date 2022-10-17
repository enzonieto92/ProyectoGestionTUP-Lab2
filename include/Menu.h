#ifndef MENU_H
#define MENU_H
#include "Cuadro.h"
class Menu
{
    private:
        int opc;
        origen _coor;
        Cuadro Cuadro, Lista;
    public:
        Menu();
        void setCuadro(origen, int, int, int);
        void setLista (origen, int, int);
        int principal();
        void Turnos();
        void Clientes();
        void Contactos();

};

#endif // MENU_H
