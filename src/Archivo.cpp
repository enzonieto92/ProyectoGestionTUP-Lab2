#include "Archivo.h"

Archivo::Archivo(){
 ///obj
}

/// CLIENTE

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

bool Archivo::grabarEnDisco(Cliente &obj){
    pCliente = fopen(CLIENTES, "ab");
    if(pCliente == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Cliente), 1, pCliente);
    fclose(pCliente);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Cliente &obj){
    pCliente = fopen(CLIENTES, "rb+");
    if(pCliente == NULL) return false;
    fseek(pCliente, sizeof(Cliente) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Cliente), 1, pCliente);
    fclose(pCliente);
    return escribio;
}

bool Archivo::modificarEnDisco(Cliente *Vec, int tam){

    pCliente = fopen(CLIENTES, "wb");
    if(pCliente == NULL) return false;
    fwrite(Vec, sizeof (Cliente), tam, pCliente);
    fclose(pCliente);
    return true;
}

int Archivo::contarRegistro(Cliente &obj){
    int cant;
    pCliente = fopen(CLIENTES, "ab");
    if(pCliente == NULL){
        return -1;
    }
    fseek(pCliente, 0, 2);
    cant = ftell(pCliente)/sizeof(Cliente);
    fclose(pCliente);
    return cant;
}

/// TURNO

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

bool Archivo::modificarEnDisco(int pos, Turno &obj){
    pTurno = fopen(TURNOS, "rb+");
    if(pTurno == NULL) return false;
    fseek(pTurno, sizeof(Turno) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Turno), 1, pTurno);
    fclose(pTurno);
    return escribio;
}

bool Archivo::modificarEnDisco(Turno *Vec, int tam){

    pTurno = fopen(TURNOS, "wb");
    if(pTurno == NULL) return false;
    fwrite(Vec, sizeof (Turno), tam, pTurno);
    fclose(pTurno);
    return true;
}


int Archivo::contarRegistro(Turno &obj){
    int cant;
    pTurno = fopen(TURNOS, "ab");
    if(pTurno == NULL){
        return -1;
    }
    fseek(pTurno, 0, 2);
    cant = ftell(pTurno)/sizeof(Turno);
    fclose(pTurno);
    return cant;
}

/// ARCHIVOS SERVICIOS

bool Archivo::leerDeDisco(int pos, Servicio &obj){
    pServicio = fopen(SERVICIOS, "rb");
    if(pServicio == NULL){
        return false;
    }
    fseek(pServicio, sizeof(Servicio) * pos, 0);
    bool leyo = fread(&obj, sizeof(Servicio), 1, pServicio);
    fclose(pServicio);
    return leyo;
}

bool Archivo::grabarEnDisco(Servicio obj){
    pServicio = fopen(SERVICIOS, "ab");
    if(pServicio == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Servicio), 1, pServicio);
    fclose(pServicio);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Servicio obj){
    pServicio = fopen(SERVICIOS, "rb+");
    if(pServicio == NULL) return false;
    fseek(pServicio, sizeof(Servicio) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Servicio), 1, pServicio);
    fclose(pServicio);
    return escribio;
}

bool Archivo::modificarEnDisco(Servicio *Vec, int tam){
    pServicio = fopen(SERVICIOS, "wb");
    if(pServicio == NULL) return false;
    bool escribio = fwrite(Vec, sizeof (Servicio), tam, pServicio);
    fclose(pServicio);
    return escribio;
}

int Archivo::contarRegistro(Servicio &obj){
    int cant;
    pServicio = fopen(SERVICIOS, "ab");
    if(pServicio == NULL){
        return -1;
    }
    fseek(pServicio, 0, 2);
    cant = ftell(pServicio)/sizeof(Servicio);
    fclose(pServicio);
    return cant;
}
