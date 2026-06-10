//Ejercicio
/*
1. Crear una lista enlazada y añadir "A", "B" y "C".
2. Eliminar el nodo con valor "B"
3. Recorrer e imprimir los valores restantes
4. Insertar un nodo con un valor "X" justo después de "A"
5. Eliminar el nodo con el valor C
6. Recorrer e imrpimir los valores finales
*/
#include <iostream>

using namespace std;

struct nodo{
    char dato;
    nodo* siguiente;
};

int main(){
    //1.
    nodo* A = new nodo{'A', nullptr};
    nodo* B = new nodo{'B', nullptr};
    nodo* C = new nodo{'C', nullptr};

    A->siguiente = B;
    B->siguiente = C;
    
    nodo* head = A;
    //2.
    A->siguiente = B->siguiente;
    delete B;

    //3.
    while(head != nullptr){
        cout<<head->dato<<" ";
        head = head->siguiente;
    }
    cout<<endl;

    nodo* X = new nodo{'X', nullptr};

    //4
    X->siguiente = A->siguiente;
    A->siguiente = X;
    //5.
    X->siguiente = nullptr;
    delete C;

    //6.
    head = A;
    while(head != nullptr){
        cout<<head->dato<<" ";
        head = head->siguiente;
    }
    
    return 0;
}


