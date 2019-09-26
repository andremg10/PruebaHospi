/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   especialidad.cpp
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 09:16 PM
 */

#include <cstdlib>

#include "especialidad.h"


especialidad::especialidad() {

}

especialidad::especialidad(string nombre)
: nombre(nombre){
}

string especialidad::obtenerNombre() {
    return nombre;
}



string especialidad::toString(){
    stringstream s;
    s<<nombre<<endl;
    return s.str();
    
}

especialidad::~especialidad() {
}


