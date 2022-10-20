#ifndef CLIENTE_H
#define CLIENTE_H
#include "Funciones.h"

class Cliente
{
    private:
        int DNI;
        char nombre[30];
        char apellido[30];
        char telefono[40];
        bool estado;
    public:
        /// CONSTRUCTOR
        Cliente();
        /// METODOS
        bool Cargar(int nD);
        void Mostrar();
        ///SETS
        bool setDNI(int nD);
        void setNombre(const char *nom);
        void setApellido(const char *ape);
        void setTelefono(const char *tel);
        void setEstado(bool e);
        ///GETS
        int getDNI();
        const char *getNombre();
        const char *getApellido();
        const char *getTelefono();
        bool getEstado();
        /// DESTRUCTOR
        ~Cliente();
};

#endif // CLIENTE_H
