#ifndef FUNCIONESTURNOS_H_INCLUDED
#define FUNCIONESTURNOS_H_INCLUDED

#include <iostream>
#include <ctime>

using namespace std;

/// PROTOTIPOS FUNCIONES GLOBALES TURNO

void borrarLista();

void agregarRegistroTurno();
void eliminarRegitroTurno(Fecha&);
bool cargarTurno(Turno&);
void cambiarFecha(Fecha);
void TurnosDelDia(Fecha);
bool turnoHoy(Fecha);
void BorrarTurno(Turno);
bool ConfirmarSeleccion(int, int);
bool cambiarRegistroTurno(Turno);
void bajaFisicaTurnoAuto();

/// DEFINICIONES FUNCIONES GLOBALES TURNO

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
    if (cargarTurno(cita) == false) {
        rlutil::setColor(3);
        rlutil::hidecursor();
        return;
    }
    if(archi.grabarEnDisco(cita)){ // GRABO EN DISCO
        gotoxy(44, 27);
        cout << "TURNO CARGADO";
        getch();
        rlutil::setColor(3);
        return;
    }
    return; // FALLO GRABAR EN DISCO
}
void seleccionarTurno(int &pos){
switch (rlutil::getkey()){
case 14:
    pos ++;
case 15:
    pos --;
case 1:
    return;

}
}
int contarRegistrosxFecha(Fecha &_fecha){
Archivo reg;
Turno _turno;
int pos = 0, cont = 0;
    while (reg.leerDeDisco(pos, _turno)){
        if (_turno.getFechaServicio() == _fecha){
            cont++;
        }
        pos++;
    }
    return cont;
}
void eliminarRegitroTurno(Fecha &_fecha){
int pos = 0;
int tam = contarRegistrosxFecha(_fecha);
int seleccion = 0;
int vec = 0;
bool buscar = true;
Archivo reg;
Turno _turno;
Turno* Lista = new Turno[tam];
    gotoxy(4, 17);
cout <<"Elija el Turno";
    while (reg.leerDeDisco(pos, _turno)){
            if (_turno.getFechaServicio() == _fecha){
            Lista[vec] = _turno;
            vec++;
            }
        pos++;
    }
            while (buscar == true){
                gotoxy(15, 2*seleccion+19);
                cout << char (175) << char(196) << char (62) ;
                switch (rlutil::getkey()){

                    case 15:
                        gotoxy(15, 2*seleccion+19);
                        cout <<"   ";
                        seleccion++;
                        if (seleccion > tam-1){
                            seleccion = tam-1;
                        }
                        break;
                    case 14:
                        gotoxy(15, 2*seleccion+19);
                        cout <<"   ";
                        seleccion--;
                        if (seleccion < 1){
                            seleccion = 0;
                        }
                        break;
                    case 1:
                       if (ConfirmarSeleccion(38, 2*seleccion+21)){
                        buscar = false;
                        BorrarTurno(Lista[seleccion]);
                        break;
                       }
                       else{
                        buscar = false;
                        return;
                       }
                       break;
                    case 0:
                        buscar = false;
                        return;
                }
            }
}
    bool ConfirmarSeleccion(int x, int y){
rlutil::setColor(rlutil::WHITE);
Cuadro confirmacion(Origen (x, y), 22, 4);
rlutil::setBackgroundColor(0);
bool opc = true;
while (true){
confirmacion.limpiar();
confirmacion.dibujar();
rlutil::setBackgroundColor(0);
gotoxy(x+4, y+1);
cout <<"Confirmar?";
if (opc == true){

gotoxy(x+8, y+3);
rlutil::setBackgroundColor(3);
cout <<"SI";
rlutil::setBackgroundColor(0);
gotoxy(x+14, y+3);
cout <<"NO";
}
else{
gotoxy(x+8, y+3);
cout <<"SI";
gotoxy(x+14, y+3);
rlutil::setBackgroundColor(3);
cout <<"NO";
rlutil::setBackgroundColor(0);
}

        switch (rlutil::getkey()){
    case 16:
        opc = true;
        break;
    case 17:
        opc = false;
        break;
    case 0:
        rlutil::setBackgroundColor(0);
        rlutil::setColor(3);
        return false;
        break;
    case 1:
        rlutil::setBackgroundColor(0);
        rlutil::setColor(3);
        return opc;
        break;
        }
}
}
        void BorrarTurno(Turno aux){
Turno _turno;
Archivo reg;
int pos = 0;
int indice = 0;
int tam = reg.contarRegistro(aux);
Turno * Lista = new Turno[tam-1];

while (reg.leerDeDisco(pos, _turno)){

if (_turno == aux){
    pos++;
}
    else
    {
        Lista[indice] = _turno;
        pos++;
        indice++;
    }

}

 reg.modificarEnDisco(Lista, tam-1);
    rlutil::hidecursor();
    gotoxy( 44, 8);
    cout <<"TURNO BORRADO!";
    getch();

}



