#include <iostream>
using namespace std; 

long int factorial(int);

int main()
{
    int n;

    cout << endl <<"Calculo del factorial de un numero" << endl;
    cout << "Ingrese un numero entero positivo para calcular su factorial: ";
    cin >> n; 

    cout << endl << "El factorial es: " << factorial(n); 

    return 0; 
}

long int factorial(int n)
{
    if(n <= 1)
    {
        return n; 
    }
    else
    {
        return n*factorial(n-1);
    }
}