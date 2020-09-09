#include <iostream>
using namespace std;

int main ()
{
    int  n = 7; // Se almacena un valor entero
    int *p = &n; 

    cout << endl << "Contenido de n: " << n << endl; 
    cout << "Puntero contiene: " << p << endl; 
    cout << "Puntero apunta a: " << *p << endl;

    cout << endl << "Ingrese el nuevo valor de n" << endl; 
    cin >> *p;

    cout << "Puntero contiene: " << p << endl; 
    cout << "Puntero apunta a: " << *p << endl;
    cout << "Contenido de n:  " << n << endl;
    
    return 0; 
}
