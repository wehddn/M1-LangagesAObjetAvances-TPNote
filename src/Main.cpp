#include <string>
#include "GarbageCollector.hpp"
#include "Graphe.hpp"
#include "Sommet.hpp"
#include "Arete.hpp"

using namespace std;
int main(){
    GarbageCollector gc;
    Sommet s1{"s1"};
    Sommet s2{"s2"};
    Sommet s3{"s3"};
    Sommet s4{"s4"};
    Sommet s5{"s5"};
    Sommet s1copy{s1};
    
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
    
    cout << "\n";
    cout << "Test sommets : \n";
    cout << "test << de s1 : " << s1 <<"\n";
    cout << "test << pour une copy de s1 : " << s1copy <<"\n";
    cout << "test getEtiquette de s2 : " <<s2.getEtiquette() <<"\n";
    cout << "\n";

    cout << "Test aretes : \n";
    cout << "test << de a1, créée à partir de deux sommets et d'un poids : " << a1 <<"\n";
    cout << "test << de a2, créée à partir de deux étiquettes et d'un poids : " << a2 <<"\n";
    cout << "test << pour une copy de a1 : " << a1copy <<"\n";
    cout << "test getS1 : " << a1.getS1()->getEtiquette() <<"\n";
    cout << "test getPoids : " << a1.getPoids() << "\n"; 
    cout << "test des arêtes avec les mêmes sommets : " << "\n";
    cout << "avant de modifier le poids du sommet s1 : " << a1 << "; " <<  a4 << "\n";
    cout << "\n";

    cout << "Test graphe : \n";
    cout << "test << : " << g1 <<"\n";
    cout << "test << pour une copy de g1 : " << g1copy <<"\n";
    cout << "test poids : " << g1.poids() << "\n";
    g1.ajoute_sommet(s5);
    cout << "test ajoute_sommet à partir d'un sommet existant : " << g1 <<"\n";
    g1.ajoute_sommet("s6");
    cout << "test ajoute_sommet à partir d'une étiquette : " << g1 <<"\n";
    g1.ajoute_arete(a5);
    cout << "\ntest ajoute_arete à partir d'une arête existante : " << g1 <<"\n";
    g1.ajoute_arete(s1, s4, 1);
    cout << "test ajoute_arete à partir de deux sommets existants et d'un poids: " << g1 <<"\n";
    g1.ajoute_arete("s1", "s5", 3);
    cout << "test ajoute_arete à partir de deux étiquettes et d'un poids " << g1 <<"\n";
    cout << "\ng1qcopy : " << g1copy << "\n";
    g1copy.symetrise();
    cout << "test symetrise : " << g1 << "\n";
    Graphe g2 = g1copy.kruskal();
    cout << "test kruskal : " << g2 << "\n";

    return 0;
}