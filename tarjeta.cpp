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

int Tarjeta::getLimiteCredito() {
    return limiteCredito;
}

