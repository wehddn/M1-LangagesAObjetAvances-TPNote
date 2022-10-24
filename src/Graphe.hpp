#ifndef GRAPHE
#define GRAPHE

#include "Sommet.hpp"
#include "Arete.hpp"

#include <vector>
#include <set>
using namespace std;

struct SommetComp
{
  bool operator()(Sommet* lhs, Sommet* rhs) const  { 
    return lhs->getEtiquette()<rhs->getEtiquette();
  }
};

class Graphe{
    private:
        set<Sommet*, SommetComp> sommets;
        set<Arete*> aretes;
        void insert_arete(Arete *sa);
    public:
        Graphe(vector<Sommet*>& ls, vector<Arete*>& la);
        Graphe(const Graphe& g);
        void ajoute_sommet(Sommet& s);
        void ajoute_sommet(string etiquette);
        void ajoute_arete(Arete& a);
        void ajoute_arete(Sommet s1, Sommet s2, int poids);
        void ajoute_arete(string etiquette1, string etiquette2, int poids);
        vector<Sommet> getSommets();
        vector<Arete> getAretes();
        int poids();
        void symetrise();
        void kruskal(); // TODO à la fin
        // Graphe(Graphe g);
};

std::ostream& operator<< (std::ostream &out, Graphe &Graphe);


#endif