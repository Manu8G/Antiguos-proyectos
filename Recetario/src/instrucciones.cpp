#include<iostream>
#include"instrucciones.h"
#include<stack>
#include"acciones.h"
#include"arbolbinario.h"

using namespace std;

instrucciones::instrucciones(){
}

void instrucciones::clear(){
  datos.clear();
}

ArbolBinario<string>::nodo instrucciones::getRaiz(){
  return datos.getRaiz();
}

ArbolBinario<string> & instrucciones::getDatos(){
  return datos;
}

const ArbolBinario<string> & instrucciones::getDatos()const{
  return datos;
}

acciones instrucciones::getAcciones(){
  return acc;
}

void instrucciones::addAcciones(acciones A){
  acc=A;
}

void instrucciones::setDatos(ArbolBinario<string> datos){
  this->datos=datos;
}

istream & operator>>(istream & is, instrucciones &I){
  I.clear();
  acciones A;
  string linea="", aux="";
  int pos=0;
  unsigned char num;
  stack<ArbolBinario<string>> p;
  while(!is.eof()){
    getline(is, linea);
    if(linea.size()>=1){
      pos=linea.find(' ');
      if(pos==-1){
        aux=linea;
        linea="";
      }else{
        aux=linea.substr(0, pos);
        linea.replace(0,pos+1,"");
      }
      if(I.getAcciones().buscar(aux)!=1 && I.getAcciones().buscar(aux)!=2){
        num=I.getAcciones().buscar(aux);
        ArbolBinario<string> d2(aux);
        if(num=='1'){
          if(linea!=""){
            d2.Insertar_Hi(d2.getRaiz(), linea);
          }else{
            // cout<<"F2"<<endl;
            d2.Insertar_Hi(d2.getRaiz(), p.top());
            p.pop();
          }
        }else{
          if(linea!=""){
            d2.Insertar_Hi(d2.getRaiz(), p.top());
            d2.Insertar_Hd(d2.getRaiz(), linea);
            p.pop();
          }else{
            d2.Insertar_Hi(d2.getRaiz(), p.top());
            p.pop();
            d2.Insertar_Hd(d2.getRaiz(), p.top());
            p.pop();
          }
        }
        p.push(d2);
        d2.clear();
      }
    }
  }
  I.setDatos(p.top());
  return is;
}

ostream & operator<<(ostream & os, const instrucciones & I){
  ArbolBinario<string>::postorden_iterador it = I.getDatos().beginpostorden();
  ArbolBinario<string>::postorden_iterador ite=I.getDatos().endpostorden();
  stack<ArbolBinario<string>::postorden_iterador> pila;
  while(it !=ite){
      if( !I.EsAccion((*it)) ){ //Si es un ingrediente o si es nodo hoja
          pila.push(it);
      }
      else{
          os << (*it) << " ";
          if(!pila.empty()){
              if(pila.size()==2){
                  os << (*pila.top()) << " ";
                  pila.pop();
              }
              os << (*pila.top());
              pila.pop();
          }
          cout<<endl;
      }
      ++it;
  }
  // os<<I.getDatos()<<endl;
  /*ArbolBinario<string>::postorden_iterador it=I.getDatos().beginpostorden();
  ArbolBinario<string>::postorden_iterador ite=I.getDatos().endpostorden();
  cout<<"\t";
  while(it!=ite){
    bool dentro=false;
    if((it.hi().nulo() || it.hd().nulo())&& !it.nulo() && !it.padre().nulo()){
      cout<<*(it.padre())<<" "<<*it;
      if((it.padre()).hd().nulo()){
      }else{
        if(!it.nulo()){
          ++it;
          cout<<" "<<*it;
        }
      }
      ++it;
      if(it!=ite){
          ++it;
      }
    }else{
      if(((it.hi().hi().nulo() || it.hi().hd().nulo()) && (it.hd().hi().nulo() || it.hd().hd().nulo()))&& !it.nulo()){
        cout<<(*it);
        ++it;
        dentro=true;
      }else if((it.hi().hi().nulo() || it.hi().hd().nulo()) || (it.hd().hi().nulo() || it.hd().hd().nulo()) && !dentro){
        if((it.hi().hi().nulo() && (it.hi().hd().nulo())&& !it.hi().nulo())){
          cout<<" "<<*(it.hi());
        }else if((it.hd().hi().nulo() && it.hd().hd().nulo())&& !it.hd().nulo()){
          cout<<" "<<*(it.hd());
        }
        ++it;
        dentro=true;
      }
    }
    cout<<endl<<"\t";
  }*/
  return os;
}

bool instrucciones::EsAccion(string nombre)const{
    bool es = true;
    if(acc.buscar(nombre)!=1 && acc.buscar(nombre)!=2){
      es=false;
    }
    return es;
}
