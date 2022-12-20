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
	
	Nodo *nodo1, *nodo2, *nodo3, *nodo4, *nodo5, *nodo6;
	//creamos los nodos, reservando memoria ram suficiente-.
	nodo1 = new Nodo();  
	nodo2 = new Nodo();
	nodo3 = new Nodo(); 
    nodo4 = new Nodo();
    nodo5 = new Nodo();
    nodo6 = new Nodo();
	
	raiz = nodo1; 
	
	nodo1->dato=100;
	nodo2->dato=50;
	nodo3->dato=150;
    nodo4->dato=55;
    nodo5->dato=110;
    nodo6->dato=125;
	//logica.
	nodo1->izq=nodo2;
	nodo2->der=nodo3;
    nodo3->der=nodo5;
    nodo2->izq=nodo4;
    nodo5->izq=nodo6;
	
	nodo2->der=NULL;
	nodo3->izq=NULL;
	nodo4->izq=NULL;
    nodo4->der=NULL;
    nodo5->izq=NULL;
    nodo6->izq=NULL;	
	nodo6->der=NULL;


	cout<<"Direccion Nodo 1: "<<nodo1<<endl;
	cout<<"Direccion Nodo 2: "<<nodo2<<endl;
	cout<<"Direccion Nodo 3: "<<nodo3<<endl;
    cout<<"Direccion Nodo 4: "<<nodo4<<endl;
    cout<<"Direccion Nodo 5: "<<nodo5<<endl;
    cout<<"Direccion Nodo 6: "<<nodo6<<endl;
	cout<<"Direccion Nodo raiz: "<<raiz<<endl;
	
	return 0;
}