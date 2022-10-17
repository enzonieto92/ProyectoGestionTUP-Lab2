#ifndef CONTACTOS_H
#define CONTACTOS_H
#include "Cuadro.h"

class Contactos
{
    public:
        Contactos();
        void Cargar();
        void Mostrar(int);
    protected:

    private:
        origen coor;
        int opc;
        char Nombre[30];
        char Telefono[30];
};

#endif // CONTACTOS_H
