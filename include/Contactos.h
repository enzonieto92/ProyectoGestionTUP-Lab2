#ifndef CONTACTOS_H
#define CONTACTOS_H
#include "Cuadro.h"

class Contactos
{
    public:
        Contactos();
        void Menu();
        void Agregar();
        void Cargar();
        void Modificar();
        void Mostrar(int);
        void Mostrar_reg();
        bool LeerDeDisco(int);
    protected:

    private:
        origen coor;
        int opc;
        char Nombre[30];
        int Telefono;
};

#endif // CONTACTOS_H
