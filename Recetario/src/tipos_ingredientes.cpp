/**
*@file tipos_ingredientes.cpp
*Se ejecuta con-> prompt>bin/tipos_ingredientes datos/ingredientes.txt Molusco
*/
#include <iostream>
#include "ingrediente.h"
#include "ingredientes.h"
#include <fstream>
#include<cmath>
#include<vector>
using namespace std;
void MuestraParametros(){

	cout<<"1.- Dime el nombre del fichero con los ingredientes"<<endl;
}

int main(int argc, char *argv[])
{
	if (argc!=3){
		MuestraParametros();
		return 0;
	}
	string nf =argv[1];
	ifstream f(nf);
	if (!f){
		cout<<"No puedo abrir "<<nf<<endl;
		return 0;
	}
	ingredientes all_ingre;
	f>>all_ingre;
	vector<string> tipos=all_ingre.getTipos();
	cout<<"Los tipos de alimentos son:"<<endl;
	for (int i=0;i<tipos.size(); ++i){
		cout<<tipos[i]<<endl;
	}
	cout<<endl<<"--------------------------------------------------------------------"<<endl;
	string tipo=argv[2];
	ingredientes ingre_tipo=all_ingre.getIngredienteTipo(tipo);
	cout<<"Los ingredientes de tipo "<<tipo<<" son: "<<endl<<ingre_tipo<<endl;
	cout<<endl<<"--------------------------------------------------------------------"<<endl;
	cout<<"Estadistica________________________________"<<endl<<"Tipo de Alimento "<<tipo<<"Promedio +-Desviacion"<<endl;
	ingrediente Caloria_max=ingre_tipo[0], Hidratos_max=ingre_tipo[0], Proteinas_max=ingre_tipo[0], Grasas_max=ingre_tipo[0], Fibra_max=ingre_tipo[0];
	ingrediente Caloria_min=ingre_tipo[0], Hidratos_min=ingre_tipo[0], Proteinas_min=ingre_tipo[0], Grasas_min=ingre_tipo[0], Fibra_min=ingre_tipo[0];
	double media_cal=0.0, media_hc=0.0, media_pro=0.0, media_gra=0.0, media_fi=0.0;
	double varianza_cal=0.0, varianza_hc=0.0, varianza_pro=0.0, varianza_gra=0.0, varianza_fi=0.0;
	for(int i=0; i<ingre_tipo.size(); i++){
		//Calculo de maximo
		if(ingre_tipo[i].getCalorias()>Caloria_max.getCalorias()){
			Caloria_max=ingre_tipo[i];
		}
		if(ingre_tipo[i].getHc()>Hidratos_max.getHc()){
			Hidratos_max=ingre_tipo[i];
		}
		if(ingre_tipo[i].getProteinas()>Proteinas_max.getProteinas()){
			Proteinas_max=ingre_tipo[i];
		}
		if(ingre_tipo[i].getGrasas()>Grasas_max.getGrasas()){
			Grasas_max=ingre_tipo[i];
		}
		if(ingre_tipo[i].getFibra()>Fibra_max.getFibra()){
			Fibra_max=ingre_tipo[i];
		}
		//Calculo de minimo
		if(ingre_tipo[i].getCalorias()<Caloria_min.getCalorias()){
			Caloria_min=ingre_tipo[i];
		}
		if(ingre_tipo[i].getHc()<Hidratos_min.getHc()){
			Hidratos_min=ingre_tipo[i];
		}
		if(ingre_tipo[i].getProteinas()<Proteinas_min.getProteinas()){
			Proteinas_min=ingre_tipo[i];
		}
		if(ingre_tipo[i].getGrasas()<Grasas_min.getGrasas()){
			Grasas_min=ingre_tipo[i];
		}
		if(ingre_tipo[i].getFibra()<Fibra_min.getFibra()){
			Fibra_min=ingre_tipo[i];
		}
		//Calculo media
		media_cal+=ingre_tipo[i].getCalorias();
		media_hc+=ingre_tipo[i].getHc();
		media_pro+=ingre_tipo[i].getProteinas();
		media_gra+=ingre_tipo[i].getGrasas();
		media_fi+=ingre_tipo[i].getFibra();
	}
	media_cal/=ingre_tipo.size();
	media_hc/=ingre_tipo.size();
	media_pro/=ingre_tipo.size();
	media_gra/=ingre_tipo.size();
	media_fi/=ingre_tipo.size();

	//Calculo de la varianza
	for(int i=0; i<ingre_tipo.size(); i++){
		varianza_cal+=pow((ingre_tipo[i].getCalorias()-media_cal),2);
		varianza_hc+=pow((ingre_tipo[i].getHc()-media_hc),2);
		varianza_pro+=pow((ingre_tipo[i].getProteinas()-media_pro),2);
		varianza_gra+=pow((ingre_tipo[i].getGrasas()-media_gra),2);
		varianza_fi+=pow((ingre_tipo[i].getFibra()-media_fi),2);
	}
	varianza_cal=sqrt((varianza_cal/ingre_tipo.size()));
	varianza_hc=sqrt((varianza_hc/ingre_tipo.size()));
	varianza_pro=sqrt((varianza_pro/ingre_tipo.size()));
	varianza_gra=sqrt((varianza_gra/ingre_tipo.size()));
	varianza_fi=sqrt((varianza_fi/ingre_tipo.size()));

	cout<<"Calorias\t"<<"Hidratos de Carb\t"<<"Proteinas\t"<<"Grasas\t"<<"Fibra\t"<<endl;
	cout<<media_cal<<"+-"<<varianza_cal<<"\t"<<media_hc<<"+-"<<varianza_hc<<"\t"<<media_pro
			<<"+-"<<varianza_pro<<"\t"<<media_gra<<"+-"<<varianza_gra<<"\t"<<media_fi<<"+-"<<varianza_fi<<endl;
	cout<<"Minimos Valores\n"<<"Calorias(Alimento)\t"<<"Hidratos de Carb(Alimento)\t"
			<<"Proteinas(Alimento)\t"<<"Grasas(Alimento)\t"<<"Fibra(Alimento)\t"<<endl;
	cout<<Caloria_max.getCalorias()<<" "<<Caloria_max.getNombre()<<"\t"<<Hidratos_max.getHc()
			<<" "<<Hidratos_max.getNombre()<<"\t"<<Proteinas_max.getProteinas()<<" "<<Proteinas_max.getNombre()
			<<"\t"<<Grasas_max.getGrasas()<<" "<<Grasas_max.getNombre()<<"\t"<<Fibra_max.getFibra()
			<<" "<<Fibra_max.getNombre()<<endl;
	cout<<"Máximos Valores\n"<<"Calorias(Alimento)\t"<<"Hidratos de Carb(Alimento)\t"
			<<"Proteinas(Alimento)\t"<<"Grasas(Alimento)\t"<<"Fibra(Alimento)\t"<<endl;
	cout<<Caloria_min.getCalorias()<<" "<<Caloria_min.getNombre()<<"\t"<<Hidratos_min.getHc()
			<<" "<<Hidratos_min.getNombre()<<"\t"<<Proteinas_min.getProteinas()<<" "<<Proteinas_min.getNombre()
			<<"\t"<<Grasas_min.getGrasas()<<" "<<Grasas_min.getNombre()<<"\t"<<Fibra_min.getFibra()
			<<" "<<Fibra_min.getNombre()<<endl;
}
