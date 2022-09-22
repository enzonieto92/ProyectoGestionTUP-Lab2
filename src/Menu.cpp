#include "Menu.h"
#include <iostream>

using  namespace std;
Menu::Menu()
{
    coor = {};
    opc = 1;
}


void Menu::Principal()
{
    rlutil::hidecursor();
    coor  = {40,10};
    while (opc != 0){
        system("cls");
        Cuadro menu1{coor, 15, 6, opc};
        menu1.dibujar();
        menu1.mostrar_texto1();
        menu1.Resaltar1();
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
                        cout <<"estás en el menu turnos";
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
