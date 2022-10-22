#include "Arete.hpp"

Arete::Arete(string s1,string s2,int p):sommet1{s1}, sommet2{s2}, poids{p} {}
Arete::Arete(Sommet s1,Sommet s2,int p):sommet1{s1}, sommet2{s2}, poids{p} {}

Sommet Arete::getS1(){
    return sommet1;
}

Sommet Arete::getS2(){
    return sommet2;
}

int Arete::getPoids(){
    return poids;
}