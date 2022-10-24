#ifndef FUNCIONESTURNOS_H_INCLUDED
#define FUNCIONESTURNOS_H_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;
//#include "Servicio.h"

/// PROTOTIPOS FUNCIONES GLOBALES TURNO

int agregarRegistroTurno();
    Turno cargarTurno();
        //bool validarCliente(int nD){
        bool validarTipoServicio(int tS);

bool modificarFechaServicioTurno();
    int buscarIdTurno(int idT);

bool mostrarTurnoPorId();

void mostrarTurnos(); // ESPERANDO SER USADA

void mostrarTunoDelDia();
    bool turnoHoy(Fecha f);

/// DEFINICIONES FUNCIONES GLOBALES TURNO

// 1 AGREGA REGISTROS TURNOS  AL ARCHIVO Turnos.dat
int agregarRegistroTurno(){
    Turno cita;
    Archivo archi;
    cita = cargarTurno();
    if(cita.getEstado() == false){ // ERROR EN FECHA O APERTURA DEL ARCHIVO
        return -1;
    }
    if(archi.grabarEnDisco(cita)){ // GRABO EN DISCO
        return 0;
    }
    return -2; // FALLO GRABAR EN DISCO
}

Turno cargarTurno(){
    Turno cita;
    int idT, nD, tS;
    Fecha _fecha;
    Archivo archi;
    cout << "DNI CLIENTE: ";
    cin >> nD;
    if(validarCliente(nD) == false){
        cout << "EL CLIENTE INGERSADO ES INVALIDO. NO ESTA REGISTRADO O FUE BORRADO" << endl;
        cita.setEstado(false);
        return cita;
    }
    cout << "TIPO SERVICIO: ";
    cin >> tS;
    if(validarTipoServicio(tS) == false){
        cout << "EL SERVICIO INGERSADO ES INVALIDO. NO ESTA REGISTRADO O FUE BORRADO" << endl;
        cita.setEstado(false);
        return cita;
    }
    cout << "INGRESE FECHA DE SERVICIO: " << endl;
    if(_fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        cita.setEstado(false);
        return cita;
    }

    if(_fecha.validarFechaTurno(_fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MAYOR O IGUAL A HOY" << endl;
        cita.setEstado(false);
        return cita;
    }
    idT = archi.contarRegistro(cita); // ESTE SERIA PK AUTOINCREMENTAL DE CLIENTE
    if(idT == -1){
        cout << "FALLO APERTURA DEL ARCHIVO" << endl;
        cita.setEstado(false);
        return cita;
    }
    idT++;
    cita.Cargar(idT, _fecha, nD, tS);
    return cita;
}
/*
bool validarCliente(int nD){
    Cliente usuario;
    Archivo archi;
    int pos = 0;
    while(archi.leerDeDisco(pos, usuario)){
        if(nD == usuario.getDNI()){
            return usuario.getEstado();
        }
        pos++;
    }
    return false;
}*/

bool validarTipoServicio(int tS){
    Servicio servicio;
    Archivo archi;
    int pos = 0;
    while(archi.leerDeDisco(pos, servicio)){
        if(tS == servicio.getCodigo()){
            return servicio.getEstado();
        }
        pos++;
    }
    return false;
}

// 2 MODIFICA POR ID LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat
bool modificarFechaServicioTurno(){
    Archivo archi;
    Turno cita;
    int idT, pos;
    Fecha _fecha;
    // buscar el turno a modificar fecha de servicio
    cout << "INGRESE EL ID TURNO DEL REGISTRO A MODIFICAR FECHA DE SERVICIO: ";
    cin >> idT;
    // leer si existe el turno
    pos = buscarIdTurno(idT);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO" << endl;
        return false;
    }
    archi.leerDeDisco(pos, cita);
    /// cambiar la fecha de servicio del turno
    cout << "INGRESE LA NUEVA FECHA DE SERVICIO: " << endl;
    if(_fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        cita.setEstado(false);
        return false;
    }
    if(_fecha.validarFechaTurno(_fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MAYOR O IGUAL A HOY" << endl;
        return false;
    }
    cita.setFechaServicio(_fecha);
    /// sobreescribir el registro
    return archi.modificarEnDisco(pos, cita);
}

int buscarIdTurno(int idT){
    Archivo archi;
    Turno cita;
    int pos = 0;
    while(archi.leerDeDisco(pos, cita)){
        if(idT == cita.getIdTurno()){
            if(cita.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

// 3 MUESTRAR POR ID LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat
bool mostrarTurnoPorId(){
    Archivo archi;
    Turno cita;
    int idT, pos;
    /// buscar el turno a mostrar
    cout << "INGRESE EL NUMERO DE ID DEL TURNO A MOSTRAR: ";
    cin >> idT;
    /// leer si existe el turno
    pos = buscarIdTurno(idT);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO" << endl;
        return false;
    }
    archi.leerDeDisco(pos, cita);
    /// LISTAR EL TURNO FILTRADO
    cita.Mostrar();
    return true;
}


// - MUESTRA LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat
void mostrarTurnos(){
    Archivo archi;
    Turno cita;
    int pos = 0;
    while(archi.leerDeDisco(pos, cita)){
        cita.Mostrar();
        cout << endl;
        pos++;
    }
}

// MOSTRAR TURNOS DEL DIA

void mostrarTunoDelDia(){
    Archivo archi;
    Turno _turno;
    Cliente usuario;
    Servicio servicio;
    int posT = 0, posC, posS, posY = 0;
    while(archi.leerDeDisco(posT, _turno)){
        if(turnoHoy(_turno.getFechaServicio()) == true){
            posC = buscarDNICliente(_turno.getDNI());
            archi.leerDeDisco(posC, usuario);
            if(_turno.getDNI() == usuario.getDNI() && usuario.getEstado()){
                posS = buscarCodigoServicio(_turno.getTipoServicio(), servicio);
                archi.leerDeDisco(posS, servicio);
                gotoxy(22, 17+(posY*2));
                _turno.getFechaServicio().Mostrar();
                gotoxy(42, 17+(posY*2));
                cout << usuario.getNombre();
                gotoxy(52, 17+(posY*2));
                cout << servicio.getDescripcion();
                gotoxy(72, 17+(posY*2));
                cout << "$ " << servicio.getPrecio();
                posY++;
            }
        }
        posT++;
    }
}

bool turnoHoy(Fecha f){
    time_t tiempo;
    struct tm *hoy;

    tiempo = time(NULL);
    hoy = localtime(&tiempo);
    if(f.getAnio() < (1900 + hoy -> tm_year)){
        return false;
    }
    else{
        if(f.getMes() < (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){

        return false;
        }
        else{
            if(f.getDia() < hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                return false;
            }
            else{
                if(f.getHora() < hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                    return false;
                }
                else{
                    if(f.getMinuto() < hoy -> tm_min && f.getHora() == hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

#endif // FUNCIONESTURNOS_H_INCLUDED
