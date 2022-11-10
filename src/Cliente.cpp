#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente()
{
    DNI = 0;
    strcpy(nombre, " ");
    strcpy(apellido, " ");
    strcpy(telefono, " ");
    strcpy(email, " ");
    idCuenta = 0;
    estado = false;
}

void Cliente::limpiarEspacios(){
for (int i = 52; i < 62; i++){
    for (int j = 24; j < 27; j++){
        gotoxy(i, j);
        cout <<" ";
    }
}
    gotoxy(40, 28);
    cout <<"                           ";
}
void Cliente::Cargar(){



    limpiarEspacios();
    gotoxy(44, 24);
    cout << "NOMBRE: ";
    gotoxy(42, 25);
    cout << "APELLIDO: ";
    gotoxy(42, 26);
    cout << "TELEFONO: ";
    gotoxy(52, 24);
    rlutil::showcursor();
    cargarCadena(nombre, 29);
       if (validarCadena(nombre)){
        setNombre(nombre);
       }
       else {
        gotoxy(40, 28);
        cout <<"Ingrese un nombre valido!";
        getch();
        Cargar();
       }

    gotoxy(52, 25);
    cargarCadena(apellido, 29);
        if (validarCadena(apellido)){
        setApellido(apellido);
        }
       else {
        gotoxy(40, 28);
        cout <<"Ingrese un apellido valido!";
        getch();
        Cargar();
       }
    gotoxy(52, 26);
    cargarCadena(telefono, 39);
    setTelefono(telefono);
    rlutil::hidecursor();


}
void Cliente::Mostrar()
{
    if(estado){
        gotoxy(34, 20);
        cout << "DNI: " << DNI;
        gotoxy(34, 21);
        cout << "NOMBRE: " << nombre;
        gotoxy(34, 22);
        cout << "APELLIDO: " << apellido;
        gotoxy(34, 23);
        cout << "TELEFONO: " << telefono;
        gotoxy(34, 24);
        cout << "EMAIL: " << email;
        gotoxy(34, 25);
        cout << "ID CUENTA: " << idCuenta;
    }
}

/// SETS
bool Cliente::setDNI(int nD){
    if(nD > 0){
        DNI = nD;
        return true;
    }
    return false;
}
void Cliente::setNombre(const char *nom){strcpy(nombre, nom);}
void Cliente::setApellido(const char *ape){strcpy(apellido, ape);}
void Cliente::setTelefono(const char *tel){strcpy(telefono, tel);}
void Cliente::setEmail(const char *e){strcpy(email, e);}
void Cliente::setIdCuenta(int idC){idCuenta = idC;}
void Cliente::setEstado(bool e){estado = e;}

/// GETS
int Cliente::getDNI(){return DNI;}
const char *Cliente::getNombre(){return nombre;}
const char *Cliente::getApellido(){return apellido;}
const char *Cliente::getTelefono(){return telefono;}
const char *Cliente::getEmail(){return email;}
int Cliente::getIdCuenta(){return idCuenta;}
bool Cliente::getEstado(){return estado;}

void Cliente::operator = (Cliente aux){
setApellido(aux.getApellido());
setNombre(aux.getNombre());
setTelefono(aux.getTelefono());
setDNI(aux.getDNI());
setEmail(aux.getEmail());
setEstado(aux.getEstado());
}
bool Cliente::operator ==(Cliente aux){
    if(apellido == aux.getApellido()
       && nombre == aux.getNombre()
       && telefono == aux.getTelefono()
       && email == aux.getEmail()
       && DNI == aux.getDNI()
       && idCuenta == aux.getIdCuenta()){
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
