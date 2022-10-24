#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Persona.h"
#include "Cliente.h"
#include "Turno.h"
#include "Servicio.h"
#include "Cuentas.h"

class Archivo
{
    private:
        const char *CLIENTES = "Clientes.dat";
        const char *TURNOS = "Turnos.dat";
        const char *PERSONA = "Contactos.dat";
        const char *SERVICIOS = "Servicios.dat";
        const char *CUENTAS = "Cuentas.dat";
        FILE *pCliente;
        FILE *pTurno;
    public:
        Archivo();
        /// ARCHIVOS CLIENTE
        bool leerDeDisco(int, Cliente &);
        bool grabarEnDisco(Cliente &);
        bool modificarEnDisco(int, Cliente &);
        int contarRegistro(Cliente &);
        /// ARCHIVOS TRUNO
        bool leerDeDisco(int, Turno&);
        bool grabarEnDisco(Turno&);
        /// ARCHIVOS PERSONA
        bool leerDeDisco(int, Persona &);
        bool grabarEnDisco(Persona);
        bool modificarEnDisco(int, Persona);
        int contarRegistro(Persona &);
        /// ARCHIVOS SERVICO
        bool leerDeDisco(int, Servicio &);
        bool grabarEnDisco(Servicio);
        bool modificarEnDisco(int, Servicio);
        int contarRegistro(Servicio &);
        /// ARCHIVOS CUENTA
        bool leerDeDisco(int, Cuenta &);
        bool grabarEnDisco(Cuenta);
        bool modificarEnDisco(int,Cuenta);
        int contarRegistro(Cuenta &);
};
#endif // ARCHIVO_H
