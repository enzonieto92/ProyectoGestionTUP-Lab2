#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
    protected:
        int ID;
        char nombre[30];
        char apellido[30];
        char telefono[40];
        bool estado;
    public:
        /// CONSTRUCTOR
        Persona();
        /// METODOS
        void cargar(int);
        void mostrar();
        /// SETS
        void setIDPersona(int);
        void setNombre(const char *);
        void setApellido(const char *);
        void setTelefono(const char *);
        void setEstado(bool e);
        /// GETS
        int getIDPersona();
        const char *getNombre();
        const char *getApellido();
        const char *getTelefono();
        bool getEstado();
        /// DESTRUCTOR
        ~Persona();
};

#endif // PERSONA_H
