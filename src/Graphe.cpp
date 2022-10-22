#include "Graphe.hpp"

Graphe::Graphe(list<Sommet> ls,list<Arete> la):sommets{ls}, aretes{la} {}

void Graphe::ajoute_sommet(Sommet s){
    sommets.push_back(s); // ajoute à la fin
}

void Graphe::ajoute_sommet(string etiquette){
    sommets.push_back(Sommet(etiquette));
}
void Graphe::ajoute_arete(Arete a){
    aretes.push_back(a);
}
void Graphe::ajoute_arete(Sommet s1, Sommet s2, int poids){
    aretes.push_back(Arete(s1,s2,poids));
}
void Graphe::ajoute_arete(string etiquette1, string etiquette2, int poids){
    aretes.push_back(Arete(etiquette1,etiquette2,poids));
}
int Graphe::poids(){
    int cpt = 0;
    for(list<Arete>::iterator it = aretes.begin(); it != aretes.end(); it++){
		cpt+= it->getPoids();
	}
    return cpt;
}
void Graphe::symetrise(){
    // TODO
}
void Graphe::kruskal(){
    // TODO 
} 