#include <iostream>
#include <string.h>
using namespace std; 

void poblarArr(int size, char *punt)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Ingrese la letra no. " << i+1 << " :"<< endl; 
        cin >> punt[i]; 
    }
}

void buscar(char *p, int size, char l)
{

    for(int i = 0; i < size; i++)
    {
        if(p[i] == l)
        {
            cout << "Direccion de la letra " <<l << " es: " << (void*) &p[i];
            break;
        }
    }
}

int main()
{
    int n = 0;          //Tamaño de la cadena de caracteres
    char palabra[n];
    char letra; 
    char *pointer = palabra; 

    cout << endl << "Ingrese el tamano de la cadena de caraccteres: " << endl;
    cin >> n; 

    poblarArr(n, pointer);

    cout << endl << "Ingrese una letra a buscar para conocer su direccion: " << endl; 
    cin >> letra; 

    buscar(pointer, n, letra);

    return 0; 
}