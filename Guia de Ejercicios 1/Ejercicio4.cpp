#include <iostream>
using namespace std;

int main ()
{
    int n;               //Tamaño del arreglo
    int numeros [n];     // Declaracion del arreglo de numeros
    int m;              //termino mayor
    int *p = &m;        //Puntero apunta a M

    cout << endl << "Ingrese la cantidad de valores en la lista: " << endl; 
    cin >> n; 

    cout << endl << "Llenando el arreglo..." << endl; 

    for(int i = 0; i < n; i++)
    {
        cout << "Ingrese un numero entero: " << endl;
        cin >> numeros[i];
    }
    
    cout << endl << "Calculando el termino mayor..." << endl; 
    m = numeros[0];

    for(int i = 1; i < n; i++)
    {
        if(numeros[i] > m)
        {
            m = numeros[i];
        }
    }

    cout << "El termino mayor es: " << *p << endl; 

    return 0; 
}
