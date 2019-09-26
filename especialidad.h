/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   especialidad.h
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 06:10 PM
 */

#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
 
#include <sstream>
#include <iostream>


using namespace std;

class especialidad{
private:
    string nombre;
public:
    especialidad();
    especialidad(string);
    virtual ~especialidad();
    string obtenerNombre();
    virtual string toString();
    
}; 


#endif /* ESPECIALIDAD_H */

