#include <iostream>
using namespace std; 

struct Nodo
{
    int elemento; 
    struct Nodo *siguiente;
};
typedef struct Nodo *Pila;

void initialize(Pila *s)
{
    *s = NULL; 
}

bool empty(Pila *s)
{
    return *s == NULL; 
}

void push(Pila *s, int e)
{
    struct Nodo *nodo; 
    nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo -> elemento = e; 
    nodo -> siguiente = *s; 

    *s = nodo; 
}

void pop(Pila *s)
{
    if(!empty(s))
    {
        struct Nodo *aux = *s;
        *s = (*s) -> siguiente;
        delete(aux); 
    }
}

void mostrarPila(Pila *s)
{
    struct Nodo *clon = *s;
    bool vacio = false; 

    while(!vacio)
    {
        if(!empty(&clon))
        {
            cout << clon -> elemento  << " ";
            clon = clon -> siguiente;
        }
        else
        {
            vacio = true; 
        }
    }
}

void menu(Pila *s)
{
    int opcion;
    bool estado = true; 

    while(estado)
    {
        cout << endl << "*------ MENU DE PILAS ------*" << endl;
        cout << "1) Ingresar un elemento a la pila" << endl;
        cout << "2) Eliminar un elemento de la pila" << endl;
        cout << "3) Terminar Programa" << endl; 
        cout << endl << "Ingrese una opcion" << endl; 
        cin >> opcion; 
        cout << endl; 

        switch(opcion)
        {
            case 1: 
            int n; 
            cout << "Ingrese el elemento a agregar a la pila: ";
            cin >> n; 
            push(s, n);
            cout << endl; 

            cout << "Mostrando pila actualizada: "; 
            mostrarPila(s); 
            cout << endl; 
            break; 

            case 2:
            pop(s);
            cout << "Mostrando pila actualizada: " << endl; 
            mostrarPila(s);
            cout << endl; 
            break; 

            case 3:
            cout << "Fin del Programa" << endl;
            estado = false; 
            break; 

            default: 
            cout  << "Opcion Invalida" << endl; 
        }
    }
}

int main()
{
    Pila pila; 
    initialize(&pila);
    menu(&pila);
    return 0; 
}