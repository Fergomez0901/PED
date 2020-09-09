#include <iostream>
using namespace std;

int main()
{
    float variable = 5.1; 
    float *puntero = &variable;

    cout << "Modificando... " << endl; 
    *puntero = 20.2;
    cout << "Contenido: " << *puntero << endl; 

    float **doble = &puntero;
    cout << "Modificando..." << endl; 
    **doble = 65.3;
    
    cout << "Contenido: " << **doble << endl; 

    return 0;
}