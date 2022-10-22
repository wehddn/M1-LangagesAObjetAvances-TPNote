#include <string>
#include <iostream>

using namespace std;

class Sommet{
    private:
        string etiquette;
    public:
        Sommet(string e);
        //Sommet(Sommet e); Je sais pas comment faire

};

Sommet::Sommet(string e):etiquette{e} {}
