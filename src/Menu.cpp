#include "Menu.h"

#include "../controller/funcionesServicios.h"
#include "../controller/funcionesClientes.h"
#include "../controller/funcionesTurnos.h"

Menu::Menu(){
    opc = 1;
    _cuadro= {{42,10}, 15, 8, opc};
}

void Menu::setOpcion(int opcion){
opc = opcion;
_cuadro.setOpc(opcion);
}
void Menu::setCuadro(Origen coor, int largo, int alto, int opc){
    _cuadro.setCoor(coor);
    _cuadro.setlargo(largo);
    _cuadro.setalto(alto);
    _cuadro.setOpc(opc);
}

void Menu::setLista(Origen coor, int largo, int alto){
    _lista.setCoor(coor);
    _lista.setlargo(largo);
    _lista.setalto(alto);
}

int Menu::principal(){
    system("cls");
    while (opc != 0){
        setCuadro({42,20}, 15, 8, opc);
        rlutil::hidecursor();
        _cuadro.dibujar();
        _cuadro.mostrar_texto1();
        _cuadro.Resaltar1();
        switch (rlutil::getkey()){
            case 14:
                if (opc == 1){
                    opc = 6;
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

void Menu::Turnos(){
    rlutil::hidecursor();
    Fecha Lista;
    system("cls");
    while (opc != 0){
        setLista({19, 16}, 61, 40);
        setCuadro({30, 10}, 40, 4, opc);
        _lista.dibujarLista();
        _cuadro.dibujar();
        _cuadro.mostrar_texto2();
        _cuadro.Resaltar2();
        Lista.Mostrar(47, 15);
        TurnosDelDia(Lista);
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
                switch (opc){
                    case 1:
                        ///AGREGAR///
                        agregarRegistroTurno();
                        break;
                    case 2:
                        ///MODIFICAR///
                        ModificarTurno(Lista);
                        break;
                    case 3:
                        ///MOSTRAR///
                        //mostrarRegistroTurno();
                        break;
                    case 4:
                        ///ELIMINAR///
                        eliminarRegitroTurno(Lista);
                        break;
                    case 5:
                        ///BUSCAR///
                        cambiarFecha(&Lista);
                        break;
                    case 6:
                        ///VOLVER///
                        opc = 1;
                        return;
                        break;
                }
            system("cls");
            break;
        }
    }
}

void Menu::Clientes(){
    rlutil::hidecursor();
    setCuadro({30, 10}, 40, 4, opc);
    system("cls");
    int posVector = 0;
    CargarClientesTurnos();
    while (opc != 0){
        setOpcion(opc);
        _cuadro.dibujar();
        _cuadro.mostrar_texto3();
        _cuadro.Resaltar3();
        mostrarClientes(posVector);
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
                            if(agregarRegistroCliente()){
                            gotoxy(42, 25);
                            cout << "CLIENTE CARGADO";
                            getch();
                            //agregarCuentaCliente(usuario);
                            rlutil::setColor(3);
                            }
                            break;
                        ///MODIFICAR///
                    case 2:
                            modificarCliente();

                        break;
                        ///MOSTRAR///
                    case 3:
                        recorrerVector(posVector);

                        break;

                        ///ELIMINAR///
                    case 4:
                            eliminarRegitroCliente(posVector);
                        break;
                        ///BUSCAR//
                    case 5:
                        break;
                    case 6:
                            opc = 1;
                            return;
                        break;
                }
            system("cls");
        }
    }
}

void Menu::Servicio(){
    rlutil::hidecursor();
    system("cls");
    while (opc != 0){
        setCuadro({36, 10}, 28, 4, opc);
        mostrarServicios();
        _cuadro.dibujar();
        _cuadro.mostrar_texto5();
        _cuadro.Resaltar5();
 switch (rlutil::getkey()){
            case 14:
                    if (opc < 3){
                        opc += 2;
                    }
                    else{

                    opc -=2;
                    }
                    break;
            case 15:
                    if (opc > 2){
                        opc -= 2;
                    }
                    else{

                    opc +=2;
                    }
                    break;
            case 16:
                    if (opc == 1 || opc == 3){
                        opc += 1;
                    }
                    else{
                    opc --;
                    }
                    break;
            case 17:
                    if (opc == 2 || opc == 4){
                        opc -= 1;
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
                        agregarRegistroServicio();
                        break;
                        ///MODIFICAR///
                    case 2:
                        modificarServicio();
                        break;
                        ///ELIMIINAR///
                    case 3:
                        eliminarServicio();
                        break;
                        ///VOLVER///
                    case 4:
                            opc = 1;
                            return;
                        break;

                }
                system("cls");
        }
    }
}
