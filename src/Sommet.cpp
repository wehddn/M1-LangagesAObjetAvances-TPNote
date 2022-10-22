#include "Sommet.hpp"

Sommet::Sommet(string e):etiquette{e} {}

string Sommet::getEtiquette(){
    return etiquette;
}

std::ostream& operator<< (std::ostream &out, Sommet &sommet)
{
    out << sommet.getEtiquette() ; 
    return out;
}