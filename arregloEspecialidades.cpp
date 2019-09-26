/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloEspecialidades.cpp
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 09:28 PM
 */

#include <cstdlib>

#include "arregloEspecialidades.h"


arregloEspecialidades::arregloEspecialidades()
:tamano(10),cantidad(0),vector(new especialidad*[10]) {
    for(int i=0; i<tamano; i++){
        vector[i] = NULL;
    }
}

void arregloEspecialidades::agregarEspecialidad(especialidad* e){
    vector[cantidad++] = e;
}

especialidad* arregloEspecialidades::buscarEspecialidad(int pos){
    for(int i=0; i<cantidad; i++){
        if(i == pos)
            return vector[i];
        
    }
}

string arregloEspecialidades::toString() const{
    stringstream s;
    for (int i=0; i<cantidad; i++){
        s<<"Especialidad "<<i+1<<":"<<vector[i]->toString()<<endl;
    }
    
    return s.str();
}

arregloEspecialidades::~arregloEspecialidades() {
    for (int i=0; i<tamano; i++){
        delete vector[i];
    }
    delete [] vector;
}



