#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

#include <iostream>

using namespace std;

/// PROTOTIPOS FUNCIONES GLOBALES CLIENTE

bool agregarRegistroCliente();
    Cliente cargarCliente();

bool modificarCliente();
bool buscarRepetidos(Cliente);
bool scroll_cliente();
void mostrarClientes(int); // ESPERANDO SER USADA
void ordenarClientes(Cliente *, int);
void cargarArchivoEnVector(Cliente *, int);
void mostrar19Clientes(Cliente *, int, int);
void recorrerVector(int*);
void limpiarLista();
void eliminarRegitroCliente(int);
void BorrarCliente(Cliente);
bool ConfirmarSeleccion(int, int);
void CargarClientesTurnos();
/// DEFINICIONES FUNCIONES GLOBALES CLIENTE

// 1 AGREGA REGISTROS CLIENTES  AL ARCHIVO Clientes.dat
void CargarClientesTurnos(){
Archivo reg;
Turno turno;
Cliente cliente;
int pos = 0;
int cant_reg = reg.contarRegistro(cliente);
        while (reg.leerDeDisco(pos, turno)){
            cliente = turno.getCliente();
                if(buscarRepetidos(cliente)){
                turno.setEstadoCliente(true);
                reg.modificarEnDisco(pos, turno);
                }
                else if (cliente.getEstado() == false){
                    cliente.setIdCuenta(cant_reg+1+pos);
                    cliente.setEstado(true);
                    turno.setEstadoCliente(true);
                    reg.modificarEnDisco(pos, turno);
                    reg.grabarEnDisco(cliente);
                }
            pos++;
        }
}

bool buscarRepetidos(Cliente aux){
Archivo reg;
int indice = 0;
int cont = 0;
Cliente obj;
int tam = reg.contarRegistro(obj);
Cliente *Vec = new Cliente[tam];
while (reg.leerDeDisco(indice, obj)){
    Vec[indice] = obj;
    indice ++;
}
for (int i = 0; i < tam; i++){
    if (aux == Vec[i]){
        cont++;
    }
}
if(cont >0){
    return true;
}
return false;
}
bool agregarRegistroCliente(){
    Cliente usuario;
    Archivo archi;
    rlutil::setColor(rlutil::WHITE);
    Cuadro cuadroClienteCarga(Origen (30, 17), 40, 10);
    cuadroClienteCarga.limpiar();
    cuadroClienteCarga.dibujar();
    gotoxy(30, 19);
    cuadroClienteCarga.div();
    gotoxy(44, 18);
    cout <<"NUEVO CLIENTE";
    if(usuario.Cargar(40, 21)){
    usuario.setEstado(true);
    }
    else{
        return false;
    }
    if(archi.grabarEnDisco(usuario)){ // GRABO EN DISCO
        return true;
    }
}



// 2 MODIFICA POR DNI LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
bool modificarCliente(){
    Archivo archi;
    Cliente usuario;
     rlutil::setColor(rlutil::WHITE);
    /// buscar el cliente a modificar telefono
    if(scroll_cliente()){
    gotoxy(34, 42);
    cout << "CLIENTE MODIFICADO";
    rlutil::setColor(3);
    return true;
    }
    else{
        return false;
    }
}

bool scroll_cliente(){
Cuadro cuadroClienteModificar(Origen(28, 17), 44, 18);
cuadroClienteModificar.limpiar();

cuadroClienteModificar.dibujar();
gotoxy(28, 20);
cuadroClienteModificar.div();
gotoxy(28, 24);
cuadroClienteModificar.div();
Archivo reg;
Cliente obj;
bool scroll = true;
int pos = 0;
int indice = 0;
int tam = reg.contarRegistro(obj);
Cliente *Vec = new Cliente[tam];

while (reg.leerDeDisco(pos, obj)){
    Vec[pos] = obj;
    pos++;
}

    while(scroll){
    rlutil::hidecursor();
    gotoxy(43, 19);
    cout <<"Registro Actual";
    Vec[indice].Mostrar(40, 20);
        rlutil::showcursor();
        switch (rlutil::getkey()){

        case 14:
            indice--;
            if (indice < 1){
                indice = 0;
            }
            break;
        case 15:
            indice ++;
            if (indice > tam-1){
                indice = tam-1;
            }
            break;
        case 1:
            gotoxy(28, 28);
            cuadroClienteModificar.div();
            gotoxy(42, 26);
            cout <<"Modificar Cliente";
            if(obj.Cargar(40, 30)){
           reg.modificarEnDisco(indice, obj);
            scroll = false;
            }
            break;

        case 0:
            rlutil::hidecursor();
            rlutil::setColor(3);
            return false;
            break;
        }
    }
return true;
}


