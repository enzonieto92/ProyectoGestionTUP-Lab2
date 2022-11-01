#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio
{
    private:
        int codigo;
        float precio;
        char descripcion[30];
        bool estado;
    public:
        /// CONSTRUCTOR
        Servicio();
        /// METODOS
        bool cargar(int);
        bool mostrar(int);
        /// SETS
        void setCodigo(int);
        bool setPrecio(float);
        void setDescripcion(const char *);
        void setEstado(bool);
        /// GETS
        int getCodigo();
        float getPrecio();
        const char *getDescripcion();
        bool getEstado();
};

#endif // SERVICIO_H
