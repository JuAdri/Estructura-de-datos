/** @brief fichero de implementacion de la clase conjunto

*/

//CONSTRUCTOR COPIA
conjunto<T,CMP>::conjunto(const conjunto<T,CMP> &con){
   this->vdatos= con.vdatos;
   //size_type= con.size_type;
   //this->value_type= con.value_type;
}


//METODOS FIND
conjunto<T,CMP>::iterator  conjunto<T,CMP>::find (const conjunto<T,CMP>::value_type &s){
	conjunto<T,CMP>::iterator it;
	
	for(it = this->begin(); it < this->end(); it++)
   	if(*it==s){
      	return it;
    	}
	
  	return it;
}

conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::find (const conjunto<T,CMP>::value_type &s) const{
	conjunto<T,CMP>::const_iterator it;
	
	for(it = this->cbegin(); it < this->cend(); it++)
   	if(*it==s){
      	return it;
    	}
	
  	return it;
}

//METODOS COUNT
conjunto<T,CMP>::size_type conjunto<T,CMP>::count (const conjunto<T,CMP>::value_type &e) const{
  for(conjunto::const_iterator it = this->cbegin(); it < this->cend(); it++)
    return *it == e;
}

//METODO INSERT
pair<typename conjunto<T,CMP>::iterator,bool> conjunto<T,CMP>::insert( const T & c){
	pair<typename conjunto<T,CMP>::iterator,bool> salida;
	bool fin = false;
	
	for (auto it = vdatos.begin(); it!=vdatos.end() && !fin; ){
		if (comp(*it,c) ) 
			it++;
		else if (!comp(*it,c) && !comp(c,*it)){ // equivalentes segun CMP
			salida.first = vdatos.end();
			salida.second = false;
			fin = true;
		}
		else {
			salida.first = vdatos.insert(it,c);
			salida.second = fin = true;
		}
	} // del for
	
	if (!fin){
		salida.first = vdatos.insert(vdatos.end(),c);
		salida.second = true;
	}
	
	return salida;
}

//METODOS ERASE
conjunto<T,CMP>::iterator conjunto<T,CMP>::erase(const conjunto<T,CMP>::iterator position){
  
}

conjunto<T,CMP>::size_type conjunto<T,CMP>::erase(const conjunto<T,CMP>::value_type &val){
  
}


//METODO CLEAR
void conjunto<T,CMP>::clear(){
   vdatos.clear();
}

//METODO SIZE
conjunto<T,CMP>::size_type conjunto<T,CMP>::size() const{
   return this->vdatos.size();
}


//METODO EMPTY
bool conjunto<T,CMP>::empty() const{
   return !vdatos.size();
}

// OPERATOR =
conjunto<T,CMP>& conjunto<T,CMP>::operator=(const conjunto<T,CMP> &org){
        conjunto<T,CMP> c_aux;
        c_aux.vdatos= org.vdatos;
        return c_aux;
}

//METODO BEGIN
conjunto<T,CMP>::iterator conjunto<T,CMP>::begin(){
   return this->vdatos.begin();
}

//METODO CBEGIN
conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cbegin() const{
   return this->vdatos.cbegin();
}

//METODO END
conjunto<T,CMP>::iterator conjunto<T,CMP>::end(){
   return vdatos.end();
}

//METODO CEND
conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cend() const{
   return vdatos.cend();
}

//METODOS LOWER_BOUND
conjunto<T,CMP>::iterator conjunto<T,CMP>::lower_bound (const conjunto<T,CMP>::value_type &val){
    conjunto<T,CMP>::iterator it;

    for(it=this->begin(); it!=this->end(); it++){
        //cout << *it;
        if(!(*it<val))
            return it;
    }
    return this->end();
}

conjunto<T,CMP>::const_iterator conjunto<T,CMP>::lower_bound (const conjunto<T,CMP>::value_type &val) const{
    conjunto<T,CMP>::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        //cout << *it;
        if(!(*it<val))
            return it;
    }
    return this->cend();
}


//METODOS UPPER BOUND
conjunto<T,CMP>::iterator conjunto<T,CMP>::upper_bound (const conjunto<T,CMP>::value_type &val){
    conjunto<T,CMP>::iterator it;

    for(it=this->begin(); it!=this->end(); it++){
        if(val<*it)
            return it;
    }
    return this->vdatos.end();
}

conjunto<T,CMP>::const_iterator conjunto<T,CMP>::upper_bound (const conjunto<T,CMP>::value_type &val) const{
    conjunto<T,CMP>::const_iterator it;

    for(it=this->cbegin(); it!=this->cend(); it++){
        if(val<*it)
            return it;
    }
    return this->vdatos.cend();
}

//INVARIANTE DE REPRESENTACION
bool conjunto::cheq_rep() const{
  int i,j;
  bool encontrado=false;
  vector<string> val_chr={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "X", "Y", "MT"};

  //Buscamos si el cromosoma coincide con alguno de los validos y si la posicion es mayor de cero
  for(i=0; i<vdatos.size(); i++){
      mutacion m_aux=vdatos[i];
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
  for(i=0; i<vdatos.size(); i++){
      for(j=0; j<val_chr.size()-1; j++){
         if(vdatos[i].getChr()==vdatos[i+1].getChr()){
            if(vdatos[i].getPos()>=vdatos[i+1].getPos())
               return 0;
         }
         else{
            if(vdatos[i].getChr() >= vdatos[i+1].getChr())
               return 0;
         }
      }
  }

  return true;
}


//OPEREADOR DE SALIDA SOBRECARGADO
ostream& operator<< (ostream& os, const conjunto<T,CMP> &c){
   //Imprimir todo el conjunto de mutaciones

   for(auto it=c.cbegin(); it<c.cend(); it++){
      os << *it;
      if((it+1)!=c.cend())
         os << ", ";
   }
   os << "\n";

   return os;
}














