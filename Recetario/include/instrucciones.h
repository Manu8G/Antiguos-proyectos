#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include<iostream>
#include"acciones.h"
#include"arbolbinario.h"

using namespace std;

class instrucciones{
  private:
    ArbolBinario<string> datos;
    acciones acc;

  public:
    /**
    *@brief Constructor por defecto
    */
    instrucciones();
    /**
    *@brief Vacia datos
    */
    void clear();
    /**
    *@brief Consultor de la raiz de datos
    *@return Devuelve un ArbolBinario<string>::nodo
    */
    ArbolBinario<string>::nodo getRaiz();
    /**
    *@brief Consultor de datos
    *@return Devuelve un ArbolBinario<string>
    */
    ArbolBinario<string> & getDatos();
    /**
    *@brief Consultor constante de datos
    *@return Devuelve un ArbolBinario<string> constante
    */
    const ArbolBinario<string> & getDatos()const;
    /**
    *@brief Devuelve las acciones
    *@return Devuelve un objeto acciones
    */
    acciones getAcciones();
    /**
    *@brief Iguala el objeto acc a las acciones
    *@param A: Las acciones que se van a establecer en el objeto
    */
    void addAcciones(acciones A);
    /**
    *@brief Establece el ArbolBinario de instrucciones
    *@param datos: ArbolBinario al que se va a igualar
    */
    void setDatos(ArbolBinario<string> datos);
    /**
    *@brief Sobrecarga del operator>> de acciones
    *@param is: Flujo de entrada
    *@param A: Acciones a rellenar
    *@return Devuelve el flujo istream
    */
    friend istream & operator>>(istream & is, instrucciones &I);
    /**
    *@brief Sobrecarga del operator<< de acciones
    *@param is: Flujo de salida
    *@param A: Acciones a mostrar
    *@return Devuelve el flujo ostream
    */
    friend ostream & operator<<(ostream & os, const instrucciones & I);
    bool EsAccion(string nombre)const;
};
#endif
