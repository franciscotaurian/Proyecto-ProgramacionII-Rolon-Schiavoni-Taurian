#ifndef CLIENTES_H // Si no esta definida la clase clientes.h
#define CLIENTES_H // Definir la clase clientes.h

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
        void setTipotarjeta(Tarjeta);
        int getNumCliente();
        int getAnioingreso();
        int getCaja_pesos();
        int getCaja_dolar();
        string getEstado();
        string getTipocliente();
        Tarjeta getTipotarjeta();
        void consultar_saldo();
};

#endif // CLIENTES_H




