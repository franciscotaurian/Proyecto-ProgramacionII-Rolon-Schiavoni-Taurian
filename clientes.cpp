#include <iostream>
#include <cstring>
#include <fstream>
#include "transacciones.h"
#include "clientes.h"
using namespace std;



Clientes::Clientes() {
   estado= "Alta";
   caja_pesos= 0;
   caja_dolar= 0;
   tipocliente="Plata";
}

Clientes::Clientes(int nc, int d, int ai, char nom[], char ap[]){
   numcliente= nc;
   dni= d;
   tipocliente= "Plata";
   anioingreso= ai;
   estado= "Alta";
   caja_pesos= 0;
   caja_dolar= 0;
   strcpy(nombre, nom);
   strcpy(apellido, ap);  

}

void Clientes::setNcliente(int ncliente){
    numcliente=ncliente;
}

void Clientes::setNombre(char nom[]) {
    strcpy(nombre,nom);
}

void Clientes::setApellido(char ap[]) {
    strcpy(apellido, ap);
}


void Clientes::setDni(int d) {
    dni = d;
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

char *Clientes::getNombre() {
    char *p= new char[20];
    strcpy(p, nombre);
    return p;
}


char *Clientes::getApellido() {
    char *p= new char[20];
    strcpy(p, apellido);
    return p;
}

int Clientes::getDni() {
    return dni;
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

Transacciones *Clientes::gettransacciones() {
    Transacciones* p = new Transacciones[100];
    for (int i = 0; i < 100; i++) {
        p[i] = trans_clientes[i];
    }
    return p;
}



void Clientes::consultar_saldo() {
    cout << "Saldo en la caja del cliente " << numcliente << " en pesos: " << caja_pesos << endl;
    cout << "Saldo en la caja del cliente " << numcliente << " en dolares: " << caja_dolar << endl;
}


