#ifndef ACCIONES_H
#define ACCIONES_H

#include<iostream>
#include<map>

using namespace std;

class acciones{
  private:
      map<string, unsigned char> datos; //nombre de la accion || si es unaria o binaria

  public:
    /**
    *@brief Condtructor por defecto
    */
    acciones();
    /**
    *@brief Consultor de la ariedad de una accion
    *@param nombre: Nombre de la accion ha buscar
    *@return Devuelve unsigned char
    */
    unsigned char buscar(string nombre);
    unsigned char buscar(const string nombre)const;
    /**
    *@brief Vacia datos de accion
    */
    void clear();
    /**
    *@brief Añade una accion a datos
    *@param var: Accion a añadir
    */
    void add(pair<string, unsigned char> var);
    /**
    *@brief Sobrecarga del operator<< de acciones
    *@param os: Flujo de entrada
    *@param A: Accion ha mostrar
    *@return Devuelve el flujo
    */
    friend ostream &operator<<(ostream &os, const acciones &A);
    /**
    *@brief Sobrecarga del operator>> de acciones
    *@param is: Flujo de salida
    *@param A: Acciones a rellenar
    *@return Devuelve el flujo
    */
    friend istream & operator>>(istream & is, acciones & A);
};
#endif
