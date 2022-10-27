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

/// ARCHIVOS PERSONA

bool Archivo::leerDeDisco(int pos, Persona &obj){
    FILE *pPersona;
    pPersona = fopen(PERSONA, "rb");
    if(pPersona == NULL){
        return false;
    }
    fseek(pPersona, sizeof(Persona) * pos, 0);
    bool leyo = fread(&obj, sizeof(Persona), 1, pPersona);
    fclose(pPersona);
    return leyo;
}

bool Archivo::grabarEnDisco(Persona obj){
    FILE *pPersona;
    pPersona = fopen(PERSONA, "ab");
    if(pPersona == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Persona), 1, pPersona);
    fclose(pPersona);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Persona obj){
    FILE *pPersona;
    pPersona = fopen(PERSONA, "rb+");
    if(pPersona == NULL) return false;
    fseek(pPersona, sizeof(Persona) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Persona), 1, pPersona);
    fclose(pPersona);
    return escribio;
}

int Archivo::contarRegistro(Persona &obj){
    FILE *pPersona;
    int cant;
    pPersona = fopen(PERSONA, "ab");
    if(pPersona == NULL){
        return -1;
    }
    fseek(pPersona, 0, 2);
    cant = ftell(pPersona)/sizeof(Persona);
    fclose(pPersona);
    return cant;
}

/// ARCHIVOS SERVICIOS

bool Archivo::leerDeDisco(int pos, Servicio &obj){
    FILE *pServicio;
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
    FILE *pServicio;
    pServicio = fopen(SERVICIOS, "ab");
    if(pServicio == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Servicio), 1, pServicio);
    fclose(pServicio);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Servicio obj){
    FILE *pServicio;
    pServicio = fopen(SERVICIOS, "rb+");
    if(pServicio == NULL) return false;
    fseek(pServicio, sizeof(Servicio) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Servicio), 1, pServicio);
    fclose(pServicio);
    return escribio;
}

int Archivo::contarRegistro(Servicio &obj){
    FILE *pServicio;
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

/// ARCHIVOS CUENTAS

bool Archivo::leerDeDisco(int pos, Cuenta &obj){
    FILE *pCuenta;
    pCuenta = fopen(CUENTAS, "rb");
    if(pCuenta == NULL){
        return false;
    }
    fseek(pCuenta, sizeof(Cuenta) * pos, 0);
    bool leyo = fread(&obj, sizeof(Cuenta), 1, pCuenta);
    fclose(pCuenta);
    return leyo;
}

bool Archivo::grabarEnDisco(Cuenta obj){
    FILE *pCuenta;
    pCuenta = fopen(CUENTAS, "ab");
    if(pCuenta == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Cuenta), 1, pCuenta);
    fclose(pCuenta);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Cuenta obj){
    FILE *pCuenta;
    pCuenta = fopen(CUENTAS, "rb+");
    if(pCuenta == NULL) return false;
    fseek(pCuenta, sizeof(Cuenta) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Cuenta), 1, pCuenta);
    fclose(pCuenta);
    return escribio;
}

int Archivo::contarRegistro(Cuenta &obj){
    FILE *pCuenta;
    int cant;
    pCuenta = fopen(CUENTAS, "ab");
    if(pCuenta == NULL){
        return -1;
    }
    fseek(pCuenta, 0, 2);
    cant = ftell(pCuenta)/sizeof(Cuenta);
    fclose(pCuenta);
    return cant;
}
