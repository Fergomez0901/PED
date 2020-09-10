#include <iostream>
using namespace std; 

int suma(int);

int main()
{
    int n; 
    cout << "Ingrese un numero natural: ";
    cin >> n;

    cout << "La suma de los primeros " << n << " numeros naturales es: " << suma(n);

    return 0; 
}

int suma(int n)
{
    if(n == 1)
    {
        return 1; 
    }
    else
    {
        return n+(suma(n-1));
    }    
}