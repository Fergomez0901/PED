#include <iostream>
#include <string.h>
using namespace std; 

void poblarArr(int size, char cadena[])
{
    for(int i = 0; i < size; i++)
    {
        cout << "Ingrese la letra no. " << i+1 << " :"<< endl; 
        cin >> cadena[i]; 
    }
}

void buscar(char word[], int size, char l)
{

    for(int i = 0; i < size; i++)
    {
        if(word[i] == l)
        {
            cout << "Direccion de la letra: " << (void*) &word[i];
            break;
        }
    }
}

int main()
{
    int n = 0;          //Tamaño de la cadena de caracteres
    char palabra[n];
    char letra; 

    cout << endl << "Ingrese el tamano de la cadena de caraccteres: " << endl;
    cin >> n; 

    poblarArr(n, palabra);

    cout << endl << "Ingrese una letra a buscar para conocer su direccion: " << endl; 
    cin >> letra; 

    buscar(palabra, n, letra);

    return 0; 
}