#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Contactos.h"
#include "Cliente.h"
#include "Turno.h"
class Archivo
{
    private:
        const char *CLIENTES = "Clientes.dat";
        const char *TURNOS = "Turnos.dat";
        FILE *pCliente;
        FILE *pTurno;
    public:
        Archivo();
        bool leerDeDisco(int, Cliente&);
        bool leerDeDisco(int, Turno&);
        ///bool leerDeDisco(Turno);
        bool grabarEnDisco(Cliente&);
        bool grabarEnDisco(Turno&);
        bool modificarEnDisco(int, Cliente&);



};
#endif // ARCHIVO_H
