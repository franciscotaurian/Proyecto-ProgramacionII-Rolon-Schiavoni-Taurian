#ifndef CLIENTES_H
#define CLIENTES_H

#include <iostream>
#include "transacciones.h"
#include "tarjeta.h"
using namespace std;

class Clientes{

    private:
    int numcliente;
    char nombre[20];
    char apellido[20];
    int dni;
    string tipocliente;
    int anioingreso;
    string estado;
    Transacciones trans_clientes[100];
    Tarjeta tipotarjeta;
    int caja_pesos;
    int caja_dolar;

    public:
    Clientes();
    Clientes(int, int, int, char[], char[]);
        void setNcliente(int);
        void setNombre(char[]);
        void setApellido(char[]);
        void setDni(int);
        void setAnioingreso(int);
        void setCaja_pesos(int);
        void setCaja_dolar(int);
        void setEstado(string);
        void setTipocliente(string);
        int getNumCliente();
        char *getNombre();
        char *getApellido();
        int getDni();
        int getAnioingreso();
        int getCaja_pesos();
        int getCaja_dolar();
        string getEstado();
        string getTipocliente();
        Transacciones *gettransacciones();
        void consultar_saldo();
        void hacer_transaccion();
        void pedir_baja();
};

#endif




