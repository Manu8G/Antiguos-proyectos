#include<iostream>
#include<math.h>

using namespace std;

int main(){	

	double tiempo_vuelo;	
	double Y_max,X_max;
	double angulo;
	double velocidad;
	const double gravedad=9.8;
	const double pi = 3.1415926535897;
	
	cout<<"Introduzca velocidad de lanzamiento(m/s): ";
	cin>>velocidad;
	cout<<"\nIntroduzca ángulo de evaluación en grados (0-90): ";
	cin>>angulo;
		
	angulo=(angulo*pi)/180;	
	tiempo_vuelo=(2*velocidad*sin(angulo))/gravedad;
	Y_max=(pow((velocidad*sin(angulo)),2))/(2*gravedad);
	X_max=(velocidad*cos(angulo))*((2*velocidad*sin(angulo))/gravedad);

	cout<<"\nTiempo de vuelo: "<<tiempo_vuelo<<" segundos";
	cout<<"\nAltura maxima: "<<Y_max<<" metros";
	cout<<"\nAlcance: "<<X_max<<" metros";
	
	return(0);
		
}

