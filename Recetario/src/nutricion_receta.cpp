#include "ingrediente.h"
#include "ingredientes.h"
#include "receta.h"
#include "recetas.h"
#include <fstream>
#include<set>

using namespace std;

string RecetaMasRazonable(const float Cmax, recetas & recetario){
  float maximo=0;
  string codigo="Undefined";
  recetas::const_iterator it;
  for(it=recetario.begin(); it!=recetario.end(); ++it){
    if(((*it).getCalorias()<Cmax) && ((*it).getProteinas()>maximo)){
      codigo=(*it).getCode();
      maximo=(*it).getProteinas();
    }
  }
  return codigo;
}

int main(int argc,char *argv[]){

  if (argc!=4){
    cout<<"Dame dos ficheros y una cantidad"<<endl;
    return 0;
  }

  ifstream g(argv[1]);
  if(!g){
    cout<<"No puedo abrir el fichero con las recetas"<<endl;
  }
  recetas rec;
  g>>rec;

  ifstream f(argv[2]);
  if(!f){
    cout<<"No puedo abrir el fichero con los ingredientes"<<endl;
  }

  ingredientes ing;
  f>>ing;
  string aux=argv[3];
  if(aux.empty()){
    cout<<"No puedo leer el numero de calorias"<<endl;
  }
  int calorias=atoi(aux.c_str());

  rec.calcularValores(ing);

  recetas::const_iterator it;
  for(it=rec.begin(); it!=rec.end(); ++it){
    cout<<"Valores Nutricionales de la receta "<<(*it);
  }

  cout<<"\n\n\n-------------------------------------------------------------------------\n\n\n";

  cout<<"Las recetas escogidas son: "<<endl;
  recetas::iterator iter;
  float SumaC=0, SumaP=0;
  string elemento="";
  bool stop=false;
  set<string> codigos;

  while(SumaC<calorias && !stop){
    elemento=RecetaMasRazonable(calorias-SumaC, rec);
    if(elemento!="Undefined" && codigos.find(elemento)==codigos.end()){
      if((SumaC+rec[elemento].getCalorias())<calorias){
        codigos.insert(elemento);
        SumaC+=rec[elemento].getCalorias();
        SumaP+=rec[elemento].getProteinas();
      }
    }else{
      stop=true;
    }
  }

  set<string>::iterator itera;
  for(itera=codigos.begin(); itera!=codigos.end(); ++itera){
    cout<<rec[*itera]<<endl;
  }

  cout<<"Calorias Totales "<<SumaC<<"\tProteinas Totales: "<<SumaP<<endl;

  return(0);

}
