#include"ingredientes.h"
#include<iostream>
#include<vector>
using namespace std;
ingredientes::ingredientes(){

}

void ingredientes::insertar(const ingrediente & I){
		pair<bool,int> posd=BBdatos(I);
		pair<bool,int> posi=BBindice(I);
		if(!posi.first){
			for(unsigned int i=0; i<indice.size(); i++){
				if(indice[i] >= posd.second){
					indice[i]++;
				}
			}
			vector<ingrediente>::iterator itd=datos.begin();
			vector<int>::iterator iti=indice.begin();
			datos.insert(itd+posd.second,I);
			indice.insert(iti+posi.second, posd.second);
		}
}

pair<bool,int> ingredientes::BBdatos(const ingrediente & I){
pair<bool,int> post(false, indice.size());
	int inicio=0, fin=datos.size()-1;
	while(inicio<=fin){
		int mitad=(fin+inicio)/2;
		if(datos[mitad].getNombre()==I.getNombre()){
			post.first=true;
			post.second=mitad;
			return post;
		}else if(datos[mitad].getNombre()<I.getNombre()){
			inicio=mitad+1;
		}else{
			fin=mitad-1;
		}
	}
	post.second=inicio;
	return post;
}

pair<bool,int> ingredientes::BBindice(const ingrediente & I){
	pair<bool,int> post(false, indice.size());
	int inicio=0, fin=indice.size()-1;

	while(inicio<=fin){
		int mitad=(fin+inicio)/2;
		if(datos[indice[mitad]].getTipo()==I.getTipo() && datos[indice[mitad]].getNombre()==I.getNombre()){
			post.first=true;
			post.second = mitad;
			return post;
		}else if(datos[indice[mitad]].getTipo()==I.getTipo() && datos[indice[mitad]].getNombre()<I.getNombre()){
			inicio=mitad+1;
		}else if(datos[indice[mitad]].getTipo()==I.getTipo() && datos[indice[mitad]].getNombre()>I.getNombre()){
			fin=mitad-1;
		}else if(datos[indice[mitad]].getTipo()<I.getTipo()){
			inicio=mitad+1;
		}else{
			fin=mitad-1;
		}
	}
	post.second=inicio;
	return post;
}

void ingredientes::borrar(string & s){
	int posd=0;
	bool encontrado=false;
	for(unsigned int i=0; i<datos.size() && !encontrado; i++){
		if(datos[i].getNombre()==s){
			posd=i;
			encontrado=true;
			vector<ingrediente>::iterator it=datos.begin();
			datos.erase(it+posd);
		}
	}
	encontrado=false;
	for(unsigned int i=0; i<indice.size() && !encontrado; i++){
		if(indice[i]==posd){
			vector<int>::iterator it=indice.begin();
			indice.erase(i+it);
		}else if(indice[i]>posd){
			indice[i]=indice[i]-1;
		}
	}
}
string ingredientes::getInformacionIngrediente(string nombre){
	string info="";
	bool encontrado=false;
	for(unsigned int i=0; i<datos.size() && !encontrado; i++){
		if(datos[i].getNombre()==nombre){
			info="Nombre: ";
			info+=datos[i].getNombre();
			info+="\nCalorias: ";
			info+=datos[i].getCalorias();
			info+="\nHidratos: ";
			info+=datos[i].getHc();
			info+="\nProteinas: ";
			info+=datos[i].getProteinas();
			info+="\nGrasas: ";
			info+=datos[i].getGrasas();
			info+="\nFibra: ";
			info+=datos[i].getFibra();
			info+="\nTipo: ";
			info+=datos[i].getTipo();
			encontrado=true;
		}
	}
	return info;
}

ingredientes ingredientes::getIngredienteTipo(string tipo){
	ingredientes devuelve;
	bool stop2=false;
	for(unsigned int i=0; i<datos.size() && !stop2; i++){
		if(datos[indice[i]].getTipo()==tipo){
			devuelve.insertar(datos[indice[i]]);
			if(datos[indice[i+1]].getTipo()!=tipo){
				stop2=true;
			}
		}
	}
	return devuelve;
}

void ingredientes::modificaIngrediente(ingrediente I, int posicion){
	string nombre=datos[posicion].getNombre();
	this->borrar(nombre);
	this->insertar(I);
}

int ingredientes::size()const{
	return datos.size();
}

ingrediente ingredientes::get(string n){
	int pos=0;
	bool encontrado=false;
	for(unsigned int i=0; i<datos.size() && !encontrado; i++){
		if(datos[i].getNombre()==n){
			encontrado=true;
			pos=i;
		}
	}
	return datos[pos];
}

vector<string> ingredientes::getTipos(){
	vector<string> devuelve;
	string anterior=datos[indice[0]].getTipo();
	devuelve.push_back(anterior);
	for(unsigned int i=0; i<datos.size(); i++){
		if(anterior!=datos[indice[i]].getTipo()){
			anterior=datos[indice[i]].getTipo();
			devuelve.push_back(anterior);
		}
	}
	return devuelve;
}

void ingredientes::clear() {
	datos.clear();
	indice.clear();
}

void ingredientes::ImprimirPorTipo(ostream & os){
	for(unsigned int i=0; i<indice.size(); i++){
		os<<datos[indice[i]]<<endl;
	}
}

ingredientes & ingredientes::operator=(const ingredientes & I){
	for(unsigned int i=0; i<datos.size();){
		this->insertar(I[i]);
	}
	return *this;
}

ingrediente & ingredientes::operator[](int i){
		return datos[i];
}

const ingrediente & ingredientes::operator[](int i)const{
	return datos[i];
}

istream & operator>>(istream & is, ingredientes & I){
	I.clear();//metodo clear para limpiar I
	string linea;
	getline(is,linea);//para limpiar basura del txt
	ingrediente ing;
	while(is>>ing){
		I.insertar(ing);
	}
	return is;
}

ostream & operator<<(ostream & os, const ingredientes & I){
		for(int i=0;i<I.size(); i++){
			os<<I[i]<<"\n";
		}
		return os;
}
