#ifndef FUNCIONESCUENTAS_H_INCLUDED
#define FUNCIONESCUENTAS_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES

void agregarRegistroCuenta();

void mostrarCuenta();

void modificarCuenta();
    int buscarCodigoCuenta(int, Cuenta);
    Cuenta leerRegistroCuenta(int, Cuenta);

void buscarCuenta();

void eliminarCuenta();

///////////// DEFINICION DE AGREGAR REGISTRO CUENTA

void agregarRegistroCuenta(){
    int var;
    Archivo archivo;
    Cuenta cuenta;
    var = archivo.contarRegistro(cuenta);
    if(var == -1){
        gotoxy (38, 24);
        cout << "FALLO AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    var += 1;
    if(cuenta.cargar(var)==false){
        gotoxy (36, 24);
        cout << "EL MONTO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.grabarEnDisco(cuenta)==false){
        gotoxy (38, 24);
        cout << "FALLO AL GUARDAR EL REGISTRO" << endl;
        return;
    }
    gotoxy (41, 24);
    cout << "REGISTRO GUARDADO" << endl;
}

///////////// DEFINICION DE MOSTRAR CUENTA

void mostrarCuenta(){
    Archivo archivo;
    Cuenta cuenta;
    int pos = 0;
    if(archivo.contarRegistro(cuenta)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
        return;
    }
    while(archivo.leerDeDisco(pos, cuenta)){
        cuenta.mostrar();
        cout << endl;
        pos++;
    }
}

///////////// DEFINICION DE MODIFICAR CUENTA

void modificarCuenta(){
    Archivo archivo;
    Cuenta cuenta;
    int cod, pos;
    float pre;
    gotoxy (28, 18);
    cout << "INGRESAR EL CODIGO DE LA CUENTA A MODIFICAR: ";
    cin >> cod;
    pos = buscarCodigoCuenta(cod,cuenta);
    if(pos == -1){
        gotoxy (27, 20);
        cout << "NO EXISTE EL CODIGO DE LA CUENTA EN EL ARCHIVO" << endl;
        return;
    }
    cuenta = leerRegistroCuenta(pos,cuenta);
    gotoxy (36, 20);
    cout << "INGRESAR NUEVO MONTO: " << endl;
    gotoxy(58, 20);
    cin >> pre;
    if(cuenta.setMonto(pre)==false){
        gotoxy(34, 22);
        cout << "EL MONTO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,cuenta)==false){
        gotoxy(34, 22);
        cout << "ERROR AL MODIFICAR LA CUENTA" << endl;
        return;
    }
    gotoxy (34, 22);
    cout << "REGISTO MODIFICADO EXISTOSAMENTE" << endl;
}

int buscarCodigoCuenta(int var, Cuenta obj){
    Archivo archivo;
    int pos = 0;
    while(archivo.leerDeDisco(pos,obj)){
        if(var == obj.getID()){
            if(obj.getEstado()==true){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Cuenta leerRegistroCuenta(int pos, Cuenta obj){
    FILE *pCuenta;
    pCuenta = fopen("Cuentas.dat","rb");
    if(pCuenta == NULL){
        return obj;
    }
    fseek(pCuenta, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, pCuenta);
    fclose(pCuenta);
    return obj;
}

///////////// DEFINICION DE BUSCAR CUENTA

void buscarCuenta(){
    Archivo archivo;
    Cuenta cuenta;
    int pos,id;
    gotoxy(31, 18);
    cout << "INGRESE EL NUMERO DE ID DE LA CUENTA: ";
    cin >> id;
    pos = buscarCodigoCuenta(id,cuenta);
    if(pos == -1){
        gotoxy(25, 21);
        cout << "NO EXISTE EL NUMERO DE ID DE LA CUENTA EN EL ARCHIVO" << endl;
        return;
    }
    cuenta = leerRegistroCuenta(pos,cuenta);
    cuenta.mostrar();
    cout << endl;
}

///////////// DEFINICION DE ELIMINAR SERVICIO

void eliminarCuenta(){
    Archivo archivo;
    Cuenta cuenta;
    int id, pos;
    gotoxy (26, 18);
    cout << "INGRESAR EL NUMERO DE ID DE LA CUENTA A ELIMINAR: ";
    cin >> id;
    pos = buscarCodigoCuenta(id,cuenta);
    if(pos == -1){
        gotoxy (24, 20);
        cout << "NO EXISTE EL NUMERO DE ID DE LA CUENTA EN EL ARCHIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,cuenta)==false){
        gotoxy (32, 20);
        cout << "ERROR AL BORRAR LA CUENTA" << endl;
        return;
    }
    gotoxy (36, 20);
    cout << "REGISTO BORRADO EXISTOSAMENTE" << endl;
}

#endif // FUNCIONESCUENTAS_H_INCLUDED
