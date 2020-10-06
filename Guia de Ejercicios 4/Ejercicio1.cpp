#include <iostream>
#include <queue>
using namespace std; 

void showQueue(queue<int> q)
{
    queue<int> clone = q; 
    while(!clone.empty())
    {
        cout << clone.front() << " "; 
        clone.pop(); 
    }
}

void menu(queue<int> q)
{
    int option; 
    bool status = true; 

    while(status)
    {
        cout << endl << "<----- Menu de opciones ----->" << endl;
        cout << "1) Ingresar un elemento a la cola" << endl;
        cout << "2) Eliminar un elementos de la cola" << endl; 
        cout << "3) Mostrar cola" << endl;
        cout << "4) Terminar el programa" << endl; 

        cout << endl << "Introduzca un opcion: ";
        cin >> option; 

        switch(option)
        {
            case 1: 
                int element;

                cout << "Ingrese el elemento a agregar a la cola: " << endl; 
                cin >> element; 

                q.push(element);
                break; 

            case 2: 
                q.pop();
                break; 

            case 3: 
                showQueue(q);
                break; 

            case 4: 
                cout << "Fin del programa" << endl; 
                status = false; 
                break; 

            default: 
                cout << "Opcion Invalida" << endl;
                break;
        } 
    }
}

int main()
{
    queue<int> intQueue; 

    menu(intQueue);
}