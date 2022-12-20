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
//Crea un nuevo nodo y retorna su dirección. 
Nodo* nuevoNodo(int valor){
  Nodo *nuevo;
  nuevo = new Nodo();
  nuevo->dato = valor;
  nuevo->izq = NULL;
  nuevo->der = NULL;
  return nuevo;
}

Nodo * insertar(Nodo *raiz, int dato){
  //Verificar si puntero raiz esta vacio.
  if(raiz == NULL){
    raiz = nuevoNodo(dato);
  } else if(dato<=raiz->dato){
    raiz->izq= insertar(raiz->izq, dato);    
  }else{
    raiz->der= insertar(raiz->der, dato);
  }
  //retornamos la dirección de raiz.
  return raiz;
}

//recorre en preorden y muestra datos
 void preorden(Nodo *raiz){
    if (raiz==NULL) return;
    
    cout<<raiz->dato<<",";//raiz
    preorden(raiz->izq);
    preorden(raiz->der);

 }
//recorre en postorden y muestra datos
 void postorden(Nodo *raiz){
    if (raiz==NULL) return;
    
    postorden(raiz->izq);
    postorden(raiz->der);
    cout<<raiz->dato<<","<<endl;

 }
//recorre en inorden y muestra datos
 void inorden(Nodo *raiz){
    if (raiz==NULL) return;
    
    inorden(raiz->izq);
    cout<<raiz->dato<<","<<endl;
    inorden(raiz->der);

 }
//Busca dato en el árbol
bool buscar(Nodo *raiz, int valor){
    //1. si el arbol/subarbol está vacio retornar false
    if(raiz == NULL){
        return false;  
    //2. si el valor buscado es igual al valor que se encuentra
	//en la raiz, devolver true    
    }else if( valor == raiz->dato){ 
        return true;
    }
    //3. de lo contrario si el valor es menor que el valor que
	//tiene la raiz, buscamos por la izquierda
    else if(valor < raiz->dato){
        return buscar(raiz->izq, valor);
    }
    //4. de lo contrario buscamos por la derecha
    else{
        return buscar(raiz->der, valor);
    }
}
  int alturaAB(Nodo *raiz)
  {
      int AltIzq, AltDer;

      if(raiz == NULL){
        return -1;
      }
      else
      {
          AltIzq = alturaAB(raiz->izq);
          AltDer = alturaAB(raiz->der);

          if(AltIzq>AltDer)
            return AltIzq+1;
          else
              return AltDer+1;
    }
}    
int main(){
  int h;
  int valor;
  Nodo *raiz;//apunta al primer nodo del árbol.
  raiz = NULL;//arbol vacio cuando no apunta a NULL.
  

  raiz=insertar(raiz, 55);
  raiz=insertar(raiz, 30);
  raiz=insertar(raiz, 75);
  raiz=insertar(raiz, 4);
  raiz=insertar(raiz, 41);
  raiz=insertar(raiz, 65);
  raiz=insertar(raiz, 85);
  raiz=insertar(raiz, 35);
  raiz=insertar(raiz, 45);
  raiz=insertar(raiz, 70);

  cout<<"Recorrido preorden"<<endl;
  preorden(raiz);
  cout<<endl;
  cout<<"Recorrido postorden"<<endl;
  postorden(raiz);
  cout<<endl;
  cout<<"Recorrido inorden"<<endl;
  inorden(raiz);
  
  cout<<endl;
  cout<<"Ingrese un valor a buscar : "<<valor<<endl;
  

  if (buscar(raiz,valor) ){
    cout<<"El dato se encuentra en el arbol."<<endl;
  }else{
    cout<<"El dato no se encuentra."<<endl;
  }
  
  h = alturaAB(raiz);
  cout<<"La altura es : "<<h<<endl;

  return 0;
}