#ifndef TARJETA_H // Si no esta definida la clase tarjeta.h
#define TARJETA_H // Definir la clase tarjeta.h

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
};

#endif