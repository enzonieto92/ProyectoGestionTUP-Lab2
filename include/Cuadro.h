#ifndef CUADRO_H
#define CUADRO_H
#include "funciones.h"
class Cuadro
{


    private:
        origen coor;
        int largo;
        int alto;
    public:
        Cuadro(origen, int, int);
        void linea_hor();
        void linea_ver();
        void esquina_inf();
        void esquina_sup();
        void div();
        void texto(origen &origen, int &opc);
        void dibujar();
        void mostrar_texto();
        void resaltar(int&);
};

#endif // CUADRO_H
