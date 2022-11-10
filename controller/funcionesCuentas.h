#ifndef FUNCIONESCUENTAS_H_INCLUDED
#define FUNCIONESCUENTAS_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES

void agregarCuentaCliente(Cliente);

void mostrarCuenta();

void modificarCuenta();
    int buscarCodigoCuenta(int, Cuenta);

void buscarCuenta();

bool eliminarCuentaCliente(int);

void agregarMontoCuenta(Turno);

///////////// DEFINICION DE AGREGAR REGISTRO CUENTA

void agregarCuentaCliente(Cliente cliente){
    Archivo archivo;
    Cuenta cuenta;
    cuenta.setID(cliente.getIdCuenta());
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
    int cont = 0;
    if(archivo.contarRegistro(cuenta)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
        return;
    }
    while(archivo.leerDeDisco(pos, cuenta)){
        gotoxy(38, cont+18);
        if(cuenta.mostrar()==true){
            cont += 3;
        }
        cout << endl;
        pos++;
    }
    if(cont==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
    }
}

///////////// DEFINICION DE MODIFICAR CUENTA

void modificarCuenta(){
    Cuadro cuadro;
    cuadro.setCoor({24,16});
    cuadro.setalto(10);
    cuadro.setlargo(52);
    cuadro.dibujar();
    Archivo archivo;
    Cuenta cuenta;
    int cod, pos;
    float pre;
    gotoxy (27, 18);
    cout << "INGRESAR EL CODIGO DE LA CUENTA A MODIFICAR: ";
    cin >> cod;
    pos = buscarCodigoCuenta(cod,cuenta);
    if(pos == -1){
        gotoxy (28, 22);
        cout << "NO EXISTE EL CODIGO DE LA CUENTA EN EL ARCHIVO" << endl;
        return;
    }
    archivo.leerDeDisco(pos,cuenta);
    gotoxy (40, 20);
    cout << "MONTO ACTUAL: " << cuenta.getMonto();
    gotoxy (33, 22);
    cout << "INGRESAR MONTO A DESCONTAR: ";
    gotoxy(61, 22);
    cin >> pre;
    if(cuenta.getMonto() < pre){
        gotoxy(28, 24);
        cout << "EL MONTO INGRESADO NO DEBE SER MAYOR AL ACTUAL" << endl;
        return;
    }
    if(cuenta.setMonto(pre)==false){
        gotoxy(36, 24);
        cout << "EL MONTO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,cuenta)==false){
        gotoxy(34, 24);
        cout << "ERROR AL MODIFICAR LA CUENTA" << endl;
        return;
    }
    gotoxy (34, 24);
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

///////////// DEFINICION DE BUSCAR CUENTA

void buscarCuenta(){
    Cuadro cuadro;
    cuadro.setCoor({23,16});
    cuadro.setalto(8);
    cuadro.setlargo(55);
    cuadro.dibujar();
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
    archivo.leerDeDisco(pos,cuenta);
    cuenta.mostrar();
    cout << endl;
}

///////////// DEFINICION DE ELIMINAR SERVICIO

bool eliminarCuentaCliente(int id){
    Archivo archivo;
    Cuenta cuenta;
    archivo.leerDeDisco(id-1,cuenta);
    if(cuenta.getMonto()!=0){
        return false;
    }
    cuenta.setEstado(false);
    archivo.modificarEnDisco(id-1,cuenta);
    return true;
}

/////////////////////// SE LE AGREGA UN MONTO SEGUN EL TURNO Y SERVICIO QUE LA PERSONA ESCOJA

void agregarMontoCuenta(Turno turno){
    float pre;
    Archivo archivo;
    Cuenta cuenta;
    Servicio servicio;
    pre = cuenta.getMonto() + servicio.getPrecio();
    cuenta.setMonto(pre);
}

#endif // FUNCIONESCUENTAS_H_INCLUDED
