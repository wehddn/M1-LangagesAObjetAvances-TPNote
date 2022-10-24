#include "Graphe.hpp"

#include "Sommet.hpp"
#include "Arete.hpp"
#include "GarbageCollector.hpp"

#include <algorithm>

Graphe::Graphe(vector<Sommet*>& vs, vector<Arete*>& va){
    for(auto &s : vs ){
        sommets.insert(s);
    }

    for(auto &a : va ){
        aretes.insert(a);
    }
}

Graphe::Graphe(const Graphe& g){
    *this = g;
}

void Graphe::ajoute_sommet(Sommet& s){
    Sommet* sp = &s;
    sommets.insert(sp);
}

void Graphe::ajoute_sommet(string etiquette){
    Sommet* sp = new Sommet(etiquette);
    GarbageCollector::create(sp);
    sommets.insert(sp);
}
void Graphe::ajoute_arete(Arete& a){
    Arete* sa = &a;
    insert_arete(sa);
}
void Graphe::ajoute_arete(Sommet s1, Sommet s2, int poids){
    Arete* sa = new Arete(s1,s2,poids);
    GarbageCollector::create(sa);
    insert_arete(sa);
}
void Graphe::ajoute_arete(string etiquette1, string etiquette2, int poids){
    Arete* sa = new Arete(etiquette1,etiquette2,poids);
    GarbageCollector::create(sa);
    insert_arete(sa);
}

void Graphe::insert_arete(Arete *sa){
    aretes.insert(sa);
    sommets.insert(sa->getS1());
    sommets.insert(sa->getS2());
}

vector<Sommet> Graphe::getSommets(){
    vector<Sommet> vs;
    for(auto &s : sommets ){
        vs.push_back(*s);
    }
    return vs;
}

vector<Arete> Graphe::getAretes(){
    vector<Arete> la;
    for(auto &a : aretes ){
        la.push_back(*a);
    }
    return la;
}

int Graphe::poids(){
    int cpt = 0;
    for(set<Arete*>::iterator it = aretes.begin(); it != aretes.end(); it++){
		cpt+= (*it)->getPoids();
	}
    return cpt;
}

void Graphe::symetrise(){
    set<Arete*> newAretes = aretes;
    for(auto &it : newAretes ){
        Sommet *s1 = (*it).getS1();
        Sommet *s2 = (*it).getS2();
        int poids = (*it).getPoids();
        bool flag = false;
        for(auto &it2 : newAretes){
            Sommet *ss1 = (*it2).getS1();
            Sommet *ss2 = (*it2).getS2();
            int poids2 = (*it2).getPoids();
            if(*s1 == *ss2 and *s2 == *ss1 and poids == poids2){
                flag = true;
            }
        }
        if(!flag){
            Arete *ar = new Arete(s2->getEtiquette(),s1->getEtiquette(),poids);
            GarbageCollector::create(ar);
            this->ajoute_arete(*ar);
        }
    }   
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
    for(auto &a : graphe.getAretes() ){
        a_str = a_str + a.getS1()->getEtiquette() + " - " + a.getS2()->getEtiquette() + ", " + to_string(a.getPoids()) + "; "; 
    }
    out << s_str << "\n" << a_str; 
    return out;
}