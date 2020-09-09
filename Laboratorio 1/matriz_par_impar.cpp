#include <iostream>
using namespace std; 

void parImpar(int *p)                   //Recibe direccion de inicio de la matriz (un arreglo es un puntero)
{
    int par = 0, impar = 0;             //contadores de los pares e impares

    for(int i = 0; i < 3; i++)
    {                                   //Recorre la matriz usando puntero
        for(int j = 0; j < 3; j++)
        {
            if(*(p+i*3+j)% 2 == 0)      //Caso Par
            {
                par+=1;             
            }
            else                        //Caso impar
            {
                impar+=1;
            }
        }
    }

    cout << endl << "En la matriz hay: " << endl;
    cout << par << " numeros pares" << endl;
    cout << impar << " numeros impares" << endl; 

}

int main()
{
    int matriz[3][3]; 
    int *puntero = &matriz[0][0];           //Puntero apunta a primer elemento de la matriz

    cout << endl << "Llenando matriz..." << endl; 
    
    for(int i = 0; i < 3; i++)              //recorre la matriz
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "Ingrese el elemento [" <<i << "][" << j << "]: " << endl; 
            cin >> matriz[i][j];            //Llenado de la matriz; 
        }
    }

    parImpar(puntero);                      //Funcion recibe direccion de la matriz

    return 0; 
}