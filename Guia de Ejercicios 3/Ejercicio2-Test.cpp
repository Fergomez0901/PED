#include <iostream>
using namespace std; 

struct Nodo
{
    int elemento;
    struct Nodo *siguiente; 
};
typedef struct Nodo *pila; 

void initialize(pila *s)
{
    *s = NULL;
}

bool empty(pila *s)
{
    return *s == NULL; 
}

void push(pila *s, int e)
{
    struct Nodo *nodo;
    nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo -> elemento = e; 
    nodo -> siguiente = *s;

    *s = nodo;
}

void pop(pila *s)
{
    if(!empty(s)
    {
        struct Nodo *clon = *s; 
        *s = (*s) -> siguiente; 
        delete (clon);
    }
    else
    {
        return;
    }
}

void mostrarPila(pila *s)
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

int main()
{
    pila pilaPar, pilaImpar; 
    initialize(&pilaPar);
    initialize(&pilaImpar);

    int n; 
    cout << endl << "Ingrese el tamano de los arreglos: "; 
    cin >> n; 

    int a[n], b[n], p[n];

    cout << endl <<"Ingrese los valores del primer arreglo: "; 
    for(int i = 0; i < n; i++)
    {
        cout << "Elemento " << i+1 << ": "; 
        cin >> a[i];
    }

    cout << endl <<"Ingrese los valores del segundo arreglo: "; 
    for(int i = 0; i < n; i++)
    {
        cout << "Elemento " << i+1 << ": "; 
        cin >> b[i];
    }

    cout << endl << "Calculando producto de los arreglos...";
    for(int i = 0; i < n; i++)
    {
        p[i] = a[i]*b[i];
    }

    cout << "Agrupando los resultados en pares e impares...";
    for(int i = 0; i < n; i++)
    {
        if(p[i] % 2 == 0)
        {
            push(&pilaPar, p[i]);
        }
        else
        {
            push(&pilaImpar, p[i]);
        }
    }

    cout << endl << "Motrando la pila de numeros pares: ";
    mostrarPila(&pilaPar);
    
    cout << endl << "Mostrando la pila de numeros impares: ";
    mostrarPila(&pilaImpar);

    return 0; 
}