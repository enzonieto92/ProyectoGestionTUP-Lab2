#ifndef FUNCIONESTURNOS_H_INCLUDED
#define FUNCIONESTURNOS_H_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;

/// PROTOTIPOS FUNCIONES GLOBALES TURNO

void borrarLista();

void agregarRegistroTurno();
    Turno cargarTurno();
        bool validarClienteId(int idC);
        bool validarTipoServicio(int tS);
        bool validarPersonalId(int idP);

void modificarFechaServicioTurno();
    int buscarIdTurno(int idT);

bool mostrarTurnoPorId();

void mostrarTunoDelDia();
    void cargarArchivoEnVector(Turno *obj, int cantReg);
    void ordenarCrecienteVector(Turno *v, int tam);
    bool turnoHoy(Fecha f);

void bajaFisicaTurnoAuto();

/// DEFINICIONES FUNCIONES GLOBALES TURNO

void borrarLista(){
    int i, j;
    for(i = 0; i < 61; i++){
        for(j = 0; j < 41; j++){
            gotoxy(20 + i, 16 + j);
            cout << " ";
        }
    }
}

// 1 AGREGA REGISTROS TURNOS  AL ARCHIVO Turnos.dat
void agregarRegistroTurno(){
    Turno cita;
    Archivo archi;
    borrarLista();
    Cuadro cuadroTurnoCarga;
    cuadroTurnoCarga.setCoor({30,17});
    cuadroTurnoCarga.setalto(10);
    cuadroTurnoCarga.setlargo(40);
    cuadroTurnoCarga.dibujar();
    cita = cargarTurno();
    if(cita.getEstado() == false){ // ERROR EN FECHA O APERTURA DEL ARCHIVO
        gotoxy(42, 25);
        cout << "DATOS INVALIDOS";
        return;
    }
    if(archi.grabarEnDisco(cita)){ // GRABO EN DISCO
        gotoxy(42, 25);
        cout << "TURNO CARGADO";
        agregarMontoCuenta(cita);
        return;
    }
    gotoxy(42, 25);
    cout << "FALLO AL GRABAR EN EL DISCO";
    return; // FALLO GRABAR EN DISCO
}

Turno cargarTurno(){
    Turno cita;
    int idT, idC, tS, idP;
    Fecha _fecha;
    Archivo archi;
    rlutil::showcursor();
    gotoxy(42, 18);
    cout << "ID CLIENTE: ";
    cin >> idC;
    if(validarClienteId(idC) == false){
        rlutil::hidecursor();
        gotoxy(32, 20);
        cout << "EL CLIENTE INGERSADO ES INVALIDO";
        cita.setEstado(false);
        return cita;
    }
    gotoxy(42, 19);
    cout << "TIPO SERVICIO: ";
    cin >> tS;
    if(validarTipoServicio(tS) == false){
        rlutil::hidecursor();
        gotoxy(32, 21);
        cout << "EL SERVICIO INGERSADO ES INVALIDO";
        cita.setEstado(false);
        return cita;
    }
    gotoxy(42, 20);
    cout << "INGRESE FECHA DE SERVICIO: ";
    if(_fecha.Cargar() == false){
        rlutil::hidecursor();
        gotoxy(42, 24);
        cout << "FALLO CARGAR FECHA";
        cita.setEstado(false);
        return cita;
    }

    if(_fecha.validarFechaTurno(_fecha) == false){
        rlutil::hidecursor();
        gotoxy(32, 24);
        cout << "LA FECHA INGRESADA ES INVALIDA";
        cita.setEstado(false);
        return cita;
    }
    gotoxy(42, 22);
    cout << "ID PERSONAL: ";
    cin >> idP;
    if(validarPersonalId(idP) == false){
        rlutil::hidecursor();
        gotoxy(32, 24);
        cout << "EL PERSONAL INGERSADO ES INVALIDO";
        cita.setEstado(false);
        return cita;
    }
    idT = archi.contarRegistro(cita); // ESTE SERIA PK AUTOINCREMENTAL DE CLIENTE
    if(idT == -1){
        rlutil::hidecursor();
        gotoxy(32, 24);
        cout << "FALLO APERTURA DEL ARCHIVO";
        cita.setEstado(false);
        return cita;
    }
    rlutil::hidecursor();
    idT++;
    cita.Cargar(idT, _fecha, idC, tS, idP);
    return cita;
}

bool validarClienteId(int idC){
    Cliente usuario;
    Archivo archi;
    int pos = 0;
    while(archi.leerDeDisco(pos, usuario)){
        if(idC == usuario.getIdCuenta()){
            return usuario.getEstado();
        }
        pos++;
    }
    return false;
}

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

bool validarPersonalId(int idP){
    Personal personal;
    Archivo archi;
    int pos = 0;
    while(archi.leerDeDisco(pos, personal)){
        if(idP == personal.getIDPersonal()){
            return personal.getEstado();
        }
        pos++;
    }
    return false;
}

