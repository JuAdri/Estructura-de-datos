/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio7.cpp
 * Author: Adrian Jesus Peña Rodriguez
 *
 * Created on January 28, 2017, 5:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

/////// Estructura del arbol binario ///////

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *btree;

btree createNode(int x){
    btree nuevo = new(struct nodo);
    nuevo->nro = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    
    return nuevo;
}

void insert(btree &tree, int x){
    if(tree == NULL)
        tree = createNode(x);
    else if(x < tree->nro)
        insert(tree->izq, x);
    else
        insert(tree->der, x);
}

void preOrder(btree tree){
    if(tree != NULL){
        cout << tree->nro << " ";
        preOrder(tree->izq);
        preOrder(tree->der);
    }
}

void inOrder(btree tree){
    if(tree != NULL){
        inOrder(tree->izq);
        cout << tree->nro << " ";
        inOrder(tree->der);
    }
}

void postOrder(btree tree){
    if(tree != NULL){
        postOrder(tree->izq);
        postOrder(tree->der);
        cout << tree->nro << " ";
    }
}

//////////////////////////////////////////

//////////////////////// Algoritmo ejercicio 7  ////////////////////////////

int depth(btree tree){
    if(tree == NULL)                // En caso de que el nodo que nos pasan sea nulo salimos de la funcion
        return -1;
    
    int ld,rd;

    if (tree == NULL)
        return 0;

    ld=depth(tree->izq);
    rd=depth(tree->der);

    if (ld>rd)
       return (1+ld);
    else
       return (1+rd);
}

bool isComplete (btree n){
   int ld,rd;

   if (n == NULL) 
       return true;

   ld=depth(n->izq);
   rd=depth(n->der);

   return (ld == rd && isComplete(n->izq) && isComplete(n->der));

}

////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
    btree tree = NULL;               // Creamos el arbol

    int n;                          // Numero de nodos del arbol
    int x;                          // Elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insert( tree, x);
    }

    cout << "\n Mostrando ABB \n\n";
    //showTree( tree, 0);

    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   inOrder(tree);
    cout << "\n\n Pre Orden  :  ";   preOrder(tree);
    cout << "\n\n Post Orden :  ";   postOrder(tree);

    cout << endl << endl;
    
    cout << "\nEs completo?? ";
    
    if(isComplete(tree))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

