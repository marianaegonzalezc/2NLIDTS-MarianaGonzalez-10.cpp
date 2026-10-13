// 2NLIDTS-MarianaGonzalez-10.cpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void ImprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "Dato: " << actual->dato
            << " | Direccion: " << actual
            << " | Anterior: " << actual->anterior
            << " | Siguiente: " << actual->siguiente << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}
void ImprimirListaReversa(Nodo* cola) {
    Nodo* actual = cola;
    while (actual != nullptr) {
        cout << "Dato: " << actual->dato
            << " | Direccion: " << actual
            << " | Anterior: " << actual->anterior
            << " | Siguiente: " << actual->siguiente << endl;
        actual = actual->anterior;
    }
    cout << endl;
}
void BorrarLista(Nodo*& cabeza, Nodo*& cola) {
    int contador = 0;
    while (cabeza != nullptr) {
        Nodo* siguiente = cabeza->siguiente;
        contador++;      
        cout << "Elemento borrado " << contador
            << " | Dato: " << cabeza->dato
            << " | Direccion: " << cabeza << endl;
        delete cabeza;
        cabeza = siguiente;
    }
    cout << "Total de elementos borrados: " << contador << endl;
    cola = nullptr;
}
void agregarNodo(Nodo*& cabeza, Nodo*& cola, int valor) {
    Nodo* nuevoNodo = new Nodo; 
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    }
    else {
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = nuevoNodo;
    }
}
int main()
{
    cout << "Actividad 08 - Lista Doblemente Enlazada\n";
    Nodo* cabeza = nullptr;
    Nodo* cola = nullptr;
    int tamanoLista;
    cout << "Ingrese la cantidad de elementos de la lista enlazada: ";
    cin >> tamanoLista;
    if (tamanoLista <= 0) {
        cout << "Cantidad de elementos no valida" << endl;
        return 1;
    }
    for (int i = 0; i < tamanoLista; i++) {
        int valor;
        cout << "Ingrese el dato " << i + 1 << ": ";
        cin >> valor;
        agregarNodo(cabeza, cola, valor);
    }
    cout << "\nImprimiendo lista (de inicio a fin):" << endl;
    ImprimirLista(cabeza);
    cout << "Imprimiendo lista (de fin a inicio):" << endl;
    ImprimirListaReversa(cola);
    cout << "\nBorrando lista de numeros" << endl;
    BorrarLista(cabeza, cola);

    return 0;
}