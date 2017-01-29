// Ejemplo de uso del tipo BST

#include <string>
#include <iostream>
#include <bst.h>
using namespace std;

int main()
{
  const int NUM = 6;
  BST<string, string> dicc;
  string palabras[NUM] = {"piedra", "tiza", "diamante", "rosa", "adoquin", "margarita"};
  string definiciones[NUM] = {"objeto muy duro", "objeto muy blando", "objeto dur�imo", "tipo de flor",
  "objeto duro o persona intransigente", "flor utilizada para tomar decisiones importantes"};
  // string clave = "piedra";
  // string definicion = "objeto muy duro";
  
  for (int i= 0; i<NUM; i++) {
    pair<string, string> aux(palabras[i], definiciones[i]);
    dicc.insert(aux);
    cout << "Num.datos: " << dicc.size() << endl;
    // BST<string, string>::iterator it2 = dicc.end();
    //if (dicc.find(palabras[i])!=it2)
    if (dicc.find(palabras[i])!=dicc.end())
      cout << "Clave " << palabras[i] << " insertada correctamente" << endl;
    else
      cerr << "Clave " << palabras[i] << "no insertada" << endl;
  }

  BST<string, string>::iterator i;
  cout << "Listado del �rbol" << endl;
  for (i= dicc.begin(); i!=dicc.end(); ++i)
    cout << (*i).first << ": " << (*i).second << endl;
  
  /*
  BST<string, string>::iterator i1;
  cout << "Listado del �rbol" << endl;
  for (i1= dicc.begin(); i1!=dicc.end(); ++i1) {
    (*i1).second = (*i1).second + "Abc";
    cout << (*i1).first << ": " << (*i1).second << endl;
  }
  */
     
  return 0;
}
