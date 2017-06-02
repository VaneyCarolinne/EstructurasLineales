#ifndef Lista_h
#define Lista_h
#include "Nodo.h"
template<class T>
class Lista
{
	private:
	  Nodo<T> *primero; //Apuntador a nodo génerico
	  int cantidad; //Longitud de la lista
	public:	
	  //Constructores:					
	  Lista<T>():primero(NULL),cantidad(0){} //Sin Párametros
	  Lista(T e); // Con Párametros
	  Lista(const Lista &l);//constructor Copia
	  //Métodos de inspección:	
	  bool es_vacia(){return(this->primero==NULL);}
	  T consultar(int pos);
	  int longitud(){return(this->cantidad);}
	  int Busqueda(T e);
	  void mostrar();
	  bool sublista(Lista<T> &x);
	  //Métodos de modificación:
	  void insertar(T elem, int pos);
	  void eliminar(int pos);
	  void destruir();
	  void modificar(T elem, int pos);
	  void invertir(){invertir(this->primero);}
	  void invertir(Nodo<T> *dir);	
	  //Sobrecarga de Operadores:
	  void operator=(const Lista<T> &l);//asignación
	  bool operator==(const Lista<T> &l);//comparación
	  Lista<T>& operator +(const Lista<T>& a);//concatenación 
	  //Destructores:	  
       	  ~Lista(); 

};
//Constructores 
template <class T>
Lista<T>::Lista(T e){
	this->primero->modificarElemento(e);
	this->primero->modificarProximo(NULL);
	this->cantidad=1;
}
template <class T>
Lista<T>::Lista(const Lista &l)
{
	Nodo<T> *nuevo,*aux;

	if(l.primero!=NULL){	
		nuevo=l.primero;
		this->primero=new Nodo<T>(nuevo->obt_elemento());
		aux=this->primero;
		nuevo=nuevo->proximo();
		while(aux!=NULL){
		     nuevo->modificarProximo(new Nodo<T>(aux->obt_elemento()));
		     nuevo=nuevo->proximo();
		     aux=aux->proximo();
		}	
		this->cantidad=l.cantidad;
	}else{
		this->primero=NULL;
		this->cantidad=0;
	}
}
//Métodos de modificación:
template<class T>
void Lista<T>::invertir(Nodo<T> *dir)
{
	Nodo<T> *nuevo;
	
	if(dir!=NULL&&dir->proximo()!=NULL){
		nuevo=dir->proximo();
		invertir(nuevo);
		nuevo->modificarProximo(dir);
		dir->modificarProximo(NULL);
	}else{
		this->primero=dir;
	}
}
template<class T>
void Lista<T>::modificar(T elem, int pos)
{
	Nodo<T> *nuevo;
	int i;

	nuevo=this->primero;
	i=1;
	while(i!=pos)
	{
		i++;
		nuevo=nuevo->proximo();	
	}	
	if(i==pos&&nuevo!=NULL){
	   nuevo->modificarElemento(elem);
	}
}

template<class T>
void Lista<T>::insertar(T elem, int pos)
{
	Nodo<T> *ant,*sig,*nuevo;
	int i;

    if(pos<=this->cantidad+1&&pos>0){
      nuevo=new Nodo<T>(elem);
      if(nuevo!=NULL){	
	if(pos==1&&es_vacia()){ //Insertar al principio
	 nuevo->modificarProximo(this->primero);
	 this->primero=nuevo;
	}else{ //Insertar en el centro
	 	ant=this->primero;
	 	sig=ant->proximo();
	 	i=2;
		while(i<pos&&sig!=NULL)
		{
			ant=sig;
			sig=sig->proximo();
			i++;
		};
		ant->modificarProximo(nuevo);
		nuevo->modificarProximo(sig);
	}
	if(pos==this->cantidad+1){
		nuevo->modificarProximo(NULL);
	}
	this->cantidad++;
	/*cout << "Operación exitosa al Insertar elemento !" << endl;*/
      }
    }else{
	cout << "Fallo la operación Insertar" << endl;
    }
}

template<class T>
void Lista<T>::eliminar(int pos)
{
	Nodo<T> *ant,*act,*sig;
	int i;

     if(!es_vacia()&&pos<=this->cantidad&&pos!=0){
	if(pos==1){
	 act=this->primero;
	 this->primero=act->proximo();
	 delete(act);
	}else{
		ant=this->primero;
		act=ant->proximo();
		sig=act->proximo();
		i=2;
		while(i<pos&&sig!=NULL){
			ant=act;
			act=sig;
			sig=sig->proximo();
			i++;
		}
		if(i==pos){
			ant->modificarProximo(sig);
			delete(act);
		}
	}
	this->cantidad--;
	/*cout << "Operación Exitosa al eliminar elemento" << endl;*/
     }else{
	cout << "Fallo la operación Eliminar" << endl;
     }
}
//Destructores:
template<class T>
Lista<T>::~Lista()
{
	destruir();
}

