#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia; /// 1 - 31
        int mes; /// 1 - 12
        int anio; /// menor o igual al actual

    public:
        /// CONSTRUCTOR
        Fecha(int d = 1, int m = 1, int a = 1900){
            dia = d;
            mes = m;
            anio = a;
        }

        /// METODOS
        bool Cargar();
        void Mostrar();

        /// SETS
        bool setDia(int d){
            if (d >= 1 && d <= 31){
                dia = d;
                return true;
            }
            return false;
        }
        bool setMes(int m){
            if (m >= 1 && m <= 12){
                mes = m;
                return true;
            }
            return false;
        }
        bool setAnio(int a){
            if (a >= 0){
                anio = a;
                return true;
            }
            return false;
        }

        /// GEST
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        /// DESTRUCTOR
        ~Fecha(){}
};

bool Fecha::Cargar(){
    cout << "DIA: ";
    cin >> dia;
    if(!setDia(dia)){
        cout << "EL DIA DEBE ESTAR ENTRE 1 Y 31" << endl;
        return false;
    }
    cout << "MES: ";
    cin >> mes;
    if(!setMes(mes)){
        cout << "EL MES DEBE ESTAR ENTRE 1 Y 12" << endl;
        return false;
    }
    cout << "ANIO: ";
    cin >> anio;
    if(!setAnio(anio)){
        cout << "EL AONIO DEBE SER POSTIVO" << endl;
        return false;
    }
    return true;
}

void Fecha::Mostrar(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}

/// PROTOTIPO VALIDAR FECHA
bool validarFechaTurno(Fecha f);

bool validarFechaNacimiento(Fecha f);

/// DEFINICION VALIDAR FECHA
bool validarFechaTurno(Fecha f){
    time_t tiempo;
    struct tm *hoy;

    tiempo = time(NULL);
    hoy = localtime(&tiempo);
    if(f.getAnio() < (1900 + hoy -> tm_year)){
        cout << "EL ANIO DEBE SER MAYOR O IGUAL AL ACTUAL" << endl;
        return false;
    }
    else{
        if(f.getMes() < (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
        cout << "EL MES DEBE SER MAYOR O IGUAL AL DEL CORRIENTE ANIO" << endl;
        return false;
        }
        else{
            if(f.getDia() < hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                cout << "LA FECHA DEBE SER MAYOR O IGUAL A LA ACTUAL" << endl;
                return false;
            }
        }
    }
    return true;
}

bool validarFechaNacimiento(Fecha f){
    time_t tiempo;
    struct tm *hoy;

    tiempo = time(NULL);
    hoy = localtime(&tiempo);
    if(f.getAnio() > (1900 + hoy -> tm_year)){
        cout << "EL ANIO DEBE SER MENOR O IGUAL AL ACTUAL" << endl;
        return false;
    }
    else{
        if(f.getMes() > (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
        cout << "EL MES DEBE SER MENOR O IGUAL AL DEL CORRIENTE ANIO" << endl;
        return false;
        }
        else{
            if(f.getDia() > hoy -> tm_mday && f.getMes() == (hoy -> tm_mon + 1) && f.getAnio() == (1900 + hoy -> tm_year)){
                cout << "LA FECHA DEBE SER MENOR O IGUAL A LA ACTUAL" << endl;
                return false;
            }
        }
    }
    return true;
}

#endif // CLSFECHA_H_INCLUDED
