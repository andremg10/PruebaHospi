/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloDoctores.cpp
 * Author: andre
 *
 * Created on 4 de septiembre de 2019, 01:27 PM
 */

#include <cstdlib>

#include "arregloDoctores.h"


arregloDoctores::arregloDoctores()
:tamano(20),cantidad(0),vector(new doctor*[20]) {
    for(int i=0; i<tamano; i++){
        vector[i] = NULL;
    }
}

doctor** arregloDoctores::obtenerVector() {
    return vector;
}


void arregloDoctores::agregarDoctor(doctor* d){
    vector[cantidad++] = d;
}

void arregloDoctores::eliminarDoctor(int pos){
    for (int i=pos; i<cantidad-1; i++){
          vector[i]=vector[i+1];
    }
    cantidad--;
}
      

doctor* arregloDoctores::buscarDoctor(int pos){
    for(int i=0; i<cantidad; i++){
        if(i == pos){
            return vector[i];
        }
    }
}

string arregloDoctores::toString() const{
    stringstream s;
    for (int i=0; i<cantidad; i++){
        s<<i+1<<vector[i]->toString()<<endl;
    }
    
    return s.str();
}

arregloDoctores::~arregloDoctores() {
    for (int i=0; i<tamano; i++){
        delete vector[i];
    }
    delete [] vector;
}

