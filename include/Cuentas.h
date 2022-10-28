#ifndef CUENTAS_H
#define CUENTAS_H
#include "Fecha.h"

class Cuenta
{
    private:
        int ID;
        Fecha fechaEmision;
        char nombre[30];
        char apellido[30];
        float monto;
        bool estado;
    public:
        /// CONSRUCTOR
        Cuenta();
        /// METODOS
        bool cargar(int);
        bool mostrar();
        /// SETS
        void setID(int);
        void setFechaEmision(Fecha);
        bool setMonto(float);
        void setEstado(bool);
        /// GETS
        int getID();
        Fecha getFechaEmision();
        float getMonto();
        bool getEstado();
};

#endif // CUENTAS_H
