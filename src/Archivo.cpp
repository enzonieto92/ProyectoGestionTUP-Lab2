#include "Archivo.h"
#include <iostream>

using namespace std;
Archivo::Archivo()
{
 ///obj
}

bool Archivo::leerDeDisco(int pos, Cliente obj){
    pCliente = fopen(CLIENTES, "ab");
    if(pCliente == NULL){
        return false;
    }
    fseek(pCliente, sizeof(Cliente) * pos, 0);
    bool leyo = fread(&obj, sizeof(Cliente), 1, pCliente);
    fclose(pCliente);
    return leyo;

}

bool Archivo::grabarEnDisco(Cliente obj)
{
    pCliente = fopen(CLIENTES, "ab");
    if(pCliente == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Cliente), 1, pCliente);
    fclose(pCliente);
    return escribio;
}
