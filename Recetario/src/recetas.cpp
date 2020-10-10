#include"receta.h"
#include<string>
#include<map>
#include<iostream>
#include<ingredientes.h>
#include"recetas.h"
using namespace std;
//FUnciones setIt y getIt del iterador
unsigned int recetas::size()const{
  return datos.size();
}

void recetas::insertar(const receta & R){
  datos[R.getCode()]=R;
}

void recetas::borrar(const string & i){
  datos.erase(i);
}

map<string, receta> recetas::getDatos(){
  return datos;
}

const map<string, receta> recetas::getDatos()const{
  return datos;
}

void recetas::calcularValores(ingredientes I){
  iterator it;
  for(it.it=datos.begin(); it.it!=datos.end(); ++it){
    (*it).calcularValores(I);
  }
}

receta recetas::fusionar(const string & cod1, const string & cod2){
  string ncod="F_"+cod1+"_"+cod2;
  receta re;
  return re.fusionar(datos[cod1], datos[cod2]);
}
/*
receta & recetas::operator[](const string & i){
		return datos[i];
}

const receta & recetas::operator[](const string & i)const{
    //return datos[i];
    map<string,receta>::const_iterator it=datos.find(i);
     return it->second;
}
*/
istream & operator>>(istream & is, recetas & R){
	R.clear();//metodo clear para limpiar I
	receta r;
	while(is>>r && r.size()>0){
		R.insertar(r);
	}
	return is;
}

ostream & operator<<(ostream & os, const recetas & R){
    recetas::const_iterator it;
    for(it=R.begin(); it!=R.end(); ++it){
			os<<(*it)<<"\n\n";
		}
		return os;
}
