/**
*@file ingrediente.h
*@brief fichero cabecera del TDA ingrediente
*@brief Funcion de abstraccion: f(r)=r.nombre+r.calorias+r.hidratos+r.proteinas+r.grasas+r.fibra+r.tipo.
*@brief Invariante de la representacion: r.calorias>=0, r.hidratos>=0, r.proteinas>=0, r.grasas>=0, r.fibra>=0.
*/
#ifndef _INGREDIENTE_H
#define _INGREDIENTE_H
#include <cstring>
#include<iostream>
#include<stdlib.h>
using namespace std;
class ingrediente{
	private:
		string nombre;
		double calorias;
		double hidratos;
		double proteinas;
		double grasas;
		double fibra;
		string tipo;

	public:
		/**
		*@brief Constructor por defecto
		*/
		ingrediente();
		/**
		*@brief Constructor por parametros
		*@param nombre_: nombre del alimento
		*@param calorias_: cantidad de calorias del alimento
		*@param hidratos_: cantidad de hidratos de carbono del alimento
		*@param proteinas: cantidad de proteinas del alimento
		*@param grasas: cantidad de grasas del alimento
		*@param fibra: cantidad de fibra del alimento
		*@param tipo: tipo de alimento (carne, pescado, aceite..)
		*/
		ingrediente(string nombre_, double calorias_, double hidratos_, double proteinas_, double grasas_, double fibra_, string tipo_);
		/**
		*@brief Establece el valor del nombre
		*@param var: nombre del alimento que se va a establecer
		*/
		void setNombre(string var);
		/**
		*@brief Establece el valor de las calorias
		*@param var: calorias del alimento que se va a establecer
		*/
		void setCalorias(double var);
		/**
		*@brief Establece el valor de los hidratos de carbono
		*@param var: hidratos de carbono del alimento que se va a establecer
		*/
		void setHidratos(double var);
		/**
		*@brief Establece el valor de las proteinas
		*@param var: proteinas del alimento que se va a establecer
		*/
		void setProteinas(double var);
		/**
		*@brief Establece el valor de las grasas
		*@param var: grasas del alimento que se va a establecer
		*/
		void setGrasas(double var);
		/**
		*@brief Establece el valor de la fibra
		*@param var: fibra del alimento que se va a establecer
		*/
		void setFibra(double var);
		/**
		*@brief Establece el valor del tipo
		*@param var: tipo del alimento que se va a establecer
		*/
		void setTipo(string var);
		/**
		*@brief Consultor del nombre
		*@return devuelve el nombre del alimento
		*/
		string getNombre();
		/**
		*@brief Consultor del nombre
		*@return devuelve el nombre del alimento
		*/
		string getNombre()const;
		/**
		*@brief Consultor de las calorias
		*@return devuelve la cantidad de calorias del alimento
		*/
		double getCalorias()const;
		/**
		*@brief Consultor de los hidratos de carbono
		*@return devuelve la cantidad de hidratos de carbono del alimento
		*/
		double getHc()const;
		/**
		*@brief Consultor de las proteinas
		*@return devuelve la cantidad de proteinas del alimento
		*/
		double getProteinas()const;
		/**
		*@brief Consultor de las grasas
		*@return devuelve la cantidad de grasas del alimento
		*/
	 	double getGrasas()const;
		/**
		*@brief Consultor de la fibra
		*@return devuelve la cantidad de fibra del alimento
		*/
	 	double getFibra()const;
		/**
		*@brief Consultor del tipo
		*@return devuelve el tipo del alimento
		*/
	 	string getTipo()const;
		/**
		*@brief sobrecarga del operador de entrada
		*@param is: flujo de entrada
		*@param I: objeto de tipo ingredientes en el que almacenaremos la informacion del flujo
		*@return devuelve el flujo de entrada
		*/
		friend istream & operator>>(istream & is, ingrediente & I);
		/**
		*@brief sobrecarga del operador de salida
		*@param os: flujo de salida
		*@param I: objeto tipo ingredientes del que mostraremos los datos
		*/
		friend ostream & operator<<(ostream & os, const ingrediente & I);
};
#endif
