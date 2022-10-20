#ifndef TURNO_H
#define TURNO_H
#include "Fecha.h"

class Turno
{
    private:
        int idTurno;
        Fecha fechaServicio;
        int DNI;
        int tipoServicio;
        bool estado;
    public:
        // CONSTRUCOR
        Turno();
        Turno(int, int, int, bool);
        // METODOS
        bool Cargar(int, Fecha, int, int);
        void Mostrar();
        // SETS
        void setIdTurno(int);
        void setFechaServicio(Fecha);
        void setDNI(int);
        void setTipoServicio(int);
        void setEstado(bool);
        // GETS
        int getIdTurno();
        Fecha getFechaServicio();
        int getDNI();
        int getTipoServicio();
        bool getEstado();
        // DESTRUCTOR
        ~Turno();
};

#endif // TURNO_H
