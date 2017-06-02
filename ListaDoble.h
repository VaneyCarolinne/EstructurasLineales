#ifndef ListaDoble_h
#define ListaDoble_h
#include "NodoDoble.h"
/********************************************************/
/*******************************************************/
/***Definición de la Clase Lista Doblemente Enlazada***/
/*************Autora: Vanessa Cruz********************/
/****************************************************/
/***************************************************/
template <class T>
class ListaDoble{
		//atributos:
		private:
			int longitud;
			NodoDoble<T> *primero;
		//métodos:	
		public:
			//Construtores de La Clase
			ListaDoble():primero(NULL),longitud(0){}
			ListaDoble(T e);
			ListaDoble(const ListaDoble &l);
			//Métodos de Inspeccion
			bool es_vacia(){return(primero==NULL);}
			T consultar(int pos);
			int obt_longitud(){return(longitud);}
			void mostrar();
			//Métodos de modificacion
			void insertar(T elem, int pos);
			void eliminar(int pos);
			void modificar(int pos, T e);
			void invertir();
			void invertir(NodoDoble<T> *p);
			void enlanzar(NodoDoble<T> *p);
			void vaciar();
			//Sobrecarga de Operadores:
			void operator=(const ListaDoble<T> &l);
			bool operator==(const ListaDoble<T> &l);
			ListaDoble<T>& operator +(const ListaDoble<T> &l);
			template<class A>
			friend std::ostream& operator<<(std::ostream& salida, const ListaDoble<A> &l); 
			//Destructor de la Clase	  
			~ListaDoble(); 
};
/******************************************/
/********Constructores de la Clase:*******/
/*****************************************/
template <class T>
ListaDoble<T>::ListaDoble(T e){
	primero->modificarElemento(e);
	primero->modificarAnterior(NULL);
	primero->modificarProximo(NULL);
	longitud=1;	
}
template <class T>
ListaDoble<T>::ListaDoble(const ListaDoble &l){	
	this=l;
}
/*****************************/
/****Métodos Modificadores:***/
/*****************************/
template <class T>
void ListaDoble<T>::insertar(T elem, int pos){
	NodoDoble<T> *nuevo=new NodoDoble<T>(elem),*ant,*sig,*aux;
	int i;

	if(pos<=longitud+1&&pos>0){	
		if(pos==1){
			nuevo->modificarProximo(primero);
			if(primero!=NULL)
				primero->modificarAnterior(nuevo);
			primero=nuevo;
		}
		else{
			i=2;
			ant=primero;
			sig=ant->proximo();		
			while(i<pos){
				ant=sig;
				sig=sig->proximo();	
				i++;					
			}
			ant->modificarProximo(nuevo);
			nuevo->modificarAnterior(ant);
			nuevo->modificarProximo(sig);
			if(sig!=NULL)
				sig->modificarAnterior(nuevo);
	    }	
   	    if(pos==longitud+1)
			nuevo->modificarProximo(NULL);	
	    longitud++;
	}else{
		cerr << "ERROR! Falló la operación Insertar" << endl;
	}	

}
template <class T>
void ListaDoble<T>::eliminar(int pos)
{
	NodoDoble<T> *nuevo,*ant,*sig;
	int i;
	if(pos<=0||longitud<pos){
		cerr << "ERROR: Se trato de eliminar una posicion inexistente" << endl;
	}else{
		if(pos==1){
			nuevo=new NodoDoble<T>(primero->obt_elemento());
			primero=primero->proximo();
			primero->modificarAnterior(NULL);
			delete(nuevo);
		}else{
			ant=primero;
			nuevo=ant->proximo();
			sig=nuevo->proximo();			
			i=2;
			while(i<pos){
			   ant=nuevo;
			   nuevo=sig;		
			   sig=sig->proximo();
			   i++;
			}
			ant->modificarProximo(sig);			 
			if(sig!=NULL)			
				sig->modificarAnterior(ant);
			delete(nuevo);
		     	
		}
		longitud--;
	}
}
template <class T>
void ListaDoble<T>::vaciar()
{
	NodoDoble<T> *act;
	
	while(primero!=NULL){
		act=new NodoDoble<T>(primero->obt_elemento());
		primero=primero->proximo();	
		delete(act);
	}
	primero=NULL;
	longitud=0;

}
template <class T>
void ListaDoble<T>::modificar(int pos, T e)
{
	NodoDoble<T> *nuevo;
	int i=1;

	if(primero!=NULL&&pos<=longitud&&pos>0){	
		nuevo=primero; 
		while(i<pos){
			nuevo=nuevo->proximo();
			i++;
		}
		nuevo->modificarElemento(e);
	}else{
		cerr << "ERROR: Se trato de modificar una posicion inexistente" << endl;
	}
}
template <class T>
void ListaDoble<T>::invertir()
{
	invertir(primero);
	enlanzar(primero);
}
template <class T>
void ListaDoble<T>::invertir(NodoDoble<T> *p)
{
	NodoDoble<T> *aux;
	
	
	if(p->proximo()!=NULL){	
			aux=p->proximo();
			invertir(aux);
			aux->modificarProximo(p);
			p->modificarProximo(NULL);
	}else{
			primero=p;
	}
	
}
template <class T>
void ListaDoble<T>::enlanzar(NodoDoble<T> *p)
{
	NodoDoble<T> *aux,*tmp;
	int i=1;
	p->modificarAnterior(NULL);
	tmp=p;
	aux=p->proximo();
	while(aux!=NULL){
		aux->modificarAnterior(tmp);
		tmp=aux;
		aux=aux->proximo();
	}	
}
/*****************************/
/***Métodos de Inspección:****/
/*****************************/
template <class T>
T ListaDoble<T>::consultar(int pos)
{
	int i;
	NodoDoble<T> *nuevo;
	
	if(pos>longitud||pos<=0){
		cerr << "ERROR: Se trato de consultar una posicion inexistente" << endl; 
		return(pos);
	}else{
		nuevo=primero;
		i=1;
		while(i<pos){
			nuevo=nuevo->proximo();
			i++;
		}
		return(nuevo->obt_elemento());
	}
}
template <class T>
void ListaDoble<T>::mostrar()
{
	NodoDoble<T> *ant,*sig;
	
	sig=primero;
	cout << "Para alante" << endl;
	while(sig!=NULL){
		cout << sig->obt_elemento() << " " ;
		ant=sig;
		sig=sig->proximo();
	}
	cout << endl;
	cout << "Para atrás" << endl;
	while(ant!=NULL){
		cout << ant->obt_elemento() << " " ;
		ant=ant->anterior();
	}
	cout << endl;
}
/*****************************/
/**Sobrecarga de Operadores:**/
/*****************************/
template <class T>
void ListaDoble<T>::operator=(const ListaDoble<T> &l)
{
	NodoDoble<T> *nuevo,*aux;
	if(this!=&l)
	{
	   if(l.primero!=NULL){
		nuevo=l.primero;
		primero=new NodoDoble<T>(nuevo->obt_elemento());
		aux=primero;			
		nuevo=nuevo->proximo();
		while(nuevo!=NULL){					
		  aux->modificarProximo(new NodoDoble<T>(nuevo->obt_elemento()));
		  aux=aux->proximo();	
		  aux->modificarAnterior(nuevo->anterior());	
		  nuevo=nuevo->proximo();
		}
		longitud=l.longitud;		
		}else{
			primero=NULL;
			longitud=0;
		}
    }	
}
template<class T>
bool ListaDoble<T>::operator==(const ListaDoble<T> &l)
{
	NodoDoble<T> *recibe,*aux,*aux2,*aux3;
	bool band;
	
        if(this!=&l)
        {
			if(longitud==l.longitud){
				band=true;
				recibe=primero;
				aux=l.primero;
				while(aux!=NULL&&band){
					if(recibe->obt_elemento()==aux->obt_elemento()){		
						recibe=recibe->proximo();
						aux=aux->proximo();
						if(recibe!=NULL&&aux!=NULL){
								aux2=recibe;
								aux3=aux;	
						}
					}else{
						band=false;
					}
				}
				recibe=aux2;
				aux=aux3;
				while(aux!=NULL&&band){
					if(recibe->obt_elemento()==aux->obt_elemento()){		
						recibe=recibe->anterior();
						aux=aux->anterior();
					}else{
						band=false;
					}	
				}
			}else{
				band=false;
			}	
        }
	return(band);
}
template<class T>
ListaDoble<T>& ListaDoble<T>::operator +(const ListaDoble<T> &l)
{
	NodoDoble<T> *aux2,*nuevo,*aux,*aux3;
	aux=primero;
	while(aux!=NULL)
	{
		aux2=aux;
		aux=aux->proximo();
	}
	aux3=l.primero;
	while(aux3!=NULL){
		aux2->modificarProximo(aux3);
		aux3->modificarAnterior(aux2);
		aux2=aux2->proximo();
		aux3=aux3->proximo();
    }
	longitud=longitud+l.longitud;
	return (*this);
}
template<class T>
std::ostream& operator<<(std::ostream& salida, const ListaDoble<T> &l)
{
	NodoDoble<T> *nuevo;
	
	nuevo=l.primero;
	while(nuevo!=NULL)
	{
		salida<<nuevo->obt_elemento()<< " ";
		nuevo=nuevo->proximo();
	}
	salida<<endl;
	return(salida);
}
/*********************************/
/**Único Destructor de la Clase:**/
/*********************************/
template <class T>
ListaDoble<T>::~ListaDoble()
{
	vaciar();
}

#endif
