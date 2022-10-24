#ifndef ARETE
#define ARETE

#include "Sommet.hpp"

#include <string>
#include <iostream>
using namespace std;

class Arete{
    private:
        Sommet* sommet1;
        Sommet* sommet2;
        int poids;
    public:
        Arete(string s1, string s2, int p);
        Arete(Sommet& s1, Sommet& s2, int p);
        Arete(const Arete& a);
        ~Arete();
        Sommet* getS1();
        Sommet* getS2();
        int getPoids();
        void setPoids(int p);
};

std::ostream& operator<< (std::ostream &out, Arete &arete);

#endif