#ifndef FUNCIONESTURNOS_H_INCLUDED
#define FUNCIONESTURNOS_H_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;

/// PROTOTIPOS FUNCIONES GLOBALES TURNO

void borrarLista();

void agregarRegistroTurno();
Turno cargarTurno();
void cambiarFecha(Fecha);
void TurnosDelDia(Fecha);
bool turnoHoy(Fecha);

void bajaFisicaTurnoAuto();

/// DEFINICIONES FUNCIONES GLOBALES TURNO

/*            if (pos == cantidad){
                gotoxy(coor.getX(), coor.getY());
                cout << "                 ";
                gotoxy(coor.getX(), coor.getY());
                cout <<"Nuevo servicio";
            }
*/

void borrarLista(){
    int i, j;
    for(i = 0; i < 61; i++){
        for(j = 0; j < 41; j++){
            gotoxy(19 + i, 16 + j);
            cout << " ";
        }
    }
}

// 1 AGREGA REGISTROS TURNOS  AL ARCHIVO Turnos.dat
void agregarRegistroTurno(){
    Turno cita;
    Archivo archi;
    rlutil::setColor(rlutil::WHITE);
    Cuadro cuadroTurnoCarga;
    cuadroTurnoCarga.setCuadro({30,17}, 40, 12);
    cuadroTurnoCarga.limpiar();
    cuadroTurnoCarga.dibujar();
    gotoxy(30, 19);
    cuadroTurnoCarga.div();
    gotoxy(30, 21);
    cuadroTurnoCarga.div();
    cita = cargarTurno();
    if(archi.grabarEnDisco(cita)){ // GRABO EN DISCO
        gotoxy(44, 27);
        cout << "TURNO CARGADO";
        getch();
        rlutil::setColor(12);
        return;
    }
    return; // FALLO GRABAR EN DISCO
}

Turno cargarTurno(){
    Turno _cita = {};
    Cliente _cliente = {};
    Fecha _fecha = {};
    Servicio _servicio;
    gotoxy(45, 18);
    cout << "NUEVO TURNO";
    _fecha.Cargar();
    gotoxy (42, 22);
    cout << "Servicio: ";
    _servicio = scroll_servicio(Origen(52, 22));
    _cliente.Cargar();
    _cita.setCliente(_cliente);
    _cita.setServicio(_servicio);
    _cita.setFecha(_fecha);
    _cita.setEstado(true);
    return _cita;
}

void cambiarFecha(Fecha* aux){
aux->setFecha();
}
// 2 MODIFICA POR ID LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat


// 3 MUESTRAR POR ID LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat

// MOSTRAR TURNOS DEL DIA
void TurnosDelDia(Fecha hoy){
    Archivo archi;
    Turno _turno;
    Cliente usuario;
    Servicio servicio;
    int posArchivo = 0;
    int posLista = 0;
    gotoxy(22, 17);
    cout << "HORA";
    gotoxy(30, 17);
    cout << "NOMBRE";
    gotoxy(52, 17);
    cout << "SERVICIO";
    gotoxy(72, 17);
    cout << "PRECIO";
    while(archi.leerDeDisco(posArchivo++, _turno)){
            if (_turno.getFechaServicio() == hoy){
                    usuario = _turno.getCliente();
                    servicio = _turno.getServicio();
                     gotoxy(21, 19+(posLista*2));
                    if(_turno.getFechaServicio().getHora() < 10) cout << "0";
                    cout << _turno.getFechaServicio().getHora() << ":";
                    if(_turno.getFechaServicio().getMinuto() < 10) cout << "0" ;
                    cout << _turno.getFechaServicio().getMinuto();
                    gotoxy(30, 19+(posLista*2));
                    cout << usuario.getNombre()<<" "<<usuario.getApellido();
                    gotoxy(52, 19+(posLista*2));
                    cout << servicio.getDescripcion();
                    gotoxy(72, 19+(posLista*2));
                    cout << "$ " << servicio.getPrecio();
            posLista++;
            }
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
                    if((f.getMinuto() + 30) < hoy -> tm_min && f.getHora() == hoy -> tm_hour && f.getDia() == hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void bajaFisicaTurnoAuto(){
    Archivo archi;
    Turno _turno;
    int pos = 0;
    FILE *pBakT, *pDatT;
    /// copia de seguridad del archivo
    pBakT = fopen("Turnos.bak", "wb"); /// vacio Turnos.bak
    if(pBakT == NULL) return;
    while(archi.leerDeDisco(pos, _turno)){
        fwrite(&_turno, sizeof(Turno), 1, pBakT);
        pos++;
    }
    /// comienza borrado fisico
    fclose(pBakT);
    pDatT = fopen("Turnos.dat", "wb"); /// vacio Turnos.dat
    if(pDatT == NULL) return;
    pBakT = fopen("Turnos.bak", "rb"); /// abre Turnos.bak
    if(pBakT == NULL){
        fclose(pDatT);
        return;
    }
    while(fread(&_turno, sizeof(Turno), 1, pBakT) == true){
        if(turnoHoy(_turno.getFechaServicio()) == true){
            fwrite(&_turno, sizeof(Turno), 1, pDatT); /// borrado fisico
        }
    }
    fclose(pBakT);
    fclose(pDatT);
}

#endif // FUNCIONESTURNOS_H_INCLUDED
