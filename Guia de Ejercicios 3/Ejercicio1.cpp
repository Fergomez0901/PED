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
        struct Node *aux = *s;
        *s = (*s) -> next;
        delete(aux);
    }
    else
    {
        return;  
    }
}

void showStack(Stack *s)
{
    struct Node *clone = *s;
    bool isEmpty = false; 

    while(!isEmpty)
    {
        if(!empty(&clone))
        {
            cout << clone -> element << " ";
            clone = clone -> next; 
        }
        else
        {
            isEmpty = true; 
        }
    }
}

void menu(Stack *s)
{
    int option; 
    bool status = true; 
    
    while(status)
    {
        cout << endl << "<----- Menu de Opciones ----->" << endl; 
        cout << "1) Ingresar elemento a la pila" << endl;
        cout << "2) Eliminar elemento de la pila" << endl; 
        cout << "3) Salir del menu" << endl;
        cout << endl << "Ingrese una opcion: " ;
        cin >> option; 
        cout << endl; 

        switch (option)
        {
        case 1:
            int element;
            cout << "Ingrese el elemento a agregar a la pila: ";
            cin >> element; 
            push(s, element);
            cout << "Mostrando pila actualizada: " << endl;
            showStack(s);
            break;
        
        case 2: 
            pop(s);
            cout << "Mostrando pila actualizada: " << endl;
            showStack(s);
            break;

        case 3: 
            cout << "Fin del programa. Hasta luego." << endl; 
            status = false; 
            break; 
        default:
            break;
        }
    }
}

int main()
{
    Stack stack; 
    initialize(&stack);
    menu(&stack);
    return 0; 
}