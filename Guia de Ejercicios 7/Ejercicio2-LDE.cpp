#include <iostream>
#include <algorithm>
#include <list>
using namespace std; 

void agregarNumero(list<int> num)
{
    char opcion = 's'; 
    int n; 
    while(opcion == 's')
    {
        cout << "Ingrese un numero entero: "; cin >> n; 
        cout << endl << "Desea agregar otro numero? (s/n): "; cin >> opcion; 
    }
}

void mostrarTodos(list<int> num)
{
    if(num.empty())
    {
        cout << "La lista esta vacia." << endl; 
        return; 
    }
    else
    {
        cout << "Mostrando lista de numeros..." << endl; 
        for(int i: num)
        {
            cout << i << " "; 
        }
    }
}

void mostrarPares(list<int> num)
{
    for(int i: num)
    {
        if(i % 2 == 0)
        {
            cout << i << " "; 
        }
    }
}

void mostrarImpares(list<int> num)
{
    for(int i: num)
    {
        if(i % 2 != 0)
        {
            cout << i << " ";
        }
    }
}

void menu(list<int> num)
{
    int opcion = 0; 
    bool estado = true;
    while(estado)
    {
        cout << "*------- MENU -------*" << endl; 
        cout << "1) Agregar numero" << endl; 
        cout << "2) Mostrar todos los elementos" << endl; 
        cout << "3) Mostrar solo elementos pares" << endl; 
        cout << "4) Mostrar solo elementos impares" << endl; 
        cout << "5) Salir" << endl; 
        cout << "Ingrese una opcion: "; cin >> opcion; 

        switch(opcion)
        {
            case 1: agregarNumero(num); break;
            case 2: mostrarTodos(num); break; 
            case 3: mostrarPares(num); break; 
            case 4: mostrarImpares(num); break; 
            case 5: estado = false; cout << "Fin del programa." << endl; break; 
            default: cout << "Opcion invalida, intentalo de nuevo." << endl; break; 
        }
    }
}

int main()
{
    list<int> numeros; 
    menu(numeros);
}