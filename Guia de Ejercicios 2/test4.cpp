#include <iostream>
using namespace std; 

int mcd(int, int);

int main()
{
    int mayor = 0, menor = 0; 

    cout << endl << "Calculo de Maximo Comun Divisor (MCD)" << endl;
    cout << "Ingrese el numero mayor: ";
    cin >> mayor; 

    cout << "Ingrese el numero menor: ";
    cin >> menor; 

    cout << "El MCD es: " << mcd(mayor, menor);

    return 0; 
}

int mcd(int mayor, int menor)
{
    if(menor == 0)
    {
        return mayor; 
    }
    else
    {
        return mcd(menor, mayor%menor);
    }
}