#include <iostream>
#include <vector>
using namespace std; 

vector<int> numeros; 

void addNumber()
{
    int option, n; 
    bool status = true; 
    while (status)
    {
        cout << "1) Agregar numero al inicio" << endl; 
        cout << "2) Agregar numero al final" << endl; 
        cout << "3) Salir" << endl; 
        cout << "\nINgrese una opcion: "; 
        cin >> option; 

        switch(option)
        {
            case 1:
                do
                {
                cout << "Ingrese un numero entero entre 1 y 100: "; 
                cin >> n; 
                }while(n < 1 || n > 100);
                numeros.insert(numeros.begin(), n);
                cout << endl << "Numero agregado con exito!" << endl << endl; 
                break; 
            case 2: 
                do
                {
                cout << "Ingrese un numero entero entre 1 y 100: "; 
                cin >> n; 
                }while(n < 1 || n > 100); 
                numeros.insert(numeros.end()-1, n);
                cout << endl << "Numero agregado con exito!" << endl << endl; 
                break; 
            case 3: 
                cout << "Saliendo..." << endl << endl; 
                status = false; 
                break; 
            default:
                cout << "Opcion invalida. Intentalo de nuevo. " << endl; 
                break; 
        }
    }
    
}

void showAllNumbers()
{
    for(int i = 0; i < numeros.size(); i++)
    {
        cout << numeros[i] << " "; 
    }
    cout << endl; 
}

void showEven()
{
    cout << "Mostrando numeros pares..." << endl; 
    for(int i = 0; i < numeros.size(); i++)
    {
        if(numeros[0] % 2 == 0)
        {
            cout << numeros[i] << " ";
        }
    }
    cout << endl; 
}

void showOdd()
{
    cout << "Mostrando numeros impares..." << endl; 
    for(int i = 0; i < numeros.size(); i++)
    {
        if(numeros[0] % 2 != 0)
        {
            cout << numeros[i] << " ";
        }
    }
    cout << endl; 
}

void menu()
{
    int option; 
    bool status = true; 

    while(status)
    {
        cout << "***** Menu: Lista de numeros *****" << endl; 
        cout << "1) Ingresar elementos a la lista" << endl; 
        cout << "2) Mostrar todos los elementos" << endl; 
        cout << "3) Mostrar solo los elementos pares" << endl; 
        cout << "4) Mostrar solo los elementos impares" << endl;
        cout << "5) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: "; cin >> option; 

        switch(option)
        {
            case 1: addNumber(); break; 
            case 2: showAllNumbers(); break; 
            case 3: showEven(); break; 
            case 4: showOdd(); break; 
            case 5: cout << "Fin del programa\n\n"; status = false; break;
            default: cout << "Opcion invalida. Intentalo de nuevo."<< endl; break; 
        }
    }
}

int main()
{
    menu(); 
}