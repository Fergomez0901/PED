#include <iostream>
using namespace std;

void llenarNum(int, int*, int);

int main()
{
    int tam, cont = 0;
    int numeros[tam]; 
    cout << endl << "Ingrese el tamano del arreglo: ";
    cin >> tam; 

    llenarNum(tam, numeros, cont);

    for(int i = 0; i < tam; i++)
    {
        cout << numeros[i] << " ";
    }

    return 0;
}

void llenarNum(int n, int numeros[], int cont)
{
    if(cont == n)
    {
        return; 
    }
    else
    {
        cout << "Ingrese un numero: ";
        cin >> numeros[cont];
        llenarNum(n, numeros, cont+1);
    }
}