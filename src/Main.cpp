#include <string>
#include "GarbageCollector.hpp"
#include "Graphe.hpp"
#include "Sommet.hpp"
#include "Arete.hpp"

using namespace std;
int main(){
    GarbageCollector gc;
    Sommet* s0 = new Sommet("s0");
    Sommet s1{"s1"};
    Sommet s2{"s2"};
    Sommet s3{"s3"};
    Sommet s4{"s4"};
    Sommet s5{"s5"};
    Sommet s1copy{s1};
    
    Arete* a0 = new Arete(*s0, *s0, 1);
    Arete* a00 = new Arete(*s0, *s0, 1);
    Arete a1{s1, s2, 1};
    Arete a11{s1, s2, 1};
    Arete a2{"s3","s4",3};
    Arete a3{s3, s4, 2};
    Arete a4{s1, s5, 2};
    Arete a5{s1, s3, 5};
    Arete a1copy{a1};
    
    vector<Sommet*> ls {&s1, &s2, &s3, &s4, &s1};
    vector<Arete*> la {&a1, &a11, &a2};

    Graphe g1{ls, la};
    Graphe g1copy{g1};

    cout << endl;
    cout << "Test sommets : \n";
    cout << "test << de s1 : " << s1 << endl;
    cout << "test << pour une copy de s1 : " << s1copy << endl;
    cout << "test getEtiquette de s2 : " <<s2.getEtiquette() << endl;
    cout << endl;

    cout << "Test aretes : \n";
    cout << "test << de a1, créée à partir de deux sommets et d'un poids : " << a1 << endl;
    cout << "test << de a2, créée à partir de deux étiquettes et d'un poids : " << a2 << endl;
    cout << "test << pour une copy de a1 : " << a1copy << endl;
    cout << "test getS1 : " << a1.getS1()->getEtiquette() << endl;
    cout << "test getPoids : " << a1.getPoids() << endl; 
    cout << "test des arêtes avec les mêmes sommets : \n";
    cout << "avant de modifier le poids du sommet s1 : " << a1 << "; " <<  a4 << endl;
    cout << endl;

    cout << "Test graphe : \n";
    cout << "test << : " << g1 << endl;
    cout << "test << pour une copy de g1 : " << g1copy << endl;
    cout << "test poids : " << g1.poids() << endl;
    g1.ajoute_sommet(s5);
    cout << "test ajoute_sommet à partir d'un sommet existant : " << g1 << endl;
    g1.ajoute_sommet("s6");
    cout << "test ajoute_sommet à partir d'une étiquette : " << g1 << endl;
    g1.ajoute_arete(a5);
    cout << "\ntest ajoute_arete à partir d'une arête existante : " << g1 << endl;
    g1.ajoute_arete(s1, s4, 1);
    cout << "test ajoute_arete à partir de deux sommets existants et d'un poids: " << g1 << endl;
    g1.ajoute_arete("s1", "s5", 3);
    cout << "test ajoute_arete à partir de deux étiquettes et d'un poids " << g1 << endl;
    cout << "\ng1qcopy : " << g1copy << endl;
    g1copy.symetrise();
    cout << "test symetrise : " << g1 << endl;
    Graphe g2 = g1copy.kruskal();
    cout << "test kruskal : " << g2 << endl;

    cout << "\ntest que 2 graphes ayant un sommet commun doivent se référer au même sommet : " << endl;
    cout << "Le sommet s1 dans les graphes g1 et g2 doit avoir la même adresse : " << g1.getAretes().at(0).getS1() << " " << g2.getAretes().at(0).getS1() << endl; 

    cout << "\nL'arête s1 dans les graphes g1 et g2 doit avoir le même poids : " << g1.getAretes().at(0).getPoids() << ", " << g2.getAretes().at(0).getPoids() << endl; 
    a1.setPoids(3);
    cout << "Le poids d'arête s1 après la modification : " << g1.getAretes().at(0).getPoids() << ", " << g2.getAretes().at(0).getPoids() << endl; 

    cout << "\ntest des constructions et destructions : \n";
    cout << "Nombre courrant de sommets et d'arêtes : \n";
    GarbageCollector::testShow();
    cout << "Nombre de sommets et d'arêtes après la suppression d'un arête " << *a0 << " :\n";
    delete(a0);
    GarbageCollector::testShow();
    cout << "Après la suppression d'un sommet " << *s0 << " (arêtes " << *a00 << " doit être supprimé) :\n";
    delete(s0);
    GarbageCollector::testShow();

    return 0;
}