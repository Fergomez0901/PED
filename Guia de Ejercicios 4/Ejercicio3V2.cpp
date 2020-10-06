#include <iostream>
using namespace std; 

struct Node{
    char element;
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

void push(queue *q, char c){
    Node *newNode;
    newNode->element = c;
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
    Node *newNode = q->front; 
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

void searchChar(queue *q, char c){          //Hay un error, creo
    queue *clone = q;
    bool found = false; 
    while(!empty(clone))
    {
        if(clone->front->element == c)
        {
            found = true; 
            cout << "Se encontro el caracter" << endl << "Borrando cola..." << endl; 
            pop(clone);
            while(!empty(q))
            {
                pop(q);
            }
            cout << "Mostrando cola vacia: " << endl; 
            showQueue(q);
        }else{
            pop(clone);
        }
    }
    if(!found){
        cout << "No se encontro el caracter." << endl; 
        cout << "Mostrando cola..." << endl; 
        showQueue(q);
    }
}

void menu(queue *q){
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar un caracter a la cola" << endl;
        cout << "2. Buscar un caracter y vaciar" << endl;
        cout << "3. Salir del programa" << endl;
        
        
        cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                char c; 
                cout << "Ingrese el caracter que desea agregar a la cola: ";
                cin >> c; 
                push(q, c);
                break;

            case 2:
                char cS; 
                cout << "Ingrese el caracter que desea buscar dentro de la cola: ";
                cin >> cS; 
                searchChar(q, cS);
                break;

            case 3:
                cout << "Fin del programa" << endl; 
                status = false; 
                break;

            default:
                cout << "Opcion Invalida" << endl;
                break;
        }
    }
}

int main(){
    queue charQ; 
    initialize(&charQ);
    menu(&charQ);
}

