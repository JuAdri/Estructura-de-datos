#include <cstdlib>
#include <iostream>
#include <stack>
#include "bintree.h"

using namespace std;

typedef bintree<char> btc;


 int hijos(const  bintree<int>::node &n){
    if(n.null())
        return 0;
    else
        return 1+hijos(n.left())+hijos(n.right());
}
 
 template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb);
/*
 ALGORITMO EJERCICIO 14
 * 
 *entradas: arbol bt1, int v1, int v2
 */
 
 void rango(const bintree<int> &bt1, int v1, int v2)
{
    if(v1>v2 || bt1.root().null())
        return;
    bintree<int> btaux(bt1);
    bintree<int> btaux2(bt1);
    
    bintree<int>::node auxi=btaux.root();
    bintree<int>::node auxd=btaux.root();
    
    while(*auxi>v1){
        auxi= auxi.left();
    }
    
    while(*auxd.right()<v2){
        auxd= auxd.right();
    }
    
    
    btaux.prune_left(auxi, btaux2);
    cout << btaux2 << endl;
    btaux.prune_right(auxd, btaux2);
    cout << btaux2 << endl;
    cout << btaux << endl;
}



int main(int argc, char** argv) {
	
	bintree<int> arb(7);
	arb.insert_left(arb.root(), 4);
	arb.insert_left(arb.root().left(), 2);
	arb.insert_left(arb.root().left().left(), 1);
        arb.insert_right(arb.root().left(), 6);
        arb.insert_right(arb.root().left().left(), 3);
	arb.insert_right(arb.root(), 12);
	arb.insert_left(arb.root().right(), 9);
        arb.insert_right(arb.root().right().left(), 10);
        arb.insert_left(arb.root().right().left(), 8);
	arb.insert_right(arb.root().right(), 14);
        arb.insert_left(arb.root().right().right(), 13);
        arb.insert_right(arb.root().right().right(), 15);
        
        
	//cout << arb << endl;	
        rango(arb,2,13);
        
   return 0;
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb)
{
  for (typename bintree<T>::const_preorder_iterator i= arb.begin_preorder(); i!=arb.end_preorder(); ++i)
    os << *i << " ";
  
  return os;
}
