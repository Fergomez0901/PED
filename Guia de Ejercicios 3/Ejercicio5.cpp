#include <iostream>
#include <string>
using namespace std; 

struct Book
{
    string title; 
    int numPages; 
    struct Book *next; 
};
typedef struct Book *Stack; 

void initialize(Stack *s)
{
    *s = NULL; 
}

bool empty(Stack *s)
{
    return *s == NULL; 
}

void push(Stack *s, string title, int numPags)
{
    struct Book *node; 
    node = (struct Book *)malloc(sizeof(struct Book));
    node->title = title; 
    node->numPages = numPags; 
    node->next = *s;

    *s = node; 
}

void pop(Stack *s)
{
    if(!empty(s))
    {
        struct Book *aux = *s; 
        *s = (*s)->next; 
        delete(aux);
    }
    else
    {
        return;
    }
}

void findBP(Stack *s, string title)
{
    if((*s)->title == title)
    {
        cout << "Tiene " << (*s)->numPages << endl; 
        return; 
    }
    else
    {
        pop(s);
        findBP(s, title);
    }
}

int main()
{
    Stack bookStack; 
    initialize(&bookStack);

    push(&bookStack, "Libro 1", 250);
    push(&bookStack, "Libro 2", 150);
    push(&bookStack, "Libro 3", 175);
    push(&bookStack, "Libro 4", 200);

    string title; 
    cout << "Ingrese el titulo del libro: " << endl; 
    getline(cin, title);

    findBP(&bookStack, title);

    return 0; 
}