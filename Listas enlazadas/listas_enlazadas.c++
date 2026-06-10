/*Las listas enlazadas son un tipo de estructuras de datos que contienen nodos que están 
enlazados, cada nodo tiene los datos que están guardados y el apuntador al nodo siguiente*/
#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* siguiente;
};

int main(){

    nodo* primero = new nodo{10, nullptr};
    nodo* segundo = new nodo{20, nullptr};
    nodo* tercero = new nodo{30, nullptr}; //El útlimo se llama tail

    primero->siguiente = segundo;    
    segundo->siguiente = tercero;

    nodo* head = primero; //El head es el primer nodo de la lista

    while (head != nullptr){
        cout<< head->dato << " ";
        head = head->siguiente;
    }

    delete primero;
    delete segundo;
    delete tercero;
    return 0;
}
