#include <iostream>
#include <vector>
using namespace std; 

struct Persona
{
    string nombre; 
    string apellido;
    string correo; 
    int carnet; 
    int telefono; 
};
struct Persona persona; 
vector<Persona> listaPersonas; 

void agregarPersona()
{
    bool estado = true; 
    int opcion; 
    cout << "Ingrese el nombre de la persona: "; getline(cin, persona.nombre);
    cout << "Ingrese el apellido de la persona: "; getline(cin, persona.apellido);
    cout << "Ingrese el correo electronico: "; getline(cin, persona.correo);
    cout << "Ingrese el numero de carnet: "; cin >> persona.carnet;     cin.ignore(); 
    cout << "Ingrese el numero de telefono: "; cin >> persona.telefono; cin.ignore();
    
    while(estado)
    {
        cout << endl << "1) Agregar persona al inicio" << endl;
        cout << "2) Agregar persona al final" << endl; 
        cout << "3) Salir" << endl; 
        cout << "Ingrese una opcion: "; cin >> opcion; cin.ignore(); 

        switch(opcion)
        {
            case 1: listaPersonas.insert(listaPersonas.begin(), persona); estado = false; break;
            case 2: listaPersonas.insert(listaPersonas.end()-1, persona); estado = false; break;
            case 3: estado = false; cout << "Saliendo..." << endl << endl; break; 
            default: cout << "Opcion invalida. Intentalo de nuevo" << endl; break; 
        }
    }
}

void eliminarPersona()
{
    int opcion; 
    bool estado = true; 

    while(estado)
    {
        cout << "1) Eliminar la primera persona en la lista" << endl; 
        cout << "2) Eliminar la ultima persona en la lista" << endl; 
        cout << "3) Eliminar todas las personas de la lita" << endl; 
        cout << "4) Salir" << endl; 
        cout << endl << "Ingrese una opcion: "; cin >> opcion; 

        switch (opcion)
        {
            case 1: listaPersonas.erase(listaPersonas.begin()); estado = false; break; 
            case 2: listaPersonas.erase(listaPersonas.end()-1); estado = false;  break;
            case 3: listaPersonas.clear(); estado = false; break;
            default: cout << "Opcion invalida. Intentalo de nuevo" << endl; break;
        }
    }
}

void actualizarDatos()
{
    int ref; 
    bool encontrado = false; 
    cout << "Ingrese el carnet correspondiente a la persona que desea modificar: "; cin >> ref; cin.ignore(); 
    
    for(int i = 0; i < listaPersonas.size(); i++)
    {
        if(listaPersonas.at(i).carnet == ref)
        {
            encontrado = true; 
            cout << "Ingrese el nuevo nombre: "; getline(cin, persona.nombre);
            cout << "Ingrese el nuevo apellido: "; getline(cin, persona.apellido);
            cout << "Ingrese el nuevo correo electronico: "; getline(cin, persona.correo);
            cout << "Ingrese el nuevo numero de telefono: "; cin >> persona.telefono; 
            //No tiene sentido actualizar carnet...
            cout << "Datos actualizados con exito!" << endl; 
        }
    }
    if(!encontrado)
    {
        cout << "El carnet ingresado no le pertenece a ninguna persona en la lista" << endl << endl; 
    }
}

void mostrarLista()
{
    cout << "Mostrando lista de personas..." << endl << endl; 
    
    for(int i = 0; i < listaPersonas.size(); i++)
    {
        cout << "Nombre: " << listaPersonas.at(i).nombre << " -Apellido: " << listaPersonas.at(i).apellido << " -Carnet: " << listaPersonas.at(i).carnet << " -Telefono: " << listaPersonas.at(i).telefono << " -Correo electronico: " << listaPersonas.at(i).correo << endl; 
    }
}

void menu()
{
    int opcion; 
    bool estado = true; 

    while(estado)
    {
        cout << "<----- MENU ----->" << endl; 
        cout << "1) Llenar lista" << endl; 
        cout << "2) Eliminar una persona" << endl; 
        cout << "3) Actualizar los datos de una persona" << endl; 
        cout << "4) Mostrar todas las personas" << endl; 
        cout << "5) Salir" << endl; 
        cout << endl << "Ingrese una opcion: ";     cin >> opcion;  cin.ignore(); 

        switch(opcion)
        {
            case 1: agregarPersona(); break; 
            case 2: eliminarPersona(); break; 
            case 3: actualizarDatos(); break; 
            case 4: mostrarLista(); break; 
            case 5: estado = false; cout << "Fin del programa" << endl; break;
            default: cout << "Opcion invalida. Intentalo de nuevo" << endl; break; 
        }
    }
}

int main()
{
    menu(); 
    return 0; 
}