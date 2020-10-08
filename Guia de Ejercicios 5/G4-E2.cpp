#include <iostream>
#include <queue>
using namespace std; 

struct Person{
    string name; 
    string last; 
    int payment; 
};
struct Person person; 

void charge(queue<Person> q, int amount)
{
    while(!q.empty())
    {
        amount += q.front().payment;
        q.pop(); 
    }
    cout << "Se ha cobrado un total de $" << amount << " a los clientes" << endl; 
}

void menu(queue<Person> q , int amount){
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
                cout << "Ingrese el nombre de la persona: ";
                cin >> person.name;
                cout << "Ingrese el apellido de la persona: ";
                cin >> person.last;
                cout << "Ingrese el monto de pago de la persona: ";
                cin >> person.payment;
                q.push(person);
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

int main(){
    int amount = 0; 
    queue<Person> clients; 
    menu(clients, amount);
}