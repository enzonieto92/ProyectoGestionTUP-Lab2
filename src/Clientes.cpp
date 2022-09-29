#include "Clientes.h"
#include <iostream>

using namespace std;
Clientes::Clientes()
{
coor = {30, 10};
opc = 1;
}

void Clientes::Menu()
{
            rlutil::hidecursor();
            while (opc != 0)
            {
                system("cls");
                Cuadro Cuadro_t(coor, 40, 4, opc);
                Cuadro_t.dibujar();
                Cuadro_t.mostrar_texto3();
                Cuadro_t.Resaltar2();

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
                                return;
                                }
                            break;

                            case 0:
                                return;
                                system("pause");

                                        }
                        }

}
