#include <iostream> 
#include <queue>
using namespace std; 

struct Pair{
    int num1; 
    int num2;
};
struct Pair pairs; 

void showQueue(queue<Pair> q)
{
    queue<Pair>clone = q;
    while(!clone.empty())
    {
        cout << "{" << clone.front().num1 << ", " << clone.front().num2 << "}" << endl; 
        clone.pop(); 
    }
}

void menu(queue<Pair> q)
{
    int option; 
    bool status = true; 

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
            cin >> pairs.num1;
            cout << "Ingrese el segundo numero: ";
            cin >> pairs.num2; 

            q.push(pairs);
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
    queue<Pair> numeros; 
    menu(numeros);
}