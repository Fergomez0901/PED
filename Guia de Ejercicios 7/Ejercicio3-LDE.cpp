#include <iostream>
#include <list>
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
};

stack<Libro> libros; 
stack<Revista> revistas; 
list<Estudiante> estudiantes; 
Libro libro; 
Revista revista; 
Estudiante estudiante; 

void agregarLibro(){
    char letra = 's';
    while(letra == 's'){
        cout << "Ingrese el titulo del libro: "; getline(cin, libro.titulo);
        cout << "Ingrese el autor del libro: "; getline(cin, libro.autor);
        cout << "Ingrese el ISBN del libro: "; cin >> libro.isbn; 
        libros.push(libro);
        cout << "Libro agregado con exito." << endl << endl; 
        cout << "Desea agregar otro libro? (s/n): "; cin >> letra; 
    }
}

void agregarRevista(){
    char letra = 's';
    while(letra == 's'){
        cout << "Ingrese el titulo de la revista: "; getline(cin, revista.titulo);
        cout << "Ingrese el autor de la revista: "; getline(cin, revista.autor);
        cout << "Ingrese el ISSN de la revista: "; cin >> revista.issn; 
        revistas.push(revista);
        cout << "Revista agregada con exito. " << endl << endl;
        cout << "Desea agregar otra revista? (s/n): "; cin >> letra; 
    }
}

void agregarEstudiantes(){
    char letra = 's';  
    while(letra == 's'){
        cout << "Ingrese el nombre del estudiante: "; getline(cin, estudiante.nombre);
        cout << "Ingrese el apellido del estudiante: "; getline(cin, estudiante.apellido);
        cout << "Ingrese el carnet del estudiante: "; cin >> estudiante.carnet; 
        estudiantes.push_back(estudiante);
        cout << "Estudiante agregado con exito." << endl << endl; 
        cout << "Desea agregar otro estudainte? (s/n): "; cin >> letra;
    }
}

void asignarLibro(int ref, Libro *book){
    if(estudiantes.empty()){
        cout << "No se puede asignar un libro. La lista de estudiantes esta vacia." << endl << endl; 
        return; 
    }
    else{
        bool encontrado = false; 
        for(Estudiante i: estudiantes){
            if(i.carnet == ref){
                encontrado = true; 
                if(i.libro == NULL && i.revista == NULL){ 
                    i.libro = book; 
                    libros.pop(); 
                    cout << "Libro asignado con exito. " << endl << endl; 
                }
                else{
                    cout << "No se puede asignar el libro. El estudiante ya tiene asignado un libro o revista." << endl;
                }
            }
        }
        if(!encontrado){
            cout << "El carnet ingresado no le corresponde a ningun estudiante." << endl << endl;
        }
    }    
}

void asignarRevista(int ref, Revista *mag){
    if(estudiantes.empty()){
        cout << "No se puede asignar la revista. La lista de estudiantes esta vacia. " << endl << endl; 
        return;
    }
    else{
        bool encontrado = false;
        for(Estudiante i: estudiantes){
            if(i.carnet == ref){
                encontrado = true; 
                if(i.libro == NULL && i.revista == NULL){
                    i.revista = mag; 
                    revistas.pop();
                    cout << "Revista asignada con exito." << endl << endl; 
                }
                else
                {
                    cout << "No se puede asignar la revista. El estudiante ya tiene asignado un libro o una revista." << endl << endl; 
                }
            }
        }
        if(!encontrado)
        {
            cout << "El carnet ingresado no le corresponde a ningun estudiante. " << endl << endl; 
        }
    }
}

void menu(){
    int opcion;
    bool estado = true; 
    while(estado){
        cout << "*------ MENU ------*" << endl; 
        cout << "1) Agregar libros a la pila." << endl; 
        cout << "2) Agregar revistas a la pila." << endl; 
        cout << "3) Agregar estudiantes a la lista." << endl; 
        cout << "4) Asignar un libro a un estudiante." << endl; 
        cout << "5) Asignar una revista a un estudiante."<< endl; 
        cout << "6) Salir del programa." << endl; 
        cout << "Ingrese una opcion: "; cin >> opcion; cin.ignore(); 
        
        switch(opcion){
            case 1: agregarLibro(); break;
            case 2: agregarRevista(); break;
            case 3: agregarEstudiantes(); break; 
            case 4: int ref; cout << "Ingrese el carnet del estudiante: "; cin >> ref; cin.ignore(); asignarLibro(ref, &libros.top()); break; 
            case 5: int ref; cout << "Ingrese el carnet del estudiante: "; cin >> ref; cin.ignore(); asignarRevista(ref, &revistas.top()); break;
            case 6: estado = false; cout << "Fin del programa." << endl << endl; break;
            default: cout << "Opcion invalida. Intentalo de nuevo." << endl << endl; break; 
        }
    }
}

int main(){
    menu(); 
    return 0; 
}
