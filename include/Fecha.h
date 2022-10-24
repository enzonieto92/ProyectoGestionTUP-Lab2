#ifndef FECHA_H
#define FECHA_H


class Fecha{
    private:
        int dia; /// 1 - 31
        int mes; /// 1 - 12
        int anio; /// menor o igual al actual
    public:
        /// CONSTRUCTOR
        Fecha();
        /// METODOS
        bool Cargar();
        void Mostrar();
        void Mostrar_hora();
        /// METODOS VALIDACION
        bool validarFechaTurno(Fecha);
        bool validarFechaNacimiento(Fecha);
        /// SETS
        bool setDia(int d);
        bool setMes(int m);
        bool setAnio(int a);
        /// GETS
        int getDia();
        int getMes();
        int getAnio();

        /// DESTRUCTOR
        ~Fecha();
};

#endif // FECHA_H
