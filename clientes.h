#ifndef CLIENTES_H
#define CLIENTES_H

#include "persona.h"
#include <iostream>
#include "transacciones.h"
#include "tarjeta.h"
using namespace std;

class Clientes:public Persona{

    private:
    int numcliente;
    string tipocliente;
    int anioingreso;
    string estado;
    Transacciones trans_clientes[100];
    Tarjeta tipotarjeta;
    int caja_pesos;
    int caja_dolar;
    int num_transacciones;

    public:
    Clientes();
    Clientes(int, int, int, char[], char[]);
        void setNcliente(int);
        void setAnioingreso(int);
        void setCaja_pesos(int);
        void setCaja_dolar(int);
        void setEstado(string);
        void setTipocliente(string);
        int getNumCliente();
        int getAnioingreso();
        int getCaja_pesos();
        int getCaja_dolar();
        string getEstado();
        string getTipocliente();
        Transacciones *gettransacciones();
        void consultar_saldo();
        void agregarTransaccion(Transacciones*);
        void pedir_baja();
};

#endif




