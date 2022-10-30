#ifndef FUNCIONESPERSONA_H_INCLUDED
#define FUNCIONESPERSONA_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES

void agregarRegistroPersona();

void mostrarPersona();

void modificarPersona();
    int buscarIdPersona(int, Personal);
    Personal leerRegistroPersona(int, Personal);

void buscarPersona();

void eliminarContacto();

///////////// DEFINICION DE AGREGAR REGISTRO PERSONA

void agregarRegistroPersona(){
    int var;
    Archivo archivo;
    Personal persona;
    var = archivo.contarRegistro(persona);
    if(var == -1){
        gotoxy (41, 24);
        cout << "FALLO AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    var += 1;
    persona.cargar(var);
    if(archivo.grabarEnDisco(persona)==false){
        gotoxy (41, 24);
        cout << "FALLO AL GUARDAR EL REGISTRO" << endl;
        return;
    }
    gotoxy (42, 24);
    cout << "REGISTRO GUARDADO" << endl;
}

///////////// DEFINICION DE MOSTRAR CONTACTO

void mostrarPersona(){
    Archivo archivo;
    Personal persona;
    int pos = 0;
    if(archivo.contarRegistro(persona)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS" << endl;
        return;
    }
    while(archivo.leerDeDisco(pos, persona)){
        gotoxy(38, pos+16);
        persona.mostrar();
        cout << endl;
        pos++;
    }
}

///////////// DEFINICION DE MODIFICAR CONTACTO

void modificarPersona(){
    Archivo archivo;
    Personal persona;
    int id, pos;
    char var[40];
    gotoxy (32, 18);
    cout << "INGRESAR NUMERO DE ID A MODIFICAR: ";
    cin >> id;
    pos = buscarIdPersona(id,persona);
    if(pos == -1){
        gotoxy (30, 20);
        cout << "NO EXISTE EL ID DEL PERSONAL EN EL ARCHIVO" << endl;
        return;
    }
    persona = leerRegistroPersona(pos,persona);
    gotoxy (30, 20);
    cout << "INGRESAR NUEVO NUMERO DE TELEFONO: " << endl;
    gotoxy(65, 20);
    cargarCadena(var,39);
    persona.setTelefono(var);
    if(archivo.modificarEnDisco(pos,persona)==false){
        cout << "ERROR AL MODIFICAR EL PERSONAL" << endl;
        return;
    }
    gotoxy (34, 22);
    cout << "REGISTO MODIFICADO EXISTOSAMENTE" << endl;
}

int buscarIdPersona(int var, Personal obj){
    Archivo archivo;
    int pos = 0;
    while(archivo.leerDeDisco(pos,obj)){
        if(var == obj.getIDPersona()){
            if(obj.getEstado()==true){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Personal leerRegistroPersona(int pos,Personal obj){
    FILE *pPersona;
    pPersona = fopen("Contactos.dat","rb");
    if(pPersona == NULL){
        return obj;
    }
    fseek(pPersona, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, pPersona);
    fclose(pPersona);
    return obj;
}

///////////// DEFINICION DE BUSCAR CONTACTO

void buscarPersona(){
    Archivo archivo;
    Personal persona;
    int pos,id;
    gotoxy(31, 18);
    cout << "INGRESE EL NUMERO DE ID DEL PERSONAL: ";
    cin >> id;
    pos = buscarIdPersona(id,persona);
    if(pos == -1){
        gotoxy(25, 21);
        cout << "NO EXISTE EL NUMERO DE ID DEL PERSONAL EN EL ARCHIVO" << endl;
        return;
    }
    persona = leerRegistroPersona(pos,persona);
    gotoxy(38, 20);
    persona.mostrar();
    cout << endl;
}

///////////// DEFINICION DE ELIMINAR CONTACTO

void eliminarPersona(){
    Archivo archivo;
    Personal persona;
    int id, pos;
    gotoxy (32, 18);
    cout << "INGRESAR NUMERO DE ID A ELIMINAR: ";
    cin >> id;
    pos = buscarIdPersona(id,persona);
    if(pos == -1){
        gotoxy (30, 20);
        cout << "NO EXISTE EL ID DEL PERSONAL EN EL ARCHIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,persona)==false){
        gotoxy (32, 20);
        cout << "ERROR AL BORRAR EL PERSONAL" << endl;
        return;
    }
    gotoxy (36, 20);
    cout << "REGISTO BORRADO EXISTOSAMENTE" << endl;
}

#endif // FUNCIONESPERSONA_H_INCLUDED
