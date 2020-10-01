#include<iostream>
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
    if(!empty(s))
    {
        struct Nodo *nodo = *s; 
        *s = (*s) -> siguiente;
        delete(nodo);
    }
    else
    {
        return; 
    }
}

void suma(pila *s, int sumaP, int sumaI)
{
    if(empty(s))
    {
        cout << "Mostrando suma de numeros pares: " << sumaP;
        cout << "Mostrando suma de numeros impares: " << sumaI;
        return; 
    }
    else
    {
        if((*s)->elemento % 2 == 0)
        {
            sumaP += (*s)->elemento;
        }
        else
        {
            sumaI += (*s)->elemento; 
        }
        
        pop(s);
        suma(s, sumaP, sumaI);
    }
    
}

int main()
{
    pila numPila; 
    initialize(&numPila);

    push(&numPila, 7);
    push(&numPila, 6);
    push(&numPila, 5);
    push(&numPila, 4);
    push(&numPila, 3);
    push(&numPila, 2);
    push(&numPila, 1);
    push(&numPila, 8);
    push(&numPila, 9);
    push(&numPila, 10);

    int sumaP = 0, sumaI = 0;
    suma(&numPila, sumaP, sumaI);
}

