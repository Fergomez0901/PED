#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    //Inicializar lista con valores predeterminados: 
    list<int> lista1 = {1, 2, 3, 4, 5};

    //Insertar al inicio:
    lista1.insert(lista1.begin(), 0);

    //Insertar al final: 
    lista1.insert(lista1.end(), 6);

    //Recorrer elementos: 
    cout << "Contenido de lista 1: " ;
    for(int i: lista1)
    {
        cout << i << " "; 
    }
    cout << endl; 

    //Invertir lista:
    lista1.reverse(); 
    cout << "Invirtiendo lista 1: ";
    for(int i: lista1)
    {
        cout << i << " ";
    }
    cout << endl;

    //Ordenar lista:
    lista1.sort(); 
    cout << "Ordenando lista 1: "; 
    for(int i: lista1)
    {
        cout << i << " ";
    }
    cout << endl; 

    //Buscar un elemento            Buscando el numero 3:
    if(find(lista1.begin(), lista1.end(), 3) != lista1.end())
    {
        cout << "El numero 3 si esta" << endl; 
    }
    else
    {
        cout << "El numero 3 no esta" << endl; 
    }

    //Insertar DESPUES de: 
    cout << "Insertando el 7 DESPUES del 4: "; 
    lista1.insert(next(find(lista1.begin(), lista1.end(), 4)), 7);
    for(int i: lista1)
    {
        cout << i << " "; 
    }
    cout << endl; 

    //Eliminar un elemento: 
    cout << "Eliminando el numero 3: " ;
    lista1.erase(find(lista1.begin(), lista1.end(), 3)); 
    for(int i: lista1)
    {
        cout << i << " ";
    }
    cout << endl; 

    //Consultar tamaño:
    cout << "Cantidad de elementos: " << lista1.size() << endl; 

    //Vaciar lista
    cout << "Vaciando lista..." << endl;
    lista1.clear(); 
    cout << "Cantidad de elementos: " << lista1.size() << endl; 

    return 0; 
}