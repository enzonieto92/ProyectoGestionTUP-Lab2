#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio
{
    private:
        int precio{};
        char descripcion[30]{};

    public:
        /// CONSTRUCTOR
        Servicio();
        /// METODOS
        void limpiarEspacios(int, int);
        void cargar(int, int);
        bool mostrar(int, int);
        /// SETS
        void setPrecio(int);
        void setPrecio(const char *);
        void setDescripcion(const char *);
        void setServicio(Servicio);
        /// GETS
        int getCodigo();
        int getPrecio();
        const char *getDescripcion();
        bool getEstado();
        void operator =(Servicio);
        bool operator ==(Servicio);
};

#endif // SERVICIO_H
