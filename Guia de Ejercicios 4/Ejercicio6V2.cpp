#include <iostream>
using namespace std; 

struct Node{
    int element; 
    struct Node *next; 
};
typedef struct Node node; 

struct Queue{
    Node *front; 
    Node *back; 
};
typedef struct Queue queue; 

void initialize(queue *q)
{
    q->front = NULL; 
    q->back = NULL; 
}

bool empty(queue *q)
{
    return(q->front == NULL) ? true : false; 
}

void push(queue *q, int e){
    Node *newNode;
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

void evenOdd(queue *n, queue *e, queue *o)
{
    while(!empty(n))
    {
        if(n->front->element %2 == 0)
        { 
            int a = n->front->element; 
            push(e, a);
        }
        else
        {
            int b = n->front->element; 
            push(o, b);
        }
        pop(n); 
    }

    showQueue(e);
    showQueue(o);
}

int main()
{
    queue numbers, even, odd; 
    initialize(&numbers);
    initialize(&even);
    initialize(&odd);

    push(&numbers, 1);
    push(&numbers, 2);
    push(&numbers, 3);
    push(&numbers, 4);
    push(&numbers, 5);
    push(&numbers, 6);
    push(&numbers, 7);
    push(&numbers, 8);
    push(&numbers, 9);
    push(&numbers, 10);

    return 0; 
}