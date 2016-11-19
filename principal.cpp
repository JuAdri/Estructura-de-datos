#include "mutacion.h"
#include "enfermedad.h"
#include "conjunto.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

	/** @brief lee un fichero de mutaciones, linea a linea
	@param[in] s nombre del fichero
  @param[in,out] cm objeto tipo conjunto sobre el que se almacenan las mutaciones
	@return true si la lectura ha sido correcta, false en caso contrario
	*/

bool load(conjunto<mutacion,ComparacionPorID> &cm, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail()){
   cerr << "Error al abrir el fichero " << s << endl;
 }
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    }while (cadena.find("#")==0 && !fe.eof());

    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof()){
        //cout << "leo:: "<< cadena << endl;
        // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
        mutacion mut = mutacion(cadena);
        // Insertar mutación en el conjunto
        cm.insert(mut);
        getline(fe,cadena,'\n');
    }
    //sort(cm.begin(), cm.end());
    fe.close();
    return true;
  } // else
  fe.close();
  return false;
 }


int main(int argc, char *argv[]){
    pair<conjunto<mutacion,ComparacionPorID>::value_type,bool> busq_aux;
	conjunto<mutacion,ComparacionPorID> conjuntoMutaciones;
    string query_str;
	//mutacion pr=mutacion("MT	15990	rs199474699	C	T	.	.	RS=199474699;RSPOS=15990;dbSNPBuildID=136;SSR=0;SAO=1;VP=0x050060000005000002110100;WGT=1;VC=SNV;PM;ASP;LSD;OM;CLNALLE=1;CLNHGVS=NC_012920.1:m.15990C>T;CLNSRC=OMIM_Allelic_Variant;CLNORIGIN=1;CLNSRCID=590075.0001;CLNSIG=5;CLNDSDB=MedGen;CLNDSDBID=C0026848;CLNDBN=Myopathy;CLNREVSTAT=no_criteria;CLNACC=RCV000010183.2");
    //mutacion pr2=mutacion("19	10984271	rs375884151	C	T	.	.	RS=375884151;RSPOS=10984271;dbSNPBuildID=138;SSR=0;SAO=0;VP=0x050000000305040026000100;GENEINFO=SMARCA4:6597;WGT=1;VC=SNV;REF;SYN;ASP;VLD;KGPhase3;CLNALLE=1;CLNHGVS=NC_000019.10:g.10984271C>T;CLNSRC=.;CLNORIGIN=1;CLNSRCID=.;CLNSIG=0|2;CLNDSDB=MedGen|MedGen:OMIM;CLNDSDBID=CN169374|C2750074:613325;CLNDBN=not_specified|Rhabdoid_tumor_predisposition_syndrome_2;CLNREVSTAT=single|single;CLNACC=RCV000192439.1|RCV000204385.1;CAF=0.998,0.001997;COMMON=1");
	//Cargar las mutaciones en vectorSNPs
    //if(conjuntoMutaciones.insert(pr))
    	//cout << "INSERTADA"<<endl;
    	
	//if(conjuntoMutaciones.insert(pr2))
    	//cout << "INSERTADA"<<endl;
	load(conjuntoMutaciones, "clinvar.vcf");

    //Imprimir número de elementos almacenados en conjuntoMutaciones
    cout << "Lectura del fichero finalizada. Mutaciones cargadas: "<<conjuntoMutaciones.size()<<endl;
    
	
    
    //for(conjunto::iterator it=conjuntoMutaciones.begin(); it<conjuntoMutaciones.end(); it++)
            //cout << *it << "\n";
    	

	
   
   return 0;
}
