#ifndef MENU_H
#define MENU_H
#include "Cuadro.h"
#include "Archivo.h"

class Menu
{
    private:
        int opc;
        origen _coor;
        Cuadro _cuadro, _lista;
    public:
        Menu();
        void setCuadro(origen, int, int, int);
        void setLista (origen, int, int);
        int principal();
        void Turnos();
        void Clientes();
        void Persona();
        void Servicio();
        void Cuentas();
};

#endif // MENU_H
