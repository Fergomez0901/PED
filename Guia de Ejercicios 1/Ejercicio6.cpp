#include <iostream>
#include <string.h>
using namespace std; 

int cantVocal(int punt);

int main ()
{
    int cant = 0;
    char cadena[cant];
    
    cout << endl; 
    cout << "Ingrese la cantidad de caracteres: " << endl; 
    cin >> cant;
    cout << endl; 
    
    cout << "Ingrese " << cant <<" caracteres: " << endl;
    for(int i = 0; i < cant; i++)
    {
        cin >> cadena[i];
    }
    cout << endl; 

    cout << "La cadena es: " << endl;
    for(int i = 0; i < cant; i++)
    {
        cout << cadena[i];
    }

    char *p = &cadena[0];

    cout << endl << "Direccion de inicio: " << p << endl;
    cout << "Valor de inicio: " << *p << endl;  
    
    cout << "Direccion de inicio: " << &cadena; 

    return 0; 
}