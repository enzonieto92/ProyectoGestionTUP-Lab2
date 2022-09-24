#ifndef FUNCIONESGLOBALESTURNO_H_INCLUDED
#define FUNCIONESGLOBALESTURNO_H_INCLUDED

/// PROTOTIPOS FUNCIONES GLOBALES TURNO

int contarRegistroTurno();  /// CUENTA LOS REGISTROS TURNOS EN EL ARCHIVO Turnos.dat PARA ASIGNAR NUEVO ID TURNO

Turno cargarTurno();    /// CARGA OBJETO TURNOS Y LO DEVUELVE CARGADO EN MEMORIA VALIDADO

int agregarRegistroTurno(); /// AGREGA REGISTROS TURNOS A DISCO EN ARCHIVO Turnos.dat

int buscarIdTurno(int idT); /// RECIVE ID TURNO BUSCA POSICION EN Turnos.dat Y LA DEVUELVE SI ENCONTRO SINO DEVUELVE -1

Turno leerRegistroTurno(int pos); /// RECIVE POSICION DE REGISTRO DENTRO DEL ARCHIVO Turnos.dat Y LO DEVUELVE CARGADO EN MEMORIA

bool mostrarTurnoPorId(); /// PIDE INGRESO ID TURNO VALIDA QUE EXISTA REGISTRO Y LO MUESTRA O AVISA QUE NO ESTA

void mostrarTurno();    /// LISTA TODOS LOS REGISTROS TURNOS DEL ARCHIVO Turnos.dat

bool sobreEscribirRegistroTurno(Turno cita, int pos); /// RECIVE REGISTRO TURNO Y POSICION DONDE QUIERE REESCRIBIR EL REGISTRO EN ARCHIVO Turnos.dat

bool modificarFechaServicioTurno(); /// PIDE ID TURNO PARA MODIFICAR LA FECHA DE SERVICIO DEL REGISTRO

bool eliminarLogicoTurno(); /// PIDE UN ID TURNO DE UN REGISTRO Y LO REESCRIBE CON  ESTADO FALSE EN ARCHIVO Turnos.dat

/// DEFINICIONES FUNCIONES GLOBALES TURNO

// PUNTO 1 AGREGAR CANCION

int contarRegistroTurno(){
    int cant;
    FILE *p;
    p = fopen(TURNOS, "rb");
    if(p == NULL){
        return 0;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Turno);
    fclose(p);
    return cant;
}

Turno cargarTurno(){
    Turno cita;
    int idT, nD;
    Fecha fecha;

    cout << "DNI CLIENTE: ";
    cin >> nD;
    if(validarCliente(nD) == false){
        cout << "EL CLIENTE INGERSADO ES INVALIDO. NO ESTA REGISTRADO O FUE BORRADO" << endl;
        cita.setEstado(false);
        return cita;
    }
    cout << "INGRESE FECHA DE SERVICIO: " << endl;
    if(fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        cita.setEstado(false);
        return cita;
    }

    if(validarFechaTurno(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MAYOR O IGUAL A HOY" << endl;
        cita.setEstado(false);
        return cita;
    }

    idT = contarRegistroTurno() + 1;
    if(idT == 1){
        cout << "FALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
    }

    if(cita.Cargar(idT, fecha, nD) == false){
        cout << "FALLO CARGAR REGISTRO" << endl;
        cita.setEstado(false);
        return cita;
    }
    return cita;
}

int agregarRegistroTurno(){
    Turno cita;
    cita = cargarTurno();
    if(cita.getEstado() == false){ /// ERROR EN FECHA o FALLO APERTURA ARCHIVO
        return -1;
    }
    if(cita.GrabarEnDisco()){ /// GRABO EN DISCO
        return 0;
    }
    return -2; /// FALLO GRABAR EN DISCO
}

// PUNTO 2 LISTAR TURNO POR ID
int buscarIdTurno(int idT){
    Turno cita;
    int pos = 0;
    while(cita.LeerDeDisco(pos)){
        if(idT == cita.getIdTurno()){
            if(cita.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Turno leerRegistroTurno(int pos){
    Turno cita;
    cita.setIdTurno(-1);
    FILE *p;
    p = fopen(TURNOS,"rb");
    if(p == NULL){
        return cita;
    }
    /// int desplazamiento = pos * sizeof tema;
    /// cantidad de bytes que necesito desplazarme
    /// 0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    /// 1 SEEK_CUR DESDE LA POSICION ACTUACL
    /// 2 SEEK_END DESDE LA POSICION FINAL
    fseek(p, pos * sizeof cita, 0);
    fread(&cita, sizeof cita, 1, p);
    fclose(p);
    return cita;
}

bool mostrarTurnoPorId(){ /// FILTRA LISTADO POR ID NUMERO DE CANCION
    Turno cita;
    int idT, pos;
    /// buscar el turno a mostrar
    cout << "INGRESE EL NUMERO DE ID TURNO DEL REGISTRO A MOSTRAR: ";
    cin >> idT;
    /// leer si existe el turno
    pos = buscarIdTurno(idT);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO" << endl;
        return false;
    }
    cita = leerRegistroTurno(pos);
    /// LISTAR EL TURNO FILTRADO
    cita.Mostrar();
    return true;
}

// PUNTO 3 LISTAR TODAS LAS CANCIONES
void mostrarTurno(){
    Turno cita;
    int pos = 0;
    while(cita.LeerDeDisco(pos)){
        cita.Mostrar();
        cout << endl;
        pos++;
    }
}

// PUNTO 4 MODIFICAR FECHA DE TURNO
bool sobreEscribirRegistroTurno(Turno cita, int pos){
    FILE *p;
    p = fopen(TURNOS, "rb+"); ///+ le agrega al modo lo que le falta
    if(p == NULL)return false;
    fseek(p, sizeof cita * pos, 0);
    bool escribio = fwrite(&cita, sizeof cita, 1, p);
    fclose(p);
    return escribio;
}

bool modificarFechaServicioTurno(){
    Turno cita;
    int idT, pos;
    Fecha fecha;
    /// buscar el turno a modificar fecha de servicio
    cout << "INGRESE EL ID TURNO DEL REGISTRO A MODIFICAR FECHA DE SERVICIO: ";
    cin >> idT;
    /// leer si existe el turno
    pos = buscarIdTurno(idT);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO" << endl;
        return false;
    }
    cita = leerRegistroTurno(pos);
    /// cambiar la fecha de servicio del campo
    cout << "INGRESE LA NUEVA FECHA DE SERVICIO: " << endl;
    if(fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        cita.setEstado(false);
        return false;
    }
    if(validarFechaTurno(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MAYOR O IGUAL A HOY" << endl;
        return false;
    }
    cita.setFechaServicio(fecha);
    /// sobreescribir el registro
    return sobreEscribirRegistroTurno(cita, pos);
}

// PUNTO 5 ELIMINAR LOGICA CANCION
bool eliminarLogicoTurno(){
    Turno cita;
    int idT, pos;
    /// buscar el registro a eliminar
    cout << "INGRESE EL ID DE TURNO DEL REGISTRO A DAR DE BAJA: ";
    cin >> idT;
    /// leer si existe el registro
    pos = buscarIdTurno(idT);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE TURNO EN EL ARCHIVO" << endl;
        return false;
    }
    cita = leerRegistroTurno(pos);
    /// cambiar el estado del campo
    cita.setEstado(false);
    /// sobreescribir el registro
    return sobreEscribirRegistroTurno(cita, pos);
}

#endif // FUNCIONESGLOBALESTURNO_H_INCLUDED
