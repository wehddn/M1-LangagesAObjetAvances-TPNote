#ifndef GRAPHE
#define GRAPHE

#include "Sommet.hpp"
#include "Arete.hpp"

#include <vector>
using namespace std;

class Graphe{
    private:
        vector<Sommet*> sommets;
        vector<Arete*> aretes;
    public:
        Graphe(vector<Sommet>& ls, vector<Arete>& la);
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