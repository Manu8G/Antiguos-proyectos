/**
*@file ingredientes.h
*@brief fichero cabecera del TDA ingredientes
*@brief Funcion de abstraccion: f(r)=r.datos+r.indice
*@brief Invariante de la representacion: datos.size()==indice.size()
*/
#ifndef INGREDIENTES_H
#define INGREDIENTES_H
#include<vector>
#include<iostream>
#include<cstring>
#include"ingrediente.h"

class ingredientes{
	private://mira en la carpeta datos para ver como es la entrada de datos
		vector<ingrediente> datos; //organizacion 1-por nombre
		vector<int> indice; //organizacion 2-por tipo y nombre
	public:
		/**
		*@brief Constructor por defecto
		*/
		ingredientes();
		/**
		*@brief Funcion de insercion de elementos en los vectores de datos e indice respetando el orden
		*@param I: ingrediente a insertar en el vector de datos
		*/
		void insertar(const ingrediente & I);
		/**
		*@brief Busca la posicion en la que insertaremos el nuevo elemento en datos
		*@param I: ingrediente del que buscaremos la posicion a insertar
		*@return Devuelve un pair con un bool y un int
		*/
		pair<bool,int> BBdatos(const ingrediente & I);
		/**
		*@brief Busca la posicion en la que insertaremos en nuevo elemento en indice
		*@param I: ingrediente del que buscaremos la posicion a insertar
		@return Devuelve un pair con un bool y un int
		*/
		pair<bool,int> BBindice (const ingrediente & I);
		/**
		*@brief Borra un elemento con el nombre s y reordena el vector
		*@param s: nombre del ingrediente a buscar
		*/
		void borrar(string & s);
		/**
		*@brief Devuelve la informacion completa del ingrediente nombre
		*@param nombre: nombre del ingrediente a buscar
		*@return Devuelve la informacion del ingrediente
		*/
		string getInformacionIngrediente(string nombre);
		/**
		*@brief Devuelve un objeto ingredientes con los ingredientes de tipo 'tipo'
		*@param tipo: tipo de ingrediente a buscar
		*@return Devuelve los ingredientes de dicho tipo
		*/
		ingredientes getIngredienteTipo(string tipo);
		/**
		*@brief Modifica el ingrediente
		*@param I: ingrediente a insertar en datos
		*@param posicion: posicion del ingrediente a eliminar
		*/
		void modificaIngrediente(ingrediente I, int posicion);
		/**
		*@brief Consultor del tamaño del vector
		*@param Devuelve el tamaño del vector
		*/
		int size()const;
		/**
		*@brief Devuelve el ingrediente de nombre n
		*@param n: nombre del ingrediente a devolver
		*@return Devuelve el ingrediente con dicho nombre
		*/
		ingrediente get(string n);
		/**
		*@brief Da los tipos de los ingredientes
		*@return Devuelve un vector con los tipos de ingredientes en datos
		*/
		vector<string> getTipos();
		/**
		*@brief Metodo para vaciar datos e indice
		*/
		void clear();
		/**
		*@brief Imprime los ingredientes de datos segun el orden de sus tipos
		*@param os: flujo de salida
		*/
		void ImprimirPorTipo(ostream & os);
		/**
		*@brief Sobrecarga del operador =
		*@return Devuelve la referencia al nuevo objeto
		*/
		ingredientes & operator=(const ingredientes & I);
		/**
		*@brief Sobrecarga del operador []
		*@param i: posicion del ingrediente a devolver
		*@return Devuelve el ingrediente con indice i
		*/
		ingrediente & operator[](int i);
		/**
		*@brief Sobrecarga del operador [] con devolucion constante
		*@param i: posicion del ingrediente a devolver
		*@return Devuelve el ingrediente constante con indice i
		*/
		const ingrediente & operator[](int i)const;
		/**
		*@brief Sobrecarga del operador de entrada
		*@param I: objeto de tipo ingredientes donde se guardara los elementos entrantes
		*/
		friend istream & operator>>(istream & is, ingredientes & I);
		/**
		*@brief Sobrecarga del operador de salida
		*@param os: flujo de salida
		*@param I: objeto que se va a mostrar
		*/
		friend ostream &operator<<(ostream & os, const ingredientes & I);

