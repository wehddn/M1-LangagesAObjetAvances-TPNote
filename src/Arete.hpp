#include <string>
using namespace std;

class Arete{
    private:
        Sommet sommet1,sommet2;
        int poids;
    public:
        Arete(string s1,string s2, int p);
        Arete(Sommet s1, Sommet s2, int p);
        // Arete(Arete a);
        
};

Arete::Arete(string s1,string s2,int p):sommet1{s1}, sommet2{s2}, poids{p} {}
Arete::Arete(Sommet s1,Sommet s2,int p):sommet1{s1}, sommet2{s2}, poids{p} {}