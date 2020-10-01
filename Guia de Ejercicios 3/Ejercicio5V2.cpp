#include <iostream>
#include <string>
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
    nodo = (struct Libro *)malloc(sizeof(struct Libro)); 
    nodo->titulo = titulo;
    nodo->numPags = numPags; 
    nodo->siguiente = *s;

    *s = nodo; 
}

void pop(Stack *s)
{
    if(!empty(s))
    {
        struct Libro *aux = *s; 
        *s = (*s)->siguiente;
        delete(aux);
    }
    else
    {
        return;
    }
}

void encontrarLibro(Stack *s, string titulo)
{
    if((*s)->titulo == titulo)
    {
        cout << "El libro tiene: " << (*s)->numPags << " paginas" << endl; 
        return; 
    }
    else
    {
        pop(s); 
        encontrarLibro(s, titulo);
    }
}

int main()
{
    Stack pilaLibros; 
    initialize(&pilaLibros);

    push(&pilaLibros, "Libro 1", 35);
    push(&pilaLibros, "Libro 2", 45);
    push(&pilaLibros, "Libro 3", 55);
    push(&pilaLibros, "Libro 4", 75);

    string titulo; 
    cout << endl << "Ingrese el tutlo del libro que desea encontrar: "; 
    getline(cin, titulo);
    cout << endl; 

    encontrarLibro(&pilaLibros, titulo);

    return 0; 
}