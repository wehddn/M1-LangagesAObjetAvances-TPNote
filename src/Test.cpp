#include "GarbageCollector.hpp"
#include "Graphe.hpp"
#include "Sommet.hpp"
#include "Arete.hpp"

#include <cassert>
#include <string>
#include <sstream>

using namespace std;

/*
    TODO

opérateur <<

Graphe
    creation 
        à partir d’un ensemble de sommets et d’un ensemble d’arêtes
        à partir d’un graphe existant
    ajoute_sommet 
        à partir d'un sommet existant 
        à partir d'une étiquette
    ajoute_arete
        à partir d'une arête existante
        à partir de deux sommets existants et d'un poids
        à partir de deux étiquettes et d'un poids
    poids
    symetrise
    kruskal

Arête
    creation 
        à partir de deux étiquettes et d'un poids
        à partir de deux sommets et d’un poids
        à partir d’une arête
    2 sommets + poids;
    poids peut être modifié;
    Il peut y avoir plusieurs arêtes avec les mêmes sommets.

Sommet
    creation 
        à partir d’une étiquette
        à partir d’un sommet
    marquage pour Kruskal

garbage collector
    stocker des pointeurs sur des :
        sommets apres la construction d’une arête,
        arêtes apres la construction d’un graphe,
    supprimer des pointeurs apres la destruction 
*/

void test(string ms, string s1, string s2){
    string res;
    if(s1 == s2)
        res = "done";
    else 
        res = "error!";
    cout << ms << " : " << res << endl;
}

int main(){
    Sommet s1{"s1"};
    stringstream out1;
    out1 << s1;
    test("Sommet s1, overcharge operator<<", out.str(), "s1");

    string s1e = s1.getEtiquette();
    test("Sommet s1, getEtiquette", s1e, "s1");
    return 0;

    Arete a1{s1, s2, 1};
    Arete a2{"s3", "s4", 3};


}