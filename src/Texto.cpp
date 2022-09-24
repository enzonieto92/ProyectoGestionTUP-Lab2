#include "Texto.h"
#include <iostream>
using namespace std;


Texto::Texto(origen _coor)
{
    coor = _coor;

}
void Texto::mostrar_texto1(){
    gotoxy(coor.x-4, coor.y-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.x+5, coor.y+1);
    cout <<"TURNOS";
    gotoxy(coor.x+4, coor.y+3);
    cout <<"CLIENTES";
    gotoxy(coor.x+5, coor.y+5);
    cout <<"SALIR";
}


void Texto::resaltar(int &opc){
    switch(opc){
        case 1:
            gotoxy(coor.x+5, coor.y+1);
            rlutil::setBackgroundColor(7);
            cout <<"TURNOS";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.x+4, coor.y+3);
            rlutil::setBackgroundColor(7);
            cout <<"CONTACTOS";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.x+5, coor.y+5);
            rlutil::setBackgroundColor(7);
            cout <<"SALIR";
            rlutil::setBackgroundColor(0);
            break;
    }
}
