#include "Sommet.hpp"
#include <cstring>

Sommet::Sommet(string e):etiquette{e} {}

string Sommet::getEtiquette(){
    return etiquette;
}

inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}


bool operator==(Sommet lhs, Sommet rhs){
    //cout << "ici" << "\n";
    //cout << lhs.getEtiquette() << " " << rhs.getEtiquette() << " " << BoolToString(lhs.getEtiquette() == rhs.getEtiquette()) << "\n";
    return lhs.getEtiquette() == rhs.getEtiquette();
}

std::ostream& operator<< (std::ostream &out, Sommet &sommet)
{
    out << sommet.getEtiquette() ; 
    return out;
}