#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

struct Libro
{
    string titulo; 
    string autor; 
    int isbn; 
};

struct Revista
{
    string titulo; 
    string autor; 
    int issn; 
};

struct Estudiante
{
    string nombre; 
    string apellido; 
    int carnet;
    Libro *libro = NULL; 
    Revista *revista = NULL; 
};

struct Libro libro; 
struct Revista revista; 
struct Estudiante estudiante; 
stack<Libro> pilaLibros; 
stack<Revista> pilaRevistas; 
vector<Estudiante> listaEstudiantes; 

void agregarEstudiantes()
{
    int opcion; 
    bool estado = true; 

    while(estado)
    {
        cout <<"1) Agregar estudiante al inicio de la lista" << endl; 
        cout <<"2) Agregar etudainte al final de la lista" << endl; 
        cout <<"3) Salir" << endl; 
        cout << endl << "Ingrese una opcion: "; cin >> opcion; cin.ignore(); 

        switch(opcion)
        {
            case 1:
                cout << "Ingrese el nombre del estudiante: "; getline(cin, estudiante.nombre);
                cout << "Ingrese el apellido del estudainte: "; getline(cin, estudiante.apellido);
                cout << "Ingrese el carnet del estudiante: "; cin >> estudiante.carnet; cin.ignore(); 
                listaEstudiantes.insert(listaEstudiantes.begin(), estudiante);
                break; 
            case 2:
                cout << "Ingrese el nombre del estudiante: "; getline(cin, estudiante.nombre);
                cout << "Ingrese el apellido del estudainte: "; getline(cin, estudiante.apellido);
                cout << "Ingrese el carnet del estudiante: "; cin >> estudiante.carnet; cin.ignore(); 
                listaEstudiantes.push_back(estudiante);
                break;
            case 3:
                estado = false; 
                cout << "Saliendo..." << endl << endl; 
                break;
            default:
                cout <<"Opcion invalida. Intentalo de nuevo" << endl; 
                break; 
        }
    }
}

void agregarLibro()
{
    cout << "Ingrese el titulo del libro: "; getline(cin, libro.autor);
    cout << "Ingrese el autor del libro: "; getline(cin, libro.autor);
    cout << "Ingrese el ISBN del libro: "; cin >> libro.isbn; cin.ignore(); 
    pilaLibros.push(libro);
}

void agregarRevista()
{
    cout << "Ingrese el titulo de la revista: "; getline(cin, revista.titulo);
    cout << "Ingrese el autor de la revista: "; getline(cin, revista.autor);
    cout << "Ingrese el ISSN de la revista: "; cin >> revista.issn; cin.ignore(); 
    pilaRevistas.push(revista);
}

bool puedeAsignar(Estudiante estudiante)
{
    return (estudiante.libro == NULL && estudiante.revista == NULL) ? true : false; 
}

bool asignarLibro(int carnet, Libro *libro)
{
    bool asignado = false; 
    if(listaEstudiantes.empty())
    {
        cout << "No se puede asignar un libro. La lista de estudiantes esta vacia" << endl; 
        return asignado; 
    }
    else
    {
        bool encontrado = false;
        for(int i = 0; i < listaEstudiantes.size(); i++)
        {
            if(listaEstudiantes[i].carnet == carnet)
            {
                encontrado = true; 
                if(puedeAsignar(listaEstudiantes[i]))
                {
                    listaEstudiantes[i].libro = libro; 
                    asignado = true; 
                    cout << "Libro asignado con exito" << endl; 
                    pilaLibros.pop(); 
                }
                else
                {
                    cout << "No se puede asignar un libro. El estudiante ya tiene asigando una revista o un libro" << endl; 
                }
            }
        }
        if(encontrado == false)
        {
            cout << "El carnet ingresado no le pertenece a ningun estudiante en la lista" << endl; 
        }
        return asignado; 
    }
}

bool asignarRevista(int carnet, Revista *revista)
{
    bool asignado = false; 
    if(listaEstudiantes.empty())
    {
        cout << "No se puede asignar una revista. La lista de estudiantes esta vacia" << endl; 
        return asignado; 
    }
    else
    {
        bool encontrado = false;
        for(int i = 0; i < listaEstudiantes.size(); i++)
        {
            if(listaEstudiantes[i].carnet == carnet)
            {
                encontrado = true; 
                if(puedeAsignar(listaEstudiantes[i]))
                {
                    listaEstudiantes[i].revista = revista; 
                    asignado = true; 
                    cout << "Libro asignado con exito" << endl; 
                    pilaRevistas.pop(); 
                }
                else
                {
                    cout << "No se puede asignar una revista. El estudiante ya tiene asigando una revista o un libro" << endl; 
                }
            }
        }
        if(encontrado == false)
        {
            cout << "El carnet ingresado no le pertenece a ningun estudiante en la lista" << endl; 
        }
        return asignado; 
    }
}

void menu()
{
    int opcion, ref; 
    bool estado = true;

    while(estado)
    {
        cout << "<----- MENU ----->" << endl; 
        cout << "1) Agregar estudiantes a la lista" << endl; 
        cout << "2) Agregar un libro a la pila" << endl;
        cout << "3) Agregar una revista a la pila" << endl;
        cout << "4) Asignar un libro a un estudiante" << endl; 
        cout << "5) Asignar revista a un estudiante" << endl; 
        cout << "6) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: "; cin >> opcion;  cin.ignore(); 

        switch (opcion)
        {
            case 1: agregarEstudiantes(); break; 
            case 2: agregarLibro(); break;
            case 3: agregarRevista(); break; 
            case 4: 
                if(pilaLibros.empty())
                {
                    cout << "No se puede asignar el libro. No hay libros en la pila" << endl; 
                }
                else
                {
                    cout <<"Ingrese el carnet del estudiante al que desea asignarle un libro: "; cin >> ref; cin.ignore(); 
                    Libro book = pilaLibros.top(); 
                    asignarLibro(ref, &book);
                }
                break; 
            case 5: 
                if(pilaRevistas.empty())
                {
                    cout << "No se puede asignar revista. No hay libros en la pila" << endl; 
                }
                else
                {
                    cout <<"Ingrese el carnet del estudiante al que desea asignarle una revista: "; cin >> ref; cin.ignore(); 
                    Revista magazine = pilaRevistas.top(); 
                    asignarRevista(ref, &magazine);
                }
                break; 
            case 6: estado = false; cout << "Fin del programa" << endl; break; 
            default: cout << "Opcion invalida. Intentalo de nuevo" << endl; break;
        }
    }
}

int main()
{
    menu(); 
}