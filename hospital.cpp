/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hospital.cpp
 * Author: andre
 *
 * Created on 9 de septiembre de 2019, 08:07 PM
 */

#include <cstdlib>

#include "hospital.h"

hospital::hospital(): pb(new arregloPabellones()), e(new arregloEspecialidades()), 
        d(new arregloDoctores()), c(new arregloCamas()), p(new arregloPacientes()){
}

hospital::~hospital() {
    delete e;
    delete pb;
    delete d;
    delete c;
    delete p;
}


void hospital::agregarEspecialidad(especialidad* esp){
    e->agregarEspecialidad(esp);
}

arregloEspecialidades* hospital::obtenerEspecialidades() {
    return e;
}


especialidad* hospital::buscarEspecialidad(int pos) {
    e->buscarEspecialidad(pos);
}

paciente* hospital::buscarPaciente(int pos) {
    p->buscarPaciente(pos);
}

void hospital::agregarPabellon(pabellon* pab){
    pb->agregarPabellon(pab);
}

arregloPabellones* hospital::obtenerPabellones() {
    return pb;
}

arregloPabellones* hospital::camaDisponible(char genero) {
    pb->camaDisponible(genero);
}

void hospital::agregarCama(cama* cam) {
    c->agregarCama(cam);
}

bool hospital::agregarCamaPabellon(cama* campab, int numeroPabellon){
    if(pb->obtenerVector()[numeroPabellon]!= NULL){
        pb->obtenerVector()[numeroPabellon]->agregarCamaPabellon(campab);
        return true;
    }else{
        cout<<"No existe ese pabellon"<<endl;
    }
    
    return false;
    
}

bool hospital::agregarPacienteDoctor(paciente* pac, int numeroDoctor){
    if(d->obtenerVector()[numeroDoctor]!= NULL){
        d->obtenerVector()[numeroDoctor]->agregarPacienteDoctor(pac);
        return true;
    }else{
        cout<<"No existe ese doctor"<<endl;
    }
    
    return false;
    
}

bool hospital::agregarPacienteCama(paciente* pac, int numeroCama){
    if(c->obtenerVector()[numeroCama]!= NULL){
        c->obtenerVector()[numeroCama]->agregarPacienteCama(pac);
        return true;
    }else{
        cout<<"No existe esa cama"<<endl;
    }
    
    return false;
    
}

void hospital::eliminarCama(int pos){
    c->eliminarCama(pos);
}

arregloCamas* hospital::obtenerCamas() {
    return c;
}

void hospital::agregarDoctor(doctor* doc){
    d->agregarDoctor(doc);
}

void hospital::eliminarDoctor(int pos){
    d->eliminarDoctor(pos);
}


arregloDoctores* hospital::obtenerDoctores() {
    return d;
}

arregloDoctores* hospital::buscarDoctor(int pos) {
    d->buscarDoctor(pos);
}

void hospital::agregarPaciente(paciente* pac){
    p->agregarPaciente(pac);
}

void hospital::eliminarPaciente(int pos){
    p->eliminarPaciente(pos);
}

arregloPacientes* hospital::obtenerPacientes() {
    return p;
}
