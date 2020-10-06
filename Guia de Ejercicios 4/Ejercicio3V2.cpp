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

void searchChar(queue q, char c){
    queue clone = q; 
    bool found = false; 
    while(!empty(&clone){
        if(clone->front == c){
            found = true; 
            cout << "Se encontro el caracter, borrando cola..." << endl; 
            pop(clone);
            while(!empty(q)){
                pop(q);
            }
            cout << "Mostrando cola vacia: " << endl; 
            showQ(charQ); // falta
        }
        else{
            pop(clone); 
        }
    }
    if(!found)
    {
        cout << "No se encontro el caractrer" << endl;
        cout << "Mostrando cola..." << endl;
        showQ(charQ); // falta 
    }
}

