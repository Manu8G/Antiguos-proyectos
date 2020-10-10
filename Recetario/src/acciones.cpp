#include"acciones.h"


acciones::acciones(){
}

unsigned char acciones::buscar(string nombre){
  return datos[nombre];
}

unsigned char acciones::buscar(const string nombre)const{
  return datos[nombre];
}

void acciones::clear(){
  datos.clear();
}

void acciones::add(pair<string, unsigned char> var){
  datos.insert(var);
}

istream & operator>>(istream & is, acciones & A){
  A.clear();
  string linea="", aux="";
  unsigned char num=0;
  pair<string, unsigned char> var;
  int pos=0;
  getline(is, linea);
  while(linea.find(' ')!=-1){
    pos=linea.find(' ');
  	aux=linea.substr(0,pos);
    linea.replace(0,pos+1,"");
    num=linea[0];
    var.first=aux;
    var.second=num;
    A.add(var);
    getline(is, linea);
  }
  return is;
}
ostream &operator<<(ostream &os, const acciones &A){

    map<string, unsigned char>::const_iterator it;

    for (it = A.datos.cbegin(); it != A.datos.cend(); ++it)
        os << it->first << " " << it->second << endl;

    return os;
}
