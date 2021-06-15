#include <iostream>
#include<sstream>
#include "ClassA.h"
#include<fstream>

using namespace std;

ClassA::ClassA(){
    for(int i = 0; i<4; i++){
        this->arreglo[i]=i;
    }
}

ClassA::ClassA(string lectura){
    int i = 0;
    int j = 0;
    string fragmento = "";
    string frag = "";
    //Para el entero
    while(lectura[i] != '|')
        fragmento[j++] = lectura[i++];
    i++;
    entero = atoi(fragmento.c_str());

    //Para el string
    j = 0;
    while(lectura[i] != '|')
        cadena += lectura[i++];
    i++;


    //Para el arreglo
    for(int k = 0; k < 3; k++){
        j = 0;
        while(lectura[i] != '|')
            frag[j++] = lectura[i++];
        i++;
        arreglo[k] = atoi(frag.c_str());
    }
    j = 0;
    while(i != lectura.length())
        frag[j++] = lectura[i++];
    arreglo[3] = atoi(frag.c_str());
}

ClassA::ClassA(int entero, string cadena, int arreglo[4]){
    this->entero = entero;
    this->cadena = cadena;
    this->arreglo[4] = arreglo[4];
}

void ClassA::setCad(string cad){
    cadena = cad;
}

void ClassA::setEntero(int key){
    entero = key;
}

int ClassA::getEntero(){
    return entero;
}

string ClassA::getCadena(){
    return cadena;
}

string ClassA::tostring(){
    stringstream ss;

    ss<< "ENTERO: "<<entero<<", "<<" CADENA: "<<cadena<<", ";
        ss<<" ARREGLO: [";
    for(int i=0; i<3; i++){
        ss << arreglo[i]<<", ";
    }
    ss <<arreglo[3]<<"]";
    return ss.str();
}

string ClassA::toFile(){

    stringstream ss;
    ss<<entero<< "|" <<cadena;
    for(int i=0; i<4; i++)
        ss<<"|"<<arreglo[i];
    return ss.str();
}


