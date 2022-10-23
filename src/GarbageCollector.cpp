#include "GarbageCollector.hpp"

#include "Sommet.hpp"
#include "Arete.hpp"

map<string, Sommet*> GarbageCollector::sommets;
set<Arete*, APtrComp> GarbageCollector::aretes;

void GarbageCollector::create(Sommet* & s){
    pair<map<string,Sommet*>::iterator,bool> ret;
    ret = sommets.insert({s->getEtiquette(), s});
    if(!ret.second){
        s=sommets.at(ret.first->second->getEtiquette());
    }
} 

void GarbageCollector::create(Arete* & a){
    pair<set<Arete*>::iterator,bool> ret;
    ret = aretes.insert(a);
    if (!ret.second){
        auto elem = *ret.first;
        a = elem;
    }
} 