#include <iostream>
#include <stack>
using namespace std; 

void showStack(stack<int> s)
{
    stack<int> clone = s; 
    bool isEmpty = false; 

    while(!isEmpty)
    {
        if(!clone.empty())
        {
            cout << clone.top() << " ";
            clone.pop();
        }
        else
        {
            isEmpty = true; 
        }
    }
}

void menu(stack<int> s)
{
    int opcion; 
    bool status = true; 

    while(status)
    {
        cout << endl <<  "<----- Menu de Pilas ----->" << endl; 
        cout << "1) Agregar un elemento a la pila" << endl; 
        cout << "2) Eliminar un elemento de la pila" << endl; 
        cout << "3) Salir del menu" << endl; 

        cout << endl << "Ingrese una opcion: ";
        cin >> opcion; 

        switch (opcion)
        {
        case 1:
            int element; 
            cout << endl << "Ingrese el numero a agregar a la pila: ";
            cin >> element;
            s.push(element);
            cout << "Mostrando pila actualizada: " << endl; 
            showStack(s);
            break;
        case 2:
            s.pop();
            cout << "Mostrando pila actualizada: " << endl; 
            showStack(s);
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
    stack <int> intStack;
    menu(intStack);
    return 0;
}