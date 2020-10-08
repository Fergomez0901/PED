#include <iostream>
#include <queue>
using namespace std;

void showQueue(queue<int> q)
{
    queue<int> clone = q; 
    while(!q.empty())
    {
        cout << clone.front() << " ";
        clone.pop();
    }
}

void menu(queue<int> q){
    int opcion; 
    bool estatus = true; 
    while(estatus)
    {
        cout << "----- Menu -----" << endl; 
        cout << "1) Ingresar un elemento a la cola" << endl;
        cout << "2) Sacar un elemento de la cola" << endl; 
        cout << "3) Mostrar cola" << endl; 
        cout << endl << "Ingrese una opcion:";
        cin >> opcion; 

        switch (opcion)
        {
        case 1: 
            int n; 
            cout << "Ingrese el numero que desea agregar a la cola: ";
            cin>> n;
            q.push(n);
            cout << "Mostrando cola actualizada: " << endl; 
            showQueue(q);
            break;

        case 2: 
            q.pop();
            cout << "Mostrando cola actualizada: " << endl; 
            showQueue(q);
            break; 
        
        case 3: 
            showQueue(q);
            break;

        default:
            cout << "Opcion invalida" << endl; 
            break;
        }
    }
}

int main(){
    queue<int>intQ; 
    menu(intQ);
}