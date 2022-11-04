#ifndef TURNO_H
#define TURNO_H
#include "Fecha.h"

class Turno
{
    private:
        int idTurno;
        Fecha fechaServicio;
        int idCuenta;
        int tipoServicio;
        int iDpersonal;
        bool estado;
    public:
        // CONSTRUCOR
        Turno();
        Turno(int, int, int, int, bool);
        // METODOS
        bool Cargar(int, Fecha, int, int, int);
        void Mostrar();
        // SETS
        void setIdTurno(int);
        void setFechaServicio(Fecha);
        void setIdCuenta(int);
        void setTipoServicio(int);
        void setIdPersonal(int);
        void setEstado(bool);
        // GETS
        int getIdTurno();
        Fecha getFechaServicio();
        int getIdCuenta();
        int getTipoServicio();
        int getIdPersonal();
        bool getEstado();
        // DESTRUCTOR
        ~Turno();
};

#endif // TURNO_H
