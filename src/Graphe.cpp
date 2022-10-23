#include "Graphe.hpp"

#include "Sommet.hpp"
#include "Arete.hpp"
#include "GarbageCollector.hpp"

#include <algorithm>

Graphe::Graphe(vector<Sommet>& vs, vector<Arete>& va){
    for(auto &s : vs ){
        Sommet* sp = &s;
        GarbageCollector::create(sp);
        sommets.insert(sp);
    }

    
    for(auto &a : va ){
        Arete* sa = &a;
        GarbageCollector::create(sa);
        aretes.insert(sa);
    }
}

void Graphe::ajoute_sommet(Sommet& s){
    Sommet* sp = &s;
    GarbageCollector::create(sp);
    sommets.insert(sp); // ajoute à la fin
}

void Graphe::ajoute_sommet(string etiquette){
    Sommet* sp = new Sommet(etiquette);
    GarbageCollector::create(sp);
    sommets.insert(sp);
}
void Graphe::ajoute_arete(Arete& a){
    Arete* sa = &a;
    GarbageCollector::create(sa);
    aretes.insert(sa);
}
void Graphe::ajoute_arete(Sommet s1, Sommet s2, int poids){
    Arete* sa = new Arete(s1,s2,poids);
    GarbageCollector::create(sa);
    aretes.insert(sa);
}
void Graphe::ajoute_arete(string etiquette1, string etiquette2, int poids){
    Arete* sa = new Arete(etiquette1,etiquette2,poids);
    GarbageCollector::create(sa);
    aretes.insert(sa);
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

int Graphe::poids(){
    int cpt = 0;
    for(set<Arete*>::iterator it = aretes.begin(); it != aretes.end(); it++){
		cpt+= (*it)->getPoids();
	}
    return cpt;
}

// à régler segmentation fault quand il y a plus d'une arete dans le graphe.
void Graphe::symetrise(){
    /*
    for(auto &it : aretes ){
        cout << "ici" << "\n";
        Sommet s1 = (*it).getS1();
        Sommet s2 = (*it).getS2();
        int poids = (*it).getPoids();
        bool flag = false;
        for(auto &it2 : aretes){
            cout << "cc" << "\n";
            Sommet ss1 = (*it2).getS1();
            Sommet ss2 = (*it2).getS2();
            int poids2 = (*it2).getPoids();
            if(s1 == ss2 and s2 == ss1 and poids == poids2){
                cout << s1 << " " << ss2 << " " << s2 << " " << ss1 << "\n";
                flag = true;
            }
            
        }
        if(!flag){
            cout << "ajoute" << "\n";
            Arete ar{s2.getEtiquette(),s1.getEtiquette(),poids};
            this->ajoute_arete(ar);
        }
        
    }   
    */
   set<Arete*> newAretes = aretes;
   for(auto &it : newAretes){
        Sommet s1 = (*it).getS1();
        cout << s1 << "\n";
        Sommet s2 = (*it).getS2();
        cout << s2 << "\n";
        int poids = (*it).getPoids();
        cout << poids << "\n";
        Arete sym{s2,s1,poids};
        cout << sym << "\n";
        this->ajoute_arete(sym);
        cout << "test final \n";
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
    for(auto &a : graphe.getAretes() ){;
        a_str = a_str + a.getS1().getEtiquette() + " - " + a.getS2().getEtiquette() + ", " + to_string(a.getPoids()) + "; "; 
    }
    out << s_str << "\n" << a_str; 
    return out;
}