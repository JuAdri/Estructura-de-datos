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
 
 
/*
 ALGORITMO EJERCICIO 9
 * 
 *entradas: arbol bt1, arbol bt2
 *salida: true si son similares, false si no lo son
 */
 
 bool simi(const bintree<int>::node bt1, const bintree<int>::node bt2)
{
    bool auxd, auxi;
   if (!bt1.null() && !bt2.null() && hijos(bt1) == hijos(bt2)){
       if(hijos(bt1.left()) != hijos(bt2.left()) || hijos(bt1.right()) != hijos(bt2.right()))
           return 0;
       else{//rama izquierda y rama derecha con los mismos hijos
           auxi= simi(bt1.left(), bt2.left());
           auxd= simi(bt1.right(), bt2.right());
           return auxi==auxd;
       }
   }
   return 0;  
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb);

int main(int argc, char** argv) {
	typedef bintree<char> bti;               // Creamos el arbol
	
	bintree<int> arb(5);
	arb.insert_left(arb.root(), 1);
	arb.insert_left(arb.root().left(), 9);
	//arb.insert_left(arb.root().left().left(), 6);
        arb.insert_right(arb.root().left(), 8);
	arb.insert_right(arb.root(), 5);
//	arb.insert_right(arb.root().left().right(), 4);
//	arb.insert_left(arb.root().right(), 5);
        
        bintree<int> arb2(8);
	arb2.insert_left(arb2.root(), 2);
	arb2.insert_right(arb2.root().left(), 3);
	arb2.insert_left(arb2.root().left(), 8);
	arb2.insert_right(arb2.root(), 5);
//	arb2.insert_right(arb2.root().left().right(), 1);
//	arb2.insert_right(arb2.root().right(), 7);
	
        cout << hijos(arb.root()) << " " << hijos(arb2.root()) << endl;
        //cout << simi(arb.root(), arb2.root()) << endl ; 
	cout << arb << endl;	
        
        cout << arb2 << endl;
   return 0;
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb)
{
  for (typename bintree<T>::const_preorder_iterator i= arb.begin_preorder(); i!=arb.end_preorder(); ++i)
    os << *i << " ";
  
  return os;
}
