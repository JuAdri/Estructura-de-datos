#include "mutacion.h"
#include <iostream>
#include <fstream>

#include "conjunto.h"

using namespace std;
	
	
/** @brief lee un fichero de mutaciones, linea a linea
@param[in] s nombre del fichero
@param[in,out] cm objeto tipo conjunto sobre el que se almacenan las mutaciones
@return true si la lectura ha sido correcta, false en caso contrario
*/
template<typename T, class CMP>
bool load(conjunto<T,CMP>  &  cm, const string & s) {
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
    }while (cadena.find('#')!=string::npos && !fe.eof());

    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof() ){ 
        //cout << "leo:: "<< cadena << endl;
        // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
         mutacion mut = mutacion(cadena);
        //cout << mut<< endl;
        // Insertar mutación en el conjunto
        cm.insert(mut);
        getline(fe,cadena,'\n');
    }
    fe.close();
    return true;
  } // else 
  fe.close();
  return false;
 }

int main(int argc, char *argv[]){

  conjunto<mutacion,less<mutacion> > cm;
  load(cm,"clinvar_20160831.vcf");
  
  //const mutacion m1= mutacion("1	1014143	rs786201005	C	T	.	.	RS=786201005;RSPOS=1014143;dbSNPBuildID=144;SSR=0;SAO=1;VP=0x050060000605000002110100;GENEINFO=ISG15:9636;WGT=1;VC=SNV;PM;NSN;REF;ASP;LSD;OM;CLNALLE=1;CLNHGVS=NC_000001.11:g.1014143C>T;CLNSRC=OMIM_Allelic_Variant;CLNORIGIN=1;CLNSRCID=147571.0003;CLNSIG=5;CLNDSDB=MedGen:OMIM;CLNDSDBID=CN221808:616126;CLNDBN=Immunodeficiency_38_with_basal_ganglia_calcification;CLNREVSTAT=no_criteria;CLNACC=RCV000162196.3");
 
  
  mutacion m2= mutacion("1	1041950	rs2799066	T	C	.	.	RS=2799066;RSPOS=1041950;RV;dbSNPBuildID=100;SSR=0;SAO=1;VP=0x0501600a000515013e100100;GENEINFO=AGRN:375790;WGT=1;VC=SNV;PM;SLO;INT;R5;ASP;VLD;G5;GNO;KGPhase1;KGPhase3;LSD;CLNALLE=1;CLNHGVS=NC_000001.11:g.1041950T>C;CLNSRC=.;CLNORIGIN=1;CLNSRCID=.;CLNSIG=2;CLNDSDB=MedGen;CLNDSDBID=CN169374;CLNDBN=not_specified;CLNREVSTAT=single;CLNACC=RCV000116254.1;CAF=0.1148,0.8852;COMMON=1");
  mutacion m3= mutacion("MT	15990	rs199474699	C	T	.	.	RS=199474699;RSPOS=15990;dbSNPBuildID=136;SSR=0;SAO=1;VP=0x050060000005000002110100;WGT=1;VC=SNV;PM;ASP;LSD;OM;CLNALLE=1;CLNHGVS=NC_012920.1:m.15990C>T;CLNSRC=OMIM_Allelic_Variant;CLNORIGIN=1;CLNSRCID=590075.0001;CLNSIG=5;CLNDSDB=MedGen;CLNDSDBID=C0026848;CLNDBN=Myopathy;CLNREVSTAT=no_criteria;CLNACC=RCV000010183.2");
  /*
  cm.insert(m1);
  cm.insert(m2);
 // cm.insert(m3);
  */
  
  //Imprimir número de elementos almacenados en conjuntoMutaciones
  cout << "Lectura del fichero finalizada. Mutaciones cargadas: " << cm.size() << endl;  
  
  conjunto<mutacion,less<mutacion> >::iterator ite;// = cm.find(*cm.begin());
   
  /*
  if (it == cm.end())
    cout << "No está."<<endl;
  else 
      cout << (*it).getID() << " " << (*it).getPos() << endl;
  */
  mutacion x,y;

  x.setPos(1014359);
  x.setChr("1");
  x.setID("rs672601312");
  
  y.setPos(0);
  y.setChr("MT");
  
  
  
  cout << "En rango " << *cm.lower_bound(x) << "pos inicio "<< cm.lower_bound(x)-cm.begin() << " pos fin "<< cm.lower_bound(y)-cm.begin()<< endl;
  
  /*
  cm.erase(cm.end()-7); // borro
  cout << cm.size()<< endl;
  cout << cm.erase(x) << endl;
  int i=0;
  for (mutacion m:cm){	
    if (i%10==0)
      cout << m<<endl;
    i++;
  }

	conjunto<mutacion,greater<mutacion> > cmg;
	
	cout << "Leo decreciente!!!" <<endl;
  load(cmg,"clinvar_20160831.vcf");
  i = 0;
  cout << cmg.size() << endl;

  cout << cmg << endl;
  cout << "Posiciones Impares" <<endl;
  for (auto iti=cmg.ibegin();iti!=cmg.iend();++iti)
    cout << *iti <<endl;

  conjunto<mutacion,greater<mutacion> >::secure_iterator sit=cmg.send();
  --sit;
  // Borro 10 elementos;
  for (int i=0;i<10;i++)
    cmg.erase(cmg.end()-1);

  
  cout << *sit << endl; // Iterador no valido, debe abortar
*/
  return 0;
}