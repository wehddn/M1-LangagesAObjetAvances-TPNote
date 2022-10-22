#ifndef SOMMET
#define SOMMET

#include <string>
#include <iostream>
using namespace std;

class Sommet{
    private:
        string etiquette;
    public:
        Sommet(string e);
        string getEtiquette();
        //Sommet(Sommet e); Je sais pas comment faire

};

std::ostream& operator<< (std::ostream &out, Sommet &sommet);


#endif