#ifndef RECETA_H
#define RECETA_H

#include<string>
#include<list>
#include<iostream>
#include"ingredientes.h"
#include"instrucciones.h"
#include"arbolbinario.h"

using namespace std;

class receta{
  private:
    string code;
    unsigned int plato;//1,2 o 3 indicando el numero de plato
    string nombre;
    list<pair<string, unsigned int>> ings;//nombre de ingrediente y cantidad
    float calorias, hc, grasas, proteinas, fibra;
    instrucciones inst;
  public:
    /**
    *@brief Constructor por defecto
    */
    receta();
    /**
    *@brief Contructor por parametros
    */
    receta(string code, unsigned int plato, string nombre, list<pair<string, unsigned int>> ings, float calorias, float hc, float grasas, float proteinas, float fibra);
    /**
    *@brief Devuelve el codigo
    *@return Devuelve un string
    */
    string getCode();
    /**
    *@brief Devuelve el plato
    *@return Devuelve un unsigned int
    */
    unsigned int getPlato();
    /**
    *@brief Devuelve el nombre
    *@return Devuelve un string
    */
    string getNombre();
    /**
    *@brief Devuelve la lista de ingredientes
    *@return Devuelve un list<pair<string, unsigned int>>
    */
    list<pair<string, unsigned int>> getIngredientes();
    /**
    *@brief Devuelve las calorias
    *@return Devuelve un float
    */
    float getCalorias();
    /**
    *@brief Devuelve los hidratos
    *@return Devuelve un float
    */
    float getHc();
    /**
    *@brief Devuelve las grasas
    *@return Devuelve un float
    */
    float getGrasas();
    /**
    *@brief Devuelve las proteinas
    *@return Devuelve un float
    */
    float getProteinas();
    /**
    *@brief Devuelve las fibra
    *@return Devuelve un float
    */
    float getFibra();

    instrucciones getInstrucciones();
    /**
    *@brief Devuelve el codigo
    *@return Devuelve un string
    */
    string getCode()const;
    /**
    *@brief Devuelve el plato
    *@return Devuelve un unsigned int
    */
    unsigned int getPlato()const;
    /**
    *@brief Devuelve el nombre
    *@return Devuelve un string
    */
    string getNombre()const;
    /**
    *@brief Devuelve la lista de ingredientes constante
    *@return Devuelve un list<pair<string, unsigned int>>
    */
    list<pair<string, unsigned int>> getIngredientes()const;
    /**
    *@brief Devuelve las calorias constantes
    *@return Devuelve un float
    */
    float getCalorias()const;
    /**
    *@brief Devuelve los hidratos constantes
    *@return Devuelve un float
    */
    float getHc()const;
    /**
    *@brief Devuelve las grasas constantes
    *@return Devuelve un float
    */
    float getGrasas()const;
    /**
    *@brief Devuelve las proteinas constantes
    *@return Devuelve un float
    */
    float getProteinas()const;
    /**
    *@brief Devuelve la fibra constantes
    *@return Devuelve un float
    */
    float getFibra()const;

    instrucciones getInstrucciones()const;
    /**
    *@brief Modifica el nombre
    *@param nombre: nuevo nombre
    */
    void setNombre(string nombre);
    /**
    *@brief Modifica el valor del codigo
    *@param code: nuevo codigo
    */
    void setCode(string code);
    /**
    *@brief Modifica el plato
    *@param plato: nuevo plato
    */
    void setPlato(unsigned int plato);
    /**
    *@brief Modifica la lista de ingredientes
    *@param ings: nueva lista de ingredientes
    */
    void setIngredientes(list<pair<string, unsigned int>> ings);
    /**
    *@brief Modifica las calorias
    *@param calorias: nuevas calorias
    */
    void setCalorias(float calorias);
    /**
    *@brief Modifica los hidratos
    *@param calorias: nuevos hidratos
    */
    void setHc(float hc);
    /**
    *@brief Modifica las grasas
    *@param calorias: nuevas grasas
    */
    void setGrasas(float grasas);
    /**
    *@brief Modifica las proteinas
    *@param calorias: nuevas proteinas
    */
    void setProteinas(float proteinas);
    /**
    *@brief Modifica la fibra
    *@param calorias: nueva fibra
    */
    void setFibra(float fibra);

    void setItDatos(ArbolBinario<string> datos);

