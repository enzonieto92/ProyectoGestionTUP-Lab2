#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Contactos.h"
#include "Cliente.h"

class Archivo
{
    private:
        const char *CLIENTES = "Clientes.dat";

        FILE *pCliente;
    public:
        Archivo();
        bool leerDeDisco(int, Cliente);
        ///bool leerDeDisco(Turno);
        bool grabarEnDisco(Cliente);
        bool modificarEnDisco(int, Cliente);



};
#endif // ARCHIVO_H
