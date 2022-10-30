#include "Sommet.hpp"
#include "GarbageCollector.hpp"

#include <cstring>

Sommet::Sommet(string e){
    etiquette = e;
    GarbageCollector::create(this);
}

Sommet::Sommet(const Sommet& s){
    *this = s;
}

string Sommet::getEtiquette(){
    return etiquette;
}

int Sommet::getMarquage(){
    return marquage;
}

void Sommet::setMarquage(int x){
    this->marquage = x;
}

Sommet::~Sommet(){
    GarbageCollector::del(this);
}

inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}

bool operator==(Sommet lhs, Sommet rhs){
    return lhs.getEtiquette() == rhs.getEtiquette();
}

std::ostream& operator<< (std::ostream &out, Sommet &sommet)
{
    out << sommet.getEtiquette() ; 
    return out;
}