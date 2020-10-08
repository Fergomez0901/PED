#include <iostream>
#include <queue>
using namespace std; 

struct Student{
    string name; 
    string last;
    int id;
};
struct Student student; 

void searchStudent(queue<Student> q, string nameS){
    queue<Student> aux = q; 
    bool found = false; 

    while(!aux.empty())
    {
        if(aux.front().name == nameS)
        {
            found = true;
            cout << "Se encontro al estudiante en la cola." << endl;
            return; 
        }
        else
        {
            aux.pop();
        }
    }
    if(!found)
    {
        cout << "No se encontro al estudiante en la cola." << endl; 
    }
}

void menu(queue<Student> q){
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
            cin >> student.name;
            cout << "Ingrese el apellido del estudiante: ";
            cin >> student.last; 
            cout << "Ingrese el ID del estudiante: "; 
            cin >> student.id; 
            q.push(student);
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

int main(){
    queue<Student> students;
    menu(students);
    return 0; 
}