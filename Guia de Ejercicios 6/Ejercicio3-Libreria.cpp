#include <iostream>
#include <stack>
#include <vector>
using namespace std; 

struct Student{
    string name; 
    int id; 
};

struct Book{
    string title; 
    string author; 
};

struct Magazine{
    string title;
    string author; 
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
    cout << "Libro agregado exitosamente!" << endl; 
}

void addMagazine()
{
    cout << "Ingrese el nombre de la revista: "; getline(cin, magazine.title);
    cout << "Ingrese el nombre del autor: "; getline(cin, magazine.author);
    magazines.push(magazine);
    cout << "Revista agregado exitosamente!" << endl; 
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

void distribute()
{
    while(!books.empty())
    {
        for (int i = 0; i < books.size(); i++)
        {
            
        }
    }
}

int main()
{

}