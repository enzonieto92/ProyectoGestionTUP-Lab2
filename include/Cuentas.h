#ifndef CUENTAS_H
#define CUENTAS_H
#include "Fecha.h"

class Cuenta
{
    private:
        int ID;
        Fecha fechaEmision;
        float monto;
        bool estado;
    public:
        /// CONSRUCTOR
        Cuenta();
        /// METODOS
        bool mostrar(int);
        /// SETS
        void setID(int);
        void setFechaEmision(Fecha);
        void setMonto(float);
        void setEstado(bool);
        /// GETS
        int getID();
        void getFechaEmision();
        float getMonto();
        bool getEstado();
};

#endif // CUENTAS_H
