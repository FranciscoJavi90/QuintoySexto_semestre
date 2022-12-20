//Programador: Francisco Javier Cifuentes Cajas.
//Id:2590-20-10308. 
#include<iostream>
#include<cstdlib>
using namespace std;
struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};
Nodo* nuevoNodo(int valor){
  Nodo *nuevo;
  nuevo = new Nodo();
  nuevo->dato = valor;
  nuevo->izq = NULL;
  nuevo->der = NULL;
  return nuevo;
}
Nodo * insertar(Nodo *raiz, int dato){
  if(raiz == NULL){
    raiz = nuevoNodo(dato);
  } else if(dato<=raiz->dato){
    raiz->izq= insertar(raiz->izq, dato);    
  }else{
    raiz->der= insertar(raiz->der, dato);
  }
  return raiz;
}
void R_orden(Nodo *raiz){
    if (raiz==NULL) return;
    R_orden(raiz->der);
    R_orden(raiz->izq);
    cout<<raiz->dato<<",";
 }
 void postorden(Nodo *raiz){
    if (raiz==NULL) return;
    postorden(raiz->izq);
    postorden(raiz->der);
    cout<<raiz->dato<<",";
 }  
 int cont_Hoj(Nodo* raiz){
        if (raiz==NULL){
                return 0;
        }
        if ((raiz->der==NULL)&&(raiz->izq==NULL)){
                return 1;
        }
        else{
                return cont_Hoj(raiz->izq) + cont_Hoj(raiz->der);
        }
}
int main(){
  int h;
  int valor;
  int cont_h=0;
  Nodo *raiz;
  raiz = NULL;
  raiz=insertar(raiz, 5);
  raiz=insertar(raiz, 7);
  raiz=insertar(raiz, 8);
  raiz=insertar(raiz, 9);
  raiz=insertar(raiz, 2);
  raiz=insertar(raiz, 10);
  raiz=insertar(raiz, 15);
  raiz=insertar(raiz, 14);
  raiz=insertar(raiz, 16);
  raiz=insertar(raiz, 20);
  raiz=insertar(raiz, 34);
  raiz=insertar(raiz, 67);
  raiz=insertar(raiz, 900);
  raiz=insertar(raiz, 1400);
  cout<<"\n	Recorrido R-orden.-"<<endl;
  R_orden(raiz);
  cout<<endl;
  cout<<"\n	Recorrido postorden.-"<<endl;
  postorden(raiz);
  cout<<endl;
  cont_h=cont_Hoj(raiz);
  cout<<"\nEl numero total de nodos hoja es: "<<cont_h;
  return 0;
}
