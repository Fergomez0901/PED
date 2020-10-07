#include <iostream>
#include <queue>
using namespace std; 

struct Student{
    string name; 
    string lastname; 
    int id; 
    float average; 
};
struct Student student;

void searchStudName(queue<Student> studentQ, string nameS){
    queue<Student> clone = studentQ; 
    if(clone.front().name == nameS){
        cout << "Se enconto al estudiante: " << endl; 
        return; 
    }
    else{
        clone.pop();
        searchStudName(clone, nameS);
    }
}

void searchStudID(queue<Student> studentQ, int idS){
    queue<Student> clone = studentQ; 
    if(clone.front().id == idS){
        cout << "Se enconto al estudiante: " << endl; 
        return; 
    }
    else{
        clone.pop();
        searchStudID(clone, idS);
    }
}

void menu(queue<Student> studentQ){
    int option;
    bool status = true;
    string nameS;
    int idS; 
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
                cin >> student.name; 
                cout << "Ingrese el apellido del estudiante:" << endl; 
                cin >> student.lastname;
                cout << "Ingrese el ID del estudiante: " << endl; 
                cin >> student.id; 
                cout << "Ingrese el promedio del estudiante: " << endl;  
                cin >> student.average; 

                studentQ.push(student);
                break;
            case 2:
                cout << "Ingrese el nombre del estudinte que desea buscar: " << endl; 
                cin >> nameS; 

                searchStudName(studentQ, nameS);
                break;
            case 3:
                cout << "Ingrese el ID del estudinte que desea buscar: " << endl; 
                cin >> idS; 
                
                searchStudID(studentQ, idS);
                break;
            case 4:
                cout << "Fin del programa" << endl; 
                status = false; 
            default:
                cout << "Opcion Invalida" << endl;
                break;
        }
    }
}

int main(){
    queue<Student> studentQ;
    menu(studentQ);
    return 0; 
}