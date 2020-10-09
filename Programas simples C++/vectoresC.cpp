//Nombre: Manuel Guerrero Mesias
//Este programa busca encontrar una cadena de caracteres en otra y sustituirla por otra diferente
#include<iostream>

using namespace std;

int main(){
	char cuerpo[100];
	char clave[100];
	char c;
	int i=0, cont=0, cont2=0, aux=0; //cont contador del cuerpo, cont2 contador de la clave
	bool stop=false, stop2=false;
	int lineas=0;
	int clineas[50];
	c=cin.get();
	while(c!='#'){
		if(c=='\n'){
			clineas[lineas]=i;
			lineas++;
		}
		cuerpo[i]=c;		
		i++;
		c=cin.get();
	}
	clineas[lineas]=i;
	c=cin.get();
	cont=i;
	i=0;
	while(c!='#'){	
		clave[i]=c;	
		i++;
		c=cin.get();
	}	
	cont2=i;
	i=0;
	cout<<"\nTexto de "<<lineas<<" l�neas\n";
	
	if(cont>0 && clave[cont2-1]!='\n'){
		for(int j=0; j<cont; j++){
			for(int k=aux; k<clineas[j];k++){
				if(cuerpo[k]==clave[i] || cuerpo[k]+32==clave[i] || cuerpo[k]==clave[i]+32){
					stop=true;
					i++;
				}else{
					stop=false;
					i=0;
				}
				if(stop && i==cont2){
					stop2=true;
					cout<<j+1<<": ";
					for(int l=aux; l<clineas[j]; l++){
						cout<<cuerpo[l];
					}
					cout<<endl;
				}
			}
			aux=clineas[j]+1;	
		}
		
	}
	if(!stop2){
		if(cont<0){
			cout<<"No es posible realizar la busqueda: Texto vacio\n";
		}else if(clave[cont2-1]=='\n'){
			cout<<"No es posible realizar la busqueda: clave multilinea\n";
		}	
	}
	
	return(0);	
}
