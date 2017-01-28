/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio4.cpp
 * Author: Adrian Jesus Peña Rodriguez
 *
 * Created on January 28, 2017, 12:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

/////// Estructura del arbol binario ///////

struct nodo{
     char nro;
     struct nodo *izq, *der, *izq1, *der1;
};

typedef struct nodo *btree;

btree createNode(char *x){
    btree nuevo = new(struct nodo);
    nuevo->nro = *x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    
    return nuevo;
}

void insert(btree &tree, char *x){
    if(tree == NULL)
        tree = createNode(x);
    else if(*x < tree->nro)
        insert(tree->izq, x);
    else
        insert(tree->der, x);
}

void preOrder(btree tree){
    if(tree != NULL){
        cout << tree->nro << " ";
        preOrder(tree->izq);
        preOrder(tree->izq1);
        preOrder(tree->der1);
        preOrder(tree->der);
    }
}

void inOrder(btree tree){
    if(tree != NULL){
        inOrder(tree->izq);
        inOrder(tree->izq1);
        cout << tree->nro << " ";
        inOrder(tree->der1);
        inOrder(tree->der);
    }
}

void postOrder(btree tree){
    if(tree != NULL){
        postOrder(tree->izq);
        postOrder(tree->izq1);
        postOrder(tree->der1);
        postOrder(tree->der);
        cout << tree->nro << " ";
    }
}

//////////////////////////////////////////

//////////////////////// Algoritmo ejercicio 4  ////////////////////////////



////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
    btree tree = NULL;               // Creamos el arbol

    int n = 5;                          // Numero de nodos del arbol

    cout << "\n\t\t  ..[ ARBOL BINARIO ]..  \n\n";

    insert(tree, "T");
    
    insert(tree->izq, "*");
    insert(tree->izq1, "+");
    insert(tree->der1, "-");
    insert(tree->der, "/");
    
    insert(tree->izq->izq, "a");
    insert(tree->izq->der, "b");
    insert(tree->izq1->izq, "c");
    insert(tree->izq1->der, "d");
    insert(tree->der1->izq, "e");
    insert(tree->der1->der, "f");
    insert(tree->der->izq, "g");
    insert(tree->der->der, "h");

    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   inOrder(tree);
    cout << "\n\n Pre Orden  :  ";   preOrder(tree);
    cout << "\n\n Post Orden :  ";   postOrder(tree);

    cout << endl << endl;

    return 0;
}