// 3 MUESTRA LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
void mostrarClientes(int pos){
    Archivo archi;
    Cliente usuario;
    int cant;
    Cliente *usuarioD;
    cant = archi.contarRegistro(usuario);
    if(cant == 0){
        gotoxy(38, 20);
        cout << "NO HAY CLIENTES REGISTRADOS";
        return;
    }

    usuarioD = new Cliente[cant];
    cargarArchivoEnVector(usuarioD, cant);
    ordenarClientes(usuarioD, cant);
    mostrar19Clientes(usuarioD, cant, pos);
    delete []usuarioD;
}
void ordenarClientes(Cliente *obj, int cantReg){
Cliente aux;
int cmp;
    for(int i = 0; i < cantReg; i++){
        for (int j = 0; j < cantReg-1; j++){
            cmp = strcmp(obj[j].getNombre(), obj[j+1].getNombre());
            if (cmp > 0){
                aux = obj[j];
                obj[j] = obj[j+1];
                obj[j+1] = aux;
            }
        }
    }
}


void cargarArchivoEnVector(Cliente *obj, int cantReg){
    Archivo archi;
    int i;
    for(i = 0; i < cantReg; i++){
        archi.leerDeDisco(i, obj[i]);
    }
}

void mostrar19Clientes(Cliente *obj, int cantReg, int pos){
    Cuadro listaCliente(Origen (20, 16), 60, 40) ;
    listaCliente.dibujarLista();
    int i, posY = 0;
    gotoxy(22, 17);
    cout << "NOMBRE";
    gotoxy(72, 17);
    cout << "TELEFONO";
    for(i = (0+pos); i <cantReg; i++){
        if (i >= pos+19){
            break;
        }
        if(obj[i].getEstado() == true){
            gotoxy(22, 19 + posY * 2);
            cout << obj[i].getNombre();
            cout << " "<<obj[i].getApellido();
            gotoxy(70, 19 + posY * 2);
            cout << obj[i].getTelefono();
            posY++;
        }
    }
}

void recorrerVector(int &pos){
    Archivo reg;
    Cliente obj;
    bool recorrer = true;
    int cantReg = reg.contarRegistro(obj);
    rlutil::setColor(rlutil::WHITE);
    limpiarLista();
    mostrarClientes(pos);
    while(recorrer){

        gotoxy(43, 8);
    cout <<"Elija la Pagina";
        switch (rlutil::getkey ()){
    case 16:
        pos -=19;
        if (pos < 0){
            pos = 0;
            break;
        }
        limpiarLista();
        mostrarClientes(pos);
        break;
    case 17:
        if (pos >=cantReg-(cantReg%19)){
            break;
        }
        pos += 19;
        limpiarLista();
        mostrarClientes(pos);
        break;
    case 1:
        recorrer = false;
        break;
    case 0:
        recorrer = false;
        break;

        }

    }
 rlutil::setColor(3);
}

void limpiarLista(){
 for (int x = 0; x < 60; x++) {
    for (int y = 0; y < 40; y++){

        gotoxy(20+x, 16+y);
        cout <<" ";

    }
 }

}
// 4 ELIMINAR CLIENTE
void eliminarRegitroCliente(int posVector){
Archivo reg;
Cliente cliente;
int pos = 0;
int tam = reg.contarRegistro(cliente);
int seleccion = 0;
int vec = 0;
bool buscar = true;
///Creación de vector en memoria dinámica//
Cliente* Lista = new Cliente[tam];
///Carga del vector///
    while (reg.leerDeDisco(pos, cliente)){
            Lista[vec] = cliente;
            vec++;
            pos++;
            }
    ordenarClientes(Lista, tam);

///interfaz para elegir cliente///
    gotoxy(4, 17);
cout <<"Elija el Cliente";
            while (buscar == true){
                gotoxy(15, 2*seleccion+19);
                cout << char (175) << char(196) << char (62) ;
                switch (rlutil::getkey()){

                    case 15:
                        gotoxy(15, 2*seleccion+19);
                        cout <<"   ";
                        seleccion++;
                        if (seleccion > 18 || seleccion > tam-1 || posVector+seleccion > tam-1){
                            seleccion --;
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
                        BorrarCliente(Lista[seleccion+posVector]);
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


void BorrarCliente(Cliente aux){
Cliente _cliente;
Archivo reg;
int pos = 0;
int indice = 0;
int tam = reg.contarRegistro(aux);
Cliente * Lista = new Cliente[tam-1];

while (reg.leerDeDisco(pos, _cliente)){

if (_cliente == aux){
    pos++;
}
    else
    {
        Lista[indice] = _cliente;
        pos++;
        indice++;
    }

}

 reg.modificarEnDisco(Lista, tam-1);
    rlutil::hidecursor();
    gotoxy( 44, 8);
    cout <<"CLIENTE BORRADO!";
    getch();

}

#endif // FUNCIONESCLIENTES_H_INCLUDED
