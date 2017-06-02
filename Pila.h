#ifndef Pila_h
#define Pila_h
#include "Nodo.h"
template<class T>
class Pila 
{
	private:
	Nodo<T> *primero;
	public:
	//Constructores:					
	  Pila<T>():primero(NULL){} //Sin Párametros
	  Pila(T e); // Con Párametros
	  Pila(const Pila &p);//constructor Copia
	  //Métodos de inspección:	
	  bool es_vacia(){return(this->primero==NULL);}	
	  T tope(){return(this->primero->obt_elemento());}
	  void mostrar();
	  //Métodos de modificación:
	  void apilar(T elem);
          void desapilar();
	  void destruir();
	  //Destructor:
	  ~Pila();

};

template <class T>
Pila<T>::Pila(T e){
	this->primero->modificarElemento(e);
	this->primero->modificarProximo(NULL);
}
template <class T>
Pila<T>::Pila(const Pila &p)
{
	Nodo<T> *nuevo,*aux;

	if(p.primero!=NULL){	
		nuevo=p.primero;
		this->primero=new Nodo<T>(nuevo->obt_elemento());
		aux=this->primero;
		nuevo=nuevo->proximo();
		while(aux!=NULL){
		     nuevo->modificarProximo(new Nodo<T>(aux->obt_elemento()));
		     nuevo=nuevo->proximo();
		     aux=aux->proximo();
		}	
	}else{
		this->primero=NULL;
	}
}
template <class T>
void Pila<T>::apilar(T elem)
{
	Nodo<T> *nuevo;
	
	nuevo=new Nodo<T>(elem);
	nuevo->modificarProximo(this->primero);
	this->primero=nuevo;
}
template <class T>
void Pila<T>::desapilar()
{
	Nodo<T> *nuevo;
	
	if(this->primero!=NULL){
	 nuevo=this->primero;
	 this->primero=this->primero->proximo();
	 delete(nuevo);
	}
}
template<class T>
void Pila<T>::destruir()
{
     Nodo<T> *act;

	while(this->primero!=NULL){
		act=this->primero;
		this->primero=this->primero->proximo();
		delete(act);
	}
	this->primero=NULL;
}
template<class T>
Pila<T>::~Pila()
{
	destruir();
}

template <class T>
void Pila<T>::mostrar()
{
	Nodo<T> *nuevo;

	nuevo=this->primero;
	if(nuevo!=NULL){
		while(nuevo!=NULL){
			cout << nuevo->obt_elemento() << endl;
			nuevo=nuevo->proximo();
		}
	}else{
		cout << "No hay elementos en la Pila" << endl;
	}

}
#endif
