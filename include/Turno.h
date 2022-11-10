#ifndef TURNO_H
#define TURNO_H
#include "Fecha.h"
#include "Cliente.h"
#include "Servicio.h"
class Turno
{
    private:
        Fecha fechaServicio;
        Cliente cliente;
        Servicio servicio;
        bool estado;
    public:
        // CONSTRUCOR
        Turno();
        void Mostrar();
        // SETS
        void setIdTurno(int);
        void setFecha(Fecha&);
        void setIdCuenta(int);
        void setTipoServicio(int);
        void setIdPersonal(int);
        void setEstado(bool);
        void setEstadoCliente(bool);
        void setCliente(Cliente);
        void setServicio(Servicio);
        // GETS
        int getIdTurno();
        int getIdCuenta();
        int getTipoServicio();
        Fecha getFechaServicio();
        bool getEstado();
        Cliente getCliente();
        Servicio getServicio();
        // DESTRUCTOR
        ~Turno();
};

#endif // TURNO_H
