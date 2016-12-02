/** @brief fichero de implementacion de la clase conjunto

*/

#include "conjunto.h"

/*CLASE ITERATOR*/

template <typename T, typename CMP>
conjunto<T,CMP>::iterator::iterator(){
    //elvector=&vm;
    //it=elvector->begin();
}

template <typename T, typename CMP>
const typename conjunto<T, CMP>::value_type& conjunto<T,CMP>::iterator::operator*(){
    
    return (*it);
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator& conjunto<T,CMP>::iterator::operator++(){
    it++;
    return *this;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator& conjunto<T,CMP>::iterator::operator+=(int i){
    it+=i;
    return *this;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator& conjunto<T,CMP>::iterator::operator--(){
    it--;
    return *this;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator& conjunto<T,CMP>::iterator::operator-=(int i){
    it-=i;
}

template <typename T, typename CMP>
bool conjunto<T,CMP>::iterator::operator==(const iterator& x) const{
    return it==x.it;
}

template <typename T, typename CMP>
bool conjunto<T,CMP>::iterator::operator!=(const iterator& x) const{
    return it!=x.it;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator& conjunto<T,CMP>::iterator::operator =(const iterator& x){
    if(this != &x)
        this->elvector = x.elvector;
    return *this;
}

//////////////////

/*CLASE CONST ITERATOR*/


template <typename T, typename CMP>
const typename conjunto<T, CMP>::value_type& conjunto<T,CMP>::const_iterator::operator*(){
    
    return (elvector->at(0));
    
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator& conjunto<T,CMP>::const_iterator::operator++(){
    elvector++;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::const_iterator::operator++(int i){
    elvector+=i;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator& conjunto<T,CMP>::const_iterator::operator--(){
    elvector--;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::const_iterator::operator--(int i){
    elvector-=i;
}

template <typename T, typename CMP>
bool conjunto<T,CMP>::const_iterator::operator==(const const_iterator& x) const{
    return &elvector==&x.elvector;
}

template <typename T, typename CMP>
bool conjunto<T,CMP>::const_iterator::operator!=(const const_iterator& x) const{
    return elvector!=x.elvector;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator& conjunto<T,CMP>::const_iterator::operator =(const const_iterator& x){
    if(this != &x)
        this->elvector = x.elvector;
    return *this;
}

//////////////////

template <typename T, typename CMP>
conjunto<T,CMP>::conjunto(){}

//CONSTRUCTOR COPIA
template <typename T, typename CMP>
conjunto<T,CMP>::conjunto(const conjunto<T,CMP> &con){
   this->vm= con.vm;
   //size_type= con.size_type;
   //this->value_type= con.value_type;
}


//METODOS FIND
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::find (const conjunto<T,CMP>::value_type &s){
    conjunto<T,CMP>::iterator ite=begin();
    //cout << "FIND: const mutacion &s: " << s << endl;
    while(ite != end()){
        //cout << "FIND: const mutacion &s: " << *ite << endl;
        if((*ite)==s){
            return ite;
        }
        ++ite;
    }

    //ite=end();
    return ite;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::find (const conjunto<T,CMP>::value_type &s) const{
    conjunto<T,CMP>::const_iterator it;

    for(it = cbegin(); it != cend(); ++it){
        if((*it)==s)
            return it;
    }

    return it;
}

//METODOS COUNT
template <typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::count (const conjunto<T,CMP>::value_type &e) const{
  for(conjunto::const_iterator it = this->cbegin(); it != this->cend(); it++)
    return *it == e;
}

//METODOS INSERT

template <typename T, typename CMP> 

pair<typename conjunto<T,CMP>::iterator,bool> conjunto<T,CMP>::insert(const conjunto<T,CMP>::value_type &c){
    pair<typename conjunto<T,CMP>::iterator, bool> salida;
    bool fin = false;
    
    for (conjunto<T,CMP>::iterator ite = begin(); ite!=end() && !fin; ){
        if (comp(*ite,c) ) 
            ++ite;
        else if (!comp(*ite,c) && !comp(c,*ite)){ // equivalentes segun CMP
            salida.first = end();
            salida.second = false;
            fin = true;
        }
        else {
            salida.first = ite;
                    vm.insert(ite.it, c);
            salida.second = fin = true;
        }
    } // del for
    
    if (!fin){
        salida.first = end();
                vm.insert(end().it,c);
        salida.second = true;
    }
    return salida;
}

//METODOS ERASE
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::erase(const conjunto<T,CMP>::iterator position){
  
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::erase(const conjunto<T,CMP>::value_type &val){
  
}


//METODO CLEAR
template <typename T, typename CMP>
void conjunto<T,CMP>::clear(){
   vm.clear();
}

//METODO SIZE
template <typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::size() const{
   return this->vm.size();
}


//METODO EMPTY
template <typename T, typename CMP>
bool conjunto<T,CMP>::empty() const{
   return !vm.size();
}

// OPERATOR =
template <typename T, typename CMP>
conjunto<T,CMP>& conjunto<T,CMP>::operator=(const conjunto<T,CMP> &org){
        conjunto<T,CMP> c_aux;
        c_aux.vm= org.vm;
        return c_aux;
}

//METODO BEGIN
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::begin(){
    conjunto<T, CMP>::iterator ite;
    ite.elvector=&vm;
    ite.it=ite.elvector->begin();
    
    return ite;
}


//METODO CBEGIN
template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cbegin() const{
   const_iterator it;
   it.elvector= &vm;
    return it;
}


//METODO END
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::end(){
   conjunto<T, CMP>::iterator ite;
    ite.elvector=&vm;
    ite.it=ite.elvector->end();
    
    return ite;
}

//METODO CEND
template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cend() const{
    const_iterator it;
    it.elvector= &vm;
    for(int i=0; i<vm.size(); i++, it++)
       ;
    return it;
}


//METODOS LOWER_BOUND
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::lower_bound (const conjunto<T,CMP>::value_type &val){
    conjunto<T,CMP>::iterator it;

    for(it=begin(); it!=end(); it++){
        if(!((*it)<val))
            return it;
    }
    return end();
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::lower_bound (const conjunto<T,CMP>::value_type &val) const{
    conjunto<T,CMP>::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        //cout << *it;
        if(!(*it<val))
            return it;
    }
    return this->cend();
}


//METODOS UPPER BOUND
template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::upper_bound (const conjunto<T,CMP>::value_type &val){
    conjunto<T,CMP>::iterator it;

    for(it=begin(); it!=end(); it++){
        if(val<(*it))
            return it;
    }
    return this->end();
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::upper_bound (const conjunto<T,CMP>::value_type &val) const{
    conjunto<T,CMP>::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        if(val<*it)
            return it;
    }
    return this->vm.cend();
}

//INVARIANTE DE REPRESENTACION
/*
bool conjunto::cheq_rep() const{
  int i,j;
  bool encontrado=false;
  vector<string> val_chr={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "X", "Y", "MT"};

  //Buscamos si el cromosoma coincide con alguno de los validos y si la posicion es mayor de cero
  for(i=0; i<vm.size(); i++){
      mutacion m_aux=vm[i];
      for(j=0; j<val_chr.size() && !encontrado; j++){
         if(m_aux.getChr()==val_chr[j])
            encontrado=true;
      }
      if(m_aux.getPos()<=0)
         return 0;
  }
  if(!encontrado)
      return 0;

  //Ahora comprobamos que estan todos en orden
  for(i=0; i<vm.size(); i++){
      for(j=0; j<val_chr.size()-1; j++){
         if(vm[i].getChr()==vm[i+1].getChr()){
            if(vm[i].getPos()>=vm[i+1].getPos())
               return 0;
         }
         else{
            if(vm[i].getChr() >= vm[i+1].getChr())
               return 0;
         }
      }
  }

  return true;
}
*/

//OPEREADOR DE SALIDA SOBRECARGADO
template <typename T, typename CMP>
ostream& operator<< (ostream& os, const conjunto<T,CMP> &c){
   //Imprimir todo el conjunto de mutaciones

   for(typename conjunto<T,CMP>::iterator it=c.cbegin(); it!=c.cend(); it++){
      os << *it;
      if((it+1)!=c.cend())
         os << ", ";
   }
   os << "\n";

   return os;
}













