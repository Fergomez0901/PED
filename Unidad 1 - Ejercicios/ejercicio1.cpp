/* 
    Digite un programa que calcule la medina de un arreglo de numeros enteros. Para simplificar el ejercicio,
    los elementos del arreglo deberán estar ya ordenados 
*/

#include <iostream>
using namespace std; 

float mediana(float *p, int tam)
{
    if(tam%2 == 0)
    {
        
    }
}

int main()
{
    int n = 0;              //Tamaño del arreglo
    float numeros[n];
    float *punt = &numeros[0]; 

    cout << endl << "Ingrese la cantidad de numeros a introducir: " << endl; 
    cin >> n;

    cout << "Ingrese los numeros (ORDENADOS):" << endl; 
    
    for(int i = 0; i < n; i++)
    {
        cout << "Ingrese un numero: " << endl; 
        cin >> numeros[i];
    }

    mediana(punt, n);


}