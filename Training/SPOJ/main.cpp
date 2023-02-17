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
    nodo *aux=raiz;
    if(aux!=nullptr){
        if(a<aux->dato){
            if(aux->izq==nullptr){
                aux->izq=new nodo(a);
            }
            else{
                insertar_profundidad(aux->izq,a);
            }            
        }else{
            if(aux->der==nullptr){
                aux->der=new nodo(a);
            }else{
                insertar_profundidad(aux->der,a);
            }
        }
    }else
    {
        aux=new nodo(a);
    }
    


    // if(raiz!=0){
    //     if(raiz->izq==0)
    //         raiz->izq=new nodo(a);
    //     else{
    //         if(raiz->der==0)
    //             raiz->der=new nodo(a);
    //         else{
    //             insertar_profundidad(raiz->izq,a);
    //         }
    //     }
    // }
    // else
    //     raiz->dato=a;
}
int cuantos(nodo *raiz){
    if(raiz!=0)
        return cuantos(raiz->izq)+cuantos(raiz->der)+1;
    return 0;
}
int suma(nodo *raiz){
    if (raiz==0)
        return 0;
    return raiz->dato+suma(raiz->izq)+suma(raiz->der);
}
int profundidad(nodo *raiz){
    if(raiz!=0){
        return profundidad(raiz->izq)+1;
    }
    return 0;
}
bool buscar(nodo *raiz,int a){
    nodo *actual=raiz;
    while(actual!=0){
        if(a==actual->dato)
            return true;
        else {
            if(a<actual->dato)
                actual=actual->izq;
            else{
                actual=actual->der;
            }
        }
    }
    return false;
}
int main()
{
    int a;
    nodo* arbol=new nodo(1);
    cin>>a;
    insertar_profundidad(arbol,a);
    imprimir_produndidad(arbol);
     cin>>a;
    insertar_profundidad(arbol,a);
    imprimir_produndidad(arbol);
     cin>>a;
    insertar_profundidad(arbol,a);
    imprimir_produndidad(arbol);
     cin>>a;
    insertar_profundidad(arbol,a);
    imprimir_produndidad(arbol);
    cout<<"\n"<<cuantos(arbol);
    cout<<"\n"<<suma(arbol);
    cout<<"\n"<<profundidad(arbol);
    cout<<"\n"<<buscar(arbol,2);
    return 0;
}
