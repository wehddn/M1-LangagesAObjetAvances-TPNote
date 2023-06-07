#ifndef GARBAGECOLLECTOR
#define GARBAGECOLLECTOR

#include "Sommet.hpp"
#include "Arete.hpp"

#include <map>
#include <set>
using namespace std;

class GarbageCollector{
    private:
        static set<Sommet*> sommets;
        static set<Arete*> aretes;
    public:
        GarbageCollector();
        ~GarbageCollector();
        static void create(Sommet* s);
        static void create(Arete* a);
        static void del(Sommet* s);
        static void del(Arete* a);
        static void testShow(){
            cout << "sommets : " << sommets.size() << "; aretes : " << aretes.size() << "\n";
        }
};

#endif