// 2 MODIFICA POR ID LOS REGISTROS DE TURNOS EN ARCHIVO Turnos.dat
void modificarFechaServicioTurno(){
    Archivo archi;
    Turno cita;
    int idT, pos;
    Fecha _fecha;
    borrarLista();
    Cuadro cuadroTurnoModificar;
    cuadroTurnoModificar.setCoor({24,16});
    cuadroTurnoModificar.setalto(10);
    cuadroTurnoModificar.setlargo(52);
    cuadroTurnoModificar.dibujar();
    // buscar el turno a modificar fecha de servicio
    rlutil::showcursor();
    gotoxy(30, 18);
    cout << "ID TURNO A MODIFICAR FECHA DE SERVICIO: ";
    cin >> idT;
    // leer si existe el turno
    pos = buscarIdTurno(idT);
    if(pos == -1){
        rlutil::hidecursor();
        gotoxy(30, 20);
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO" << endl;
        return;
    }
    archi.leerDeDisco(pos, cita);
    /// cambiar la fecha de servicio del turno
    gotoxy(32, 20);
    cout << "INGRESE LA NUEVA FECHA: " << endl;
    if(_fecha.Cargar() == false){
        rlutil::hidecursor();
        gotoxy(42, 24);
        cout << "FALLO CARGAR FECHA" << endl;
        cita.setEstado(false);
        return;
    }
    if(_fecha.validarFechaTurno(_fecha) == false){
        rlutil::hidecursor();
        gotoxy(32, 24);
        cout << "LA FECHA INGRESADA ES INVALIDA." << endl;
        return;
    }
    cita.setFechaServicio(_fecha);
    /// sobreescribir el registro
    if(archi.modificarEnDisco(pos, cita) == false){
        rlutil::hidecursor();
        gotoxy(34, 23);
        cout << "ERROR AL MODIFICAR TURNO" << endl;
        return;
    }
    rlutil::hidecursor();
    gotoxy(34, 23);
    cout << "TURNO MODIFICADO EXITOSAMENTE" << endl;
    return;
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
    borrarLista();
    Cuadro cuadroTurnoMostarId;
    cuadroTurnoMostarId.setCoor({28,16});
    cuadroTurnoMostarId.setalto(12);
    cuadroTurnoMostarId.setlargo(42);
    cuadroTurnoMostarId.dibujar();
    /// buscar el turno a mostrar
    rlutil::showcursor();
    gotoxy(38, 18);
    cout << "ID DEL TURNO A MOSTRAR: ";
    cin >> idT;
    /// leer si existe el turno
    rlutil::hidecursor();
    pos = buscarIdTurno(idT);
    if(pos == -1){
        gotoxy(30, 20);
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO";
        return false;
    }
    archi.leerDeDisco(pos, cita);
    /// LISTAR EL TURNO FILTRADO
    cita.Mostrar();
    gotoxy(42, 26);
    cout << "TURNO LISTADO";
    return true;
}

// MOSTRAR TURNOS DEL DIA
void mostrarTunoDelDia(){
    Archivo archi;
    Turno _turno;
    Cliente usuario;
    Servicio servicio;
    Personal personal;
    int posC, posS, posY = 0, posP;
    int cant;
    Turno *citasD;
    cant = archi.contarRegistro(_turno);
    if(cant == 0){
        return;
    }
    citasD = new Turno[cant];
    if(citasD == NULL){
        return;
    }
    cargarArchivoEnVector(citasD, cant);
    ordenarCrecienteVector(citasD, cant);
    gotoxy(22, 17);
    cout << "ID";
    gotoxy(26, 17);
    cout << "HORA";
    gotoxy(32, 17);
    cout << "FECHA";
    gotoxy(40, 17);
    cout << "NOMBRE";
    gotoxy(52, 17);
    cout << "PERSONAL";
    gotoxy(62, 17);
    cout << "SERVICIO";
    gotoxy(73, 17);
    cout << "PRECIO";
    for(int i = 0; i < cant; i++){
        if(turnoHoy(citasD[i].getFechaServicio()) == true){
            posC = buscarIdCliente(citasD[i].getIdCuenta());
            archi.leerDeDisco(posC, usuario);
            if(citasD[i].getIdCuenta() == usuario.getIdCuenta() && usuario.getEstado()){
                posS = buscarCodigoServicio(citasD[i].getTipoServicio(), servicio);
                archi.leerDeDisco(posS, servicio);
                posP = buscarIdPersonal(citasD[i].getIdPersonal(), personal);
                archi.leerDeDisco(posP, personal);
                gotoxy(22, 19+(posY*2));
                cout << citasD[i].getIdTurno();
                gotoxy(26, 19+(posY*2));
                if(citasD[i].getFechaServicio().getHora() < 10) cout << "0";
                cout << citasD[i].getFechaServicio().getHora() << ":";
                if(citasD[i].getFechaServicio().getMinuto() < 10) cout << "0" ;
                cout << citasD[i].getFechaServicio().getMinuto();
                gotoxy(32, 19+(posY*2));
                cout << citasD[i].getFechaServicio().getDia()<< "/" << citasD[i].getFechaServicio().getMes();
                gotoxy(40, 19+(posY*2));
                cout << usuario.getNombre();
                gotoxy(52, 19+(posY*2));
                cout << personal.getNombre();
                gotoxy(62, 19+(posY*2));
                cout << servicio.getDescripcion();
                gotoxy(73, 19+(posY*2));
                cout << "$ " << servicio.getPrecio();
                posY++;
            }
        }
    }
    delete []citasD;
}

void cargarArchivoEnVector(Turno *obj, int cantReg){
    Archivo archi;
    int i;
    for(i = 0; i < cantReg; i++){
        archi.leerDeDisco(i, obj[i]);
    }
}

void ordenarCrecienteVector(Turno *v, int tam){
    int i, j, posMin;
    Turno aux;
    for(i = 0; i < tam - 1; i++){
        posMin = i;
        for(j = i + 1; j < tam; j++){
            if(v[j].getFechaServicio() < v[posMin].getFechaServicio()){
                posMin = j;
            }
        }
        aux = v[i];
        v[i]= v[posMin];
        v[posMin] = aux;
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
