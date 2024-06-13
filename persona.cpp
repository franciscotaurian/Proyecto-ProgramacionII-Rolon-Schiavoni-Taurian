#include "persona.h"
#include <iostream>
#include <cstring>
using namespace std;

Persona::Persona(){

};

Persona::Persona(char nom[], char ap[],int d){
   dni= d;
   strcpy(nombre, nom); // copia el contenido de nom en nombre
   strcpy(apellido, ap);  // copia el contenido de ap en apellido
}

void Persona::setNombre(char nom[]) {
    strcpy(nombre,nom);
}

void Persona::setApellido(char ap[]) {
    strcpy(apellido, ap);
}


void Persona::setDni(int d) {
    dni = d;
}

char *Persona::getNombre() {
    char *p= new char[20];
    strcpy(p, nombre);
    return p;
}


char *Persona::getApellido() {
    char *p= new char[20];
    strcpy(p, apellido);
    return p;
}

int Persona::getDni() {
    return dni;
}