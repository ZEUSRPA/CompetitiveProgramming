#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
/*
1.- Una estructura linael nos permite tener elementos almacenados de forma organizada, solo que de forma dinamica por lo cual los arreglos, la pila, la cola y las listasn enlazadas tienen cada una sus caracteristicas individuales, que seg�n sea tu necesidad sea mas apropiado usar una u otra.
2.- La diferencia entre una  lista simple enlazada y una doble enlazada es que en la simple cada nodo tiene un unico enlace que es siguiente, mientras que en la doble enlazada se tiene dos que son siguente y anterior.*/
using namespace std;

class nodo
{
	int dato;
	nodo *sig;
	public:
		nodo(int);
		void implista();
		void inserta(int);
		void modifica(int,int);
};
nodo::nodo(int a)
{
	dato=a;  sig=0;
}

void nodo::inserta(int a)
{
	if (this!=0)
	{
		nodo* actual=this;
		if (actual->sig!=0)
			actual->sig->inserta(a);
		else
			actual->sig=new nodo(a);
	}
}

void nodo::modifica(int num,int pos)
{
    nodo* actual=this;
    int x=1;
    if (pos<=100&&pos>0){
        while(actual!=0&&x!=pos)
        {
            actual=actual->sig;
            x++;
        }
        actual->dato=num;
    }
}

void agregar_arreglo(int a[],int n,nodo *lista)
{
    for (int i=0;i<n;i++){
		lista->inserta(a[i]);
	}
}

void elimina(int x,nodo *lista)
{
    while(lista->sig->dato!=x && lista->sig!=nullptr){
		lista=lista->sig;
	}
	nodo *aux;
	if(lista!=nullptr){
		*aux=lista.sig;
		lista.sig=lista.sig.sig;
	}
	delete(aux);


}

void nodo::implista()
{
	nodo* actual=this;
	while(actual!=0)
	{
		cout << actual->dato << ", ";
		actual=actual->sig;
	}

}

int main()
{
    srand(time(0));
    int x;
    x=rand()%100;
	nodo* lista=new nodo(x);

	for (int i=2;i<101;i++){
        x=rand()%100;
		lista->inserta(x);
	}
	lista->implista();
	cout<<"\n\n";

	lista->modifica(15,100);
	lista->implista();
	cout<<"\n\n";
	lista->elimina(10,lista);
	int a[]={1,2,3,4,5};
	agregar_arreglo(a,5,lista);
	lista->implista();
	return 0;

}
