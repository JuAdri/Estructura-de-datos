/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ejercicio2.cpp
 * Author: Adrian Jesus Peña Rodriguez
 *
 * Created on January 28, 2017, 00:35 AM
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

//////////////////////// Algoritmo ejercicio 2  ////////////////////////////

int nodeSearch(btree tree, btree buscar){
    if(tree == NULL)                // En caso de que el nodo que nos pasan sea nulo salimos de la funcion
        return -1;
    
    stack<btree> s;                 // Creamos una pila de nodos donde los iremos metiendo y de esta manera podamos retroceder para luego meternos por otra rama
    s.push(tree);                   // Metemos el primer elemento, el nodo que nos pasan
    btree prev = NULL;              // Este sera el nodo anterior al actual
    int nivel_nodo = -1;            // Variable que retornaremos
    
    while (!s.empty() && nivel_nodo == -1) {            // Mientras que la pila no este vacia, es decir, no tengamos revisadas todas las ramas y no hallamos encontrado el nodo que buscamos
        btree curr = s.top();       // curr es el nodo tope de pila(ultimo en llegar), lo cogemos como actual
        
        if(curr->nro != buscar->nro){       // Vemos si lo hemos encontrado
            if (!prev || prev->izq == curr || prev->der == curr) {      // Si nuestro nodo previo no es nulo o nuestro nodo izquierdo del anterior nodo es igual que el actual o lo mismo con el derecho, entramos
                if (curr->izq)          // Si el nodo actual tiene un hijo por la izquierda entramos
                    s.push(curr->izq);
                else if (curr->der)     // Si el nodo actual tiene un hijo por la derecha entramos
                    s.push(curr->der);
            } else if (curr->izq == prev) {     // En caso de no cumplirse el if externo, comprobamos si tiene un hijo a la izquierda nuestro nodo actual y si este es igual al nodo previo, en este caso ya hemos revisado la izquierda y ahora vamos con la derecha
                if (curr->der)          // Si no es nulo, lo metemos en la pila
                    s.push(curr->der);
            } else {                    // En caso de no cumplirse ninguno de los anteriores sacamos el nodo de la pila
                s.pop();
            }
            prev = curr;
        }
        else
            nivel_nodo = s.size() - 1;
    }
    
    return nivel_nodo;
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
    
    cout << " Que nodo quieres buscar?:  ";
    cin >> n;
    cout << endl;
    
    btree buscar = NULL;
    insert(buscar, n);
    
    if(nodeSearch(tree, buscar) != -1){
        cout << "\nEl nodo que buscas tiene una profundidad de ";
        if(nodeSearch(tree, buscar) == 0)
            cout << 0 << " es la raiz del arbol." << endl;
        else
            cout << nodeSearch(tree, buscar) << endl;
    }                
    else
        cout << "\nNo se ha encontrado el nodo que buscas." << endl;

    return 0;
}

