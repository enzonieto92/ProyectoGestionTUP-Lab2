#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES
void limpiarEspacios();

void agregarRegistroServicio();

void mostrarServicios();
bool scroll_servicio(Origen, Servicio&);
void modificarServicio();
    int buscarCodigoServicio(int, Servicio);

void buscarServicio();

void eliminarServicio();

///////////// DEFINICION DE AGREGAR REGISTRO SERVICIO

void limpiarEspacios(int x, int y){
for (int i = x; i < 62; i++){
    for (int j = y; j < 27; j++){
        gotoxy(i, j);
        cout <<" ";
    }
}

}
void agregarRegistroServicio(){
    rlutil::setColor(rlutil::WHITE);
    Cuadro cuadro(Origen(30,16), 40, 9);
    cuadro.limpiar();
    cuadro.dibujar();
    gotoxy(44, 17);
    cout <<"NUEVO SERVICIO";
    gotoxy(30, 18);
    cuadro.div();
    Archivo archivo;
    Servicio servicio;
    servicio.cargar(40, 20);
    archivo.grabarEnDisco(servicio);
    gotoxy (42, 23);
    cout << "REGISTRO GUARDADO";
    getch();
    rlutil::setColor(3);
}

///////////// DEFINICION DE MOSTRAR SERVICIO

void mostrarServicios(){
    Cuadro cuadro(Origen(31,16), 38, 26);
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int pos = 0;
    int cont = 0;
    gotoxy(42, 17);
    cout <<"SERVICIOS ACTUALES";
    gotoxy(31, 18);
    cuadro.div();
    if(archivo.contarRegistro(servicio)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS";
        getch();
        return;

    }
    while(archivo.leerDeDisco(pos, servicio)){

        if(servicio.mostrar(34, 19+cont*2)==true){
            cont++;
        }
        gotoxy(32, cont*2+18);
        cuadro.linea_hor();
        pos++;

    }
    if(cont == 0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS";
        getch();
    }
}

bool scroll_servicio(Origen coor, Servicio &aux){
    Archivo reg;
    bool scroll_servicio = true;
    int pos = 0;
    int cantidad = reg.contarRegistro(aux);
    reg.leerDeDisco(pos, aux);
        while (scroll_servicio){
            rlutil::hidecursor();
            if (reg.leerDeDisco(pos, aux)){
            gotoxy (coor.getX(), coor.getY());
            cout << "              ";
            gotoxy(coor.getX(), coor.getY());
            cout << aux.getDescripcion();
            }
            rlutil::showcursor();
            switch (rlutil::getkey()){
                case 15:
                    if (pos == cantidad-1){
                            break;
                    }
                    pos++;
                    break;
                case 14:
                    if (pos == 0){
                    pos = 0;
                    break;
                    }
                    pos--;
                    break;
                case 1:
                    scroll_servicio = false;
                    break;
                case 0:
                    scroll_servicio = false;
                    rlutil::hidecursor();
                    rlutil::setColor(3);
                    return false;
                    break;
            }
        }
    return true;
}

void eliminarServicio(){
    rlutil::setColor(rlutil::WHITE);

    Cuadro cuadro(Origen(32, 20), 36, 4);
    cuadro.limpiar();
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio, victima;
    int cont = archivo.contarRegistro(servicio);
    Servicio *Vec = new Servicio[cont];
    Servicio *Vec2 = new Servicio[cont-1];
    ///CARGA DEL VECTOR
    int pos = 0;
    while(archivo.leerDeDisco(pos, servicio)){
        Vec[pos] = servicio;
        pos++;
    }

    gotoxy(35, 22);
    cout <<"Borrar Servicio: ";
    rlutil::showcursor();
    if(scroll_servicio(Origen(52, 22), victima) == false)return;
    /// BUSQUEDA DEL SERVICIO EN EL VECTOR
    for (int i = 0; i < cont; i++){
        if (victima == Vec[i]){
            for (int j = i; j < cont-1; j ++){
            Vec[j] = Vec[j+1];
            }
            break;
        }
    }

    for (int k = 0; k < cont -1; k ++){
        Vec2[k] = Vec[k];
    }
    archivo.modificarEnDisco(Vec2, cont-1);
    rlutil::hidecursor();
    gotoxy( 42, 23);
    cout <<"SERVICIO BORRADO!";
    getch();



    rlutil::setColor(3);
    rlutil::hidecursor();

    }
///////////// DEFINICION DE MODIFICAR SERVICIO


void modificarServicio(){
    rlutil::setColor(rlutil::WHITE);

    Cuadro cuadro(Origen(31, 20), 38, 7);
    cuadro.limpiar();
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio, victima;
    int cont = archivo.contarRegistro(servicio);
    Servicio *Vec = new Servicio[cont];
    ///CARGA DEL VECTOR
    int pos = 0;
    char aux[30];
    while(archivo.leerDeDisco(pos, servicio)){
        Vec[pos] = servicio;
        pos++;
    }

    gotoxy(34, 22);
    cout <<"Modificar Servicio: ";
    rlutil::showcursor();
    if(scroll_servicio(Origen(54, 22), victima) == false)return;
    /// BUSQUEDA DEL SERVICIO EN EL VECTOR
    for (int i = 0; i < cont; i++){
        if (victima == Vec[i]){

            gotoxy(40, 23);
            cout <<"Nuevo Precio: $";
            cargarCadena(aux, 30);
                if (isdigit(*aux)){
                victima.setPrecio(aux);
                Vec[i] = victima;
                }

            break;
        }
    }
    rlutil::hidecursor();
    if (archivo.modificarEnDisco(Vec, cont) == true){
         gotoxy(41, 25);
         cout <<"SERVICIO CARGADO";
         getch();
    };
    rlutil::setColor(3);
}
/*void modificarServicio(){
    Cuadro cuadro;
    cuadro.setCoor({24,16});
    cuadro.setalto(8);
    cuadro.setlargo(52);
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int cod, pos;
    float pre;
    gotoxy (27, 18);
    cout << "INGRESAR EL CODIGO DEL SERVICIO A MODIFICAR: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy (28, 21);
        cout << "NO EXISTE EL CODIGO DEL SERVICO EN EL ARCHIVO" << endl;
        return;
    }
    archivo.leerDeDisco(pos,servicio);
    gotoxy (36, 20);
    cout << "INGRESAR NUEVO PRECIO: " << endl;
    gotoxy(59, 20);
    cin >> pre;
    if(servicio.setPrecio(pre)==false){
        gotoxy (34, 22);
        cout << "EL PRECIO NO PUEDE SER NEGATIVO" << endl;
        return;
    }
    if(archivo.modificarEnDisco(pos,servicio)==false){
        gotoxy (34, 22);
        cout << "ERROR AL MODIFICAR EL PERSONAL" << endl;
        return;
    }
    gotoxy (34, 22);
    cout << "REGISTO MODIFICADO EXISTOSAMENTE" << endl;
}

*/



#endif // FUNCIONESSERVICIOS_H_INCLUDED
