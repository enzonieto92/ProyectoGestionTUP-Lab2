#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Cliente.h"
#include "Turno.h"
#include "Servicio.h"

class Archivo
{
    private:
        const char *CLIENTES = "Clientes.dat";
        const char *TURNOS = "Turnos.dat";
        const char *SERVICIOS = "Servicios.dat";
        FILE *pCliente;
        FILE *pTurno;
        FILE *pServicio;
    public:
        Archivo();
        /// ARCHIVOS CLIENTE
        bool leerDeDisco(int, Cliente &);
        bool grabarEnDisco(Cliente &);
        bool modificarEnDisco(int, Cliente &);
        bool modificarEnDisco(Cliente*, int);
        int contarRegistro(Cliente &);
        /// ARCHIVOS TURNO
        bool leerDeDisco(int, Turno&);
        bool grabarEnDisco(Turno&);
        bool modificarEnDisco(int, Turno&);
        bool modificarEnDisco(Turno*, int);
        int contarRegistro(Turno&);
        /// ARCHIVOS SERVICO
        bool leerDeDisco(int, Servicio &);
        bool grabarEnDisco(Servicio);
        bool modificarEnDisco(int, Servicio);
        bool modificarEnDisco(Servicio*, int);
        int contarRegistro(Servicio &);
};
#endif // ARCHIVO_H
