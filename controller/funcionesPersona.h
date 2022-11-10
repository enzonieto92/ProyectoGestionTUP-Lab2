#ifndef FUNCIONESPERSONA_H_INCLUDED
#define FUNCIONESPERSONA_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES

void agregarRegistroPersonal();

void mostrarPersonal();

void modificarPersonal();
    int buscarIdPersonal(int, Personal);

void buscarPersonal();

void eliminarPersonal();

///////////// DEFINICION DE AGREGAR REGISTRO PERSONA

void agregarRegistroPersonal(){
    Cuadro cuadro;
    cuadro.setCoor({30,16});
    cuadro.setalto(12);
    cuadro.setlargo(40);
    cuadro.dibujar();
    int var;
    Archivo archivo;
    Personal personal;
    var = archivo.contarRegistro(personal);
    if(var == -1){
        gotoxy (37, 26);
        cout << "FALLO AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    var += 1;
    if(personal.cargar(var)==false){
        gotoxy (35, 26);
        cout << "EL SUELDO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.grabarEnDisco(personal)==false){
        gotoxy (37, 26);
        cout << "FALLO AL GUARDAR EL REGISTRO" << endl;
        return;
    }
    gotoxy (40, 26);
    cout << "REGISTRO GUARDADO" << endl;
}

///////////// DEFINICION DE MOSTRAR CONTACTO

void mostrarPersonal(){
    Cuadro cuadro;
    cuadro.setCoor({30,16});
    cuadro.setalto(12);
    cuadro.setlargo(40);
    cuadro.dibujar();
    Archivo archivo;
    Personal personal;
    int pos = 0;
    int cont = 0;
    if(archivo.contarRegistro(personal)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
        return;
    }
    while(archivo.leerDeDisco(pos, personal)){
        gotoxy(34, cont+18);
        if(personal.mostrar()==true){
            cont++;
        }
        cout << endl;
        pos++;
    }
    if(cont == 0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
    }
}

///////////// DEFINICION DE MODIFICAR CONTACTO

void modificarPersonal(){
    Cuadro cuadro;
    cuadro.setCoor({25,18});
    cuadro.setalto(8);
    cuadro.setlargo(50);
    cuadro.dibujar();
    Archivo archivo;
    Personal personal;
    int id, pos;
    char var[40];
    gotoxy (32, 20);
    cout << "INGRESAR NUMERO DE ID A MODIFICAR: ";
    cin >> id;
    pos = buscarIdPersonal(id,personal);
    if(pos == -1){
        gotoxy (29, 22);
        cout << "NO EXISTE EL ID DEL PERSONAL EN EL ARCHIVO" << endl;
        return;
    }
    archivo.leerDeDisco(pos,personal);
    gotoxy (28, 22);
    cout << "INGRESAR NUEVO NUMERO DE TELEFONO: " << endl;
    gotoxy(63, 22);
    cargarCadena(var,39);
    personal.setTelefono(var);
    if(archivo.modificarEnDisco(pos,personal)==false){
        gotoxy (34, 24);
        cout << "ERROR AL MODIFICAR EL PERSONAL" << endl;
        return;
    }
    gotoxy (34, 24);
    cout << "REGISTO MODIFICADO EXISTOSAMENTE" << endl;
}

int buscarIdPersonal(int var, Personal obj){
    Archivo archivo;
    int pos = 0;
    while(archivo.leerDeDisco(pos,obj)){
        if(var == obj.getIDPersonal()){
            if(obj.getEstado()==true){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

///////////// DEFINICION DE BUSCAR CONTACTO

void buscarPersonal(){
    Cuadro cuadro;
    cuadro.setCoor({23,16});
    cuadro.setalto(8);
    cuadro.setlargo(55);
    cuadro.dibujar();
    Archivo archivo;
    Personal personal;
    int pos,id;
    gotoxy(31, 18);
    cout << "INGRESE EL NUMERO DE ID DEL PERSONAL: ";
    cin >> id;
    pos = buscarIdPersonal(id,personal);
    if(pos == -1){
        gotoxy(25, 21);
        cout << "NO EXISTE EL NUMERO DE ID DEL PERSONAL EN EL ARCHIVO" << endl;
        return;
    }
    archivo.leerDeDisco(pos,personal);
    gotoxy(38, 20);
    personal.mostrar();
    cout << endl;
}

///////////// DEFINICION DE ELIMINAR CONTACTO

void eliminarPersonal(){
    Cuadro cuadro;
    cuadro.setCoor({25,16});
    cuadro.setalto(6);
    cuadro.setlargo(50);
    cuadro.dibujar();
    Archivo archivo;
    Personal personal;
    int id, pos;
    gotoxy (32, 18);
    cout << "INGRESAR NUMERO DE ID A ELIMINAR: ";
    cin >> id;
    pos = buscarIdPersonal(id,personal);
    if(pos == -1){
        gotoxy (30, 20);
        cout << "NO EXISTE EL ID DEL PERSONAL EN EL ARCHIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,personal)==false){
        gotoxy (32, 20);
        cout << "ERROR AL BORRAR EL PERSONAL" << endl;
        return;
    }
    gotoxy (36, 20);
    cout << "REGISTO BORRADO EXISTOSAMENTE" << endl;
}

#endif // FUNCIONESPERSONA_H_INCLUDED
