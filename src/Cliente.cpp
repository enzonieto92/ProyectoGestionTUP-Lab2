#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente()
{
    strcpy(nombre, " ");
    strcpy(apellido, " ");
    strcpy(telefono, " ");
    idCuenta = 0;
    estado = false;
}

void Cliente::limpiarEspacios(int x, int y){
for (int i = x+10; i < x+25; i++){
    for (int j = y; j < 3+y; j++){
        gotoxy(i, j);
        cout <<" ";
    }
}
    gotoxy(x-4, y+4);
    cout <<"                             ";
}
bool Cliente::Cargar(int x, int y){



    limpiarEspacios(x, y);
    gotoxy(x+2, y);
    cout << "NOMBRE: ";
    gotoxy(x, y+1);
    cout << "APELLIDO: ";
    gotoxy(x, y+2);
    cout << "TELEFONO: ";
    gotoxy(x+10, y);
    rlutil::showcursor();
   if(cargarCadena(nombre, 30)){

       if (validarCadena(nombre)){
        setNombre(nombre);
       }
       else {
        gotoxy(x-2, y+4);
        cout <<"Ingrese un nombre valido!";
        getch();
        Cargar(x, y);
       }
    }
    else{
        return false;
    }

    gotoxy(x+10, y+1);

    if(cargarCadena(apellido, 30)){
        if (validarCadena(apellido)){
        setApellido(apellido);
        }
       else {
        gotoxy(x-2, y+4);
        cout <<"Ingrese un apellido valido!";
        getch();
        Cargar(x, y);
       };
    }
    else{
        return false;
    };
    gotoxy(x+10, y+2);

    if (cargarCadena(telefono, 40)){

        if (isdigit(*telefono)){
        setTelefono(telefono);
        }
        else{
            gotoxy(x-2, y+4);
            cout <<"Ingrese un telefono valido!";
            getch();
            Cargar(x, y);
        }
    }
    else{
        return false;
    }
    rlutil::hidecursor();

    return true;

}
void Cliente::Mostrar(int x,int y)
{

        gotoxy(x, y+1);
        cout << "                         " ;
        gotoxy(x, y+2);
        cout << "                          " ;
        gotoxy(x, y+3);
        cout << "                           " ;

        gotoxy(x, y+1);
        cout << "  NOMBRE: " << nombre;
        gotoxy(x, y+2);
        cout << "APELLIDO: " << apellido;
        gotoxy(x, y+3);
        cout << "TELEFONO: " << telefono;

}

/// SETS

void Cliente::setNombre(const char *nom){strcpy(nombre, nom);}
void Cliente::setApellido(const char *ape){strcpy(apellido, ape);}
void Cliente::setTelefono(const char *tel){strcpy(telefono, tel);}
void Cliente::setIdCuenta(int idC){idCuenta = idC;}
void Cliente::setEstado(bool e){estado = e;}

/// GETS
const char *Cliente::getNombre(){return nombre;}
const char *Cliente::getApellido(){return apellido;}
const char *Cliente::getTelefono(){return telefono;}
int Cliente::getIdCuenta(){return idCuenta;}
bool Cliente::getEstado(){return estado;}

void Cliente::operator = (Cliente aux){
setApellido(aux.getApellido());
setNombre(aux.getNombre());
setTelefono(aux.getTelefono());
setEstado(aux.getEstado());
}
bool Cliente::operator ==(Cliente aux){
    if(strcmp(apellido, aux.getApellido()) == 0
       && strcmp(nombre, aux.getNombre()) == 0
       && strcmp(telefono, aux.getTelefono()) == 0){
        return true;
    }
    else{
        return false;
    }
}
/// DESTRUCTOR
Cliente::~Cliente()
{
    //dtor
}
