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
int numNodos = 0; 
int numK = 0, k;
Nodo* nuevoNodo(int valor){
  Nodo *nuevo;
  nuevo = new Nodo();
  nuevo->dato = valor;
  nuevo->izq = NULL;
  nuevo->der = NULL;
  return nuevo;
}
Nodo * insertar(Nodo *raiz, int x){
  if(raiz == NULL){
    raiz = nuevoNodo(x);
    cout<<"Dato insertado";
  } else if(x<=raiz->dato){
    raiz->izq= insertar(raiz->izq, x);    
  }else{
    raiz->der= insertar(raiz->der, x);
  }
  return raiz;
}
 void preorden(Nodo *raiz){
    if (raiz==NULL) return;
    
    cout<<raiz->dato<<",";
    preorden(raiz->izq);
    preorden(raiz->der);
 }
 void postorden(Nodo *raiz){
    if (raiz==NULL) return;
    
    postorden(raiz->izq);
    postorden(raiz->der);
    cout<<raiz->dato<<",";
 }
 void inorden(Nodo *raiz){
    if (raiz==NULL) return;
    
    inorden(raiz->izq);
    cout<<raiz->dato<<",";
    inorden(raiz->der);
 }
bool buscar(Nodo *raiz, int valor){
    if(raiz == NULL){
        return false;     
    }else if( valor == raiz->dato){ 
        return true;
    }
    else if(valor < raiz->dato){
        return buscar(raiz->izq, valor);
    }
    else{
        return buscar(raiz->der, valor);
    }
}
  int alturaAB(Nodo *raiz){
      int AltIzq, AltDer;
      if(raiz == NULL){
        return -1;
      }
      else{
          AltIzq = alturaAB(raiz->izq);
          AltDer = alturaAB(raiz->der);
          if(AltIzq>AltDer)
            return AltIzq+1;
          else
              return AltDer+1;
    }
} 
void verArbol(Nodo *raiz, int n){
     if(raiz==NULL)
          return;
     verArbol(raiz->der,n+1);
     for(int i=0; i<n; i++)
         cout<<"   ";
     numNodos++;
     cout<<raiz->dato<<endl;
     verArbol(raiz->izq, n+1);
} 
Nodo* unirABB(Nodo* izq, Nodo* der){
    if(izq==NULL) return der;
    if(der==NULL) return izq;
    Nodo* centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}
void elimina(Nodo* &raiz, int x){
     if(raiz==NULL) return;
     if(x<raiz->dato)
         elimina(raiz->izq, x);
     else if(x>raiz->dato)
         elimina(raiz->der, x);
     else{
         Nodo* p = raiz;
         raiz = unirABB(raiz->izq, raiz->der);
         delete p;
     }
}  
int contarHojas(Nodo* raiz){
        if (raiz==NULL){
                return 0;
        }
        if ((raiz->der==NULL)&&(raiz->izq==NULL)){
                return 1;
        }
        else{
                return contarHojas(raiz->izq) + contarHojas(raiz->der);
        }
}
int main(){
    Nodo* raiz;
	raiz = NULL;
	int contarh = 0;
    int x;
    int op, op2;  
    do{
    cout<<"		\n\n  --ABB ARBOL BINARIO DE BUSQUEDA--  \n\n";
    cout<<" 	-1-  	Insertar elemento                  \n";
    cout<<" 	-2-  	Mostrar arbol                      \n";
    cout<<" 	-3-  	Recorridos de profundiad           \n";
    cout<<" 	-4-  	Buscar elemento                    \n";
    cout<<" 	-5-  	Eliminar elemento                  \n";
    cout<<" 	-6-  	Altura del arbol                   \n";
    cout<<" 	-7-  	Contar nodos                       \n";
    cout<<" 	-8-  	Contar hojas                       \n";
    cout<<" 	-9- 	SALIR                              \n";

     cout<< "\n\t Que numero desea seleccionar: ";
    	cin>>op;
          switch(op){
               	case 1:
                    cout<<"Ingrese valor: ";  
					cin>>x;
                    raiz=insertar(raiz, x);
                    break;
               	case 2:
                    verArbol(raiz, 0);
                    break;
               	case 3:
                    if(raiz!=NULL)
                    {
                    	cout<<"[1] Inorden\n";
     					cout<<"[2] Preorden\n";
     					cout<<"[3] Postorden\n";
     					cin>>op2;
                         switch(op2)
                         {
                             case 1:
                                 inorden(raiz); break;
                             case 2:
                                 preorden(raiz); break;
                             case 3:
                                 postorden(raiz); break;
                         }
                    }
                    else
                        cout<<"\n Arbol vacio.";
                    break;
               	case 4:
                    bool band;
                    cout<<" Valor a buscar: "; cin>>x;
                    band = buscar(raiz, x);
                    if(band==1)
                       cout<<"\nEncontrado.";
                    else
                       cout<<"\nNo encontrado.";
                    break;
               	case 5:
                    cout<<" Valor a eliminar: "; cin>>x;
                    elimina(raiz, x);
                    cout<<"\n\tEliminado..!";
                    break; 
               	case 6:
                    int h;
                    h = alturaAB(raiz);
  					cout<<"La altura es : "<<h<<endl;
  					break;
               	case 7:
               		numNodos=0;
                    verArbol(raiz, 0);
                    cout<<"\n El numero de nodos es : ";
                    cout<<numNodos;
                    break;
				case 8:
					contarh=contarHojas(raiz);
					cout<<"El numero de hojas es: "<<contarh;
					break;
               	case 9:
                    exit(0);
          }
          cout<<"\n";  
    }while(op!=9);
return 0;
}
