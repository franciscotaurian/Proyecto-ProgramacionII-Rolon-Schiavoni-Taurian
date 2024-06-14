#include <iostream>
#include <cstring>
#include <fstream>
#include "transacciones.h"
using namespace std;

Transacciones::Transacciones() {

}

Transacciones::Transacciones(int nc, int t, int d, int m, int a, int mo){

 num_cliente = nc;
 tipo= t;
 dia= d;
 mes= m;
 anio= a;

}

void Transacciones::setNum_cliente(int nc) {
    num_cliente = nc;
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

void Transacciones::setMonto(int mo) {
    monto = mo;
}

int Transacciones::getNum_cliente() {
    return num_cliente;
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

int Transacciones::getMonto() {
    return monto;
}