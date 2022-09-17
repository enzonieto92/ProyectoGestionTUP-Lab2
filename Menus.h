#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "Cuadro.h"




void menu_turnos(){
int opc = 1;

origen coor {10,10};
origen coor2{51, 10};
while (opc!=0){

Cuadro menu1{coor, 40, 30};
Cuadro menu2{coor2, 40, 30};
menu1.dibujar();
menu2.dibujar();
if(rlutil::getkey() == 1){
    opc = 0;
}

}
}

void menu_principal(){
rlutil::hidecursor();
int opc = 1;
origen coor {40,10};

while (opc != 0){
system("cls");
Cuadro menu1{coor, 15, 6};
menu1.dibujar();
menu1.mostrar_texto();
menu1.resaltar(opc);
switch (rlutil::getkey()){
case 14:
    if (opc == 1){
        opc = 3;
    }
    else{
        opc --;
    }
    break;
case 15:
    if (opc == 3){
        opc = 1;
    }
    else{
        opc ++;
    }
    break;
case 1:
    switch(opc){
case 1:
    system("cls");
    menu_turnos();
    getch();
    break;
case 2:
    system("cls");
    cout <<"estas en menu 2";
    getch();
    break;
case 3:
    opc = 0;
    }
}
}

}


#endif // MENUS_H_INCLUDED