    void setInstrucciones(instrucciones inst);
    /**
    *@brief Vacia la lista de ingredientes
    */
    void clear();
    /**
    *@brief Devuelve el tamaño de la lista de ingredientes
    *@return Devuelve un int
    */
    int size();
    /**
    *@brief Añade un ingrediente a la lista
    *@param var: nuevo ingrediente a insertar en la lista
    */
    void insertarIngrediente(pair<string, unsigned int> var);
    /**
    *@brief Calcula las calorias, grasas, proteinas, fibra e hidratos de la receta
    *@param I: Objeto que contiene todos los ingredientes ingredientes
    */
    void calcularValores(ingredientes I);
    /**
    *@brief Devuelve el numero de ingredientes en la lista
    */
    int ningredientes();

    receta fusionar(receta & uno, receta & dos);

    /**
    *@brief Sobrecarga del operator de entrada
    *@param is: flujo de entrada
    *@param R: objeto que se va a mostrar
    */
    friend istream & operator>>(istream & is, receta & R);
    /**
    *@brief sobrecarga del operador de salida
    *@param os: flujo de salida
    *@param I: objeto que se va a mostrar
    */
    friend ostream &operator<<(ostream & os, const receta & R);


//--------------------------------iterator------------------------------//


    class iterator{
      private:
        list<pair<string, unsigned int>>::iterator it;

      public:
        /**
        *@brief Constructor por defecto
        */
        iterator(){};
        /**
        *@brief Sobrecarga del operator *
        *@return Devuelve un pair<string, unsigned int>
        */
        pair<string,unsigned int> & operator*(){
          return *it;
        }
        /**
        *@brief Sobrecarga del operator ==
        *@return Devuelve un bool con el resultado de la comprobacion
        */
        bool operator==(const iterator & otro){
          return it==otro.it;
        }
        /**
        *@brief Sobrecarga del operator ++
        *@return Devuelve el propio objeto
        */
        iterator & operator++(){
          it++;
          return *this;
        }
        /**
        *@brief Sobrecarga del operator --
        *@return Devuelve el propio objeto
        */
        iterator & operator--(){
          it--;
          return *this;
        }
        /**
        *@brief Sobrecarga del operatro !=
        *@return Devuelve el propio objeto
        */
        bool operator!=(const iterator & otro){
          return !(it==otro.it);
        }
        friend class receta;
        friend class const_iterator;
    };


//--------------------------------const_iterator------------------------------//


    class const_iterator{
      private:
        list<pair<string, unsigned int>>::const_iterator it;

      public:
        /**
        *@brief Constructor por defecto
        */
        const_iterator(){};
        /**
        *@brief Constructor de copia
        */
        const_iterator(const iterator & otro){
          it=otro.it;
        }
        /**
        *@brief Sobrecarga del operator *
        *@return Devuelve un pair<string, unsigned int>
        */
        const pair<string, unsigned int> & operator*(){
          return *it;
        }
        /**
        *@brief Sobrecarga del operator ==
        *@param otro: El const iterator con el que se va a comparar
        *@return Devuelve un bool con el resultado de la comprobacion
        */
        const bool operator==(const const_iterator & otro){
          return it==otro.it;
        }
        /**
        *@brief Sobrecarga del operator ++
        *@return Devuelve el propio objeto
        */
        const_iterator & operator++(){
          it++;
          return *this;
        }
        /**
        *@brief Sobrecarga del operator --
        *@return Devuelve el propio objeto
        */
        const_iterator & operator--(){
          it--;
          return *this;
        }
        /**
        *@brief Sobrecarga del operator !=
        *@param otro: EL const_iterator con el que se va a comparar
        *@return Devuelve un bool con el resultado de la operacion
        */
        const bool operator!=(const const_iterator & otro){
          return !(it==otro.it);
        }

        friend class receta;
    };
    /**
    *@brief Devuelve la primera posicion de los ingredientes
    *@return Devuelve un iterator
    */
    iterator begin(){
      iterator i;
      i.it=ings.begin();
      return i;
    }
    /**
    *@brief Devuelve la ultima posicion de los ingredientes
    *@return Devuelve un iterator
    */
    iterator end(){
      iterator i;
      i.it=ings.end();
      return i;
    }
    /**
    *@brief Devuelve la primera posicion de los ingredientes
    *@return Devuelve un const_iterator
    */
    const_iterator begin()const{
      const_iterator i;
      i.it=ings.cbegin();
      return i;
    }
    /**
    *@brief Devuelve la ultima posicoin de los ingredientes
    *@return Devuelve un const_iterator
    */
    const_iterator end()const{
      const_iterator i;
      i.it=ings.cend();
      return i;
    }

};

#endif
