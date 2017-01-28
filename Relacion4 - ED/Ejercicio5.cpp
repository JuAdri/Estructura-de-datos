/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio5.cpp
 * Author: Adrian Jesus Peña Rodriguez
 *
 * Created on January 28, 2017, 2:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/////// Estructura del arbol binario ///////

struct nodo{
     char nro;
     struct nodo *izq, *der;
};

typedef struct nodo *btree;

btree createNode(char x){
    btree nuevo = new(struct nodo);
    nuevo->nro = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    
    return nuevo;
}

void insert(btree &tree, char x){
    if(tree == NULL)
        tree = createNode(x);
    else if(x < tree->nro)
        insert(tree->izq, x);
    else
        insert(tree->der, x);
}

void preOrder(btree tree){
    if(tree != NULL){
        cout << tree->nro << ' ';
        preOrder(tree->izq);
        preOrder(tree->der);
    }
}

void inOrder(btree tree){
    if(tree != NULL){
        inOrder(tree->izq);
        cout << tree->nro << ' ';
        inOrder(tree->der);
    }
}

void postOrder(btree tree){
    if(tree != NULL){
        postOrder(tree->izq);
        postOrder(tree->der);
        cout << tree->nro << ' ';
    }
}

//////////////////////////////////////////

//////////////////////// Algoritmo ejercicio 5 ////////////////////////////

int getInorderIndex(char inOrder[], int start, int end, char data){
    for(int i = start ; i <= end ; i++){
        if(inOrder[i] == data){
            return i;
        }
    }
    return -1;
}

btree makeBTree(char inOrder[], char preOrder[], int start, int end){
    static int pIndex=0;

    if(start>end){
        return NULL;
    }
    
    btree root = createNode(preOrder[pIndex]);
    pIndex++;

    if(start==end){
        return root;
    }
    
    int index = getInorderIndex(inOrder, start, end, root->nro);
    root->izq = makeBTree(inOrder,preOrder,start, index-1);
    root->der = makeBTree(inOrder,preOrder,index+1, end);
    //}
    return root;
}

////////////////////////////////////////////////////////////////////////////



int main(int argc, char** argv) {
    btree tree = NULL;               // Creamos el arbol

    char preord[] = {'G', 'E', 'A', 'I', 'B', 'M', 'C', 'L', 'D', 'F', 'K', 'J', 'H'};                         
    char inord[] = {'I', 'A', 'B', 'E', 'G', 'L', 'D', 'C', 'F', 'M', 'K', 'H', 'J'};

    tree = makeBTree(inord, preord, 0, 12);
    
    cout << "\nInOrder = " << "\n";
    
    inOrder(tree);
    
    cout << "\nPostOrder = " << "\n";
    
    postOrder(tree);
    
    cout << endl << endl;

    return 0;
}
