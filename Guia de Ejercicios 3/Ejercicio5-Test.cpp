#include <iostream>
using namespace std;

struct Libro
{
    string titulo; 
    int numPags; 
    struct Libro *siguiente;
};
typedef struct Libro *Stack; 

void initialize(Stack *s)
{
    *s = NULL;
}

bool empty(Stack *s)
{
    return *s == NULL; 
}

void push(Stack *s, string titulo, int numPags)
{
    struct Libro *nodo;
    nodo = new Libro; 
    nodo->titulo = titulo; 
    nodo->numPags = numPags; 
    nodo->siguiente = *s; 

    *s = nodo; 
}

void pop

int main()
{

    return 0; 
}