void ModificarTurno(Fecha &_fecha){
int pos = 0;
int tam = contarRegistrosxFecha(_fecha);
int seleccion = 0;
int vec = 0;
bool buscar = true;
Archivo reg;
Turno _turno;
Turno* Lista = new Turno[tam];
    gotoxy(4, 17);
cout <<"Elija el Turno";
    while (reg.leerDeDisco(pos, _turno)){
            if (_turno.getFechaServicio() == _fecha){
            Lista[vec] = _turno;
            vec++;
            }
        pos++;
    }
            while (buscar == true){
                gotoxy(15, 2*seleccion+19);
                cout << char (175) << char(196) << char (62) ;
                switch (rlutil::getkey()){

                    case 15:
                        gotoxy(15, 2*seleccion+19);
                        cout <<"   ";
                        seleccion++;
                        if (seleccion > tam-1){
                            seleccion = tam-1;
                        }
                        break;
                    case 14:
                        gotoxy(15, 2*seleccion+19);
                        cout <<"   ";
                        seleccion--;
                        if (seleccion < 1){
                            seleccion = 0;
                        }
                        break;
                    case 1:
                        if(cambiarRegistroTurno(Lista[seleccion])){

                        buscar = false;
                        break;
                        return;
                        }
                        else{
                            return;
                        }
                    case 0:
                        buscar = false;
                        return;
                }
            }
}

bool cambiarRegistroTurno(Turno obj){
Archivo reg;
Turno aux;
Cuadro Modificacion(Origen (30, 17), 40, 15);
    Modificacion.limpiar();
    Modificacion.dibujar();
    gotoxy(30, 19);
    Modificacion.div();
    gotoxy(30, 21);
    Modificacion.div();
int pos = 0;
        while (reg.leerDeDisco(pos, aux)){
            if (obj == aux){
                if(cargarTurno(aux)){

                if (ConfirmarSeleccion(30, 29)){

                    reg.modificarEnDisco(pos, aux);
                    break;
                    return false;
                }
                else{
                    return true;
                }

                    }
            }
            pos++;
        }




}
//CARGAR TURNO: inicializa los objetos vacíos, recibe un objeto "Turno" como referencia para cargarlo, devuelve falso si no se completó la carga
bool cargarTurno(Turno &_cita){
    Cliente _cliente = {};
    Fecha _fecha = {};
    Servicio _servicio = {};
    gotoxy(45, 18);
    cout << "NUEVO TURNO";
    if (_fecha.Cargar() == false)return false;
    gotoxy (42, 22);
    cout << "Servicio: ";
    if (scroll_servicio(Origen(52, 22), _servicio) == false)return false;
    if(_cliente.Cargar(42, 24)){
    _cita.setCliente(_cliente);
    _cita.setFecha(_fecha);
    _cita.setServicio(_servicio);
    _cita.setEstado(true);
    }
    else{
        rlutil::hidecursor();
        return false;
    };
    return true;
}

// CAMBIAR LA FECHA DEL OBJETO QUE RECIBE, EN ESTE CASO ES LA FECHA QUE SE USA PARA MOSTRAR LA LISTA DE TURNOS
void cambiarFecha(Fecha* aux){
aux->setFecha();
}


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


#endif // FUNCIONESTURNOS_H_INCLUDED
