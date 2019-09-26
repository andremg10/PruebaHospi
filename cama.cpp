/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cama.cpp
 * Author: andre
 *
 * Created on 4 de septiembre de 2019, 02:34 PM
 */

#include <cstdlib>
#include <string>
#include "cama.h"
#include "pabellon.h"

using namespace std;

cama::cama() {

}

cama::cama(int numero)
:numero(numero), estado(false){
    
    pacienteCama = new arregloPacientes();
}



bool cama::cambiarEstado() {
    return true;
}

string cama::estadoCama() {
    if (estado==true){
        return "Ocupado";
    } else 
        return "Disponible";
}

void cama::codigoCama() {
    pabellon* pb;
    codigo=pb->obtenerLetra()+numero;
}

int cama::obtenerNumero() {
    return numero;
}


void cama::agregarPacienteCama(paciente* p){
    pacienteCama->agregarPaciente(p);
}


        
string cama::toString() {
    stringstream s;
    s<<"Numero "<<numero<<endl;
    s<<"Estado "<<this->estadoCama()<<endl;
    return s.str();
    
}

cama::~cama() {
}
