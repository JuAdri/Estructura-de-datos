#include <cstdlib>
#include <iostream>
#include "bintree.h"

using namespace std;

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb);

//template <typename T>
int nhojas(const typename bintree<int>::node &t){
    if(t.null())
        return 0;
    
    if(t.left().null() && t.right().null())
        return 1;
    
    return nhojas(t.left())+nhojas(t.right());
}

//template <typename T>
int profundidad(const bintree<int>::node &t){
    if(t.null())
        return 0;
    
    int prof_i= profundidad(t.left());
    int prof_d= profundidad(t.right());
    
    if(prof_i > prof_d)
        return prof_i+1;
    else
        return prof_d+1;
}
//
//template <typename T>
int calcDensidad(const bintree<int>::node &t){
    return nhojas(t)*profundidad(t);
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb);

int main(int argc, char** argv) {
	typedef bintree<char> bti;               // Creamos el arbol
        
	bintree<int> arb(5);
	arb.insert_left(arb.root(), 1);
	arb.insert_right(arb.root(), 9);
	arb.insert_left(arb.root().left(), 6);
	arb.insert_right(arb.root().left(), 8);
	arb.insert_right(arb.root().left().right(), 4);
        arb.insert_right(arb.root().left().right().right(), 88);
	arb.insert_left(arb.root().right(), 77);
        arb.insert_right(arb.root().right(), 78);
	
	//cout << calcDensidad(bti);
        
	/*typename bintree<char>::inorder_iterator it_p;
	
	for(it_p= arb.begin_inorder(); it_p != arb.end_inorder(); ++it_p)
		cout << *it_p << " " << endl; 
	*/
	cout << calcDensidad(arb.root()) << endl;	
   return 0;
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb)
{
  for (typename bintree<T>::const_postorder_iterator i= arb.begin_postorder(); i!=arb.end_postorder(); ++i)
    os << *i << " ";
  
  return os;
}
