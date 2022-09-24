#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Menu.h"
#include "funciones.h"
using namespace std;

const char *TURNOS = "Turnos.dat";
const char *CLIENTES = "Clientes.dat";

#include "funcionesGlobales.h"
#include "clsFecha.h"
#include "clsTurno.h"
#include "clsCliente.h"
#include "funcionesGlobalesTurno.h"
#include "funcionesGlobalesCliente.h"
#include "opcionesGlobalesMenu.h"

int main()
{
rlutil::setColor(12);
Menu Menu;
int opc = Menu.Principal();
switch (opc){
case 1:
    menuTurnos();
    ///Menu.Turnos();
    break;
case 2:
    menuClientes();
    ///Menu.Contactos();
    break;
}

    return 0;
}
