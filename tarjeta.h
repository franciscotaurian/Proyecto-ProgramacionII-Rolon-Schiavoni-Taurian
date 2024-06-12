#ifndef TARJETA_H
#define TARJETA_H

#include <iostream>
using namespace std;

class Tarjeta {

private:
    string tipotarjeta;
    int limiteCredito;

public:
    Tarjeta();
    Tarjeta(string, int);
    void setTipotarj(string);
    void setLimiteCredito(int);
    string getTipotarj();
    int getLimiteCredito();
    //void asignarTarjeta(Clientes&);
};

#endif