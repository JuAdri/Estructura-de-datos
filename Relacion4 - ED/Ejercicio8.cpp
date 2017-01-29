#include <cstdlib>
#include <iostream>
#include <stack>
#include "bintree.h"

using namespace std;

typedef bintree<char> btc;

bool is_operator(char c){
	return c == '+' || c=='-' || c=='*' || c=='/';
	}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb);

void generarPost( string e_post, bintree<char> &t){
	stack<bintree<char> > s_bt;
	bintree<char>::node ni, nd;
	bintree<char> btaux;
	
	for(int i=0; i<e_post.size(); i++){
		if(!is_operator(e_post[i])){
			btaux=bintree<char>(e_post[i]);
			s_bt.push(btaux);
		}
		else{
			btaux=bintree<char>(e_post[i]);
			btaux.insert_right(btaux.root(), s_bt.top());
			s_bt.pop();
			btaux.insert_left(btaux.root(), s_bt.top());
			s_bt.pop();
			s_bt.push(btaux);
		}
	}
	
	t=s_bt.top();
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb);

int main(int argc, char** argv) {
	typedef bintree<char> bti;               // Creamos el arbol
	string prueba= "134*+";
	bintree<char> arb;
	/*
	arb.insert_left(arb.root(), 1);
	arb.insert_right(arb.root(), 9);
	arb.insert_left(arb.root().left(), 6);
	arb.insert_right(arb.root().left(), 8);
	arb.insert_right(arb.root().left().right(), 4);
	arb.insert_left(arb.root().right(), 5);
	*/
	generarPost(prueba, arb);
	/*typename bintree<char>::inorder_iterator it_p;
	
	for(it_p= arb.begin_inorder(); it_p != arb.end_inorder(); ++it_p)
		cout << *it_p << " " << endl; 
	*/
	cout << arb << endl;	
   return 0;
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb)
{
  for (typename bintree<T>::const_postorder_iterator i= arb.begin_postorder(); i!=arb.end_postorder(); ++i)
    os << *i << " ";
  
  return os;
}
