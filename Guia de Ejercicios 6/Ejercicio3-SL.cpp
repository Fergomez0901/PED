#include <iostream>
#include <stack>
using namespace std; 

struct Libro{
    string titulo; 
    string autor; 
    int isbn; 
};

struct Revista{
    string titulo; 
    string autor; 
    int issn; 
};

struct Estudiante{
    string nombre; 
    string apellido; 
    int carnet; 
    Libro *libro = NULL; 
    Revista *revista = NULL; 
    struct Estudiante *sig;
};

struct Lista{
    Estudiante *inicio; 
};
typedef struct Lista lista; 

void inicializar(Lista *students)
{
    students->inicio = NULL; 
}

bool estaVacia(Lista *students)
{
    return(students->inicio == NULL) ? true : false; 
}

void insertarInicio(Lista *students, string nombre, string apellido, int carnet)
{
    Estudiante *nuevo = new Estudiante;
    nuevo->nombre = nombre; 
    nuevo->apellido = apellido; 
    nuevo->carnet = carnet;
    
    nuevo->sig = students->inicio; 
    students->inicio = nuevo; 
}

void insertarFinal(Lista *students, string nombre, string apellido, int carnet)
{
    Estudiante *nuevo = new Estudiante; 
    nuevo->nombre = nombre;
    nuevo->apellido = apellido; 
    nuevo->carnet = carnet; 

    nuevo->sig = NULL; 
    
    if(students->inicio == NULL)
    {
        students->inicio = nuevo; 
    }
    else
    {
        Estudiante *p = students->inicio; 
        Estudiante *q = NULL; 

        while(p)
        {
            q = p; 
            p = p->sig; 
        }
        q->sig = nuevo; 
    }
}

bool puedeAsignar(Estudiante *estudiante)
{
    if(estudiante->libro == NULL && estudiante->revista == NULL)
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

bool asignarLibro(Lista *students, int carnet, Libro *libro)
{
    bool asignado = false; 

    if(estaVacia(students))
    {
        cout << "No se puede asignar el libro, no hay estudiantes en la lista." << endl; 
        return asignado; 
    }
    else
    {
        bool encontrado = false; 
        Estudiante *aux = students->inicio; 
        
        while(aux)
        {
            if(aux->carnet == carnet)
            {
                encontrado = true; 

                if(!puedeAsignar(aux))
                {
                    cout << "No se puede asignar el libro, el estudiante ya tiene asignado un libro o una revista" << endl; 
                    return asignado; 
                }
                else
                {
                    aux->libro = libro; 
                    asignado = true; 
                    cout << "Se le ha asignado un libro exitosamente!" << endl << endl; 
                    return asignado; 
                }
            }
            else
            {
                aux = aux->sig; 
            }
        }
        if(encontrado == false)
        {
            cout << "El carnet ingresado no le pertenece a ningun estudiante en la lista" << endl;
        }
        return asignado;         
    }
}

bool asignarRevista(Lista *students, int carnet, Revista *revista)
{
    bool asignado = false; 
    
    if(estaVacia(students))
    {
        cout << "No se puede asignar la revista, no hay estudiantes en la lista" << endl; 
        return asignado; 
    }
    else
    {
        bool found = false; 
        Estudiante *aux = students->inicio; 

        while(aux)
        {
            if(aux->carnet == carnet)
            {
                found = true; 

                if(!puedeAsignar(aux))
                {
                    cout << "No se puede asignar la revista, el estudiante ya tiene asigando un libro o una revista" << endl;
                    return asignado;
                }
                else
                {
                    aux->revista = revista; 
                    asignado = true; 
                    cout << "Se ha asignado la revista de manera exitosa!" << endl; 
                    return asignado; 
                }
            }
            else
            {
                aux = aux->sig; 
            }
        }
        if(!found)
        {
            cout << "El carnet ingresado no pertenece a ningun estudiante de la lista" << endl; 
        }
        return asignado;
    }
}

int main()
{
    Lista students; 
    inicializar(&students);
    stack<Libro> libros;
    stack<Revista> revistas; 
    bool status = true; 
    int opcion, opcion2; 

    while(status)
    {
        cout << "****** Menu ******" << endl;
        cout << "1) Ingresar libro a la pila" << endl;
        cout << "2) Ingresar revista a la pila" << endl; 
        cout << "3) Ingresar estudiante a la lista" << endl; 
        cout << "4) Asignar libro a un estudiante de la lista" << endl; 
        cout << "5) Asignar revista a un estudiante de la lista" << endl; 
        cout << "6) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: ";     cin >> opcion; cin.ignore(); 

        Libro libro; 
        Revista revista; 
        string nombre, apellido; 
        int carnet; 

        switch(opcion)
        {
            case 1: 
                cout << "Ingrese el titulo del libro: "; getline(cin, libro.titulo);
                cout << "Ingrese el autor del libro: "; getline(cin, libro.autor);
                cout << "Ingrese el ISBN del libro: "; cin >> libro.isbn;
                libros.push(libro);    
                break;
            case 2:
                cout << "Ingrese el titulo de la revista: "; getline(cin, revista.autor);
                cout << "Ingrese el nombre del autor: "; getline(cin, libro.autor);
                cout << "Ingrese el ISSN de la revista: "; cin >> libro.isbn;
                revistas.push(revista);
                break; 
            case 3:
                cout << "Ingrese el nombre del estudiante: "; getline(cin, nombre);
                cout << "Ingrese el apellido del estudiante: "; getline(cin, apellido);
                cout << "Ingrese el carnet del estudiante: ";   cin >> carnet; 

                cout << "\nDonde desea insertar al estudiante?" << endl; 
                cout << "1) Insertar al inicio" << endl; 
                cout << "2) Insertar al final" << endl; 
                cout << "3) Salir" << endl; 
                cout << "Ingrese una opcion: "; cin >> opcion2; 

                switch(opcion2)
                {
                    case 1: insertarInicio(&students, nombre, apellido, carnet); break; 
                    case 2: insertarFinal(&students, nombre, apellido, carnet); break; 
                    case 3: cout << "Saliendo..." << endl << endl; break; 
                    default: cout << "Opcion invalida" << endl << endl; break;
                }
            case 4: 
                if(libros.empty())
                {
                    cout << "No se puede asignar libro, la pila de libros esta vacia" << endl; 
                }
                else
                {
                    Libro libro = libros.top(); 
                    int carnet; 

                    cout << "Ingrese el carnet del estudiante al que le desea asignar un libro: "; cin >> carnet; 
                    if(asignarLibro(&students, carnet, &libro))
                    {
                        libros.pop(); 
                    }
                }
                break; 
            case 5:
                if(revistas.empty())
                {
                    cout << "No se puede asignar revista, la pila de revistas esta vacia" << endl; 
                }
                else
                {
                    Revista revista = revistas.top(); 
                    int carnet; 

                    cout << "Ingrese el carnet del etudiante al que desea asignarle una revista: "; cin >> carnet; 
                    if(asignarRevista(&students, carnet, &revista))
                    {
                        revistas.pop();
                    }
                }
                break; 
            case 6:
                status = false; 
                cout << "Fin del programa" << endl;
                break; 
            default:
                cout << "Opcion invalida. Intentalo de nuevo" << endl; 
                break;  
        }
    }
    return 0; 
}




