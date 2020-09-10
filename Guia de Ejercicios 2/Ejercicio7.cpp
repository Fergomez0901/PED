#include <iostream>
using namespace std; 

float raiz(float, float);

int main()
{
    float n; 
    float r; 

    cout << "Introduzca un numero entero positivo: ";
    cin >> n; 

    cout << "Introduzca un valor semilla: ";
    cin >> r; 

    cout << "La raiz cuadrada es: " << raiz(n, r) << endl; 

}

float raiz(float n, float r)
{
    
    float ant = r; 
    r = ((n/r)+r)/2;
    
    if(ant - r < 0.0000001)
    {
        return r; 
    }
    else
    {
        return raiz(n, r);
    }
}

