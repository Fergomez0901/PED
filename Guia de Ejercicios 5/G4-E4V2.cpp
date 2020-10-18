#include <iostream> 
using namespace std; 

struct Pair{
    int num1; 
    int num2;
    struct Pair *next; 
};
typedef struct Pair pairs; 

struct Queue{
    pairs *front; 
    pairs *back;
};
typedef struct Queue queue; 

void initialize(queue *q){
    q->front = NULL; 
    q->back = NULL; 
}

bool empty(queue *q)
{
    return(q->front == NULL) ? true:false; 
}

void push(queue *q, int num1, int num2)
{
    pairs *newPair; 
    newPair = new pairs; 
    newPair->num1 = num1; 
    newPair->num2 = num2; 
    newPair->next = NULL; 

    if(q->back== NULL)
    {
        q->front = newPair;
    }
    else
    {
        (q->front)->next = newPair;
    }
    q->back = newPair;
}
void pop(queue *q)
{ 
    if(empty(q))
    {
        cout << "Underflow" << endl; 
        return; 
    }
    pairs *aux = q->front;
    q->front = (aux)->next;
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
        cout << "{" << clone->front->num1 << ", " << clone->front->num2 << "}" << endl; 
        pop(clone); 
    }
}

void menu(queue *q)
{
    int option; 
    bool status = true; 
    pairs pareja; 

    while(status)
    {
        cout << "----- Menu -----" << endl; 
        cout << "1) Ingresar parejas de numeros a la cola" << endl; 
        cout << "2) Mostrar la cola" << endl; 
        cout << "3) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: ";
        cin >> option; 

        switch (option)
        {
        case 1:
            cout << "Ingrese el primer numero: ";
            cin >> pareja.num1;
            cout << "Ingrese el segundo numero: ";
            cin >> pareja.num2; 

            push(q, pareja.num1, pareja.num2);
            break;

        case 2: 
            cout << "Mostrando cola..." << endl; 

            showQueue(q);
            break; 

        case 3: 
            cout << "Fin del programa" << endl; 
            status = false; 
            break; 

        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}

int main()
{
    queue numPairs; 
    initialize(&numPairs);
    menu(&numPairs);
}