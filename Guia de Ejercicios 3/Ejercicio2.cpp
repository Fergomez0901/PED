#include <iostream>
using namespace std; 

struct Node
{
    int element; 
    struct Node *next;
};
typedef struct Node *Stack;

void initialize(Stack *s)
{
    *s = NULL;
}

bool empty(Stack *s)
{
    return *s == NULL;
}

void push(Stack *s, int e)
{
    struct Node *node; 
    node = (struct Node *)malloc(sizeof(struct Node));
    node -> element = e; 
    node -> next = *s;

    *s = node;
}

void pop(Stack *s)
{
    if(!empty(s))
    {
        struct Node *node = *s;
        *s = (*s) -> next; 
        delete(node);
    }
    else
    {
        return; 
    }
}

void showStack (Stack *s)
{
    struct Node *node = *s;
    bool isEmpty = false; 
    while(!isEmpty)
    {
        if(!empty(&node))
        {
            cout << node -> element << " ";
            node = node -> next;
        }
        else
        {
            isEmpty = true; 
        }
    }
}

int main()
{
    Stack sp, si; 
    initialize(&sp);
    initialize(&si);

    int n;
    cout << endl << "Ingrese el tamano de los arreglos: ";
    cin >> n; 

    int a[n], b[n], prod[n];

    cout << endl << "Ingrese los valores para el primer arreglo: " << endl; 
    for(int i = 0; i < n; i++)
    {
        cout << "Elemento " << i+1 << ": "; 
        cin >> a[i];
    }

    cout << endl << "Ingrese los valores para el segundo arreglo: " << endl; 
    for(int i = 0; i < n; i++)
    {
        cout << "Elemento " << i+1 << ": "; 
        cin >> b[i];
    }

    cout << endl << "Multiplicando los valores de los dos arreglos... " << endl; 
    for(int i = 0; i < n; i++)
    {
        prod[i] = a[i]*b[i];
    }

    cout << endl << "Agrupando los numeros pares e impares en pilas... " << endl; 
    for(int i = 0; i < n; i++)
    {
        if(prod[i] % 2 == 0)
        {
            push(&sp, prod[i]);
        }
        else
        {
            push(&si, prod[i]);
        }
    }

    cout << endl << "Mostrando la pila de numeros pares: " << endl; 
    showStack(&sp);

    cout << endl << "Mostrando la pila de numeros impares: " << endl;
    showStack(&si);
}

