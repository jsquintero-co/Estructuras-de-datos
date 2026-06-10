//Las listas dobles tienen nodos con un dato, y dos punteros, a uno anterior y a otro siguiente
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* siguiente;
    nodo* anterior;
};

//Para insertar al final de la lista: 
void insertarAlFinal(nodo* &cabeza, nodo* &cola, int valor){
    nodo* nuevo = new nodo;

    nuevo->dato = valor;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;

    if(cabeza == nullptr){
        cabeza = nuevo;
        cola = nuevo;
    }
    else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

//Para recorrerla hacia adelante
void mostrarAdelante(nodo* cabeza){
    nodo* actual = cabeza;

    while(actual != nullptr){
        cout<<actual->dato<<" ";
        actual = actual->siguiente;
    }

    cout<<endl;
}

void mostrarAtras(nodo* cola){
    nodo* actual = cola;

    while(actual != nullptr){
        cout<<actual->dato<<" ";
        actual = actual->anterior;
    }
    cout<<endl;
}

int main(){
    nodo* cabeza = nullptr;
    nodo* cola = nullptr;

    insertarAlFinal(cabeza, cola, 10);
    insertarAlFinal(cabeza, cola, 20);
    insertarAlFinal(cabeza, cola, 30);
    insertarAlFinal(cabeza, cola, 40);

    cout<<"Hacia adelante: ";
    mostrarAdelante(cabeza);
    cout<<"Hacia atras: ";
    mostrarAtras(cola);

    return 0;
}
