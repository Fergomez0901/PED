#include <iostream>
using namespace std; 

struct Pairs{
    int num1; 
    int num2; 
    struct Pairs *next; 
};
typedef struct Pairs pairs; 

struct Queue{
    pairs *front; 
    pairs *back; 
};
typedef struct Queue queue; 

void initialize(queue *q){
    q->front = NULL; 
    q->back = NULL; 
}

bool empty(queue *q){
    return (q->front == NULL) ? true : false; 
}

void push(queue *q, int num1, int num2){
    pairs *newPair; 
    newPair = new pairs; 
    newPair->num1 = num1; 
    newPair->num2 = num2; 
    newPair->next = NULL; 

    if(q->back == NULL){
        q->front = newPair; 
    }else{
        (q->back)->next = newPair; 
    }

    q->back = newPair; 
}

void pop(queue *q){
    if(empty(q)){
        cout << "Underflow" << endl; 
        return; 
    }
    pairs *newPairs = q->front; 
    q->front = newPairs->next; 

    if(q->front == NULL){
        q->back = NULL; 
    }
    delete(newPairs);
}

void showQueue(queue *q){
    pairs *aux = q->front;
    if(empty(q)){
        cout << "La cola esta vacia" << endl; 
    }else{
        while(aux){
            cout << "{" << aux->num1 << "," << aux->num2 << "} ";
            aux = aux->next;
        }
    }
}

void menu(queue *q){
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar pares a la cola" << endl;
        cout << "2. Mostrar los pares en la cola" << endl;
        cout << "3. Salir del programa" << endl;
        
        cout << "\n" << "Ingrese la opción que desea ejecutar: ";
        cin >> option;
        cout << endl; 

        switch(option) {
            case 1:
                int num1, num2; 
                cout << "Ingrese el primer numero: ";
                cin>> num1; 
                cout << "Ingrese el segundo numero: ";
                cin >> num2; 
                push(q, num1, num2);
                break;

            case 2:
                showQueue(q);
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

    queue q;
    initialize(&q);
    menu(&q);

    return 0; 
}