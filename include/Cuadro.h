#ifndef CUADRO_H
#define CUADRO_H
#include "Texto.h"

class Cuadro
{
    private:
        Origen coor;
        Texto _txt;
        int largo;
        int alto;
        int opc;
    public:
        Cuadro();
        Cuadro(Origen, int, int, int&);
        void setalto(int);
        void setlargo(int);
        void setCoor(Origen);
        void linea_hor();
        void linea_ver();
        void linea_ver(int);
        void linea_punteada_ver(int);
        void esquina_inf();
        void esquina_sup();
        void div();
        void dibujar();
        void dibujarLista();
        void mostrar_texto1();
        void mostrar_texto2();
        void mostrar_texto3();
        void mostrar_texto4();
        void mostrar_texto5();
        void mostrar_texto6();
        void Resaltar1();
        void Resaltar2();
        void Resaltar3();
        void Resaltar4();
        void Resaltar5();
        void Resaltar6();
        void setOpc(int&);
};

#endif // CUADRO_H
