/*Ejercicio 2:
Eliminar un nodo dado un número que coincida con algún dato de la lista doble
*/

#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* anterior;
    nodo* siguiente;
};

void agregarNodos(nodo*& cabeza, nodo*& cola, int valor){

    nodo* nuevo = new nodo{valor, nullptr, nullptr};

    if(cabeza == nullptr){
        cabeza = nuevo;
        cola = nuevo;
    }
    else{
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

void recorrerArriba(nodo* cabeza){

    nodo* actual = cabeza;

    while(actual != nullptr){
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    cout << endl;
}

void eliminarNodo(nodo*& cabeza, nodo*& cola, int valor){

    nodo* actual = cabeza;

    while(actual != nullptr){

        if(actual->dato == valor){

            // único nodo
            if(cabeza == cola){
                cabeza = nullptr;
                cola = nullptr;
            }

            // primer nodo
            else if(actual == cabeza){
                cabeza = cabeza->siguiente;
                cabeza->anterior = nullptr;
            }

            // último nodo
            else if(actual == cola){
                cola = cola->anterior;
                cola->siguiente = nullptr;
            }

            // nodo intermedio
            else{
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            return;
        }

        actual = actual->siguiente;
    }

    cout << "Valor no encontrado." << endl;
}

int main(){

    nodo* cabeza = nullptr;
    nodo* cola = nullptr;

    agregarNodos(cabeza, cola, 10);
    agregarNodos(cabeza, cola, 20);
    agregarNodos(cabeza, cola, 30);
    agregarNodos(cabeza, cola, 40);

    cout << "Lista original: ";
    recorrerArriba(cabeza);

    eliminarNodo(cabeza, cola, 20);

    cout << "Despues de eliminar 20: ";
    recorrerArriba(cabeza);

    eliminarNodo(cabeza, cola, 10);

    cout << "Despues de eliminar 10: ";
    recorrerArriba(cabeza);

    eliminarNodo(cabeza, cola, 40);

    cout << "Despues de eliminar 40: ";
    recorrerArriba(cabeza);

    return 0;
}