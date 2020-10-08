#include <iostream>
using namespace std; 

struct Node{
    char element; 
    struct Node *next; 
};
typedef struct Node node; 

struct Queue{
    node *front; 
    node *back; 
};
typedef Queue queue;

void initialize(queue *q){
    q->front = NULL; 
    q->back = NULL; 
}

bool empty(queue *q){
    return(q->front == NULL) ? true:false; 
}

void push(queue *q, char e){
    node *newNode; 
    newNode = new node;
    newNode->element = e; 
    newNode->next = NULL; 

    if(q->back == NULL)
    {
        q->front = newNode; 
    }
    else
    {
        (q->front)->next = newNode;
    }
    q->back = newNode; 
}

void pop(queue *q){
    if(empty(q))
    {
        cout << "Underflow" << endl; 
        return; 
    }

    node *newNode = q->front;
    q->front = newNode->next;

    if(q->front == NULL)
    {
        q->back = NULL; 
    }
    delete(newNode);
}

void searchChar(queue *q, char carS){
    bool found = false; 
    queue *clone = q; 
    
    while(!empty(clone))
    {
        if(clone->front->element == carS)
        {
            found = true; 
            cout << "Se encontro el caracter. \nBorrando cola..." << endl; 
            pop(clone);
            while(!empty(q))
            {
                pop(q);
            }
        }
        else
        {
            pop(clone); 
        }
    }

    if(!found)
    {
        cout << "No se encontro el caracter. " << endl;
    }
}

void menu(queue *q){
    int opcion; 
    bool estado = true; 
    char car, carS; 
    while(estado)
    {
        cout << endl << "----- Menu -----" << endl; 
        cout << "1) Ingresar un caracter a la cola" << endl; 
        cout << "2) Buscar un caracter en la cola" << endl; 
        cout << "3) Salir del programa" << endl;
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion; 

        switch (opcion)
        {
        case 1:
            cout << "Ingrese un caracter: ";
            cin >> car; 

            push(q, car);
            break;
        
        case 2: 
            cout << "Ingrese el caracter que desea buscar: ";
            cin >> carS; 
        
            searchChar(q, carS);
            break; 

        case 3: 
            cout << "Fin del programa" << endl; 
            estado = false; 
            break;

        default:
            cout << "Opcion Invalida" << endl;
            break;
        }
    }
}

void main(){
    queue charQ; 
    initialize(&charQ);
    menu(&charQ);
}