#include <iostream>
using namespace std;

float raiz(int, float);

int main()
{
    int n;
    float r;  

    cout << "Introduzca un numero entero positivo: ";
    cin >> n; 

    cout << "Introduzca un valor semilla: ";
    cin >> r; 

    cout << "La raiz cuadrada es: " << raiz(n, r);

    return 0; 
}

float raiz(int n, float r)
{
    float anterior = r; 
    r = ((n/r+r)/2);

    if(anterior-r < 0.0000001)
    {
        return r; 
    }
    else
    {
        return raiz(n, r);
    }
}