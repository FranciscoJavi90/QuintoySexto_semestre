#include<iostream>
using namespace std;

int main(){
    int *p;    
    p = new int;
    cout<<"La direccion de la memoria reservada es: "<<p<<endl;    
    *p = 10;
    cout<<"El valor almacenado en la memoria reservada es: "<<*p<<endl;

    return 0;
}