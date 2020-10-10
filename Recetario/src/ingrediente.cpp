#include "ingrediente.h"
#include<iostream>
using namespace std;
ingrediente::ingrediente(){
	nombre="defecto";
	calorias=100.0;
	hidratos=0.0;
	proteinas=0.0;
	grasas=0.0;
	fibra=0.0;
	tipo="defecto";
}

ingrediente::ingrediente(string nombre_, double calorias_, double hidratos_, double proteinas_, double grasas_, double fibra_, string tipo_){

	nombre=nombre_;
	calorias=calorias_;
	hidratos=hidratos_;
	proteinas=proteinas_;
	grasas=grasas_;
	fibra=fibra_;
	tipo=tipo_;

}

void ingrediente::setNombre(string var){
	nombre=var;
}

void ingrediente::setCalorias(double var){
	calorias=var;
}

void ingrediente::setHidratos(double var){
	hidratos=var;
}

void ingrediente::setProteinas(double var){
	proteinas=var;
}

void ingrediente::setGrasas(double var){
	grasas=var;
}

void ingrediente::setFibra(double var){
	fibra=var;
}

void ingrediente::setTipo(string var){
	tipo=var;
}

string ingrediente::getNombre(){
 return nombre;
}

 string ingrediente::getNombre()const{
	return nombre;
}

 double ingrediente::getCalorias()const{
	return calorias;
}

 double ingrediente::getHc()const{
	return hidratos;
}

 double ingrediente::getProteinas()const{
	return proteinas;
}

 double ingrediente::getGrasas()const{
	return grasas;
}

 double ingrediente::getFibra()const{
	return fibra;
}

 string ingrediente::getTipo()const{
	return tipo;
}

istream & operator>>(istream & is, ingrediente & I){
	string linea="";
	string aux="";
	getline(is,linea);//Cojo la linea con los datos
	int pos=linea.find(';');//Busco la primera coma
	I.setNombre(linea.substr(0,pos));
	linea.replace(0,pos+1,"");
	pos=linea.find(';');
	aux=linea.substr(0,pos);
	I.setCalorias(atof(aux.c_str()));
	linea.replace(0,pos+1,"");
	pos=linea.find(';');
	aux=linea.substr(0,pos);
	I.setHidratos(atof(aux.c_str()));
	linea.replace(0,pos+1,"");
	pos=linea.find(';');
	aux=linea.substr(0,pos);
	I.setProteinas(atof(aux.c_str()));
	linea.replace(0,pos+1,"");
	pos=linea.find(';');
	aux=linea.substr(0,pos);
	I.setGrasas(atof(aux.c_str()));
	linea.replace(0,pos+1,"");
	pos=linea.find(';');
	aux=linea.substr(0,pos);
	I.setFibra(atof(aux.c_str()));
	linea.replace(0,pos+1,"");
	pos=linea.find('\r');
	I.setTipo(linea.substr(0,pos));
	return is;
}

ostream & operator<<(ostream & os, const ingrediente & I){
	os<<"Nombre: "<<I.getNombre()<<", Calorias: "<<I.getCalorias()<<", Hidratos: "<<I.getHc()<<", Proteinas: "<<I.getProteinas()<<", Grasas: "<<I.getGrasas()<<", Fibra: "<<I.getFibra()<<" y Tipo: "<<I.getTipo();
	return os;
}
