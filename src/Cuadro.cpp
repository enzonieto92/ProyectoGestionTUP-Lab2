#include "Cuadro.h"
#include <iostream>
using namespace std;
Cuadro::Cuadro(origen _coor, int _largo, int _alto, int &_opc): _txt(_coor){
    coor = _coor;
    largo = _largo;
    alto = _alto;
    opc = _opc;

}



void Cuadro::linea_hor (){
for (int i = 0; i< largo-1; i++){

cout << char(205);

}
}
void Cuadro::linea_ver (){
for (int z = 0; z < 2; z++){
for (int i = 0; i < (alto-1); i++){
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

gotoxy (coor.x, coor.y+alto+1);

linea_ver();
esquina_inf();

}
void Cuadro::mostrar_texto1(){
_txt.mostrar_texto1();
}
void Cuadro::mostrar_texto2(){
_txt.mostrar_texto2();
}
void Cuadro::mostrar_texto3(){
_txt.mostrar_texto3();
}
void Cuadro::mostrar_texto4(){
_txt.mostrar_texto4();
}
void Cuadro::Resaltar1(){
_txt.resaltar1(opc);
}
void Cuadro::Resaltar2(){
_txt.resaltar2(opc);
}

void Cuadro::setOpc(int &_opc){
opc = _opc;
}
