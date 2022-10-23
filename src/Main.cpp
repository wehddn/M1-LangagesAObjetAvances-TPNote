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
    Sommet s3{"s3"};
    Sommet s4{"s4"};
    Arete a1{s1, s2, 1};
    Arete a2{s3,s4,3};
    
    vector<Sommet> ls {s1, s2, s3, s4};
    vector<Arete> la {a1,a2};
    Graphe g1{ls, la};
    

    cout << s1 <<"\n";
    cout << s2 <<"\n";
    cout << a1 <<"\n";
    cout << g1 <<"\n";
    g1.symetrise();
    cout << g1 <<"\n";
    return 0;
}