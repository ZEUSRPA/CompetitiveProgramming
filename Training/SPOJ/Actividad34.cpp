#include <iostream>
#include <conio.h>
using namespace std;

class Node{
private:
    Node *next;
    Node *prev;
    int dato;
public:

    Node():next(nullptr),prev(nullptr){

    }

    Node(int value):next(nullptr),prev(nullptr){
        dato=value;
    }

    void setNext(Node *value){
        next=value;
    }

    void setPrev(Node *value){
        prev=value;
    }

    void setDato(const int value){
        dato=value;
    }

    Node* getNext(){
        return next;
    }

    Node* getPrev(){
        return prev;
    }

    int getDato(){
        return dato;
    }

};

class Lista{
private:
    Node *anchor;
    int tam;
public:
    Lista():anchor(nullptr){
        tam=0;
    }
    bool isValidPos(int pos){
        return (pos>0 && pos<=tam+1);
    }

    bool insertPos(int pos,int value){
        if(isValidPos(pos)){
            Node *aux=anchor;
            Node *ant=anchor;
            while(--pos){
                ant=aux;
                aux=aux->getNext();
            }
            Node *newNode=new Node(value);
            if(aux==anchor){
                if(aux!=nullptr){
                    aux->setPrev(newNode);
                }
                newNode->setNext(aux);
                anchor=newNode;
            }else{
                if(aux==nullptr){
                    ant->setNext(newNode);
                    newNode->setPrev(ant);
                }else{
                    newNode->setNext(aux);
                    newNode->setPrev(aux->getPrev());
                    if(aux->getPrev()!=nullptr){
                        aux->getPrev()->setNext(newNode);
                    }
                    aux->setPrev(newNode);
                }
            }
            tam++;
            return true;
        }else{
            return false;
        }
    }

    int deleteElements(int value){
        Node *aux=anchor;
        int cont=0;
        while(aux!=nullptr){
            if(aux->getDato()==value){
                if(aux==anchor){
                    anchor=aux->getNext();
                }
                if(aux->getPrev()!=nullptr){
                    aux->getPrev()->setNext(aux->getNext());
                }
                if(aux->getNext()!=nullptr){
                    aux->getNext()->setPrev(aux->getPrev());
                }
                Node *del=aux;
                aux=aux->getNext();
                delete(del);
                cont++;
                tam--;
            }else{
                aux=aux->getNext();
            }
        }
        return cont;
    }

    void insertArray(int arr[],int tama){
        while(--tama>-1){
            insertPos(1,arr[tama]);
        }
    }

    void swapp(Node *uno,Node *dos){
        Node *aux=uno->getPrev();
        uno->setNext(dos->getNext());
        if(uno->getNext()!=nullptr){
            uno->getNext()->setPrev(uno);
        }
        uno->setPrev(dos);
        dos->setNext(uno);
        dos->setPrev(aux);
        if(aux!=nullptr){
            aux->setNext(dos);
        }
        if(anchor==uno){
            anchor=dos;
        }
    }

    void sortList(){
        
        for(int i=tam-1;i>0;i--){
            Node *aux=anchor;
            for(int j=0;j<i;j++){
                if(aux->getDato()>aux->getNext()->getDato()){
                    swapp(aux,aux->getNext());
                }else{
                    aux=aux->getNext();
                }
            }
        }
    }

    void showList(){
        Node *aux=anchor;
        while(aux!=nullptr){
            cout<<aux->getDato()<<endl;
            aux=aux->getNext();
        }
    }
};

int main(){
    Lista lista;
    char op;
    int num,pos;
    do{
        cout<<"a.-Insertar numero\nb.-Eliminar numero\nc.-Insertar arreglo\nd.-Ordenar lista\ne.-Mostrar lista\nf.-Salir\n";
        cin>>op;
        op=tolower(op);
        switch(op){
            case 'a':{

                cout<<"Ingrese el numero a insertar"<<endl;
                cin>>num;
                cout<<"Ingrese la posicion"<<endl;
                cin>>pos;
                bool ok=lista.insertPos(pos,num);
                if(ok){
                    cout<<"Se ha insertado el numero"<<endl;
                }else{
                    cout<<"Posicion no valida"<<endl;
                }
                break;
            }
            case 'b':{

                cout<<"Ingrese el numero a eliminar"<<endl;
                cin>>num;
                int cont=lista.deleteElements(num);
                cout<<"Se han eliminado "<<cont<<" elementos de la lista"<<endl;
                break;
            }
            case 'c':{

                cout<<"Cantidad de elementos a ingresar"<<endl;
                cin>>num;
                int arr[7];
                cout<<"Ingrese los numeros separados por un espacio"<<endl;
                for(int i=0;i<num;i++){
                    cin>>arr[i];
                }
                lista.insertArray(arr,num);
                cout<<"Se ha ingresado el arreglo"<<endl;
                break;
            }
            case 'd':{

                lista.sortList();
                cout<<"Se ha ordenado la lista"<<endl;
                break;
            }
            case 'e':{

                lista.showList();
                break;
            }
            case 'f':break;
            default:cout<<"Opcion no valida"<<endl;
                    getch();
        }
    }while(op!='f');
    return 0;
}