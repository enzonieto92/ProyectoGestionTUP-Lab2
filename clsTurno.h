#ifndef CLSTURNO_H_INCLUDED
#define CLSTURNO_H_INCLUDED

class Turno{
    private:
        //Hora horaServicio;
        int idTurno; /// autoincremental
        Fecha fechaServicio;
        int DNI;
        int tipoServicio;
        bool estado;
    public:
        ///CONSTRUCTOR
        Turno(int t = 0, int d = 0, int tS = 0, bool e = false){
            idTurno = t;
            DNI = d;
            tipoServicio = tS;
            estado = e;
        }
        /// METODOS
        bool Cargar(int idT, Fecha fecha, int nD);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();

        ///SETS
        void setIdTurno(int t){idTurno = t;}
        void setFechaServicio(Fecha f){fechaServicio = f;}
        void setDNI(int d){DNI = d;}
        void setTipoServicio(int s){tipoServicio = s;}
        void setEstado(bool e){estado = e;}
        ///GETS
        int getIdTurno(){return idTurno;}
        Fecha getFechaServicio(){return fechaServicio;}
        int getDNI(){return DNI;}
        int getTipoServicio(){return tipoServicio;}
        bool getEstado(){return estado;}
        /// DESTRUCTOR
        ~Turno(){}
};

bool Turno::Cargar(int idT, Fecha fecha, int nD){
    //cout << "ID TURNO: ";
    //cin >> idTurno;
    setIdTurno(idT);

    //cout << "DNI: ";
    //cin >> DNI;
    setDNI(nD);

    //cout << "FECHA DE SERVICIO: ";
    //fechaServicio.Cargar();
    setFechaServicio(fecha);

    cout << "TIPO DE SERVICIO: ";
    cin >> tipoServicio;
    setTipoServicio(tipoServicio);

    estado = 1;
    setEstado(estado);
    return true;
}

void Turno::Mostrar(){
    if(estado){
        cout << "DNI: " << DNI << endl;

        cout << "FECHA DE SERVICIO: " << endl;;
        fechaServicio.Mostrar();

        cout << "TIPO DE SERVICIO: " << tipoServicio << endl;

        cout << "ESTADO: " << estado << endl;
    }
}

bool Turno::LeerDeDisco(int pos){
    FILE *p;
    p = fopen(TURNOS, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Turno) * pos, 0);
    bool leyo = fread(this, sizeof(Turno), 1, p);
    fclose(p);
    return leyo;
}

bool Turno::GrabarEnDisco(){
    FILE *p;
    p = fopen(TURNOS, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Turno), 1, p);
    fclose(p);
    return escribio;
}

#endif // CLSTURNO_H_INCLUDED
