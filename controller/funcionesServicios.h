#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED

#include <iostream>

using namespace std;

/// DECLARACION DE FUNCIONES
void limpiarEspacios();

void agregarRegistroServicio();

void mostrarServicio();
Servicio scroll_servicio(Origen);
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
    Cuadro cuadro(Origen(30,16), 40, 8);
    cuadro.limpiar();
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    servicio.cargar(40, 18);
    archivo.grabarEnDisco(servicio);
    gotoxy (42, 22);
    cout << "REGISTRO GUARDADO";
    getch();
}

///////////// DEFINICION DE MOSTRAR SERVICIO

void mostrarServicio(){
    Cuadro cuadro(Origen(30,16), 40, 12);
    cuadro.limpiar();
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int pos = 0;
    int cont = 0;
    if(archivo.contarRegistro(servicio)==0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS";
        getch();
        return;

    }
    while(archivo.leerDeDisco(pos, servicio)){
        gotoxy(38, cont+18);
        if(servicio.mostrar()==true){
            cont++;
        }
        cout << endl;
        pos++;
    }
    if(cont == 0){
        gotoxy(38, 20);
        cout << "NO HAY REGISTRO GUARDADOS";
    }
    getch();
}

Servicio scroll_servicio(Origen coor){
    Archivo reg;
    Servicio aux;
    bool scroll_servicio = true;
    int pos = 0;
    int cantidad = reg.contarRegistro(aux);
    reg.leerDeDisco(pos, aux);
        while (scroll_servicio){
        gotoxy (1, 1);
            if (reg.leerDeDisco(pos, aux)){
            gotoxy (coor.getX(), coor.getY());
            cout << "                 ";
            gotoxy(coor.getX(), coor.getY());
            cout << aux.getDescripcion();
            }
            switch (rlutil::getkey()){
                case 14:
                    if (pos == cantidad-1){
                            break;
                    }
                    pos++;
                    break;
                case 15:
                    if (pos == 0){
                    pos = 0;
                    break;
                    }
                    pos--;
                    break;
                case 1:
                    scroll_servicio = false;
                    break;
            }
        }
    return aux;
}

void eliminarServicio(){
    rlutil::setColor(rlutil::WHITE);

    Cuadro cuadro(Origen(30, 17), 40, 12);
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
    victima = scroll_servicio(Origen(52, 22));
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




    rlutil::setColor(12);
    rlutil::hidecursor();

    }
///////////// DEFINICION DE MODIFICAR SERVICIO

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

///////////// DEFINICION DE BUSCAR SERVICIO

/*void buscarServicio(){
    Cuadro cuadro;
    cuadro.setCoor({24,16});
    cuadro.setalto(8);
    cuadro.setlargo(52);
    cuadro.dibujar();
    Archivo archivo;
    Servicio servicio;
    int pos,cod;
    gotoxy(29, 18);
    cout << "INGRESE EL NUMERO CODIGO DEL SERVICIO: ";
    cin >> cod;
    pos = buscarCodigoServicio(cod,servicio);
    if(pos == -1){
        gotoxy(28, 21);
        cout << "NO EXISTE EL CODIGO DE SERVICIO EN EL ARCHIVO" << endl;
        return;
    }
    archivo.leerDeDisco(pos,servicio);
    gotoxy(38, 21);
    servicio.mostrar();
    cout << endl;
}

///////////// DEFINICION DE ELIMINAR SERVICIO
*/

#endif // FUNCIONESSERVICIOS_H_INCLUDED
