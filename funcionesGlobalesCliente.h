#ifndef FUNCIONESGLOBALESCLIENTE_H_INCLUDED
#define FUNCIONESGLOBALESCLIENTE_H_INCLUDED

/// PROTOTIPOS FUNCIONES GLOBALES CLIENTE

int contarRegistroCliente();  /// CUENTA LOS REGISTROS CLIENTES EN EL ARCHIVO Clientes.dat PARA DEVOLVER LA CANTIDAD

Cliente cargarCliente();    /// CARGA OBJETO CLIENTE Y LO DEVUELVE CARGADO EN MEMORIA VALIDADO

int agregarRegistroCliente(); /// AGREGA REGISTROS CLIENTES A DISCO EN ARCHIVO Clientes.dat

int buscarDNICliente(int nD); /// RECIVE DNI CLIENTE BUSCA POSICION EN Clientes.dat Y LA DEVUELVE SI ENCONTRO SINO DEVUELVE -1

Cliente leerRegistroCliente(int pos); /// RECIVE POSICION DE REGISTRO DENTRO DEL ARCHIVO Clientes.dat Y LO DEVUELVE CARGADO EN MEMORIA

bool mostrarClientePorDNI(); /// PIDE INGRESO DNI CLIENTE VALIDA QUE EXISTA REGISTRO Y LO MUESTRA O AVISA QUE NO ESTA

void mostrarCliente();    /// LISTA TODOS LOS REGISTROS CLIENTES DEL ARCHIVO Clientes.dat CON ESTADO POSITIVO

bool sobreEscribirRegistroCliente(Cliente usuario, int pos); /// RECIVE REGISTRO CLIENTE Y POSICION DONDE QUIERE REESCRIBIR EL REGISTRO EN ARCHIVO Clientes.dat

bool modificarFechaNacimientoCliente(); /// PIDE DNI CLIENTE PARA MODIFICAR LA FECHA DE NACIMIENTO DEL REGISTRO
/*
bool eliminarLogicoCliente(); /// PIDE UN DNI CLIENTE DE UN REGISTRO Y LO REESCRIBE CON  ESTADO FALSE EN ARCHIVO Clientes.dat
*/
/// DEFINICIONES FUNCIONES GLOBALES CLIENTE

// PUNTO 1 AGREGAR CLIENTE

