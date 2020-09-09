#include <iostream>
using namespace std;

int main () 
{
    int n; //Declaracion de variable
    int *p = &n; //Declaracion de puntero
    
    cout << endl << "Ingrese un numero entero: " << endl; 
    cin >> n;

    cout << "Valor almacenado: " << *p << endl; 
    cout << "Direccion: " << p << endl; 

    return 0; 
}