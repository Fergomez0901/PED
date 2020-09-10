#include <iostream>
using namespace std;

int MCD(int, int);

int main()
{
    int mayor = 0, menor = 0; 

    cout << "Ingrese el valor del numero mayor: ";
    cin >> mayor; 

    cout << "Ingrese el valor del numero menor: "; 
    cin >> menor; 

    cout << "El resultado es: " << MCD(mayor, menor);

}

int MCD(int mayor, int menor)
{
    if(menor == 0)
    {
        return mayor; 
    }
    else
    {
        return MCD(menor, mayor%menor);
    }    
}
