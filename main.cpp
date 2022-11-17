#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <ctime>

using namespace std;

#include "Funciones.h"
#include "Fecha.h"
#include "Cliente.h"
#include "Turno.h"
#include "Menu.h"
#include "Origen.h"

int main(){
    setlocale(LC_ALL, "en_ES.utf8");
    AjustarVentana(100, 60);
    rlutil::setColor(3);
    Menu Menu;
    int opc = 1;
    do{
        opc = Menu.principal();
        switch (opc){
            case 1:
                Menu.Turnos();
            break;
            case 2:
                Menu.Clientes();
            break;
            case 3:
                Menu.Servicio();
            break;
            case 4:
                gotoxy(1, 40);
                return 0;
            break;
        }
    }
    while (opc != 6);
    cout <<endl;
    return 0;
}
