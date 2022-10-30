#ifndef PERSONAL_H
#define PERSONAL_H

class Personal
{
    protected:
        int ID;
        char nombre[30];
        char apellido[30];
        char telefono[40];
        float sueldo;
        bool estado;
    public:
        /// CONSTRUCTOR
        Personal();
        /// METODOS
        bool cargar(int);
        bool mostrar();
        /// SETS
        void setIDPersonal(int);
        void setNombre(const char *);
        void setApellido(const char *);
        void setTelefono(const char *);
        bool setSueldo(float);
        void setEstado(bool e);
        /// GETS
        int getIDPersonal();
        const char *getNombre();
        const char *getApellido();
        const char *getTelefono();
        float getSueldo();
        bool getEstado();
};

#endif // PERSONAL_H
