/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloPabellones.cpp
 * Author: andre
 *
 * Created on 5 de septiembre de 2019, 05:27 PM
 */

#include <cstdlib>

using namespace std;

#include "arregloPabellones.h"


arregloPabellones::arregloPabellones()
:tamano(10),cantidad(0){
    vector = new pabellon*[10];
    for(int i =0; i<tamano; i++){
        vector[i] = NULL;
    }
}


pabellon** arregloPabellones::obtenerVector() {
    return vector;
}



void arregloPabellones::agregarPabellon(pabellon* pb){
    vector[cantidad++] = pb;
}

pabellon* arregloPabellones::camaDisponible(char genero){
    for(int i=0; i<cantidad; i++){
        if(genero == vector[i]->obtenerGenero()){
            return vector[i];
        }
    }
}


string arregloPabellones::toString() const{
    stringstream s;
    for (int i=0; i<cantidad; i++){
        s<<i+1<<" "<<vector[i]->toString()<<endl;
    }
    
    return s.str();
}

arregloPabellones::~arregloPabellones() {
    for (int i=0; i<tamano; i++){
        delete vector[i];
    }
    delete [] vector;
}






