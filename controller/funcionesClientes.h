#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

#include <iostream>

using namespace std;

/// PROTOTIPOS FUNCIONES GLOBALES CLIENTE

int agregarRegistroCliente();
    Cliente cargarCliente();

bool modificarTelefonoCliente();
    int buscarIdCliente(int idC);

void mostrarClientes(); // ESPERANDO SER USADA
    void ordenarClientes(Cliente *obj, int cantReg);
    void cargarArchivoEnVector(Cliente *obj, int cantReg);
    void mostrarVectorClientes(Cliente *obj, int cantReg);

void eliminarCliente();

bool mostrarClientePorId();
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

                    if (cliente.getEstado() == false){
                        cliente.setIdCuenta(cant_reg+1+pos);
                        cliente.setEstado(true);
                        turno.setEstadoCliente(true);
                        reg.modificarEnDisco(pos, turno);
                        reg.grabarEnDisco(cliente);
                    }


            pos++;
        }
}
int agregarRegistroCliente(){
    Cliente usuario;
    Archivo archi;
    Cuadro cuadroClienteCarga;
    cuadroClienteCarga.setCoor({30,17});
    cuadroClienteCarga.setalto(10);
    cuadroClienteCarga.setlargo(40);
    cuadroClienteCarga.dibujar();
    rlutil::showcursor();
    rlutil::hidecursor();
    if(usuario.getEstado() == false){ // ERROR DNI O APERTURA DEL ARCHIVO
        gotoxy(42, 22);
        cout << "DATOS INVALIDOS";
        return -1;
    }
    if(archi.grabarEnDisco(usuario)){ // GRABO EN DISCO
        gotoxy(42, 25);
        cout << "CLIENTE CARGADO";
        agregarCuentaCliente(usuario);
        return 0;
    }
    gotoxy(42, 26);
    cout << "FALLO AL GRABAR EN EL DISCO";
    return -2; // FALLO GRABAR EN DISCO
}



// 2 MODIFICA POR DNI LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
bool modificarTelefonoCliente(){
    Archivo archi;
    Cliente usuario;
    int idC, pos;
    char nT[40];
    Cuadro cuadroClienteModificar(Origen(28, 17), 18, 44);
    cuadroClienteModificar.limpiar();
    cuadroClienteModificar.dibujar();
    /// buscar el cliente a modificar telefono
    rlutil::showcursor();
    gotoxy(30, 18);
    cout << "ID CLIENTE A MODIFICAR TELEFONO: ";
    cin >> idC;
    // leer si existe el cliente
    pos = buscarIdCliente(idC);
    if(pos == -1){
        rlutil::hidecursor();
        gotoxy(30, 20);
        cout << "NO EXISTE EL ID DE CLIENTE EN EL ARCHIVO";
        return false;
    }
    archi.leerDeDisco(pos, usuario);
    // cambiar telefono del cliente
    gotoxy(32, 20);
    cout << "INGRESE EL NUEVO TELEFONO: ";
    cargarCadena(nT, 39);
    usuario.setTelefono(nT);
    // sobrescribir el registro
    rlutil::hidecursor();
    gotoxy(34, 22);
    cout << "CLIENTE MODIFICADO";
    return archi.modificarEnDisco(pos, usuario);
}

int buscarIdCliente(int idC){
    Archivo archi;
    Cliente usuario;
    int pos = 0;
    while(archi.leerDeDisco(pos, usuario)){
        if(idC == usuario.getIdCuenta()){
            if(usuario.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

// 3 MUESTRA LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
void mostrarClientes(){
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
    mostrarVectorClientes(usuarioD, cant);
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

void mostrarVectorClientes(Cliente *obj, int cantReg){
    Cuadro listaCliente(Origen (20, 16), 60, 40) ;
    listaCliente.dibujarLista();
    int i, posY = 0;
    gotoxy(22, 17);
    cout << "NOMBRE";
    gotoxy(72, 17);
    cout << "TELEFONO";
    for(i = 0; i < cantReg; i++){
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

// 4 ELIMINAR CLIENTE
void eliminarCliente(){
    Archivo archi;
    Cliente usuario;
    Cuadro _cuadro;
    _cuadro.setCoor({28,17});
    _cuadro.setalto(10);
    _cuadro.setlargo(44);
    _cuadro.limpiar();
    _cuadro.dibujar();
    int idC, pos;
    /// buscar el cliente a eliminar
    rlutil::showcursor();
    gotoxy(34, 18);
    cout << "ID DEL CLIENTE A BORRAR: ";
    cin >> idC;
    /// leer si existe el registro
    rlutil::hidecursor();
    pos = buscarIdCliente(idC);
    if(pos == -1){
        gotoxy(30, 20);
        cout << "NO EXISTE EL ID DEL CLIENTE EN EL ARCHIVO";
        return;
    }
    archi.leerDeDisco(pos, usuario);
    /// Validar cuenta corriente deuda o no
    if(eliminarCuentaCliente(usuario.getIdCuenta()) == false){
        gotoxy(34, 20);
        cout << "NO SE PUEDE ELIMINAR TIENE DEUDA";
        return;
    }
    /// cambiar el estado del campo
    usuario.setEstado(false);
    /// sobreescribir el registro
    archi.modificarEnDisco(pos, usuario);
    gotoxy(42, 20);
    cout << "CLIENTE BORRADO";
    gotoxy(42, 21);
    cout << usuario.getNombre();
    gotoxy(42, 22);
    cout << usuario.getApellido();
    gotoxy(42, 23);
    cout << usuario.getTelefono();
}

// 5 MUESTRAR POR DNI LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
bool mostrarClientePorId(){
    Archivo archi;
    Cliente usuario;
    int idC, pos;
    Cuadro _cuadroID;
    _cuadroID.setCoor({28,17});
    _cuadroID.setalto(10);
    _cuadroID.setlargo(44);
    _cuadroID.limpiar();
    _cuadroID.dibujar();
    /// buscar el cliente a mostrar
    rlutil::showcursor();
    gotoxy(34, 18);
    cout << "ID DEL CLIENTE A MOSTRAR: ";
    cin >> idC;
    /// leer si existe el cliente
    rlutil::hidecursor();
    pos = buscarIdCliente(idC);
    if(pos == -1){
        gotoxy(30, 20);
        cout << "NO EXISTE EL ID DE CLIENTE EN EL ARCHIVO";
        return false;
    }
    archi.leerDeDisco(pos, usuario);
    /// LISTAR EL CLIENTE FILTRADO
    usuario.Mostrar();
    gotoxy(34,26);
    cout << "CLIENTE LISTADO";
    return true;
}

#endif // FUNCIONESCLIENTES_H_INCLUDED
