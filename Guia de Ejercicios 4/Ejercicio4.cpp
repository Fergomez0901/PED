#include <iostream>
#include <queue>
using namespace std; 

struct Pairs{
    int num1; 
    int num2; 
};

struct Pairs pairs; 

void showQ(queue<Pairs> pairsQ){
    queue<Pairs> clone = pairsQ; 
    while(!clone.empty()){
        cout << "[" << clone.front().num1 << "," << clone.front().num2 << "]" << endl; 
        clone.pop(); 
    }
}

void menu(queue<Pairs> pairsQ){
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar pares a la cola" << endl;
        cout << "2. Mostrar los pares en la cola" << endl;
        cout << "3. Salir del programa" << endl;
        
        
        cout << "\n" << "Ingrese la opción que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Ingresando pares" << endl; 
                cout << "Ingrese el primer numero: ";
                cin >> pairs.num1; 
                cout << "Ingrese el segundo numero: ";
                cin >> pairs.num2; 

                pairsQ.push(pairs);
                break;
            case 2:
                showQ(pairsQ);
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
    queue<Pairs> pairsQ; 

    menu(pairsQ);
    
    return 0; 
}