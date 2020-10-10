//principal.cpp
#include "ingrediente.cpp"
#include<cstring>
#include<iostream>
using namespace std;
int main (){
	ingrediente nuevo1;
	string nom, tip;
	double cal, hid, pro, gra, fib;
	cin>>nom>>cal>>hid>>pro>>gra>>fib>>tip;
	ingrediente nuevo2(nom,cal,hid,pro,gra,fib,tip);
	cout<<nuevo1.getNombre()<<" "<<nuevo1.getTipo();
	cout<<"\n"<<nuevo2.getNombre()<<" "<<nuevo2.getTipo();
}
