#include <iostream>
using namespace std; 

struct Student{
    string name; 
    string last; 
    int id;
    struct Student *next; 
};
typedef struct Student student; 
student estudiante; 

struct Queue{
    student *front; 
    student *back;
};
typedef struct Queue queue; 

void initialize(queue *q){
    q->front = NULL;
    q->back = NULL;
}

bool empty(queue *q){
    return(q->front == NULL) ? true:false; 
}

void push(queue *q, string name, string last, int id){
    student *newStudent; 
    newStudent = new student; 
    newStudent->name = name; 
    newStudent->last = last; 
    newStudent->id = id; 
    newStudent->next = NULL; 

    if(q->back == NULL)
    {
        q->front = newStudent; 
    }
    else
    {
        (q->front)->next = newStudent; 
    }
    q->back = newStudent; 
}

void pop(queue *q){
    if(empty(q))
    {
        cout << "Underflow" << endl; 
        return; 
    }
    student *aux = q->front; 
    q->front = aux->next;
    
    if(q->front ==  NULL)
    {
        q->back = NULL; 
    }
    delete(aux);
}

void searchStudent(queue *q, string nameS){
    queue *aux = q; 
    bool found = false;

    while(!empty(aux))
    {
        if(q->front->name == nameS)
        {
            bool found = true; 
            cout << "Se encontro el estudiante en la cola." << endl;
            return; 
        }
        else
        {
            pop(aux);
        }
    }
    if(!found)
    {
        cout << "No se encontro al estudiante en la cola." << endl;
    }
}

void menu(queue *q){
    int option; 
    string nameS; 
    bool status = true; 
    while(status)
    {
        cout << "----- Menu -----" << endl; 
        cout << "1) Ingresar un estudiante a la cola" << endl; 
        cout << "2) Buscar estudiante por nombre" << endl; 
        cout << "3) Salir del programa." << endl; 
        cout << "\nIngrese una opcion: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
            cout << "Ingrese el nombre del estudiante: ";
            cin >> estudiante.name;
            cout << "Ingrese el apellido del estudiante: ";
            cin >> estudiante.last; 
            cout << "Ingrese el ID del estudiante: "; 
            cin >> estudiante.id; 
            push(q, estudiante.name, estudiante.last, estudiante.id);
            break;

        case 2: 
            cout << "Ingrese el nombre del estudiante a buscar: "; 
            cin >> nameS;
            searchStudent(q, nameS);
            break;

        case 3: 
            cout << "Fin del programa." << endl;
            status = false; 
            break; 

        default:
            cout << "Opcion Invalida" << endl; 
            break;
        }
    }
}

int main()
{
    queue students; 
    initialize(&students);
    menu(&students);
}