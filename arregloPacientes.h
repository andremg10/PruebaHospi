/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloPacientes.h
 * Author: andre
 *
 * Created on 6 de septiembre de 2019, 12:39 AM
 */

#ifndef ARREGLOPACIENTES_H
#define ARREGLOPACIENTES_H

#include <sstream>
#include "paciente.h"


class arregloPacientes{
private:
    paciente** vector;
    int tamano, cantidad;
public:
    arregloPacientes();
    virtual ~arregloPacientes();
    virtual void agregarPaciente(paciente*);
    virtual void eliminarPaciente(int);
    virtual paciente** obtenerVector();
    virtual paciente* buscarPaciente(int);
    virtual string toString() const;

    
};
#endif /* ARREGLOPACIENTES_H */

