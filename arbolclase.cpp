#include<iostream>
#include<cstdlib>

using namespace std;

struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};
    //crear un nuevo nodo y guarda el dato 
    //e Inicializa los punteros a null
Nodo * nuevoNodo(int valor){
        Nodo *nuevo;
        nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->izq = NULL; 
        nuevo->der = NULL; 
        return nuevo;
    }

int main(){
    Nodo *raiz;   //apunta al nodo raiz
    raiz = NULL;

    Nodo *nodo1, *nodo2, *nodo3;
    //creamos los nodos, reservando memoria RAM suficiente
    nodo1 = nuevoNodo(100);  
    nodo2 = nuevoNodo(50);
    nodo3 = nuevoNodo(150);

    raiz = nodo1;

    nodo1->izq = nodo2;
    nodo1->der = nodo3;

    nodo2->izq = NULL;
    nodo2->der = NULL;
    nodo3->izq = NULL;
    nodo3->der = NULL;    

    cout<<"Direccion Nodo 1: "<<nodo1<<endl;
    cout<<"Direccion Nodo 2: "<<nodo2<<endl;
    cout<<"Direccion Nodo 3: "<<nodo3<<endl;
    cout<<"Direccion Nodo raiz: "<<raiz<<endl;

    return 0;
}