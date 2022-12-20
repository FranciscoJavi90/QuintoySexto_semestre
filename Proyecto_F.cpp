//Proyecto Final
//Programador: Francisco Javier Cifuentes Cajas.
//Id:2590-20-10308. 
//Programador: Antonio Guadalupe Flores Torres.
//Id:2590-20-10825.
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};
void lectura(){
ifstream archivo;
	string nombreArchivo,texto;
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in); 
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){ 
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close(); 
};
int main(){
	string nombreArchivo;
    int op, op2;
    string arch;
    do{
    cout<<"		\n\n    --PROYECTO FINAL--                \n\n";
    cout<<" 	-1-  	Manejo de Archivo                  \n";
    cout<<" 	-2-  	Recorrido Pre-Orden                \n";
    cout<<" 	-3-  	Buscar Clave                       \n";
    cout<<" 	-4-  	Eliminar elemento                  \n";
    cout<<" 	-5-  	Salir                             \n";

     cout<< "\n\t Que numero desea seleccionar: ";
    	cin>>op;
          switch(op){
               	case 1:
               		cout<<"Digite el nombre del archivo con extension .txt: ";
               		getline(cin,nombreArchivo);
               		lectura();
               		break;
               	case 5:
                    exit(0);
                    break;
    }
          cout<<"\n";  
    }
	while(op!=5);
	system("pause");
return 0;
}
