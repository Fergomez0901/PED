#include <iostream>
using namespace std; 

struct Node
{
    int element; 
    struct Node *next; 
};
typedef struct Node node; 

struct Queue{
    Node *front;
    Node *back; 
};
typedef struct Queue queue; 

void initialize(queue *q){
    q->front = NULL; 
    q->back = NULL;
}

bool empty(queue *q){
    return(q->front == NULL) ? true : false; 
}

void push(queue *q, int e){
    node *newNode; 
    newNode = new node; 
    newNode->element = e;
    newNode->next = NULL; 

    if(q->back == NULL){
        q->front = newNode;
    }else{
        (q->back)->next = newNode; 
    }

    q->back = newNode; 
}

void pop(queue *q){
    if(empty(q)){
        cout << "Underflow" << endl; 
        return; 
    }

    node *newNode = q->front; 
    q->front = newNode->next; 

    if(q->front == NULL){
        q->back = NULL; 
    }
    delete(newNode);
}

void showQueue(queue *q){
    node *aux = q->front; 
    if(empty(q)){
        cout << "La cola esta vacia" << endl; 
    }else{
        while(aux){
            cout << aux->element << " ";
            aux = aux->next; 
        }
    }
}

void menu(queue *q)
{
    int option; 
    bool status = true; 

    while(status)
    {
        cout << endl << "<----- Menu de opciones ----->" << endl;
        cout << "1) Ingresar un elemento a la cola" << endl;
        cout << "2) Eliminar un elementos de la cola" << endl; 
        cout << "3) Mostrar cola" << endl;
        cout << "4) Terminar el programa" << endl; 

        cout << endl << "Introduzca un opcion: ";
        cin >> option; 

        switch(option)
        {
            case 1: 
                int e; 
                cout << "Ingrese un numero a la cola: ";
                cin >> e; 
                push(q, e);
                cout << "Mostrando cola actualizada" << endl;
                showQueue(q);
                break; 

            case 2: 
                pop(q);
                break; 

            case 3: 
                showQueue(q);
                break; 

            case 4: 
                cout << "Fin del programa" << endl; 
                status = false; 
                break; 

            default: 
                
                break;
        } 
    }
}