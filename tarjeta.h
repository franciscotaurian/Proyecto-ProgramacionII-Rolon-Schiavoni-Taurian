#include <iostream>
#include "clientes.h"
using namespace std;

class Tarjeta {

private:
    string tipotarjeta;
    Clientes ctarjeta[100];
    int limiteCredito;

public:
    Tarjeta();
    Tarjeta(string, Clientes[], int);
    void setTipotarj(string);
    void setClientes(Clientes);
    void setLimiteCredito(int);
    string getTipotarj();
    Clientes getClientes();
    int getLimiteCredito();
    void asignarTarjeta(Clientes&);
};