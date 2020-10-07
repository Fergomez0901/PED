#include <iostream>
using namespace std; 

struct Student{
    string name; 
    string last; 
    int id; 
    struct Student *next; 
};
typedef struct Student student; 
Student estudiante; 

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
    return(q->front == NULL) ? true: false; 
}

void push(queue *q, string nombre, string apellido, int id){
    Student *newStudent;
    newStudent = new Student; 
    newStudent->name = nombre; 
    newStudent->last = apellido;
    newStudent->id = id; 
    newStudent->next = NULL; 

    if(q->back == NULL){
        q->front = newStudent; 
    }
    else{
        (q->back)->next = newStudent; 
    }
    q->back = newStudent; 
}

void pop(queue *q){
    if(empty(q))
    {
        cout << "Underflow" << endl; 
        return; 
    }
    Student *newStudent = q->front; 
    q->front = newStudent->next; 

    if(q->front == NULL)
    {
        q->back = NULL; 
    }
    delete(newStudent);
}

void searchStudName(queue *q, string nameS)
{
    queue *clone = q; 
    bool found = false; 

    while(!empty(clone))
    {
        if(clone->front->name == nameS)
        {
            found = true;
            cout << "El estudiante esta en la cola." << endl;
            return;  
        }
        else
        {
            pop(clone);
        }
    }

    if(!found)
    {
        cout << "El estudiante no esta en la cola. " << endl; 
    }
}

void searchStudID(queue *q, int idS)
{
    queue *clone = q; 
    bool found = false; 

    while(!empty(clone))
    {
        if(clone->front->id == idS)
        {
            found = true;
            cout << "El estudiante esta en la cola." << endl;
            return;  
        }
        else
        {
            pop(clone);
        }
    }
    
    if(!found)
    {
        cout << "El estudiante no esta en la cola. " << endl; 
    }
}

void menu(queue *q){
    int option, idS;
    bool status = true;
    string nameS; 
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar un estudiante a la cola" << endl;
        cout << "2. Buscar un estudiante en la cola por nombre" << endl;
        cout << "3. Buscar estudiante por ID" << endl; 
        cout << "4. Salir del programa" << endl;
        
        cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Ingrese el nombre del estudiante: " << endl; 
                cin >> estudiante.name; 
                cout << "Ingrese el apellido del estudiante:" << endl; 
                cin >> estudiante.last;
                cout << "Ingrese el ID del estudiante: " << endl; 
                cin >> estudiante.id; 

                push(q, estudiante.name, estudiante.last, estudiante.id);
                break;

            case 2:
                cout << "Ingrese el nombre del estudinte que desea buscar: " << endl; 
                cin >> nameS; 

                searchStudName(q, nameS);
                break;

            case 3:
                cout << "Ingrese el ID del estudinte que desea buscar: " << endl; 
                cin >> idS; 
                
                searchStudID(q, idS); 
                break;

            case 4:
                cout << "Fin del programa" << endl; 
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
    queue studentQ; 
    initialize(&studentQ);
    menu(&studentQ);
}