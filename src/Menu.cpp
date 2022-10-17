#include "Menu.h"
Menu::Menu() :Cuadro({42,10}, 15, 8, opc)
{
    opc = 1;
}
void Menu::setCuadro(origen coor, int largo, int alto, int opc){
Cuadro.setCoor(coor);
Cuadro.setlargo(largo);
Cuadro.setalto(alto);
Cuadro.setOpc(opc);
}
void Menu::setLista(origen coor, int largo, int alto){
    Lista.setCoor(coor);
    Lista.setlargo(largo);
    Lista.setalto(alto);
}
int Menu::principal()
{
            while (opc != 0){
                system("cls");
                setCuadro({42,10}, 15, 8, opc);
                rlutil::hidecursor();
                Cuadro.dibujar();
                Cuadro.mostrar_texto1();
                Cuadro.Resaltar1();
                    switch (rlutil::getkey()){
                    case 14:
                        if (opc == 1){
                            opc = 4;
                        }
                        else{
                            opc --;
                        }
                        break;
                    case 15:
                        if (opc == 4){
                            opc = 1;
                        }
                        else{
                            opc ++;
                        }
                        break;
                    case 1:
                        return opc;
                        break;
                    default:
                        rlutil::nb_getch();
                       break;
                    }
            }
return opc;
}

void Menu::Turnos()
{
            rlutil::hidecursor();
            while (opc != 0)
            {
                system("cls");
                setCuadro({30, 10}, 40, 4, opc);
                setLista({20, 16}, 60, 40);
                Cuadro.dibujar();
                Cuadro.mostrar_texto2();
                Cuadro.Resaltar2();
                Lista.dibujarLista();

                        switch (rlutil::getkey()){
                            case 14:
                                    if (opc < 4){
                                        opc += 3;
                                    }
                                    else{

                                    opc -=3;
                                    }
                                    break;
                            case 15:
                                    if (opc > 3){
                                        opc -= 3;
                                    }
                                    else{

                                    opc +=3;
                                    }
                                    break;
                            case 16:
                                    if (opc == 1 || opc == 4){
                                        opc += 2;
                                    }
                                    else{
                                    opc --;
                                    }
                                    break;
                            case 17:
                                    if (opc == 3 || opc == 6){
                                        opc -= 2;
                                    }
                                    else{
                                    opc ++;
                                    }
                                    break;

                            case 1:
                                ///ACA VAN LAS OPCIONES SEGUN DONDE SE PRESIONE ENTER

                                switch (opc){
                                ///AGREGAR///
                            case 1:
                                ///MODIFICAR///
                            case 2:
                                ///MOSTRAR///
                            case 3:
                                ///ELIMINAR///
                            case 4:
                                ///BUSCAR///
                            case 5:
                                ///VOLVER///
                            case 6:
                                opc = 1;
                                return;
                                }
                            break;
                            case 0:
                                break;

                                        }
                        }
}

void Menu::Clientes()
{
            rlutil::hidecursor();
            while (opc != 0)
            {
                system("cls");
                setCuadro({30, 10}, 40, 4, opc);
                Cuadro.dibujar();
                Cuadro.mostrar_texto2();
                Cuadro.Resaltar2();

                        switch (rlutil::getkey()){
                            case 14:
                                    if (opc < 4){
                                        opc += 3;
                                    }
                                    else{

                                    opc -=3;
                                    }
                                    break;
                            case 15:
                                    if (opc > 3){
                                        opc -= 3;
                                    }
                                    else{

                                    opc +=3;
                                    }
                                    break;
                            case 16:
                                    if (opc == 1 || opc == 4){
                                        opc += 2;
                                    }
                                    else{
                                    opc --;
                                    }
                                    break;
                            case 17:
                                    if (opc == 3 || opc == 6){
                                        opc -= 2;
                                    }
                                    else{
                                    opc ++;
                                    }
                                    break;

                            case 1:
                                ///ACA VAN LAS OPCIONES SEGUN DONDE SE PRESIONE ENTER

                                switch (opc){
                                ///AGREGAR///
                            case 1:
                                ///MODIFICAR///
                            case 2:
                                ///MOSTRAR///
                            case 3:
                                ///ELIMINAR///
                            case 4:
                                ///BUSCAR///
                            case 5:
                                ///VOLVER///
                            case 6:
                                opc = 1;
                                return;
                                }
                            break;

                            case 0:
                                return;
                                system("pause");

                                        }
                        }

}
