#include "Sommet.hpp"
#include "Arete.hpp"
#include <list>

class Graphe{
    private:
        list<Sommet> sommets;
        list<Arete> aretes;
    public:
        Graphe(list<Sommet> ls, list<Arete> la);
        // Graphe(Graphe g);
};

Graphe::Graphe(list<Sommet> ls,list<Arete> la):sommets{ls}, aretes{la} {}
