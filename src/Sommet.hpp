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
        ~Sommet();
        string getEtiquette();
        //Sommet(Sommet e); Je sais pas comment faire

};
bool operator==(Sommet lhs, Sommet rhs);

std::ostream& operator<< (std::ostream &out, Sommet &sommet);


#endif