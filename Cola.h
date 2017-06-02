#ifndef Cola_h
#define Cola_h
#include "Nodo.h"
template<class T>
class Cola
{
	private:
		Nodo<T> *primero,*ultimo;
	public:
		//Constructores de la clase
		Cola():primero(NULL),ultimo(NULL){} //sin Parámetros
		Cola(T elem);//Con Parámetros
		Cola(const Cola &c);//Copia
		//Métodos de Inspección
		bool es_vacia(){return(this->primero==NULL);}	
		T frente(){return(this->primero->obt_elemento());}
		void mostrar();
		//Métodos de Modificación
		void encolar(T elem);
		void desencolar();
		void destruir();
		//Destructor
		~Cola();

};

template <class T>
Cola<T>::Cola(T elem){
	this->primero->modificarElemento(elem);
	this->ultimo=this->primero;
	this->ultimo->modificarProximo(NULL);
}
template <class T>
Cola<T>::Cola(const Cola &c)
{
	Nodo<T> *nuevo,*aux;

	if(c.primero!=NULL){	
		nuevo=c.primero;
		this->primero=new Nodo<T>(nuevo->obt_elemento());
		aux=this->primero;
		this->ultimo=this->primero;
		nuevo=nuevo->proximo();
		while(aux!=NULL){
		     nuevo->modificarProximo(new Nodo<T>(aux->obt_elemento()));
		     nuevo=nuevo->proximo();
		     aux=aux->proximo();
		}	
		this->ultimo=nuevo;
	}else{
		this->primero=NULL;
		this->ultimo=NULL;
	}
}
template<class T>
void Cola<T>::destruir()
{
     Nodo<T> *act;

	while(this->primero!=NULL){
		act=this->primero;
		this->primero=this->primero->proximo();
		delete(act);
	}
	this->primero=NULL;
	this->ultimo=NULL;
}
template<class T>
Cola<T>::~Cola()
{
	destruir();
}

template <class T>
void Cola<T>::mostrar()
{
	Nodo<T> *nuevo;

	nuevo=this->primero;
	if(nuevo!=NULL){
		while(nuevo!=NULL){
			cout << nuevo->obt_elemento() << endl;
			nuevo=nuevo->proximo();
		}
	}else{
		cout << "No hay elementos en la Cola" << endl;
	}

}
template <class T>
void Cola<T>::encolar(T elem)
{
	Nodo<T> *nuevo;
	
	nuevo=new Nodo<T>(elem);
	if(this->primero==NULL){
		this->primero=nuevo;
		this->ultimo=nuevo;
	}else{
		if(this->primero==this->ultimo){
			this->ultimo=nuevo;
			this->primero->modificarProximo(this->ultimo);
		}else{
			this->ultimo->modificarProximo(nuevo);
			this->ultimo=nuevo;
		}
	}
}
template <class T>
void Cola<T>::desencolar()
{
	Nodo<T> *nuevo;
	if(this->primero!=NULL){
		if(this->primero==this->ultimo){
			nuevo=this->primero;
			this->primero=NULL;
			this->ultimo=NULL;
		}else{
			nuevo=this->primero;
			this->primero=this->primero->proximo();
		}
		delete(nuevo);
	}
}
#endif
