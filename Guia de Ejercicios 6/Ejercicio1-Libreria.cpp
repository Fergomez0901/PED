#include <iostream>
#include <vector>
#include <string>
using namespace std; 

struct Person{

    string name; 
    string last; 
    int id; 
    int phone; 
    string mail; 
};
struct Person person;
vector<Person> list; 

void addPerson()
{
    int n; 
    bool status = true; 
    
    while(status)
    {
        cout << "1) Agregar persona al inicio" << endl; 
        cout << "2) Agregar persona al final" << endl;
        cout << "3) Salir" << endl;  
        cout << "Ingrese una opcion: ";
        cin >> n; cin.ignore(); 

        switch(n)
        {
            case 1:
                cout << "Ingrese el nomnbre: "; 
                getline(cin, person.name);
                cout << "Ingrese el apellido: ";
                getline(cin, person.last);
                cout << "Ingrese el correo electronico: ";
                getline(cin, person.mail);
                cout << "Ingrese el numero de carnet: ";
                cin >> person.id; 
                list.insert(list.begin(), person);
                cout << "Persona agregada exitosamente!\n"; 
                break;
            case 2: 
                cout << "Ingrese el nomnbre: "; 
                getline(cin, person.name);
                cout << "Ingrese el apellido: ";
                getline(cin, person.last);
                cout << "Ingrese el correo electronico: ";
                getline(cin, person.mail);
                cout << "Ingrese el numero de carnet: ";
                cin >> person.id; 
                list.insert(list.end(), person);
                cout << "Persona agregada exitosamente!\n"; 
                break;
            case 3: 
                cout << "Saliendo..." << endl; 
                status = false;  
                break; 
            default: 
                cout << "Opcion Invalida. Intentalo denuevo" << endl;
                break; 
        }
    }
}

void deletePerson()
{
    int option;
    bool status = true; 
    
    while(status)
    {
        cout << "1) Eliminar primera persona." << endl; 
        cout << "2) Eliminar ultima persona. " << endl; 
        cout << "3) Vaciar lista" << endl; 
        cout << "4) Salir" << endl; 
        cout << "Ingrese una opcion: ";
        cin >> option; cin.ignore(); 

        switch(option)
        {
            case 1:
                list.erase(list.begin());
                cout << "Primera persona eliminada con exito!" << endl;
                cout << endl; 
                break; 
            case 2:
                list.erase(list.end()-1);
                cout << "Ultima persona eliminada con exito!" << endl;
                cout << endl; 
                break; 
            case 3: 
                list.clear(); 
                cout << "Lista vaciada." << endl;
                cout << endl; 
                break; 
            case 4: 
                cout << "Saliendo..." << endl; 
                status = false; 
                break; 
            default: 
                cout << "Opcion invalida. Intentalo de nuevo." << endl;
                break; 
        }
    }
}

void showList()
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << "Nombre: " << list[i].name << " " << list[i].last << " - Carnet: " << list[i].id;
        cout << " - Email: " << list[i].mail << " - Telefono: " << list [i].phone << endl; 
    }
}

void menu()
{
    int option; 
    bool status = true; 
    
    while(status)
    {
        cout << endl << "***** Menu de lista *****" << endl; 
        cout << "1) Llenar lista" << endl; 
        cout << "2) Eliminar personas" << endl; 
        cout << "3) Actualizar los datos de una persona" << endl; 
        cout << "4) Mostrar todas las personas" << endl; 
        cout << "5) Salir" << endl; 
        cout << endl << "Ingrese una opcion: ";
        cin >> option; cin.ignore(); 

        switch(option)
        {
            case 1: 
                addPerson(); 
                break; 
            case 2:
                deletePerson();
                break; 
            case 3:
                break; 
            case 4: 
                showList();
                break; 
            case 5: 
                status = false; 
                cout << "Fin del programa" << endl; 
                break; 
            case 6: 
                cout << "Opcion invalida. Intentalo de nuevo. " << endl; 
                break; 
        }
    }
}

int main(){
    menu();
    return 0; 
}