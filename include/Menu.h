#ifndef MENU_H
#define MENU_H
#include "Cuadro.h"
#include "Archivo.h"

class Menu
{
    private:
        int opc;
        Origen _coor;
        Cuadro _cuadro, _lista;
    public:
        Menu();
        void setCuadro(Origen, int, int, int);
        void setLista (Origen, int, int);
        int principal();
        void Turnos();
        void Clientes();
        void Personal();
        void Servicio();
        void Cuentas();
};

#endif // MENU_H
