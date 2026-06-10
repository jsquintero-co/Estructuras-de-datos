//Apuntadores
#include <iostream>

using namespace std;

struct Estudiante{
    string nombre;
    int edad;
};


void incrementar();
void incrementarRef();

int main(){

    int N = 5; //Es una variable normal
    /*Cada variable guarda un dato en una dirección de memoria*/
    int* ptr = &N; //Aquí se creó un puntero

    /*El puntero es el que guarda la dirección de memoria 
    de una variable, y este tambien puede acceder al contenido
    de dicha variable*/

    cout<<"El valor es de N es: "<<N<<endl;
    cout<<"El valor del puntero ptr es: "<<ptr<<endl;
    cout<<"El valor que está almacenado en la direccion de memoria es:"<<*ptr<<endl;

    //Memoria dinámica
    int* x = new int;
    /*La ram tiene un espacio llamado heap, donde se pueden guardar valores para que sea más
    rápido el procesamiento o algo así*/
    *x = 2;
    cout<<"El valor del puntero dinamico x es: "<<*x<<endl;
    delete x;

    //Arreglos dinámicos
    int c = 10;
    int* v = new int[c];
    
    int r;
    //Añadir contenido
    for(int i = 0; i < c; i++){
        cin>>r;
        *(v+i) = r;
    }

    //Recorrerlo y mostrar su contenido
    for(int i = 0; i < c; i++){
        cout<<*(v+i)<<" "; //Para acceder al valor de cada índice
    }

    //Estructuras de apuntadores
    Estudiante e;
    e.nombre = "Juan";
    Estudiante* p = &e;
    cout<<p->nombre<<endl;

    //Estructuras dinámicas
    Estudiante* a = new Estudiante;

    a->nombre = "Bob";
    a->edad = 12;

    delete a;

    return 0; 
}

/*Si se implementa una función así, la variable a la que se le implementa que tiene un 
valor dado, se le implementaria a una copia, pero su valor original no cambia:
incrementar(a) donde a = 1
seguiría siendo a = 1 pero en la copia sería 2*/
//Argumento por valor
void incrementar(int x){
    x++;
}

/*Si se usa una referencia para una variable (dirección de memoria) como argumento para
una función, a la variable a la que se le aplique se le aplicará a su valor original:
donde a = 1
incrementarRef(a) = 2
al igual que a = 2 */
//Argumento por referencia
void incrementarRef(int& x){
    x++;
}



//Y ya