//Nombre: Manuel Guerrero Mesias
//Dada una cadena buscar otra cadena en su interior y sustituirla
#include <iostream>

using namespace std;

int main(){
   char cuerpo[100], clave[100], c;
   int cont=0, lineas=0, ccuer, cclave, k, clineas[50];
   bool var=false, abortar = false;

   c= cin.get();
   while(c!= '#'){
      if(c == '\n'){
         clineas[lineas] = cont;
         lineas++;
      }
      cuerpo[cont] = c;
      //cout<<c<<endl;
      cont++;
      c= cin.get();
   }
   clineas[lineas] = cont;
   ccuer = cont;

   c= cin.get();
   cont = 0;
   while(c!= '#'){
      clave[cont] = c;
      c = cin.get();
      cont++;
   }
   cclave = cont;

   cont = 0;
   k = 0;

   cout<<"Texto de "<<lineas<<" lineas"<<endl;

   if(ccuer>0 && clave[cclave-1] != '\n'){
   for(int i=0; i<ccuer; i++){
      for(int j=k; j<clineas[i]; j++){  
         if(cuerpo[j] == clave[cont] || cuerpo[j] == clave[cont]+32
          || cuerpo[j]+32 == clave[cont]){
            var= true;
            cont++;
         }
         else{
            var= false;
            cont = 0;
         }
         if(var && cont == cclave){
            abortar= true;
            cout<<i+1<<": ";
            for(int x=k; x<clineas[i]; x++){
               cout<<cuerpo[x];
            }
            cout<<endl;
         }
      }
      k = clineas[i]+1;
   }
   }

   if(!abortar){
      cout<<"No es posible realizar la busqueda: ";
      if(ccuer!=0){
         if(clave[cclave-1] != '\n'){
            for(int i=0; i<cclave; i++){
               cout<<clave[i];
            }
         }
         else
            cout<<"clave multilinea."<<endl;
      }
      else
         cout<<"texto vacio."<<endl;
   }

   return 0;
   
};
