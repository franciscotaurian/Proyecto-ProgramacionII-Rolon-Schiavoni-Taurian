#ifndef TRANSACCIONES_H // Si no esta definida la clase transacciones.h
#define TRANSACCIONES_H // Definir la clase transacciones.h

#include <iostream>
using namespace std;

class Transacciones{
    
    private: 
        //int num_trans;
        int num_cliente;
        int tipo;
        int dia;
        int mes;
        int anio;
        int monto;

    public:
        Transacciones();
        Transacciones(int, int, int, int, int,int);
        void setNum_cliente(int);
        void setTipo(int);
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        void setMonto(int);
        int getNum_cliente();
        int getTipo();
        int getDia();
        int getMes();
        int getAnio();
        int getMonto();
        void muestraTrasacciones();
};

#endif