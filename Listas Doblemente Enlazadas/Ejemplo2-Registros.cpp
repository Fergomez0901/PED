#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std; 

struct Persona{
    string nombre; 
    int edad; 
};

bool compararEdad(Persona a, Persona b)
{
    return(a.edad < b.edad) ? true : false; 
}

int main()
{
    list<Persona> estudiantes; 
    char letra = 's'; 

    while(letra == 's')
    {
        cout << endl; 
        Persona unaPersona; 
        cout << "Nombre del estudiante: "; getline(cin, unaPersona.nombre);
        cout << "Edad del estudiante: "; cin >> unaPersona.edad; cin.ignore(); 
        estudiantes.insert(estudiantes.end(), unaPersona); 

        cout << "Desea agregar a otro estudiante? (s/n): "; cin >> letra; cin.ignore(); 
    }
    cout << endl; 

    //Ordenando estudiantes por edad
    cout << "Ordenando..." << endl; 
    estudiantes.sort(compararEdad);

    //Mostrando estudiantes ya ordenados: 
    for(Persona i: estudiantes)
    {
        cout << i.nombre << " tiene ";
        cout << i.edad << " anios." << endl; 
    }
    cout << endl; 

    //Borrando un elemento 
    cout << "Borrando a Fernando..." << endl; 
    for(auto iter = estudiantes.begin(); iter != estudiantes.end(); ++iter)
    {
        if(iter->nombre == "Fernando")
        {
            iter = estudiantes.erase(iter);
            break;
        }
    }

    //Mostrando la lista con el elemento ya eliminado: 
    for(Persona i: estudiantes)
    {
        cout << i.nombre << " tiene "; 
        cout << i.edad << " anios." << endl; 
    }
    cout << endl; 
    return 0; 
}