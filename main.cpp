#include <iostream>
#include "Menu.h"
#include "funciones.h"
using namespace std;


int main()
{
rlutil::setColor(12);
Menu Menu;
int opc = Menu.Principal();
switch (opc){
case 1:
    Menu.Turnos();
    break;
case 2:
    Menu.Contactos();
    break;
}

    return 0;
}
