#ifndef FECHA_H
#define FECHA_H
#include "rlutil.h"


class Fecha{
    private:
        int dia; /// 1 - 31
        int mes; /// 1 - 12
        int anio; /// menor o igual al actual
        int hora; /// 0 - 23
        int minuto; /// 0 - 59
        bool esBisiesto(int);
    public:
        /// CONSTRUCTOR
        Fecha();
        /// METODOS
        bool Cargar();
        void MostrarFecha();
        void MostrarHora();
        /// METODOS VALIDACION
        bool validarFechaTurno(Fecha);
        /// SETS
        bool setDia(int, int&);
        bool setMes(int);
        bool setAnio(int);
        bool setHora(int);
        bool setMinuto(int);
        /// GETS
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
        /// SOBRECARGA OPERADOR
        bool operator < (Fecha);
        /// DESTRUCTOR
        ~Fecha();
};

#endif // FECHA_H
