#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std; 

struct Persona{
    string nombre; 
    string apellido; 
    string email; 
    int edad; 
    int telefono; 
    int carnet; 
};
Persona unaPersona; 

void llenarLista(list<Persona> p){
    char letra = 's';
    while(letra == 's')
    {
        cout << "Ingrese el nombre: "; getline(cin, unaPersona.nombre);
        cout << "Ingrese el apellido: "; getline(cin, unaPersona.apellido);
        cout << "Ingrese la edad: "; cin >> unaPersona.edad; cin.ignore(); 
        cout << "Ingrese el carnet: "; cin >> unaPersona.carnet; cin.ignore(); 
        cout << "Ingrese el numero de telefono: "; cin >> unaPersona.telefono; cin.ignore(); 
        cout << "Ingrese el correo electronico: "; getline(cin, unaPersona.email);
        p.push_back(unaPersona);
        
        cout << "Desea agregar otra persona? (s/n): ";  cin >> letra; cin.ignore(); 
    }
}

void eliminarPersona(list<Persona> p){

    int option; 
    int ref; 
    cout << "1) Eliminar primera persona" << endl; 
    cout << "2) Eliminar ultima persona" << endl; 
    cout << "3) Eliminar usando carnet" << endl; 
    cout << "4) Vaciar" << endl; 
    cout << "5) Salir" << endl;
    cout << "Ingrese una opcion: "; cin >> option; cin.ignore(); 

    switch(option)
    {
        case 1: p.pop_front(); break;
        case 2: p.pop_back(); break; 
        case 3: 
            cout << "Ingrese el carnet : "; cin >> ref; cin.ignore();
            for(auto iter = p.begin(); iter != p.end(); ++iter)
            {
                if(iter->carnet == ref)
                {
                    iter = p.erase(iter);
                    break;
                }
            }
            break; 
        case 4: p.clear(); break; 
        case 5: cout << "Saliendo... "<< endl; break; 
        default: cout << "Opcion invalida" << endl; break; 
    }
}

void actualizarDatos(list<Persona> p)
{
    int ref; 
    bool found = false; 
    cout << "Ingrese el carnet de la persona que desea actualizar: "; cin >> ref; cin.ignore(); 

    for(Persona i: p)
    {
        if(i.carnet == ref)
        {
            found = true;
            cout << "Ingrese el nombre: ";  getline(cin, i.nombre);
            cout << "Ingrese el apellido: "; getline(cin, i.apellido);
            cout << "Ingrese la edad: ";  cin >> i.edad; cin.ignore(); 
            cout << "Ingrese el telefono: "; cin >> i.telefono; cin.ignore(); 
            cout << "Ingrese el correo electronico: "; getline(cin, i.email);
            cout << "Datos actualizados con exito!" << endl; 
        }
    }
    if(!found)
    {
        cout << "El carnet ingresado no le corresponde a ninguna persona en la lista" << endl; 
    }
}

void mostrarLista(list<Persona> p)
{
    cout << "Mostrando lista: " << endl << endl; 

    for(auto iter = p.begin(); iter != p.end(); ++iter)
    {
        cout << "*) Nombre: " << iter->nombre << " -Apellido: " << iter->apellido << " -Edad: " << iter->edad << " -Carnet: " << iter->carnet << " -Email: " << iter->email << " -Telefono: " << iter->telefono; 
    }
}

void menu(list<Persona> p)
{
    int opcion = 0; 
    bool estado = true; 
    while(estado)
    {
        cout << "*------- MENU -------*" << endl; 
        cout << "1) Llenar lista" << endl; 
        cout << "2) Eliminar una persona" << endl; 
        cout << "3) Actualizar los datos de una persona" << endl; 
        cout << "4) Mostrar todas las personas" << endl; 
        cout << "5) Salir" << endl; 
        cout << "Ingrese una opcion: ";     cin >> opcion; cin.ignore(); 

        switch(opcion)
        {
            case 1: llenarLista(p); break; 
            case 2: eliminarPersona(p); break; 
            case 3: actualizarDatos(p); break; 
            case 4: mostrarLista(p); break; 
            case 5: estado = false; cout << "Fin del programa." << endl; break; 
            default: cout << "Opcion invalida. Intentalo de nuevo." << endl; break;
        }
    }
}

int main()
{
    list<Persona> personas; 
    menu(personas);
    return 0; 
}