/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cama.h
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 06:11 PM
 */

#ifndef CAMA_H
#define CAMA_H

class pabellon;

#include "arregloPacientes.h"
#include <iostream>
#include <sstream>

using namespace std;

class cama {
private:
    int numero;
    bool estado;
    arregloPacientes* pacienteCama;
    string codigo;
public:
    cama();
    cama(int); 
    virtual ~cama();
    virtual void codigoCama();
    virtual int obtenerNumero();
    virtual bool cambiarEstado();
    string estadoCama();
    virtual void agregarPacienteCama(paciente*);
    virtual string toString();
}; 

#endif /* CAMA_H */

