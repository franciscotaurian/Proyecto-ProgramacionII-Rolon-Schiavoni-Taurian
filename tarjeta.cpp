#include "tarjeta.h"

Tarjeta::Tarjeta(){

}

Tarjeta::Tarjeta(string _tipotarj, int _limite){
    
    tipotarjeta = _tipotarj;
    limiteCredito = _limite;

}

void Tarjeta::setTipotarj(string tipotarj) {
    tipotarjeta = tipotarj;
}

void Tarjeta::setLimiteCredito(int limite) {
    limiteCredito = limite;
}

string Tarjeta::getTipotarj() {
    return tipotarjeta;
}
/*
Clientes *Tarjeta::getClientes() {
    Clientes *p = new Clientes[100];
    for (int i = 0; i < 100; i++) {
        p[i] = ctarjeta[i];
    }
    return p;

}
*/

int Tarjeta::getLimiteCredito() {
    return limiteCredito;
}

