#include "Inicio.h"

Inicio::Inicio() :Cuadro({42,10}, 15, 8, opc)
{
    opc = 1;
}

int Inicio::Menu()
{

            while (opc != 0){
                system("cls");
                rlutil::hidecursor();
                Cuadro.setOpc(opc);
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
