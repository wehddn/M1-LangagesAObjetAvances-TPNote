#include <string>
#include "GarbageCollector.hpp"
#include "Graphe.hpp"
#include "Sommet.hpp"
#include "Arete.hpp"

using namespace std;
//TODO
int main(){
    Sommet s1{"s1"};
    Sommet s2{"s2"};
    Sommet s3{"s3"};
    Sommet s4{"s4"};
    
    Arete a1{s1, s2, 1};
    Arete a11{s1, s2, 1};
    Arete a2{s3,s4,3};
    Arete a3{"s3", "s4", 2};
    
    vector<Sommet> ls {s1, s2, s3, s4, s1};
    vector<Arete> la {a1, a11, a2};

    Graphe g1{ls, la};
    

    cout << "\n";
    cout << "Test sommets : \n";
    cout << "test << : " << s1 <<"\n";
    cout << "test getEtiquette : " <<s2.getEtiquette() <<"\n";
    cout << "\n";

    cout << "Test aretes : \n";
    cout << "test << : " << a1 <<"\n";
    cout << "test getS1 : " << a2.getS1().getEtiquette() <<"\n";
    cout << "test getPoids : " << a2.getPoids() << "\n"; 
    cout << "\n";

    cout << "Test graphe : \n";
    cout << "test << : " << g1 <<"\n";
    cout << "test poids : " << g1.poids() << "\n";
    g1.ajoute_sommet(s4);
    cout << "test ajoute_sommet : " << g1 <<"\n";
    g1.ajoute_sommet("s5");
    cout << "test ajoute_sommet : " << g1 <<"\n";
    //g1.symetrise();
    //cout << "test symetrise : " << g1 <<"\n";

    GarbageCollector::test();

    return 0;
}