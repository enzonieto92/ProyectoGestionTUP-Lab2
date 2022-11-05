#include "Archivo.h"

/// CLIENTE

bool Archivo::leerDeDisco(int pos, Cliente &obj){
    p = fopen(CLIENTES, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Cliente) * pos, 0);
    bool leyo = fread(&obj, sizeof(Cliente), 1, p);
    fclose(p);
    return leyo;
}

bool Archivo::grabarEnDisco(Cliente &obj){
    p = fopen(CLIENTES, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Cliente &obj){
    p = fopen(CLIENTES, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof(Cliente) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}

int Archivo::contarRegistro(Cliente &obj){
    int cant;
    p = fopen(CLIENTES, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Cliente);
    fclose(p);
    return cant;
}

/// TURNO

bool Archivo::leerDeDisco(int pos, Turno &obj){
    p = fopen(TURNOS, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Turno) * pos, 0);
    bool leyo = fread(&obj, sizeof(Turno), 1, p);
    fclose(p);
    return leyo;
}

bool Archivo::grabarEnDisco(Turno &obj){
    p = fopen(TURNOS, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Turno), 1, p);
    fclose(p);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Turno &obj){
    p = fopen(TURNOS, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof(Turno) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Turno), 1, p);
    fclose(p);
    return escribio;
}

int Archivo::contarRegistro(Turno &obj){
    int cant;
    p = fopen(TURNOS, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Turno);
    fclose(p);
    return cant;
}

/// ARCHIVOS PERSONAL

bool Archivo::leerDeDisco(int pos, Personal &obj){
    p = fopen(PERSONAL, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Personal) * pos, 0);
    bool leyo = fread(&obj, sizeof(Personal), 1, p);
    fclose(p);
    return leyo;
}

bool Archivo::grabarEnDisco(Personal obj){
    p = fopen(PERSONAL, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Personal), 1, p);
    fclose(p);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Personal obj){
    p = fopen(PERSONAL, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof(Personal) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Personal), 1, p);
    fclose(p);
    return escribio;
}

int Archivo::contarRegistro(Personal obj){
    int cant;
    p = fopen(PERSONAL, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Personal);
    fclose(p);
    return cant;
}

/// ARCHIVOS SERVICIOS

bool Archivo::leerDeDisco(int pos, Servicio &obj){
    p = fopen(SERVICIOS, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Servicio) * pos, 0);
    bool leyo = fread(&obj, sizeof(Servicio), 1, p);
    fclose(p);
    return leyo;
}

bool Archivo::grabarEnDisco(Servicio obj){
    p = fopen(SERVICIOS, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Servicio), 1, p);
    fclose(p);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Servicio obj){
    p = fopen(SERVICIOS, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof(Servicio) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Servicio), 1, p);
    fclose(p);
    return escribio;
}

int Archivo::contarRegistro(Servicio obj){
    int cant;
    p = fopen(SERVICIOS, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Servicio);
    fclose(p);
    return cant;
}

/// ARCHIVOS CUENTAS

bool Archivo::leerDeDisco(int pos, Cuenta &obj){
    p = fopen(CUENTAS, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Cuenta) * pos, 0);
    bool leyo = fread(&obj, sizeof(Cuenta), 1, p);
    fclose(p);
    return leyo;
}

bool Archivo::grabarEnDisco(Cuenta obj){
    p = fopen(CUENTAS, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof(Cuenta), 1, p);
    fclose(p);
    return escribio;
}

bool Archivo::modificarEnDisco(int pos, Cuenta obj){
    p = fopen(CUENTAS, "rb+");
    if(p == NULL) return false;
    fseek(p, sizeof(Cuenta) * pos, 0);
    bool escribio = fwrite(&obj, sizeof(Cuenta), 1, p);
    fclose(p);
    return escribio;
}

int Archivo::contarRegistro(Cuenta obj){
    int cant;
    p = fopen(CUENTAS, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Cuenta);
    fclose(p);
    return cant;
}
