#ifndef Nodo_h
#define Nodo_h
#include <iostream>
using namespace std;
template<class T>// un tipo de dato generico 
class Nodo
{
	private:
		T elemento; //elemento generico 
		Nodo<T>* prox;//apuntador a nodo generico
	public:	
		//Constructores					
		Nodo():prox(NULL){}//Sin parametros
		Nodo(T e):prox(NULL),elemento(e){}//Con parametro
		//Métodos de modificación
		void modificarElemento(T e){this->elemento=e;}
		void modificarProximo(Nodo<T>* sig){this->prox=sig;}
		//Métodos de Inspección
		Nodo<T>* proximo()const{return(this->prox);}
		T obt_elemento()const{return(this->elemento);}
};




#endif
