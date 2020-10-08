#include <iostream>
using namespace std; 

struct Person{
    string name; 
    string last; 
    int payment; 
    struct Person *next; 
};
typedef struct Person person;
person client; 

struct Queue{
    person *front; 
    person *back;
};
typedef struct Queue queue; 

void initialize(queue *q){
    q->front = NULL;
    q->back = NULL; 
}

bool empty(queue *q){
    return(q->front == NULL) ? true:false; 
}

void push(queue *q, string name, string last, int payment){
    person *newPerson; 
    newPerson = new person; 
    newPerson->name = name;
    newPerson->last = last; 
    newPerson->payment = payment; 
    newPerson->next = NULL; 

    if(q->back == NULL)
    {
        q->front = newPerson; 
    }
    else
    {
        (q->back)->next = newPerson; 
    }
    q->back = newPerson;
}

void pop(queue *q)
{
    if(empty(q))
    {
        cout << "Underflow" << endl;
        return;
    }

    Person *newPerson = q->front;
    q->front = (q->front)->next; 
    if(q->front == NULL)
    {
        q->back = NULL; 
    }
    delete(newPerson);
}

void charge(queue *q, int amountPaid)
{
    while(!empty(q))
    {
        amountPaid += q->front->payment;
        pop(q); 
    }
    cout << "Se ha cobrado un total de $" << amountPaid << " a los clientes" << endl; 
}

void menu(queue *q , int amount){
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar cliente a la cola" << endl;
        cout << "2. Cobrar" << endl;
        cout << "3. Salir del programa" << endl;
                
        cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Ingrese el nombre del cliente: " << endl;
                cin >> client.name; 
                cout << "Ingrese el apellido del cliente: " << endl;
                cin >> client.last;
                cout << "Ingrese el monto a pagar del cliente:" << endl; 
                cin >> client.payment;

                push(q, client.name, client.last, client.payment);
                break;

            case 2:
                charge(q, amount);
                break;

            case 3:
                cout << "Fin del programa" << endl; 
                status = false; 
                break;
                
            default:
                cout << "No es una opción" << endl;
                break;
        }
    }
}

int main()
{
    int amount = 0;
    queue clients; 
    initialize(&clients);
    menu(&clients, amount);
}