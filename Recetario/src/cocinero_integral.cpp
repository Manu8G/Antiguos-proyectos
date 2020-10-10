/*
Pasos a seguir:
1. Cargar en memoria las acciones
2. Cargar en memoria los ingredientes
3. Cargar en memoria las recetas
4. Obtener el valor nutricional de todas las recetas usando los ingredientes
5. Escribir el código, nombre y plato de todas las recetas
6. Preguntar al usuario sobre que código de receta quiere obtener la información
7. Mostrar la información completa de la receta. Esto implica mostrar los nombres de los
ingredientes con sus cantidades, valor nutricional de la receta y pasos a seguir para crear
la receta
8. Pedir al usuario dos códigos de recetas a fusionar
9. Obtener una nueva receta fusión creada a partir de las dos recetas dadas en el paso 8.
10. Mostrar toda la información completa de la receta fusión como se hizo en el paso 7.


Mirar punto 4 para representacion

*/
#include<iostream>
#include"recetas.h"
#include"receta.h"
#include"ingrediente.h"
#include"ingredientes.h"
#include"acciones.h"
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fstream>
#include"color.h"

using namespace std;

int main(int argc,char *argv[]){
  ifstream f(argv[1]);
  acciones acc;
  recetas rall;
  ingredientes ings;
  ifstream g(argv[2]);
  ifstream h(argv[3]);

  f>>acc;
  g>>rall;
  h>>ings;
  rall.calcularValores(ings);
  //----------------------------------------------------PARTE EXPERIMENTAL--------------
  instrucciones ins;
  ins.addAcciones(acc);
  if(DIR *pDIR=opendir(argv[4])){
    while(dirent*entry=readdir(pDIR)){
      string fileName=entry->d_name;//R5m.txt
      if(fileName!="."&& fileName!=".."){
        cout<<"Fichero a introducir: "<<fileName<<endl;
        string archivo_instruccion=argv[4]+fileName;
        ifstream myfile(archivo_instruccion);
        myfile>>ins;
        cout<<"Contenido arbol despues de inserccion->\n"<<ins<<endl;
        string receta;
        size_t pos=fileName.find("m");
        receta=fileName.substr(0,pos);
        rall[receta].setInstrucciones(ins);
      }
    }
  }

   for(recetas::iterator it=rall.begin(); it!=rall.end(); ++it){
     cout<<*it<<"\n\n\n---------------------------------------------------------------------------\n\n\n";
   }

  cout<<"Las recetas son:\n";
  for(recetas::iterator it=rall.begin(); it!=rall.end(); ++it){
    cout<<FBLU("CODE: ")<<(*it).getCode()<<"\t"<<FBLU("NOMBRE: ")<<(*it).getNombre()<<"\t"<<FBLU("PLATO: ")<<(*it).getPlato()<<endl;
  }
  string cod1, cod2, cod3;
  cout<<"\nIntroduce el codigo de una receta: ";
  cin>>cod1;
  cout<<rall[cod1];

  cout<<"\nIntroduce el codigo de dos recetas a fusionar: ";
  cout<<"\nReceta 1:";
  cin>>cod2;
  cout<<"\nReceta 2:";
  cin>>cod3;
  cout<<rall.fusionar(cod2,cod3);
  string ncod="F_"+cod2+"_"+cod3;
  cout<<"\n\nf"<<rall[ncod];

  return(0);

}
