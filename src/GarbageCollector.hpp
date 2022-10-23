#ifndef GARBAGECOLLECTOR
#define GARBAGECOLLECTOR

#include "Sommet.hpp"
#include "Arete.hpp"

#include <map>
#include <set>
using namespace std;

struct APtrComp
{
  bool operator()(Arete* lhs, Arete* rhs) const  { 
    bool res;
    if(lhs->getS1().getEtiquette() < rhs->getS1().getEtiquette())
        return true;
    if(lhs->getS1().getEtiquette() > rhs->getS1().getEtiquette())
        return false;
    else{
        if(lhs->getS2().getEtiquette() < rhs->getS2().getEtiquette())
            return true;
        if(lhs->getS2().getEtiquette() > rhs->getS2().getEtiquette())
            return false;
        else{
            if(lhs->getPoids() < rhs->getPoids())
                return true;
            else 
                return false;
        }
    }

    return res; }
};

class GarbageCollector{
    private:
        static map<string, Sommet*> sommets;
        static set<Arete*, APtrComp> aretes;
        GarbageCollector();
    public:
        static void create(Sommet* & s);
        static void create(Arete* & s);
        static void test(){
            cout << "sommets : " << sommets.size() << "; aretes : " << aretes.size() << "\n";
        }
};

#endif