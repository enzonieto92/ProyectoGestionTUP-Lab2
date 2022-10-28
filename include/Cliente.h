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
        char email[40];
        int idCuenta;
        bool estado;
    public:
        /// CONSTRUCTOR
        Cliente();
        /// METODOS
        bool Cargar(int nD, int idC);
        void Mostrar();
        ///SETS
        bool setDNI(int nD);
        void setNombre(const char *nom);
        void setApellido(const char *ape);
        void setTelefono(const char *tel);
        void setEmail(const char *e);
        void setIdCuenta(int idC);
        void setEstado(bool e);
        ///GETS
        int getDNI();
        const char *getNombre();
        const char *getApellido();
        const char *getTelefono();
        const char *getEmail();
        int getIdCuenta();
        bool getEstado();
        /// DESTRUCTOR
        ~Cliente();
};

#endif // CLIENTE_H
