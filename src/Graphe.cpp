#include "Graphe.hpp"

#include "Sommet.hpp"
#include "Arete.hpp"

#include <algorithm>

Graphe::Graphe(list<Sommet> ls, list<Arete> la){
    std::transform(
    ls.begin(), ls.end(),
    std::back_inserter(sommets), 
    [](Sommet &p) { return &p; });
    
    std::transform(
    la.begin(), la.end(),
    std::back_inserter(aretes), 
    [](Arete &p) { return &p; });
}

void Graphe::ajoute_sommet(Sommet s){
    sommets.push_back(&s); // ajoute à la fin
}

void Graphe::ajoute_sommet(string etiquette){
    sommets.push_back(new Sommet(etiquette));
}
void Graphe::ajoute_arete(Arete a){
    aretes.push_back(&a);
}
void Graphe::ajoute_arete(Sommet s1, Sommet s2, int poids){
    aretes.push_back(new Arete(s1,s2,poids));
}
void Graphe::ajoute_arete(string etiquette1, string etiquette2, int poids){
    aretes.push_back(new Arete(etiquette1,etiquette2,poids));
}

list<Sommet> Graphe::getSommets(){
    list<Sommet> ls;
    std::transform(
    sommets.begin(), sommets.end(),
    std::back_inserter(ls), 
    [](Sommet* p) { return *p; });
    
    return ls;
}

list<Arete> Graphe::getAretes(){
    list<Arete> la;
    std::transform(
    aretes.begin(), aretes.end(),
    std::back_inserter(la), 
    [](Arete* p) { return *p; });
    
    return la;
}

/*
int Graphe::poids(){
    int cpt = 0;
    for(list<Arete>::iterator it = aretes.begin(); it != aretes.end(); it++){
		cpt+= it->getPoids();
	}
    return cpt;
}*/
void Graphe::symetrise(){
    // TODO
}
void Graphe::kruskal(){
    // TODO 
} 

std::ostream& operator<< (std::ostream &out, Graphe &graphe)
{

    out << "graphe" ; 
    return out;
}