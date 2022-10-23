#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <ctime>

using namespace std;

#include "Funciones.h"
#include "Fecha.h"
#include "Persona.h"
#include "Cliente.h"
#include "Turno.h"
#include "Cuentas.h"
#include "Menu.h"

int main(){
    rlutil::setColor(12);
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
                Menu.Persona();
            break;
            case 4:
                Menu.Servicio();
            break;
            case 5:
                Menu.Cuentas();
            break;
        }
    }
    while (opc != 6);
    cout <<endl;
    return 0;
}
