#include <string>
using namespace std;

class Arete{
    private:
        Sommet sommet1,sommet2;
        int poids;
    public:
        Arete(string s1,string s2, int p);
        Arete(Sommet s1, Sommet s2, int p);
        Sommet getS1();
        Sommet getS2();
        int getPoids();
        // Arete(Arete a);
        
};

