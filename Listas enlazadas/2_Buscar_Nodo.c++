#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* siguiente;
};

nodo* cabeza;
nodo* cola;

void insertar_nodo(int valor);
void buscar_nodo(int valor);

int main(){
    insertar_nodo(1);
    insertar_nodo(43);
    insertar_nodo(25);
    insertar_nodo(34);
    insertar_nodo(8);

    buscar_nodo(8);
    return 0;
}

void insertar_nodo(int valor){
    nodo* nuevo = new nodo;
    nuevo->dato = valor;
    if(cabeza == nullptr){
        cabeza = nuevo;
        cabeza->siguiente;
        cola = nuevo;
    } else{
        cola->siguiente = nuevo;
        nuevo->siguiente = nullptr;
        cola = nuevo;
    }   
}

void buscar_nodo(int valor){
    nodo* actual = cabeza;
    bool encontrado = false;
    while(encontrado == false && actual != nullptr){
        if(actual->dato == valor){
            encontrado = true;
            cout<<"Encontrado! "<<endl;
        } else{
            actual = actual->siguiente;
        }
    }
    if(encontrado == false){
        cout<<"No esta dentro de la lista. "<<endl;
    }
}