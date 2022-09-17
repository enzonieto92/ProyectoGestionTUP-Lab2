#include "Cuadro.h"
#include <iostream>
#include "funciones.h"
using namespace std;
Cuadro::Cuadro(origen _coor, int _largo, int _alto){
    coor = _coor;
    largo = _largo;
    alto = _alto;
}



void Cuadro::linea_hor (){
for (int i = 0; i< largo-1; i++){

cout << char(205);

}
}

void Cuadro::linea_ver (){
for (int z = 0; z < 2; z++){
for (int i = 0; i < alto; i++){
    gotoxy (coor.x+(z*largo), 1+coor.y+i);
    cout <<char(186);

}
}
}
void Cuadro::esquina_inf(){
gotoxy(coor.x, coor.y+alto);
cout <<char(200);
linea_hor();
cout <<char(188);
}
void Cuadro::esquina_sup (){
cout <<char(201);
linea_hor();
cout <<char(187);
}
void Cuadro::div (){
cout <<char(204);
linea_hor();
cout <<char(185);
}

void Cuadro::dibujar(){


gotoxy(coor.x, coor.y);
esquina_sup();
gotoxy(coor.x, coor.y+2);

gotoxy (coor.x, coor.y+alto+1);

linea_ver();
esquina_inf();

}
void Cuadro::mostrar_texto(){
gotoxy(coor.x-4, coor.y -5);
cout <<"Peluquería Erica Martinez";
gotoxy(coor.x+5, coor.y+1);
cout <<"TURNOS";
gotoxy(coor.x+4, coor.y+3);
cout <<"CONTACTOS";
gotoxy(coor.x+5, coor.y+5);
cout <<"SALIR";
}

void Cuadro::resaltar(int &opc){
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
