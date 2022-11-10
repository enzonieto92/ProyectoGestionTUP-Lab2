#ifndef FECHA_H
#define FECHA_H
#include "rlutil.h"


class Fecha{
    private:
        int dia; /// 1 - 31
        int diaFin;
        int mes; /// 1 - 12
        int vMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    //cantidad de días de los meses
        int anio; /// menor o igual al actual
        int hora; /// 0 - 23
        int minuto; /// 0 - 59
        bool esBisiesto(int);
    public:
        /// CONSTRUCTOR
        Fecha();
        Fecha(int, int, int);
        /// METODOS
        bool Cargar();
        void Mostrar(int, int);
        void Mostrar_hora();
        /// METODOS VALIDACION
        bool validarFechaTurno(Fecha);
        /// SETS
        bool setDia(int, int&);
        bool setMes(int);
        bool setAnio(int);
        bool setHora(int);
        bool setMinuto(int);
        void setFecha();
        /// GETS
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
        /// SOBRECARGA OPERADOR
        bool operator < (Fecha);
        void operator = (Fecha);
        bool operator == (Fecha);
        /// DESTRUCTOR
        ~Fecha();
};

#endif // FECHA_H
