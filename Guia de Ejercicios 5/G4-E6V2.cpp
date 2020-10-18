#include <iostream>
using namespace std; 

struct Node{
    int element; 
    struct Node *next; 
};
typedef struct Node node; 

struct Queue{
    node *front; 
    node *back; 
};
typedef struct Queue queue; 

void initialize(queue *q)
{
    q->front = NULL; 
    q->back = NULL; 
}

bool empty(queue *q)
{
    return(q->front == NULL) ? true:false; 
}

void push(queue *q, int e)
{
    node *newNode; 
    newNode = new Node;
    newNode->element = e; 
    newNode->next = NULL;

    if(q->back == NULL)
    {
        q->front = newNode; 
    }
    else
    {
        (q->back)->next = newNode; 
    }
    q->back = newNode; 
}

void pop(queue *q)
{
    if(empty(q))
    {
        cout << "Underflow" << endl;
        return; 
    }
    
    node *aux = q->front; 
    q->front = aux->next; 

    if(q->front == NULL)
    {
        q->back = NULL; 
    }
    delete(aux);
}

void showQueue(queue *q)
{
    queue *clone = q;
    while(!empty(clone))
    {
        cout << clone->front->element << " ";
        pop(clone);
    }
}

bool isEven(int n)
{
    if(n % 2 == 0)
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

void parImpar(queue *n, queue *e, queue *o)
{
    while(!empty(n))
    {
        int num; 
        if(isEven(n->front->element))
        {
            num = n->front->element;
            push(e, num);
        }
        else
        {
            num = n->front->element; 
            push(o, num);
        }
        pop(n);
    }
    showQueue(e);
    cout << endl; 
    showQueue(o);
}

int main(){
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