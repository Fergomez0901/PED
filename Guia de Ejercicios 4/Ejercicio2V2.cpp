#include <iostream>
using namespace std;

struct Client{
    string name;
    int payment; 
    struct Client *next; 
};
typedef struct Client client; 

struct Queue{
    client *front; 
    client *back; 
};
typedef struct Queue queue;

void initialize(queue *q){
    q->front = NULL; 
    q->back = NULL; 
}

bool empty(queue *q){
    return (q->front == NULL) ? true : false; 
}

void push(queue *q, string nombre, int payment){
    client *newClient;
    newClient = new Client; 
    newClient->name = nombre; 
    newClient->payment = payment; 
    newClient->next = NULL; 

    if(q->back == NULL){
        q->front = newClient; 
    }else{
        (q->back)->next = newClient; 
    }

    q->back = newClient; 
}

void pop(queue *q){
    if(empty(q)){
        cout << "Underflow" << endl; 
        return; 
    }

    client *newClient = q->front;
    q->front = newClient->next; 

    if(q->front == NULL){
        q->back == NULL;
    }

    delete(newClient);
}

int cobro(queue *q, int paidAmount){
    if(empty(q)){
        cout << "no hay clientes en la cola, no se realizo ningun cobro" << endl; 
        return 0; 
    }else{
        while(!empty(q)){
            paidAmount += q->front->payment;
            cout << "Se le ha cobrado $" << q->front->payment << " a " << q->front->name << endl; 
            pop(q);
        }
    }

    return paidAmount; 
}

void menu(queue *q){
    int option;
    string name;
    int amount = 0, totalPaid = 0; 
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar cliente a la cola" << endl;
        cout << "2. Cobrar" << endl;
        cout << "3. Salir del programa" << endl;
        
        
        cout << "\n" << "Ingrese la opción que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                int payment;
                cout << "Ingrese el nombre del cliente: "; 
                cin.ignore(); 
                getline(cin, name);
                cout << "Ingrese el monto de pago del cliente: ";
                cin >> payment; 

                push(q, name, payment);
                break;
            case 2:
                totalPaid += cobro(q, amount);
                cout << "Se ha cobrado un total de $" << totalPaid << " a los clientes" << endl; 
                break;
            case 3:
                cout << "Fin del programa" << endl;
                status = false;
                break;
            default:
                cout << "No es una opción valida" << endl;
                break;
        }
    }
}

int main(){
    queue q; 
    initialize(&q);
    menu(&q);
}
