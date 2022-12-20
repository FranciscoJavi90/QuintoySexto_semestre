#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo{
	int dato;
	Nodo *izq;
	Nodo *der;
};

int main() {
	Nodo *raiz;  //apunta al nodo raiz
	raiz = NULL;
	
	Nodo *nodo1, *nodo2, *nodo3;
	//creamos los nodos, reservando memoria ram suficiente-.
	nodo1 = new Nodo();  
	nodo2 = new Nodo();
	nodo3 = new Nodo(); 
	
	raiz = nodo1; 
	
	nodo1->dato=100;
	nodo2->dato=50;
	nodo3->dato=150;
	
	nodo1->izq=nodo2;
	nodo2->der=nodo3;
	
	nodo2->izq=NULL;
	nodo2->der=NULL;
	nodo3->izq=NULL;
	nodo3->der=NULL;	
	
	cout<<"Direccion Nodo 1: "<<nodo1<<endl;
	cout<<"Direccion Nodo 2: "<<nodo2<<endl;
	cout<<"Direccion Nodo 3: "<<nodo3<<endl;
	cout<<"Direccion Nodo raiz: "<<raiz<<endl;
	
	return 0;
}
