/*Las listas enlazadas sirven para almacenar datos de forma dinámica, se componen de nodos que contienen el valor y un puntero al siguiente nodo*/

#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo* siguiente;
};

nodo* cabeza;
nodo* cola;

void insertarNodo();
void desplegarLista();

int main(){
    int n;
    cout<<"Ingrese cuantos nodos quiere insertar: "<<endl;
    cin>>n;
    int i = 0;
    while(i < n){
        insertarNodo();
        i++;
    }

    desplegarLista();
    return 0;
}

//Cabeza apunta y es null, cola tambien apunta y es null
//La lista es: 10, 6, 92, 3, 48, 2.
void insertarNodo(){
    nodo* nuevo = new nodo;
    cout<<"Ingrese el dato: "<<endl;
    cin>> nuevo->dato;
    if(cabeza == nullptr){
        cabeza = nuevo;
        cabeza->siguiente = nullptr;
        cola = nuevo;
    } else{
        cola->siguiente = nuevo;
        nuevo->siguiente = nullptr;
        cola = nuevo; 
    }
    cout<<"Nodo insertado \n"<<endl;
}

//Mostrar la lista
void desplegarLista(){
    nodo* actual = new nodo;
    actual = cabeza;
    if(actual != nullptr){
        while(actual != nullptr){
            cout<<actual->dato<<" ";
            actual = actual->siguiente;
        }
    } else{
        cout<<"La lista no tiene nada"<<endl;
    }
}
