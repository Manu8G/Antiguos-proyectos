//Ejercicio de estadistica con una ecuacion de Gauss

#include<iostream>                 //Introduccion de elementos de E/S
#include<cmath>                    //Introduccion de elementos matematicos
using namespace std;

int main(){
	
	double esperanza;               //Variable de la esperanza
	double desviacion_tipica;       //Variable de la desviacion tipica
	double x;                       //variable del eje de abcisas
	const double PI=3.1415;         //Constante pi
	double solucion;                //posicion de la funcion gaussiana dados los anteriores valores
	
	cout << "Introduzca la esperanza:";
	cin >> esperanza;
	cout << "Introduzca la desviacion tipica:";
	cin >> desviacion_tipica;
	cout << "Introduzca el punto en el eje x:";
	cin >> x;
	
	solucion=exp(-0.5*(pow(((x-esperanza)/desviacion_tipica),2)))/(desviacion_tipica*sqrt(2*PI));
	
	cout << "Este es el valor de la ecuacion gaussiana:" << solucion;
	
	return (0);
	
}	
