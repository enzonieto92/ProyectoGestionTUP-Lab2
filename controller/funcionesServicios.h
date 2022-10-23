#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES

void agregarRegistroServicio();

void mostrarServicio();

void modificarServicio();
    int buscarCodigoServicio(int, Servicio);
    Servicio leerRegistroServicio(int, Servicio);

void buscarServicio();

void eliminarServicio();

///////////// DEFINICION DE AGREGAR REGISTRO SERVICIO

void agregarRegistroServicio(){
    int var;
    Archivo archivo;
    Servicio servicio;
    var = archivo.contarRegistro(servicio);
    if(var == -1){
        gotoxy (41, 24);
        cout << "FALLO AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    var += 1;
    if(servicio.cargar(var)==false){
        gotoxy (42, 22);
        cout << "EL PRECIO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.grabarEnDisco(servicio)==false){
        gotoxy (41, 24);
        cout << "FALLO AL GUARDAR EL REGISTRO" << endl;
        return;
    }
    gotoxy (42, 24);
    cout << "REGISTRO GUARDADO" << endl;
}

///////////// DEFINICION DE MOSTRAR SERVICIO

void mostrarServicio(){
    Archivo archivo;
    Servicio servicio;
    int pos = 0;
    if(archivo.contarRegistro(servicio)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
        return;
    }
    while(archivo.leerDeDisco(pos, servicio)){
        gotoxy(38, pos+16);
        servicio.mostrar();
        cout << endl;
        pos++;
    }
}

///////////// DEFINICION DE MODIFICAR SERVICIO

void modificarServicio(){
    Archivo archivo;
    Servicio servicio;
    int cod, pos;
    float pre;
    gotoxy (32, 18);
    cout << "INGRESAR EL CODIGO DEL SERVICIO A MODIFICAR: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy (30, 20);
        cout << "NO EXISTE EL CODIGO DEL SERVICO EN EL ARCHIVO" << endl;
        return;
    }
    servicio = leerRegistroServicio(pos,servicio);
    gotoxy (30, 20);
    cout << "INGRESAR NUEVO PRECIO: " << endl;
    gotoxy(65, 20);
    cin >> pre;
    if(servicio.setPrecio(pre)==false){
        gotoxy (34, 22);
        cout << "EL PRECIO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,servicio)==false){
        gotoxy (34, 22);
        cout << "ERROR AL MODIFICAR EL PERSONAL" << endl;
        return;
    }
    gotoxy (34, 22);
    cout << "REGISTO MODIFICADO EXISTOSAMENTE" << endl;
}

int buscarCodigoServicio(int var, Servicio obj){
    Archivo archivo;
    int pos = 0;
    while(archivo.leerDeDisco(pos,obj)){
        if(var == obj.getCodigo()){
            if(obj.getEstado()==true){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Servicio leerRegistroServicio(int pos, Servicio obj){
    FILE *pServicio;
    pServicio = fopen("Servicios.dat","rb");
    if(pServicio == NULL){
        return obj;
    }
    fseek(pServicio, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, pServicio);
    fclose(pServicio);
    return obj;
}

///////////// DEFINICION DE BUSCAR SERVICIO

void buscarServicio(){
    Archivo archivo;
    Servicio servicio;
    int pos,cod;
    gotoxy(31, 18);
    cout << "INGRESE EL NUMERO CODIGO DEL SERVICIO: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy(25, 21);
        cout << "NO EXISTE EL CODIGO DE SERVICIO EN EL ARCHIVO" << endl;
        return;
    }
    servicio = leerRegistroServicio(pos,servicio);
    gotoxy(38, 20);
    servicio.mostrar();
    cout << endl;
}

///////////// DEFINICION DE ELIMINAR SERVICIO

void eliminarServicio(){
    Archivo archivo;
    Servicio servicio;
    int cod, pos;
    gotoxy (32, 18);
    cout << "INGRESAR EL CODIGO DE SERVICIO A ELIMINAR: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy (30, 20);
        cout << "NO EXISTE EL CODIGO DE SERVICIO EN EL ARCHIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,servicio)==false){
        gotoxy (32, 20);
        cout << "ERROR AL BORRAR EL SERVICIO" << endl;
        return;
    }
    gotoxy (36, 20);
    cout << "REGISTO BORRADO EXISTOSAMENTE" << endl;
}

#endif // FUNCIONESSERVICIOS_H_INCLUDED
