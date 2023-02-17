#include <iostream>
#include <queue>

using namespace std;

class nodo{
    public:
    int dato;
    nodo *izq,*der;
    nodo (int);
};

nodo::nodo(int a){
    dato=a;
    izq=nullptr;
    der=nullptr;
}

void imprimir_produndidad(nodo *raiz){
    if(raiz!=0){
        cout<<raiz->dato<<" ";
        imprimir_produndidad(raiz->izq);
        imprimir_produndidad(raiz->der);
    }
}

void insertar_profundidad(nodo *raiz,int a){
    if(raiz!=nullptr){
        if(raiz->izq==0)
            raiz->izq=new nodo(a);
        else{
            if(raiz->der==0)
                raiz->der=new nodo(a);
            else{
                insertar_profundidad(raiz->izq,a);
            }
        }
    }
    else
        raiz->dato=a;
}

void imprimir_anchor(nodo *raiz){
    if(raiz!=0){
        queue<nodo*> cola;
        cola.push(raiz);
        while(cola.empty()){
            nodo* actual=cola.front();
            cola.pop();
            cout<<raiz->dato<<" ";
            if(actual->izq!=0)
                cola.push(actual->izq);
            if(actual->der!=0)
                cola.push(actual->der);
        }
    }
}

void insertar_anchor(nodo* raiz, int a){
    if(raiz!=0){
        queue<nodo*> cola;
        cola.push(raiz);
        while(!cola.empty()){
            nodo* actual=cola.front();
            cola.pop();
            if(actual->izq!=0){
                cola.push(actual->izq);
            }else{
                actual->izq=new nodo(a);break;
                }
            if(actual->der!=0){
                cola.push(actual->der);
            }else{
                actual->der=new nodo(a);break;
            }
        }
    }
    else
        raiz->dato=a;
}
