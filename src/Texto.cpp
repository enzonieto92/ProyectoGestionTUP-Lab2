#include "Texto.h"
#include <iostream>

using namespace std;

Texto::Texto(Origen &_coor){
    coor = _coor;
    opc = 1;
}

void Texto::mostrar_texto1(){
    gotoxy(coor.getX()-4, coor.getY()-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.getX()+5, coor.getY()+1);
    cout <<"TURNOS";
    gotoxy(coor.getX()+4, coor.getY()+3);
    cout <<"CLIENTES";
    gotoxy(coor.getX()+4, coor.getY()+5);
    cout <<"PERSONAL";
    gotoxy(coor.getX()+4, coor.getY()+7);
    cout <<"SERVICIO";
    gotoxy(coor.getX()+5, coor.getY()+9);
    cout <<"CUENTA";
    gotoxy(coor.getX()+5, coor.getY()+11);
    cout <<"SALIR";
}

void Texto::mostrar_texto2(){
    gotoxy(coor.getX()-4, coor.getY()-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.getX()+2, coor.getY()-5);
    cout << "MENU TURNOS";
    gotoxy(coor.getX()-2, coor.getY()+1);
    cout <<"AGREGAR";
    gotoxy(coor.getX()+10, coor.getY()+1);
    cout <<"MODIFICAR";
    gotoxy(coor.getX()-1, coor.getY()+3);
    cout <<"BUSCAR";
    gotoxy(coor.getX()+11, coor.getY()+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto3(){
    gotoxy(coor.getX()-4, coor.getY()-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.getX()+2, coor.getY()-5);
    cout << "MENU CLIENTES";
    gotoxy(coor.getX()-7, coor.getY()+1);
    cout <<"AGREGAR";
    gotoxy(coor.getX()+5, coor.getY()+1);
    cout <<"MODIFICAR";
    gotoxy(coor.getX()+18, coor.getY()+1);
    cout <<"MOSTRAR";
    gotoxy(coor.getX()-7, coor.getY()+3);
    cout <<"ELIMINAR";
    gotoxy(coor.getX()+6, coor.getY()+3);
    cout <<"BUSCAR";
    gotoxy(coor.getX()+18, coor.getY()+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto4(){
    gotoxy(coor.getX()-4, coor.getY()-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.getX()+2, coor.getY()-5);
    cout << "MENU PERSONAL";
    gotoxy(coor.getX()-7, coor.getY()+1);
    cout <<"AGREGAR";
    gotoxy(coor.getX()+5, coor.getY()+1);
    cout <<"MODIFICAR";
    gotoxy(coor.getX()+18, coor.getY()+1);
    cout <<"MOSTRAR";
    gotoxy(coor.getX()-7, coor.getY()+3);
    cout <<"ELIMINAR";
    gotoxy(coor.getX()+6, coor.getY()+3);
    cout <<"BUSCAR";
    gotoxy(coor.getX()+18, coor.getY()+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto5(){
    gotoxy(coor.getX()-4, coor.getY()-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.getX()+2, coor.getY()-5);
    cout << "MENU SERVICIOS";
    gotoxy(coor.getX()-7, coor.getY()+1);
    cout <<"AGREGAR";
    gotoxy(coor.getX()+5, coor.getY()+1);
    cout <<"MODIFICAR";
    gotoxy(coor.getX()+18, coor.getY()+1);
    cout <<"MOSTRAR";
    gotoxy(coor.getX()-7, coor.getY()+3);
    cout <<"ELIMINAR";
    gotoxy(coor.getX()+6, coor.getY()+3);
    cout <<"BUSCAR";
    gotoxy(coor.getX()+18, coor.getY()+3);
    cout <<"VOLVER";
}

void Texto::mostrar_texto6(){
    gotoxy(coor.getX()-4, coor.getY()-7);
    cout <<"Peluqueria Erica Martinez";
    gotoxy(coor.getX()+2, coor.getY()-5);
    cout << "MENU CUENTAS";
    gotoxy(coor.getX()-2, coor.getY()+1);
    cout <<"MODIFICAR";
    gotoxy(coor.getX()+11, coor.getY()+1);
    cout <<"MOSTRAR";
    gotoxy(coor.getX()-1, coor.getY()+3);
    cout <<"BUSCAR";
    gotoxy(coor.getX()+11, coor.getY()+3);
    cout <<"VOLVER";
}

void Texto::resaltar1(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.getX()+5, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"TURNOS";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.getX()+4, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"CLIENTES";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.getX()+4, coor.getY()+5);
            rlutil::setBackgroundColor(7);
            cout <<"PERSONAL";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.getX()+4, coor.getY()+7);
            rlutil::setBackgroundColor(7);
            cout <<"SERVICIO";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.getX()+5, coor.getY()+9);
            rlutil::setBackgroundColor(7);
            cout <<"CUENTA";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.getX()+5, coor.getY()+11);
            rlutil::setBackgroundColor(7);
            cout <<"SALIR";
            rlutil::setBackgroundColor(0);
            break;
    }
}

void Texto::resaltar2(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.getX()-2, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.getX()+10, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.getX()-1, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.getX()+11, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}

void Texto::resaltar3(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.getX()-7, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.getX()+5, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.getX()+18, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.getX()-7, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"ELIMINAR";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.getX()+6, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.getX()+18, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
void Texto::resaltar4(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.getX()-7, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.getX()+5, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.getX()+18, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.getX()-7, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"ELIMINAR";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.getX()+6, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.getX()+18, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
void Texto::resaltar5(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.getX()-7, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"AGREGAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.getX()+5, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.getX()+18, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.getX()-7, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"ELIMINAR";
            rlutil::setBackgroundColor(0);
            break;
        case 5:
            gotoxy(coor.getX()+6, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 6:
            gotoxy(coor.getX()+18, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
void Texto::resaltar6(int opc){
    switch(opc){
        case 1:
            gotoxy(coor.getX()-2, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MODIFICAR";
            rlutil::setBackgroundColor(0);
            break;
        case 2:
            gotoxy(coor.getX()+11, coor.getY()+1);
            rlutil::setBackgroundColor(7);
            cout <<"MOSTRAR";
            rlutil::setBackgroundColor(0);
            break;
        case 3:
            gotoxy(coor.getX()-1, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"BUSCAR";
            rlutil::setBackgroundColor(0);
            break;
        case 4:
            gotoxy(coor.getX()+11, coor.getY()+3);
            rlutil::setBackgroundColor(7);
            cout <<"VOLVER";
            rlutil::setBackgroundColor(0);
            break;
    }
}
