#include "Contactos.h"
#include "Archivo.h"
#include <iostream>
#include <cstdio>
using namespace std;
Contactos::Contactos()
{
strcpy(Nombre, "");
strcpy(Telefono, "");
coor = {30, 10};
opc = 1;
}


void Contactos::Cargar()
{
    gotoxy (40, 30);
    cout <<"Nombre: ";
    cin.getline(Nombre, 30);
    gotoxy (40, 32);
    cout <<"Telefono: ";
    cin.getline(Telefono, 30);


}
void Contactos::Mostrar(int i)
{
    gotoxy(33, i+17);
    cout <<Nombre<<": "<<Telefono;

}

