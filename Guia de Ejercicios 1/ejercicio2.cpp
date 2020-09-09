#include <iostream>
using namespace std;

int main () 
{
    int n, m;  //Variables

    cout << endl << "Ingrese un numero entero: " << endl;
    cin >> n; 
    cout << endl << "Ingrese un numero entero: " << endl;
    cin >> m; 

    int *p = &n, *q = &m; //Se declaran punteros y se les asigna una variable

    cout << endl << "Puntero P contiene: " << p << endl; 
    cout << "Puntero P apunta a: " << *p << endl;

    cout << "Puntero Q contiene: " << q << endl; 
    cout << "Puntero Q apunta a: " << *q << endl;
    
    return 0; 
}