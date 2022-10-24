#include "GarbageCollector.hpp"

#include "Sommet.hpp"
#include "Arete.hpp"

set<Sommet*> GarbageCollector::sommets;
set<Arete*> GarbageCollector::aretes;

void GarbageCollector::create(Sommet* s){
    sommets.insert(s);
} 

void GarbageCollector::create(Arete* a){
    aretes.insert(a);
} 

void GarbageCollector::del(Sommet* s){
    sommets.erase(s);
}

void GarbageCollector::del(Arete* a){
    aretes.erase(a);
} 