#ifndef GRAPHE
#define GRAPHE

#include "Sommet.hpp"
#include "Arete.hpp"

#include <list>
using namespace std;

class Graphe{
    private:
        list<Sommet*> sommets;
        list<Arete*> aretes;
    public:
        Graphe(list<Sommet> ls, list<Arete> la);
        void ajoute_sommet(Sommet s);
        void ajoute_sommet(string etiquette);
        void ajoute_arete(Arete a);
        void ajoute_arete(Sommet s1, Sommet s2, int poids);
        void ajoute_arete(string etiquette1, string etiquette2, int poids);
        list<Sommet> getSommets();
        list<Arete> getAretes();
        int poids();
        void symetrise();
        void kruskal(); // TODO à la fin
        // Graphe(Graphe g);
};

std::ostream& operator<< (std::ostream &out, Graphe &Graphe);


#endif