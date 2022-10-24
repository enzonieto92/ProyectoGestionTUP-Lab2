#ifndef TURNO_H
#define TURNO_H
#include "Fecha.h"

class Turno
{
    private:
        Fecha _fecha;
        char nombre[30];
        char apellido[30];

    public:
        Turno();
        void setNombre(const char *nom);
        void setApellido(const char *ape);
        void Cargar();
        void Mostrar();
};

#endif // TURNO_H
