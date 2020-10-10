#include "receta.h"
#include<iostream>
#include<string>
#include<list>
#include"ingredientes.h"
#include"instrucciones.h"
#include"arbolbinario.h"
#include"color.h"

using namespace std;

receta::receta(){
  code="defecto";
  plato=-1;
  nombre="defecto";
  calorias=0.0;
  hc=0.0;
  grasas=0.0;
  proteinas=0.0;
  fibra=0.0;
}

receta::receta(string code, unsigned int plato, string nombre, list<pair<string, unsigned int>> ings, float calorias, float hc, float grasas, float proteinas, float fibra){
 this->code=code;
 this->plato=plato;
 this->nombre=nombre;
 this->ings=ings;
 this->calorias=calorias;
 this->hc=hc;
 this->grasas=grasas;
 this->proteinas=proteinas;
 this->fibra=fibra;
}

string receta::getCode(){
  return code;
}

unsigned int receta::getPlato(){
  return plato;
}

string receta::getNombre(){
  return nombre;
}

list<pair<string, unsigned int>> receta::getIngredientes(){
  return ings;
}

float receta::getCalorias(){
  return calorias;
}
float receta::getHc(){
  return hc;
}
float receta::getGrasas(){
  return grasas;
}
float receta::getProteinas(){
  return proteinas;
}
float receta::getFibra(){
  return fibra;
}

instrucciones receta::getInstrucciones(){
  return inst;
}

string receta::getNombre()const{
  return nombre;
}

list<pair<string, unsigned int>> receta::getIngredientes()const{
  return ings;
}

float receta::getCalorias()const{
  return calorias;
}
float receta::getHc()const{
  return hc;
}
float receta::getGrasas()const{
  return grasas;
}
float receta::getProteinas()const{
  return proteinas;
}
float receta::getFibra()const{
  return fibra;
}

string receta::getCode()const{
  return code;
}
unsigned int receta::getPlato()const{
  return plato;
}

instrucciones receta::getInstrucciones()const{
  return inst;
}

void receta::setNombre(string nombre){
  this->nombre=nombre;
}

void receta::setCode(string code){
  this->code=code;
}

void receta::setPlato(unsigned int plato){
  this->plato=plato;
}

void receta::setCalorias(float calorias){
  this->calorias=calorias;
}

void receta::setHc(float hc){
  this->hc=hc;
}

void receta::setGrasas(float grasas){
  this->grasas=grasas;
}

void receta::setProteinas(float proteinas){
  this->proteinas=proteinas;
}

void receta::setFibra(float fibra){
  this->fibra=fibra;
}

void receta::setItDatos(ArbolBinario<string> datos){
  this->inst.setDatos(datos);
}

void receta::setInstrucciones(instrucciones inst){
  this->inst=inst;
}

void receta::clear(){
  ings.clear();
}
int receta::size(){
return ings.size();

}

void receta::insertarIngrediente(pair<string, unsigned int> var){
  ings.push_back(var);
}

void receta::calcularValores(ingredientes I){
  receta::iterator it;
  for(it.it=ings.begin(); it.it!=ings.end(); ++it){
      ingrediente i(I.get(it.it->first));
      calorias+=(i.getCalorias()*it.it->second)/100;
      hc+=(i.getHc()*(it.it->second))/100;
      grasas+=(i.getGrasas()*it.it->second)/100;
      proteinas+=(i.getProteinas()*it.it->second)/100;
      fibra+=(i.getFibra()*(it.it->second))/100;
  }
}

int receta::ningredientes(){
  return ings.size();
}

receta receta::fusionar(receta & uno, receta & dos){
  receta sol;
  sol.setCode("F_"+uno.getCode()+"_"+dos.getCode());
  if(uno.getPlato()<dos.getPlato()){
    sol.setPlato(uno.getPlato());
  }else{
    sol.setPlato(dos.getPlato());
  }
  sol.setNombre("Fusion "+uno.getNombre()+" "+dos.getNombre());
  for(iterator it=uno.begin(); it!=uno.end(); ++it){
    sol.insertarIngrediente(*it);
  }
  for(iterator it=dos.begin(); it!=dos.end(); ++it){
    sol.insertarIngrediente(*it);
  }
  sol.setCalorias(uno.getCalorias()+dos.getCalorias());
  sol.setHc(uno.getHc()+dos.getHc());
  sol.setGrasas(uno.getGrasas()+dos.getGrasas());
  sol.setProteinas(uno.getProteinas()+dos.getProteinas());
  sol.setFibra(uno.getFibra()+dos.getFibra());
  ArbolBinario<string> a("acompañar");
  a.Insertar_Hi(a.getRaiz(), uno.getInstrucciones().getDatos());
  a.Insertar_Hd(a.getRaiz(), dos.getInstrucciones().getDatos());
  sol.setItDatos(a);
}

istream & operator>>(istream & is, receta & R){
	R.clear();
  string linea="";
	string aux="";
  pair<string, unsigned int> par;
  getline(is,linea);
  if(linea[linea.size()-1] == ' '){
      linea.pop_back();
  }
  if(!is) return is;
	int pos=linea.find(';');//Busco la primera coma
  R.setCode(linea.substr(0,pos));
  linea.replace(0, pos+1, "");
  pos=linea.find(';');
	aux=linea.substr(0,pos);
	R.setPlato(atoi(aux.c_str()));
	linea.replace(0,pos+1,"");
	pos=linea.find(';');
	R.setNombre(linea.substr(0,pos));
	linea.replace(0,pos+1,"");
  while(linea.find(' ')!=-1){
    pos=linea.find(';');
  	aux=linea.substr(0,pos);
    pos=aux.rfind(' ');
    par.first=linea.substr(0,pos);
    linea.replace(0,pos+1,"");
    pos=linea.find(';');
  	aux=linea.substr(0,pos);
    par.second=atoi(aux.c_str());
    R.insertarIngrediente(par);
    linea.replace(0,pos+1,"");
  }
  R.setCalorias(0);
  R.setHc(0);
  R.setGrasas(0);
  R.setProteinas(0);
  R.setFibra(0);
	return is;
}

ostream & operator<<(ostream & os, const receta & R){
  os<<FBLU("CODE: ")<<R.getCode();
  os<<FBLU("  RECETA: ")<<R.getNombre();
  os<<FBLU("  PLATO: ")<<R.getPlato();
  os<<UNDL(BOLD("\nIngredientes:\n"));
  receta::const_iterator it;
  for(it=R.begin();it!=R.end(); ++it){
		os<<"\n\tIngrediente: "<<(*it).first<<", cantidad: "<<(*it).second;
	}
  cout<<UNDL(BOLD("\nInformacion nutricional:\n"));
  os<<"\n\tCalorias: "<<R.getCalorias()<<"\n\tHidratos de Carbono: "<<R.getHc()<<"\n\tProteina: "<<R.getProteinas()<<"\n\tGrasas: "<<R.getGrasas()<<"\n\tFibra: "<<R.getFibra()<<endl;
  os<<endl;
  os<<UNDL(BOLD("Pasos a seguir:\n"));
  os<<R.getInstrucciones()<<endl;
  return os;
}
