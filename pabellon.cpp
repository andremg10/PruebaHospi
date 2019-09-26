/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pabellon.cpp
 * Author: andre
 *
 * Created on 4 de septiembre de 2019, 07:44 PM
 */

#include <cstdlib>
#include "pabellon.h"



pabellon::pabellon() {

}

pabellon::pabellon(char letra, char genero)
: genero(genero), letra(letra)
{
    camaPabellon = new arregloCamas();
}

pabellon::~pabellon() {
    delete camaPabellon;
}

arregloCamas* pabellon::obtenerCamaPabellon() {
    return camaPabellon;
}

void pabellon::agregarCamaPabellon(cama* c){
    camaPabellon->agregarCama(c);
}

char pabellon::obtenerLetra() {
    return letra;
}

char pabellon::obtenerGenero() {
    return genero;
}

//
//arregloCamas* pabellon::obtenerCamaPabellon() {
//    return camaPabellon;
//}
//
//arregloCamas* pabellon::agregarCamaPabellon(cama* c){
//    camaPabellon->agregarCama(c);
//}

        
string pabellon::toString() const{
    stringstream s;
    s<<"Letra: "<<letra<<endl;
    s<<"Genero: "<<genero<<endl;
    return s.str();
    
}
