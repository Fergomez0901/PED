#include <iostream>
using namespace std; 

int main()
{
    int numero = 7; 
    int *puntero = &numero;                         //Indireccion
    cout << "Puntero contiene: " << *puntero;       //Desreferencia
                                                    
    *puntero = 9;                                   //Desreferencia

    cout << "Puntero contiene: " << *puntero;       //Desreferencia

    return 0;
}