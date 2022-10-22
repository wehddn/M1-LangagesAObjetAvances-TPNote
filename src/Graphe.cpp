#include "Graphe.hpp"

#include "Sommet.hpp"
#include "Arete.hpp"

#include <algorithm>

Graphe::Graphe(vector<Sommet>& vs, vector<Arete>& va){
    for(auto &s : vs ){;
        sommets.push_back(&s);
    }
    
    for(auto &a : va ){;
        aretes.push_back(&a);
    }
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

vector<Sommet> Graphe::getSommets(){
    vector<Sommet> vs;
    std::transform(
    sommets.begin(), sommets.end(),
    std::back_inserter(vs), 
    [](Sommet* p) { return *p; });
    
    return vs;
}

vector<Arete> Graphe::getAretes(){
    vector<Arete> la;
    std::transform(
    aretes.begin(), aretes.end(),
    std::back_inserter(la), 
    [](Arete* p) { return *p; });
    
    return la;
}

/*
int Graphe::poids(){
    int cpt = 0;
    for(vector<Arete>::iterator it = aretes.begin(); it != aretes.end(); it++){
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
    string s_str, a_str;
    for(auto &s : graphe.getSommets() ){
        s_str = s_str + s.getEtiquette() + " ";
    }
    for(auto &a : graphe.getAretes() ){;
        a_str = a_str + a.getS1().getEtiquette() + " - " + a.getS2().getEtiquette() + ", " + to_string(a.getPoids()); 
    }

    out << s_str << "\n" << a_str; 
    return out;
}