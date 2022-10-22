#include <string>
#include "GC.hpp"
#include "Graphe.hpp"
#include "Sommet.hpp"
#include "Arete.hpp"

using namespace std;
//TODO
int main(){
    Sommet s1{"s1"};
    Sommet s2{"s2"};
    Arete a1{s1, s2, 1};
    
    list<Sommet> ls {s1, s2};
    list<Arete> la {a1};
    Graphe g1{ls, la};

    cout << s1 <<"\n";
    cout << s2 <<"\n";
    cout << a1 <<"\n";
    return 0;
}