#include <iostream>
using namespace std; 

void direccionCaracter(char *p)     //Imprimir direccion de la letra introducida
{
    cout << endl << "La direccion del caracter introducido es: " << &p; 
}

void buscarLetra(char l, char *pointer)
{
    int contador = 0;       //contador de las veces que se repite una letra en la palabra
    
    cout << endl << "Direccion del primer elemento en el arreglo: " << &pointer; //direccion del primer elementos (para referencia)

    for(int i = 0; i < 12; i++)         //Recorrer arreglo
    {
        if(*(pointer+i) == l)            //compara cada letra del arreglo con la letra porporcionada. 
        {
            contador+=1; 
        }
    }

    if(contador == 1)
    {
        cout << endl << "La letra " << l << " se repite: " << contador << " vez"  << endl; 

    }
    if(contador > 1)
    {
        cout << endl << "La letra " << l << " se repite: " << contador << " veces"  << endl; 
    }
    else
    {
        cout << endl << "El caracter no se encuentra en la palabra" << endl; 
    }

}

int main()
{
    char palabra[12] = {'p','r','o','g','r','a','m','a','c','i','o','n'}; 
    char letra;
    char *punt = palabra;    //puntero apunta a direccion del primer elemento del arreglo

    cout << endl << "Ingrese una letra: "; 
    cin >> letra; 

    direccionCaracter(&letra);
    buscarLetra(letra, punt);

    return 0; 
}