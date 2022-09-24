#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

class Cliente{
    private:
        int DNI;
        Fecha fechaNacimiento;
        char nombre[30];
        char apellido[30];
        char telefono[40];
        char email[40];
        bool estado;
    public:
        ///CONSTRUCTOR
        Cliente(int d = 0, const char *n = "SIN DATO", const char *a = "SIN DATO", const char *t = "SIN DATO", const char *eM = "SIN DATO", bool e = false){
            DNI = d;
            strcpy(nombre, n);
            strcpy(apellido, a);
            strcpy(telefono, t);
            strcpy(email, eM);
            estado = e;
        }
        /// METODOS
        bool Cargar(int nD, Fecha fecha);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();

        ///SETS
        bool setDNI(int nD){
            if(DNI > 0){
                DNI = nD;
                return true;
            }
            return false;
        }
        void setFechaNacimiento(Fecha f){fechaNacimiento = f;}
        void setNombre(const char *nom){strcpy(nombre, nom);}
        void setApellido(const char *ape){strcpy(apellido, ape);}
        void setTelefono(const char *tel){strcpy(telefono, tel);}
        void setEmail(const char *eM){strcpy(nombre, eM);}
        void setEstado(bool e){estado = e;}
        ///GETS
        int getDNI(){return DNI;}
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        const char *getTelefono(){return telefono;}
        const char *getEmail(){return email;}
        bool getEstado(){return estado;}
        /// DESTRUCTOR
        ~Cliente(){}
};

bool Cliente::Cargar(int nD, Fecha fecha){
    //cout << "DNI: ";
    //cin >> DNI;
    if(!setDNI(nD)){
        cout << "EL DNI DEBE SER UN VALOR POSITIVO" << endl;
        return false;
    }

    //cout << "FECHA DE NACIMIENTO: ";
    //fechaNacimiento.Cargar();
    setFechaNacimiento(fecha);

    cout << "NOMBRE: ";
    cargarCadena(nombre, 29);
    setNombre(nombre);

    cout << "APELLIDO: ";
    cargarCadena(apellido, 29);
    setApellido(apellido);

    cout << "TELEFONO: ";
    cargarCadena(telefono, 39);
    setTelefono(telefono);

    cout << "EMAIL: ";
    cargarCadena(email, 39);
    setEmail(email);

    estado = 1;
    setEstado(estado);
    return true;
}

void Cliente::Mostrar(){
    if(estado){
        cout << "DNI: " << DNI << endl;

        cout << "FECHA DE NACIMIENTO: " << endl;;
        fechaNacimiento.Mostrar();

        cout << "NOMBRE: " << nombre << endl;

        cout << "APELLIDO: " << apellido << endl;

        cout << "TELEFONO: " << telefono << endl;

        cout << "ESTADO: " << estado << endl;
    }
}

bool Cliente::LeerDeDisco(int pos){
    FILE *p;
    p = fopen(CLIENTES, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Cliente) * pos, 0);
    bool leyo = fread(this, sizeof(Cliente), 1, p);
    fclose(p);
    return leyo;
}

bool Cliente::GrabarEnDisco(){
    FILE *p;
    p = fopen(CLIENTES, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}

/// PROTOTIPO VALIDAR CLIENTE

bool validarCliente(int nD); /// BUSCA POR DNI SI EL CLIENTE ESTA REGISTRADO Y DEVULVE VERDADERO O FALSO

/// DEFINICION VALIDAR CLIENTE;

bool validarCliente(int nD){
    Cliente usuario;
    int pos = 0;
    while(usuario.LeerDeDisco(pos)){
        if(nD == usuario.getDNI()){
            return usuario.getEstado();
        }
        pos++;
    }
    return false;
}

#endif // CLSCLIENTE_H_INCLUDED