template<class T>
void Lista<T>::destruir()
{
     Nodo<T> *act;

	while(this->primero!=NULL){
		act=this->primero;
		this->primero=this->primero->proximo();
		delete(act);
	}
	this->primero=NULL;
	this->cantidad=0;
}
//Métodos de inspección:
template <class T>
bool Lista<T>::sublista(Lista<T> &x)
{
	Nodo<T> *nuevo,*ant,*aux, *aux2;
	bool flag=false;
	aux=x.primero;
	aux2=this->primero;
	while(aux!=NULL&&aux2!=NULL){
		nuevo=aux;
		if(aux2->obt_elemento()==nuevo->obt_elemento()){
			flag=true;
			ant=aux;
			aux=aux->proximo();
		}else{
			flag=false;
			aux=ant;
			
		}
		aux2=aux2->proximo();
	}
	return(flag);
}
template <class T>
void Lista<T>::mostrar()
{
	Nodo<T> *nuevo;
	int i;

	nuevo=this->primero;
	i=1;
	if(nuevo!=NULL){
		while(nuevo!=NULL&&i<=this->cantidad){
			i++;
			cout << "" << nuevo->obt_elemento();
			nuevo=nuevo->proximo();
		}
		cout << endl;
	}else{
		cout << "No hay elementos en la lista" << endl;
	}

}
template <class T>
int Lista<T>::Busqueda(T e){
	Nodo<T> *nuevo;
	int i;

	i=1;
	nuevo=this->primero;
	if(nuevo!=NULL){	
		while(nuevo!=NULL&&e!=nuevo->obt_elemento()){
			i++;
			nuevo=nuevo->proximo();
		}
		if(nuevo==NULL){
			i=0;
		}
	}else{
		i=0;
	}
	return i;

}

template <class T>
T Lista<T>::consultar(int pos)
{
	Nodo<T> *ant, *act;
	int i;
	
	if(pos==1){
		return(this->primero->obt_elemento());
	}else{
		ant=this->primero;
		act=ant->proximo();
		i=2;
		while(act!=NULL&&i<pos)
		{
			ant=ant->proximo();
			act=ant->proximo();
			i++;
		}
		if(act!=NULL&&i==pos)
		{
			return(act->obt_elemento());
		}
	}
}
//Sobrecarga de Operadores:
template <class T>
void Lista<T>::operator=(const Lista<T> &l)
{
	Nodo<T> *nuevo,*aux;
	
	if(this!=&l)
	{
	  if(l.primero!=NULL){//No debe ser vacia la lista que recibe para asignar
	     nuevo=l.primero;
	     this->primero=new Nodo<T>(nuevo->obt_elemento());
	     aux=this->primero;
             nuevo=nuevo->proximo();
		while(nuevo!=NULL){
		  aux->modificarProximo(new Nodo<T>(nuevo->obt_elemento()));
		  aux=aux->proximo();
		  nuevo=nuevo->proximo();
		}
		this->cantidad=l.cantidad;	//asigna la misma cantidad
	  }else{
	     	this->primero=NULL; //Si es vacia solo se 
		this->cantidad=0;  //crea 
	  }

	}
}
template<class T>
bool Lista<T>::operator==(const Lista<T> &l)
{
	Nodo<T> *recibe,*aux;
	bool band;
	int i;
	
        if(this!=&l)
        {
	   if(this->cantidad==l.cantidad){
		band=true;
		i=1;
		recibe=this->primero;
		aux=l.primero;
		while(i<=this->cantidad&&band){
		  if(recibe->obt_elemento()==aux->obt_elemento()){		
			recibe=recibe->proximo();
			aux=aux->proximo();
		  }else{
			band=false;
		  }
		  i++;		
		}
	
	   }else{
		band=false;
	   }	
	
        }
	return(band);

}
template<class T>

Lista<T>& Lista<T>::operator +(const Lista<T>& b)
{
	Nodo<T> *aux2,*nuevo,*aux,*aux3;
	
	aux=this->primero;	
	while(aux!=NULL){
		nuevo=aux;
		aux=aux->proximo();
	}//obtener ultimo
	aux2=b.primero;
	
	while(aux2!=NULL){
		aux3=nuevo;
		nuevo=new Nodo<T>(aux2->obt_elemento());
		aux3->modificarProximo(aux2);	
		aux2=aux2->proximo();
	}
	this->cantidad=this->cantidad+b.cantidad;

	return *this;
}

#endif