int contarRegistroCliente(){
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

Cliente cargarCliente(){
    Cliente usuario;
    int nD;
    Fecha fecha;

    cout << "DNI CLIENTE: ";
    cin >> nD;
    if(validarCliente(nD) == true){
        cout << "EL CLIENTE INGERSADO ESTA REGISTRADO O FUE RECUPERADO" << endl;
        usuario.setEstado(false);
        return usuario;
    }
    cout << "INGRESE FECHA DE NACIMIENTO: " << endl;
    if(fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        usuario.setEstado(false);
        return usuario;
    }

    if(validarFechaNacimiento(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        usuario.setEstado(false);
        return usuario;
    }

    /*idC = contarRegistroTurno() + 1;
    if(idC == 1){
        cout << "FALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
    }*/

    if(usuario.Cargar(nD, fecha) == false){
        cout << "FALLO CARGAR REGISTRO" << endl;
        usuario.setEstado(false);
        return usuario;
    }
    return usuario;
}

int agregarRegistroCliente(){
    Cliente usuario;
    usuario = cargarCliente();
    if(usuario.getEstado() == false){ /// ERROR EN FECHA, DNI o FALLO APERTURA ARCHIVO
        return -1;
    }
    if(usuario.GrabarEnDisco()){ /// GRABO EN DISCO
        return 0;
    }
    return -2; /// FALLO GRABAR EN DISCO
}

// PUNTO 2 LISTAR CLIENTE POR DNI
int buscarDNICliente(int nD){
    Cliente usuario;
    int pos = 0;
    while(usuario.LeerDeDisco(pos)){
        if(nD == usuario.getDNI()){
            if(usuario.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Cliente leerRegistroCliente(int pos){
    Cliente usuario;
    usuario.setDNI(-1);
    FILE *p;
    p = fopen(CLIENTES,"rb");
    if(p == NULL){
        return usuario;
    }
    /// int desplazamiento = pos * sizeof tema;
    /// cantidad de bytes que necesito desplazarme
    /// 0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    /// 1 SEEK_CUR DESDE LA POSICION ACTUACL
    /// 2 SEEK_END DESDE LA POSICION FINAL
    fseek(p, pos * sizeof usuario, 0);
    fread(&usuario, sizeof usuario, 1, p);
    fclose(p);
    return usuario;
}

bool mostrarClientePorDNI(){ /// FILTRA LISTADO POR DNI DE CLIENTE
    Cliente usuario;
    int nD, pos;
    /// buscar el cliente a mostrar
    cout << "INGRESE EL NUMERO DE DNI DEL REGISTRO A MOSTRAR: ";
    cin >> nD;
    /// leer si existe el cliente
    pos = buscarDNICliente(nD);
    if(pos == -1){
        cout << "NO EXISTE EL DNI DE CLIENTE EN EL ARCHIVO" << endl;
        return false;
    }
    usuario = leerRegistroCliente(pos);
    /// LISTAR EL CLIENTE FILTRADO
    usuario.Mostrar();
    return true;
}

// PUNTO 3 LISTAR TODAS LOS CLIENTES
void mostrarCliente(){
    Cliente usuario;
    int pos = 0;
    while(usuario.LeerDeDisco(pos)){
        usuario.Mostrar();
        cout << endl;
        pos++;
    }
}

// PUNTO 4 MODIFICAR FECHA DE NACIMIENTO
bool sobreEscribirRegistroCliente(Cliente usuario, int pos){
    FILE *p;
    p = fopen(CLIENTES, "rb+"); ///+ le agrega al modo lo que le falta
    if(p == NULL)return false;
    fseek(p, sizeof usuario * pos, 0);
    bool escribio = fwrite(&usuario, sizeof usuario, 1, p);
    fclose(p);
    return escribio;
}

bool modificarFechaNacimientoCliente(){
    Cliente usuario;
    int nD, pos;
    Fecha fecha;
    /// buscar el cliente a modificar fecha de nacimiento
    cout << "INGRESE EL DNI DEL REGISTRO A MODIFICAR FECHA DE NACIMIENTO: ";
    cin >> nD;
    /// leer si existe el cliente
    pos = buscarDNICliente(nD);
    if(pos == -1){
        cout << "NO EXISTE EL DNI DE CLIENTE EN EL ARCHIVO" << endl;
        return false;
    }
    usuario = leerRegistroCliente(pos);
    /// cambiar la fecha de nacimiento del campo
    cout << "INGRESE LA NUEVA FECHA DE NACIMIENTO: " << endl;
    if(fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        usuario.setEstado(false);
        return false;
    }
    if(validarFechaNacimiento(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        return false;
    }
    usuario.setFechaNacimiento(fecha);
    /// sobreescribir el registro
    return sobreEscribirRegistroCliente(usuario, pos);
}
/*
// PUNTO 5 ELIMINAR LOGICA CLIENTE
bool eliminarLogicoCliente(){
    Cliente usuario;
    int nD, pos;
    /// buscar el registro a eliminar
    cout << "INGRESE EL DNI DEL CLIENTE DEL REGISTRO A DAR DE BAJA: ";
    cin >> nD;
    /// leer si existe el registro
    pos = buscarDNICliente(nD);
    if(pos == -1){
        cout << "NO EXISTE EL DNI DEL CLIENTE EN EL ARCHIVO" << endl;
        return false;
    }
    usuario = leerRegistroCliente(pos);
    /// cambiar el estado del campo
    usuario.setEstado(false);
    /// sobreescribir el registro
    return sobreEscribirRegistroCliente(usuario, pos);
}
*/
#endif // FUNCIONESGLOBALESCLIENTE_H_INCLUDED
