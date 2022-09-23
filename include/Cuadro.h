#ifndef CUADRO_H
#define CUADRO_H
#include "Texto.h"
class Cuadro
{


    private:
        origen coor;
        Texto _txt;
        int largo;
        int alto;
        int opc;
    public:
        Cuadro(origen, int, int, int);
        void linea_hor();
        void linea_ver();
        void esquina_inf();
        void esquina_sup();
        void div();
        void dibujar();
        void mostrar_texto1();
        void Resaltar1();
};

#endif // CUADRO_H
