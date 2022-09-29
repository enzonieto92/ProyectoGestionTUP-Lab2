#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Inicio.h"
#include "Funciones.h"
#include "Turnos.h"
#include "Clientes.h"
#include "Contactos.h"
using namespace std;



int main()
{
rlutil::setColor(12);
Inicio Inicio;
Turnos Turnos;
Clientes Clientes;
Contactos Contactos;

int opc = 1;
do{
opc = Inicio.Menu();

switch (opc){
case 1:
    Turnos.Menu();
    break;
case 2:
    Clientes.Menu();
    break;
case 3:
    Contactos.Menu();
    break;
    }
}
while (opc != 4);

return 0;
}
