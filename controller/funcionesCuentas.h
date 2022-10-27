#ifndef FUNCIONESCUENTAS_H_INCLUDED
#define FUNCIONESCUENTAS_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES

void agregarCuentaCliente(Cliente);

void mostrarCuenta();

void modificarCuenta();
    int buscarCodigoCuenta(int, Cuenta);
    Cuenta leerRegistroCuenta(int, Cuenta);

void buscarCuenta();

bool eliminarCuentaCliente(int);

void agregarMontoCuenta(Turno);

///////////// DEFINICION DE AGREGAR REGISTRO CUENTA

void agregarCuentaCliente(Cliente cliente){
    Archivo archivo;
    Cuenta cuenta;
    cuenta.setID(cliente.getIdCuenta());
    cuenta.setNombre(cliente.getNombre());
    cuenta.setApellido(cliente.getApellido());
    cuenta.setEstado(true);
    if(archivo.grabarEnDisco(cuenta)==false){
        gotoxy (42, 27);
        cout << "FALLO AL GRABAR EN DISCO" << endl;
        return;
    }
    gotoxy (38, 26);
    cout << "CUENTA CREADA EXITOSAMENTE" << endl;
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

bool eliminarCuentaCliente(int id){
    Archivo archivo;
    Cuenta cuenta;
    if(archivo.leerDeDisco(id-1,cuenta)==false){
        return false;
    }
    if(cuenta.getMonto()!=0){
        return false;
    }
    cuenta.setEstado(false);
    if(archivo.modificarEnDisco(id-1,cuenta)==false){
        return false;
    }
    return true;
}

void agregarMontoCuenta(Turno turno){
    float pre;
    Archivo archivo;
    Cuenta cuenta;
    Servicio servicio;
    archivo.leerDeDisco(turno.getTipoServicio()-1,servicio);
    archivo.leerDeDisco(turno.getIdCuenta()-1,cuenta);
    pre = cuenta.getMonto() + servicio.getPrecio();
    cuenta.setMonto(pre);
    archivo.modificarEnDisco(turno.getIdCuenta()-1,cuenta);
}

#endif // FUNCIONESCUENTAS_H_INCLUDED