		class iterator{
			private:
				vector<ingrediente>::iterator it;
			public:
				/**
				*@brief Constructor por defector del iterator de ingredientes
				*/
				iterator(){};
				/**
				*@brief Sobrecarga del operator * del iterator de ingredientes
				*@return Devuelve el ingrediente al que apunta el iterator
				*/
				ingrediente & operator*(){
					return *it;
				}
				/**
				*@brief Sobrecarga del operator == del iterator de ingredientes
				*@param otro: iterator con el que se va a comparar
				@return Devuelve un bool con el resultado de la comprobacion
				*/
				bool operator==(const iterator & otro){
					return it==otro.it;
				}
				/**
				*@brief Sobrecarga del operator ++ del iterator de ingredientes
				*@return Devuelve el propio objeto
				*/
				iterator & operator++(){
					it++;
					return *this;
				}
				/**
				*@brief Sobrecarga del operator -- del iterator de ingredientes
				*@return Devuelve el propio objeto
				*/
				iterator & operator--(){
					it--;
					return *this;
				}
				/**
				*@brief Sobrecarga del operator != del iterator de ingredientes
				*@param otro: iterator con el que se va a comparar
				*@return Devuelve un bool con el resultado de la comprobacion
				*/
				bool operator!=(const iterator & otro){
					return !(it==otro.it);
				}
				friend class ingredientes;
				friend class const_iterator;
		};
		class const_iterator{
			private:
				vector<ingrediente>::const_iterator it;
			public:
				/**
				*@brief Constructor por defecto del const_iterator de ingredientes
				*/
				const_iterator(){};
				/**
				*@brief Constructor de copia del const_iterator de la clase ingredientes
				*@param otro: iterator del que se a copiar
				*/
				const_iterator(const iterator & otro){
					it=otro.it;
				}
				/**
				*@brief Sobrecarga del operator * del const_iterator de ingredientes
				*@return Devuelve el ingrediente constante al que apunta el const_iterator
				*/
				const ingrediente & operator*(){
					return *it;
				}
				/**
				*@brief Sobrecarga del operator == del const_iterator de ingredientes
				*@param otro: const_iterator con el que se va a comparar
				*@param Devuelve un bool constante con el resultado de la comprobacion
				*/
				const bool operator==(const const_iterator & otro){
					return it==otro.it;
				}
				/**
				*@brief Sobrecarga del operator ++ del const_iterator de ingredientes
				*@return Devuelve el propio objeto
				*/
				const_iterator & operator++(){
					it++;
					return *this;
				}
				/**
				*@brief Sobrecarga del operator -- del const_iterator de ingredientes
				@return Devuelve el propio objeto
				*/
				const_iterator & operator--(){
					it--;
					return *this;
				}
				/**
				*@brief Sobrecarga del operator != del const_iterator de ingredientes
				*@return Devuelve un bool constante con el resultado de la comparacion
				*/
				const bool operator!=(const const_iterator & otro){
					return !(it==otro.it);
				}
				friend class ingredientes;
		};
		/**
		*@brief Devuelve la primera posicion del vector que contiene los ingredientes
		*@return Devuelve un iterator
		*/
		iterator begin(){
			iterator i;
			i.it=datos.begin();
			return i;
		}
		/**
		*@brief Devuelve la ultima posicion del vector que contiene los ingredientes
		*@return Devuelve un iterator
		*
		*/
		iterator end(){
			iterator i;
			i.it=datos.end();
			return i;
		}
		/**
		*@brief Devuelve la primera posicion del vector que contiene los ingredientes
		*@return Devuelve un const_iterator
		*/
		const_iterator begin()const{
			const_iterator i;
			i.it=datos.begin();
			return i;
		}
		/**
		*@brief Devuelve la primera posicion del vector que contiene los ingredientes
		*@return Devuelve un const_iterator
		*/
		const_iterator end()const{
			const_iterator i;
			i.it=datos.end();
			return i;
		}

};
#endif
