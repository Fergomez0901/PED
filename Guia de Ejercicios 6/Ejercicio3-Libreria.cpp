#include <iostream>
#include <stack>
#include <vector>
using namespace std; 

struct Book{
    string title; 
    string author; 
};

struct Magazine{
    string title;
    string author; 
};

struct Student{
    string name; 
    int id; 
    Book *libro = NULL; 
    Magazine *revista = NULL; 
};

struct Student student; 
struct Book book; 
struct Magazine magazine; 
stack<Book> books; 
stack<Magazine> magazines; 
vector<Student> students; 

void addBook()
{
    cout << "Ingrese el nombre del libro: "; getline(cin, book.title);
    cout << "Ingrese el nombre del autor: "; getline(cin, book.author);
    books.push(book);
    cout << "Libro agregado exitosamente!" << endl << endl; 
}

void addMagazine()
{
    cout << "Ingrese el nombre de la revista: "; getline(cin, magazine.title);
    cout << "Ingrese el nombre del autor: "; getline(cin, magazine.author);
    magazines.push(magazine);
    cout << "Revista agregado exitosamente!" << endl << endl; 
}

void addStudent()
{
    int option;
    bool status = true; 

    while(status)
    {
        cout << "1) Insertar estudiante al inicio" << endl; 
        cout << "2) Insertar estudiante al final" << endl; 
        cout << "3) Salir" << endl; 
        cout << "\nIngrese una opcion: "; cin >> option; cin.ignore(); 

        switch(option)
        {
            case 1: 
                cout << "Ingrese el nombre del estudiante: "; getline(cin, student.name);
                cout << "Ingrese el carnet del estudiante: "; cin >> student.id;
                students.insert(students.begin(), student);
                cout << "Estudiante agregado con exito!" << endl << endl;
                break; 
            case 2:
                cout << "Ingrese el nombre del estudiante: "; getline(cin, student.name);
                cout << "Ingrese el carnet del estudiante: "; cin >> student.id;
                students.insert(students.end()-1, student);
                cout << "Estudiante agregado con exito!" << endl << endl; 
                break;
            case 3:
                cout << "Saliendo..." << endl << endl; 
                status = false; 
                break; 
            default: 
                cout << "Opcion invalida" << endl; 
                break;
        }
    }
}

bool canAssing(Student student)
{
    return(student.revista == NULL && student.libro == NULL);
}

void assingBook(int carnet, Book *libro)
{
    bool assigned = false; 
    if(students.empty())
    {
        cout << "No se puede asignar un libro. La lista de estudiantes esta vacia" << endl << endl;
        return;  
    }
    else
    {
        bool found = false; 
        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].id == carnet)
            {
                found = true;

                if(canAssing(students.at(i)))
                {
                    students[i].libro = libro; 
                    assigned = true; 
                    cout << "Se ha asignado el libro exitosamente!" << endl << endl;
                    books.pop(); 
                }
                else
                {
                    cout << "No se puede asignar un libro. El etudiante ya tiene un libro o una revista asignado" << endl << endl; 
                }
            }
        }
    } 
}

void assignMagazine(int carnet, Magazine *mag)
{
    bool assigned = false; 
    if(students.empty())
    {
        cout << "No se puede asignar una revista.La lista de estudiantes esta vacia" << endl << endl; 
        return; 
    }
    else
    {
        bool found = false; 
        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].id == carnet)
            {
                found = true; 
                if(canAssing(students[i]))
                {
                    students[i].revista = mag; 
                    assigned = true;
                    cout << "Se ha asignado una revista exitosamente" << endl<< endl; 
                    magazines.pop(); 
                }
                else
                {
                    cout << "No se puede asignar una revista. El estudiante ya tiene asignado un libro o revista" << endl << endl; 
                }
                
            }
        }
    }
}


void menu()
{
    int option; 
    bool status = true;

    while(status)
    {
        cout << "***** Menu *****" << endl; 
        cout << "1) Ingresar libro a la pila" << endl; 
        cout << "2) Ingresar revista a la pila" << endl; 
        cout << "3) Ingresar estudiante a la lista" << endl; 
        cout << "4) Asignar libro a un estudiante" << endl; 
        cout << "5) Asignar revista a un estudiante" << endl; 
        cout << "6) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: ";     cin >> option; cin.ignore(); 

        switch(option)
        {
            case 1:
                addBook(); 
                break;
            case 2:
                addMagazine(); 
                break; 
            case 3:
                addStudent(); 
                break; 
            case 4: 
                int carnet; 
                cout << "Ingrese el carnet del estudiante al que desea asignarle un libro: ";   cin >> carnet; cin.ignore();
                assingBook(carnet, &books.top());
                break; 
            case 5:
                int carnet2; 
                cout << "Ingrese el carnet del estudiante al que desea asignarle un libro: ";    cin >> carnet2; cin.ignore(); 
                break; 
            case 6:
                status = false; 
                cout << "Fin del programa" << endl << endl; 
                break; 
            default:
                cout << "Opcion invalida. Intentalo de nuevo" << endl; 
                break; 
        }
    }
}

int main()
{
    menu(); 
    return 0;
}