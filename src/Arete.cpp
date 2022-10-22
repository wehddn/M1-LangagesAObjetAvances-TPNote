#include "Arete.hpp"

Arete::Arete(string s1,string s2,int p){
    sommet1 = new Sommet(s1);
    sommet2 = new Sommet(s2);
    poids = p;
}
Arete::Arete(Sommet& s1, Sommet& s2,int p){
    sommet1 = &s1;
    sommet2 = &s2;
    poids = p;
}

Sommet Arete::getS1(){
    return *sommet1;
}

Sommet Arete::getS2(){
    return *sommet2;
}

int Arete::getPoids(){
    return poids;
}

std::ostream& operator<< (std::ostream &out, Arete &arete)
{
    Sommet s1 = arete.getS1();
    Sommet s2 = arete.getS2();
    out << s1 << " - " << s2 << ", "<< arete.getPoids(); 
    return out;
}