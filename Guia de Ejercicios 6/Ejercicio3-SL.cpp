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

