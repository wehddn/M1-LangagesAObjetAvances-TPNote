#include "Arete.hpp"
#include "GarbageCollector.hpp"

Arete::Arete(string s1,string s2,int p){
    sommet1 = new Sommet(s1);
    sommet2 = new Sommet(s2);
    poids = p;
}
Arete::Arete(Sommet& s1, Sommet& s2, int p){
    Sommet* sp1 = &s1; 
    Sommet* sp2 = &s2;
    GarbageCollector::create(sp1);
    GarbageCollector::create(sp2);
    sommet1 = sp1;
    sommet2 = sp2;
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
    out << arete.getS1().getEtiquette() << " - " << arete.getS2().getEtiquette() << ", "<< arete.getPoids(); 
    return out;
}