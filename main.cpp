#include "ListaDoble.h"
#include "Lista.h"
int main()
{
	ListaDoble<int> l;
	Lista<int> a,f,c;
	l.insertar(1,1);
	l.insertar(2,2);
	l.insertar(3,3);
	l.insertar(4,4);
	l.mostrar();
	cout << l;
	a.insertar(3,1);
	a.insertar(4,2);
	f.insertar(3,1);
	f.insertar(4,2);
	if(a==f){
			cout << endl;
	}
	a.mostrar();
	f.mostrar();
	return 0;
}
