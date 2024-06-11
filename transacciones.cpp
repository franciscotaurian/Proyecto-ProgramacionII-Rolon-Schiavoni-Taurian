#include <iostream>
#include "transacciones.h"
using namespace std;

Transacciones::Transacciones() {

}

Transacciones::Transacciones(int nt, int t, int d, int m, int a){

 num_trans = nt;
 tipo= t;
 dia= d;
 mes= m;
 anio= a;

}


void Transacciones::setNumtrans(int nt) {
    num_trans = nt;
}

void Transacciones::setTipo(int t) {
    tipo = t;
}

void Transacciones::setDia(int d) {
    dia = d;
}

void Transacciones::setMes(int m) {
    mes = m;
}

void Transacciones::setAnio(int a) {
    anio = a;
}


int Transacciones::getNumtrans() {
    return num_trans;
}

int Transacciones::getTipo() {
    return tipo;
}

int Transacciones::getDia() {
    return dia;
}

int Transacciones::getMes() {
    return mes;
}

int Transacciones::getAnio() {
    return anio;
}