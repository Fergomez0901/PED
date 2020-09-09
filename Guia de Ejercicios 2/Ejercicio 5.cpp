#include <iostream>
using namespace std; 

int sumaN(int);

int main()
{
    int n;
    cout << "Ingrese un numero: ";
    cin >> n; 

    cout << "La suma de los numeros es: " << sumaN(n);
    return 0;
}

int sumaN(int n)
{
    if(n == 1)                          //Caso base
    {
        return 1; 
    }
    else
    {
        return(sumaN(n-1)+n)
    }
    
}
