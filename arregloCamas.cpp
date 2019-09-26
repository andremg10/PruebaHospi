/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloCamas.cpp
 * Author: andre
 *
 * Created on 4 de septiembre de 2019, 07:34 PM
 */

#include <cstdlib>

#include "arregloCamas.h"


arregloCamas::arregloCamas()
:tamano(20),cantidad(0),vector(new cama*[20]) {
    for(int i =0; i<tamano; i++){
        vector[i] = NULL;
    }
}

cama** arregloCamas::obtenerVector() {
    return vector;
}

void arregloCamas::agregarCama(cama* c){
    vector[cantidad++] = c;
}

void arregloCamas::eliminarCama(int pos){
    for (int i=pos; i<cantidad-1; i++){
        vector[i]=vector[i+1];
    }
    cantidad--;
}

cama* arregloCamas::buscarCama(int pos){
    for(int i=0; i<cantidad; i++){
        if(i == pos){
            return vector[i];
        }
    }
}

string arregloCamas::toString() const{
    stringstream s;
    for (int i=0; i<cantidad; i++){
        s<<i+1<<vector[i]->toString()<<endl;
    }
    
    return s.str();
}

arregloCamas::~arregloCamas() {
    for (int i=0; i<tamano; i++){
        delete vector[i];
    }
    delete [] vector;
}

