#include <cstdlib>
#include <iostream>
#include "bst.h"
#include "pot.h"

using namespace std;

template<typename Key, typename value>
ostream& operator<<(ostream &os,  BST<Key, value> &arb);

//template<typename value>
//ostream& operator<<(ostream &os,  POT<value> &arb);

int main(int argc, char** argv) {
    const int NUM = 11;
    BST<int, int> bst1;
    POT<int> pot1;
    int palabras[NUM] = {50,25,75,10,40,60,90,35,45,70,42};
    int definiciones[NUM] = {1,5};

    for (int i= 0; i<NUM; i++) {
        pair<int, int> aux(palabras[i], definiciones[i]);
        bst1.insert(aux);
        pot1.insert(palabras[i]);
    }
    
    cout << bst1 << endl;
//    cout << pot1 << endl;
    
      return 0;
}

template<typename Key, typename value>
ostream& operator<<(ostream &os,  BST<Key, value> &arb) {
    for (typename BST<Key, value>::iterator i= arb.begin(); i!=arb.end(); ++i)
        os << (*i).first << ": " << (*i).second << endl;

    return os;
}

//template<typename value>
//ostream& operator<<(ostream &os,  POT<value> &arb) {
//    for (int i= 0; i<arb.size(); ++i){
//        os << arb.min() << endl;
//        arb.erase();
//    }
//    
//    return os;
//}