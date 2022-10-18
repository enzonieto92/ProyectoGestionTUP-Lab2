#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Funciones.h"
#include "Fecha.h"
#include "Cliente.h"
#include "Turno.h"
#include "Contactos.h"
#include "Menu.h"
using namespace std;



int main()
{
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

    break;
    }
}
while (opc != 4);
cout <<endl;
return 0;
}
