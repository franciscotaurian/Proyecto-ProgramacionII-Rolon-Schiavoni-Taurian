#include "tarjeta.h"

Tarjeta::Tarjeta(){

}

Tarjeta::Tarjeta(string _tipotarj, Clientes _cliente[], int _limite){
    
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

Clientes Tarjeta::getClientes() {
    Clientes* p = new Clientes[100];
    for (int i = 0; i < 100; i++) {
        p[i] = ctarjeta[i];
    }
    return p;

}

int Tarjeta::getLimiteCredito() {
    return limiteCredito;
}

void Tarjeta::asignarTarjeta(Clientes& cliente) {
    if (cliente.getTipocliente() == "Plata") {
        setTipotarj("No tiene acceso a tarjeta de crédito");
        setLimiteCredito(0);
    } else if (cliente.getTipocliente() == "Oro") {
        setTipotarj("Credix");
        setLimiteCredito(250000);
    } else if (cliente.getTipocliente() == "Platino") {
        setTipotarj("Premium");
        setLimiteCredito(500000);
    }
    setClientes(cliente);
}
