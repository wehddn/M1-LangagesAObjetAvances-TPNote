#include "GarbageCollector.hpp"
#include "Graphe.hpp"
#include "Sommet.hpp"
#include "Arete.hpp"

#include <cassert>
#include <string>
#include <sstream>

using namespace std;

void test(string ms, string s1, string s2){
    string res;
    if(s1 == s2)
        res = "done";
    else 
        res = "error!";
    cout << ms << " : " << res << endl;
}

int main(){
    Sommet s1{"s1"};
    stringstream out1;
    out1 << s1;
    test("Sommet s1, overcharge operator<<", out.str(), "s1");

    string s1e = s1.getEtiquette();
    test("Sommet s1, getEtiquette", s1e, "s1");
    return 0;

    Arete a1{s1, s2, 1};
    Arete a2{"s3", "s4", 3};


}