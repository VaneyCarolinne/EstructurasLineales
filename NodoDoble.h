#ifndef NodoDoble_h
#define NodoDoble_h
#include <iostream>
using namespace std;
template<class T>// un tipo de dato generico 
class NodoDoble
{
	private:
		T elemento; //elemento generico 
		NodoDoble<T> *prox, *ant;//apuntador a nodo generico
	public:	
		//Constructores					
		NodoDoble():prox(NULL),ant(NULL){}//Sin parametros
		NodoDoble(T e):prox(NULL),ant(NULL),elemento(e){}//Con parametro
		//Métodos de modificación
		void modificarElemento(T e){this->elemento=e;}
		void modificarProximo(NodoDoble<T>* sig){this->prox=sig;}
		void modificarAnterior(NodoDoble<T>* p){this->ant=p;}
		//Métodos de Inspección
		NodoDoble<T>* proximo()const{return(this->prox);}
		NodoDoble<T>* anterior()const{return(this->ant);}
		T obt_elemento()const{return(this->elemento);}
};

#endif
