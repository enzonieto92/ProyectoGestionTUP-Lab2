#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

#include <iostream>

using namespace std;

/// PROTOTIPOS FUNCIONES GLOBALES CLIENTE

int agregarRegistroCliente();
    Cliente cargarCliente();
        bool validarCliente(int nD);

bool modificarTelefonoCliente();
    int buscarDNICliente(int nD);

bool mostrarClientePorDNI();

void mostrarClientes(); // ESPERANDO SER USADA

/// DEFINICIONES FUNCIONES GLOBALES CLIENTE

// 1 AGREGA REGISTROS CLIENTES  AL ARCHIVO Clientes.dat
int agregarRegistroCliente(){
    Cliente usuario;
    Archivo archi;
    usuario = cargarCliente();
    if(usuario.getEstado() == false){ // ERROR DNI O APERTURA DEL ARCHIVO
        return -1;
    }
    if(archi.grabarEnDisco(usuario)){ // GRABO EN DISCO
        return 0;
    }
    return -2; // FALLO GRABAR EN DISCO
}

Cliente cargarCliente(){
    Cliente usuario;
    int nD;
    //int idC;
    //Archivo archi;
    cout << "DNI CLIENTE: ";
    cin >> nD;
    if(validarCliente(nD) == true){
        cout << "EL CLIENTE INGERSADO ESTA REGISTRADO" << endl;
        usuario.setEstado(false);
        return usuario;
    }
    /*idC = archi.contarRegistro(usuario); // ESTE SERIA PK AUTOINCREMENTAL DE CLIENTE
    if(idC == -1){
        cout << "FALLO APERTURA DEL ARCHIVO" << endl;
        usuario.setEstado(false);
        return usuario;
    }
    idC++;*/
    usuario.Cargar(nD);
    return usuario;
}

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
}

// 2 MODIFICA POR DNI LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
bool modificarTelefonoCliente(){
    Archivo archi;
    Cliente usuario;
    int nD, pos;
    char nT[40];
    /// buscar el cliente a modificar telefono
    cout << "INGRESE EL DNI DEL CLIENTE A MODIFICAR TELEFONO: ";
    cin >> nD;
    // leer si existe el cliente
    pos = buscarDNICliente(nD);
    if(pos == -1){
        cout << "NO EXISTE EL DNI DE CLIENTE EN EL ARCHIVO" << endl;
        return false;
    }
    archi.leerDeDisco(pos, usuario);
    // cambiar telefono del cliente
    cout << "INGRESE EL NUEVO TELEFONO: ";
    cargarCadena(nT, 39);
    usuario.setTelefono(nT);
    // sobrescribir el registro
    return archi.modificarEnDisco(pos, usuario);
}

int buscarDNICliente(int nD){
    Archivo archi;
    Cliente usuario;
    int pos = 0;
    while(archi.leerDeDisco(pos, usuario)){
        if(nD == usuario.getDNI()){
            if(usuario.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

// 3 MUESTRAR POR DNI LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
bool mostrarClientePorDNI(){
    Archivo archi;
    Cliente usuario;
    int nD, pos;
    /// buscar el cliente a mostrar
    cout << "INGRESE EL NUMERO DE DNI DEL CLIENTE A MOSTRAR: ";
    cin >> nD;
    /// leer si existe el cliente
    pos = buscarDNICliente(nD);
    if(pos == -1){
        cout << "NO EXISTE EL DNI DE CLIENTE EN EL ARCHIVO" << endl;
        return false;
    }
    archi.leerDeDisco(pos, usuario);
    /// LISTAR EL CLIENTE FILTRADO
    usuario.Mostrar();
    return true;
}

// - MUESTRA LOS REGISTROS DE CLIENTES DEL ARCHIVO Clientes.dat
void mostrarClientes(){
    Archivo archi;
    Cliente usuario;
    int pos = 0;
    while(archi.leerDeDisco(pos, usuario)){
        usuario.Mostrar();
        cout << endl;
        pos++;
    }
}

#endif // FUNCIONESCLIENTES_H_INCLUDED
