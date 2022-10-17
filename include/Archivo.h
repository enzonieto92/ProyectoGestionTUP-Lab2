#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Contactos.h"

class Archivo
{
    public:
        Archivo();
        void Guardar(Contactos);
        void Mostrar(Contactos);

    private:
        int a;
};
#endif // ARCHIVO_H
