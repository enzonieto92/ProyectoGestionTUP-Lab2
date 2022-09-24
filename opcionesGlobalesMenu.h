#ifndef OPCIONESGLOBALESMENU_H_INCLUDED
#define OPCIONESGLOBALESMENU_H_INCLUDED

/// DECLARACION OPCIONES GLOBALES MENU

void menuTurnos();

/// DEFINICION OPCIONES GLOBALES MENU

// MENU TURNOS
void menuTurnos(){
    int opc, valorAgregarTurno;
    while(true){
        system("cls");
        cout << "MENU TURNOS" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) AGREGAR TURNO" << endl;
        cout << "2) LISTAR TURNO POR DNI" << endl;
        cout << "3) LISTAR TODAS LOS TURNOS" << endl;
        cout << "4) MODIFICAR FECHA SERVICIO DE TURNO" << endl;
        cout << "5) ELIMINAR TURNO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarTurno = agregarRegistroTurno();
                    if(valorAgregarTurno == -2){
                        cout << "FALLO GRABAR EN DISCO " << endl;
                        return;
                    }
                    else{
                        if(valorAgregarTurno == -1){
                            cout << "ERROR DATOS INVALIDOS INGRESADOS O FALLO APERTURA DE ARCHIVO" << endl;
                            return;
                        }
                    }
                    cout << "REGISTRO CARGADO" << endl;
                break;
            case 2: if(mostrarTurnoPorId() == false){
                        cout << "ERROR EN LA BUSQUEDA DE REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO LISTADO" << endl;
                    }
                break;
            case 3: mostrarTurno();
                break;
            case 4: if(modificarFechaServicioTurno() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "REGISTRO MODIFICADO" << endl;
                    }
                break;
            case 5: if(eliminarLogicoTurno() == false){
                        cout << "ERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO BORRADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

// MENU CLIENTES
void menuClientes(){
    int opc, valorAgregarCliente;
    while(true){
        system("cls");
        cout << "MENU CLIENTES" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) AGREGAR CLIENTE" << endl;
        cout << "2) LISTAR CLIENTE POR DNI" << endl;
        cout << "3) LISTAR TODOS LOS CLIENTES" << endl;
        cout << "4) MODIFICAR FECHA DE NACIMIENTO DE CLIENTE" << endl;
        //cout << "5) ELIMINAR TURNO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarCliente = agregarRegistroCliente();
                    if(valorAgregarCliente == -2){
                        cout << "FALLO GRABAR EN DISCO " << endl;
                        return;
                    }
                    else{
                        if(valorAgregarCliente == -1){
                            cout << "ERROR DATOS INVALIDOS INGRESADOS O FALLO APERTURA DE ARCHIVO" << endl;
                            return;
                        }
                    }
                    cout << "REGISTRO CARGADO" << endl;
                break;
            case 2: if(mostrarClientePorDNI() == false){
                        cout << "ERROR EN LA BUSQUEDA DE REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO LISTADO" << endl;
                    }
                break;
            case 3: mostrarCliente();
                break;
            case 4: if(modificarFechaNacimientoCliente() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "REGISTRO MODIFICADO" << endl;
                    }
                break;
            /*case 5: if(eliminarLogicoCliente() == false){
                        cout << "ERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO BORRADO" << endl;
                    }
                break;*/
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

#endif // OPCIONESGLOBALESMENU_H_INCLUDED
