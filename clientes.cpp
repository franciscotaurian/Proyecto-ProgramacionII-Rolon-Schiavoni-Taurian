#include <iostream>
#include <cstring>
#include <fstream>
#include "persona.h"
#include "transacciones.h"
#include "clientes.h"
using namespace std;



Clientes::Clientes() {
   estado= "Alta";
   caja_pesos= 0;
   caja_dolar= 0;
   tipocliente="Plata";
}

Clientes::Clientes(int nc, int d, int ai, char nom[], char ap[]):Persona(nom,ap,d){
   tipocliente= "Plata";
   anioingreso= ai;
   estado= "Alta";
   caja_pesos= 0;
   caja_dolar= 0;
}

void Clientes::setNcliente(int ncliente){
    numcliente=ncliente;
}

void Clientes::setTipotarjeta(Tarjeta tarj){
    tipotarjeta=tarj;
}

void Clientes::setAnioingreso(int ai) {
    anioingreso = ai;
}

void Clientes::setCaja_pesos(int cp) {
    caja_pesos = cp;
}

void Clientes::setCaja_dolar(int cd) {
    caja_dolar = cd;
}

void Clientes::setEstado(string e) {
    estado = e;
}

void Clientes::setTipocliente(string tc) {
    tipocliente = tc;
}

int Clientes::getNumCliente(){
    return numcliente;
}


int Clientes::getAnioingreso() {
    return anioingreso;
}

int Clientes::getCaja_pesos() {
    return caja_pesos;
}

int Clientes::getCaja_dolar() {
    return caja_dolar;
}

string Clientes::getEstado() {
    return estado;
}

string Clientes::getTipocliente() {
    return tipocliente;
}

Transacciones Clientes::gettransacciones() {
    return transaccion_cliente;
}

Tarjeta Clientes::getTipotarjeta(){
    return tipotarjeta;
}

void Clientes::consultar_saldo() {
    cout << "Saldo en la caja del cliente " << numcliente << " en pesos: " << caja_pesos << endl;
    cout << "Saldo en la caja del cliente " << numcliente << " en dolares: " << caja_dolar << endl;
}


