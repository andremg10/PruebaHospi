/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloPacientes.cpp
 * Author: andre
 *
 * Created on 9 de septiembre de 2019, 07:39 PM
 */

#include <cstdlib>

#include "arregloPacientes.h"


arregloPacientes::arregloPacientes()
:tamano(200),cantidad(0),vector(new paciente*[200]) {
    for(int i =0; i<tamano; i++){
        vector[i] = NULL;
    }
}

paciente** arregloPacientes::obtenerVector() {
    return vector;
}


void arregloPacientes::agregarPaciente(paciente* p){
    vector[cantidad++] = p;
}

void arregloPacientes::eliminarPaciente(int pos){
    for (int i=pos; i<cantidad-1; i++){
        vector[i]=vector[i+1];
    }
    cantidad--;
}

paciente* arregloPacientes::buscarPaciente(int pos){
    for(int i=0; i<cantidad; i++){
        if(i == pos){
            return vector[i];
        }
    }
}

string arregloPacientes::toString() const{
    stringstream s;
    for (int i=0; i<cantidad; i++){
        s<<vector[i]->toString()<<endl;
    }
    
    return s.str();
}

arregloPacientes::~arregloPacientes() {
    for (int i=0; i<tamano; i++){
        delete vector[i];
    }
    delete [] vector;
}


