#include "Archivo.h"
Archivo::Archivo()
{
 ///obj
}

bool Archivo::leerDeDisco(int pos, Cliente &obj){
    pCliente = fopen(CLIENTES, "rb");
    if(pCliente == NULL){
        return false;
    }
    fseek(pCliente, sizeof(Cliente) * pos, 0);
    bool leyo = fread(&obj, sizeof(Cliente), 1, pCliente);
    fclose(pCliente);
    return leyo;

}
bool Archivo::leerDeDisco(int pos, Turno &obj){
    pTurno = fopen(TURNOS, "rb");
    if(pTurno == NULL){
        return false;
    }
    fseek(pTurno, sizeof(Turno) * pos, 0);
    bool leyo = fread(&obj, sizeof(Turno), 1, pTurno);
    fclose(pTurno);
    return leyo;

}
bool Archivo::grabarEnDisco(Turno &obj){
    pTurno = fopen(TURNOS, "ab");
    if(pTurno == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Turno), 1, pTurno);
    fclose(pTurno);
    return escribio;
}

bool Archivo::grabarEnDisco(Cliente &obj){
    pCliente = fopen(CLIENTES, "ab");
    if(pCliente == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Cliente), 1, pCliente);
    fclose(pCliente);
    return escribio;
}
