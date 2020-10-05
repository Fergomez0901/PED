#include <iostream>
#include <stack>
using namespace std;

struct Capa{
    string tipo;
    float grosor; 
    int dureza;
};

void showStack(stack <Capa> &s){
    while(!s.empty()){
        Capa actual = s.top();
        cout << "Tipo de suelo: " << actual.tipo; 
        cout << " -Grosor: " << actual.grosor; 
        cout << " -Dureza: " << actual.dureza;
        s.pop(); 
    }
    cout << endl; 
}

void agregarCapa(stack <Capa> &s){
    Capa capa;
    
    cout << "Ingrese el tipo de suelo: ";
    getline(cin, capa.tipo);

    do{
        cout << "Ingrese el grosor de la capa: ";
        cin >> capa.grosor; 
    }while(capa.grosor <= 0);

    do{
        cout << "Ingrese la dureza de la capa: ";
        cin >> capa.dureza; 
    }while(capa.grosor <= 0);
        s.push(capa);
}


void borrarPila(stack <Capa> &s){
    while(!s.empty()){
        s.pop();
    }
}

void promedioDureza(stack <Capa> &s){
    float suma = 0, promedio; 
    int contador = s.size(); 

    while(!s.empty()){
        Capa actual = s.top(); 
        suma += actual.dureza; 
        s.pop(); 
    }
    promedio = suma / contador; 
    cout << "El promeio de durezas es: " << promedio << endl;
}

void menu(stack <Capa> &s){
    int opcion = 0; 
    bool estado = true; 
    
    while(estado){

        cout << endl  <<  "----- Menu -----" << endl; 
        cout << "1) Agregar una nueva capa" << endl; 
        cout << "2) Borrar ultima capa" << endl;
        cout << "3) Borrar todas las capas" << endl;
        cout << "4) Calcular promedio de durezas" << endl;
        cout << "5) Mostrar pila" << endl; 
        cout << "6) Salir del programa" << endl; 

        cout << endl << "Ingrese una opcion: "; 
        cin >> opcion;
        cin.ignore();

        switch(opcion){
            case 1:
                agregarCapa(s);
                break; 
            case 2:
                s.pop();
                break; 
            case 3: 
                borrarPila(s);
                break; 
            case 4:
                promedioDureza(s);
                break;
            case 5:
                showStack(s);
                break; 
            case 6: 
                cout << "Fin del programa" << endl;
                estado = false; 
                break; 
            default: 
                cout <<"Opcion invalida" << endl; 
                break;
        } 
    }
}

int main(){

    stack <Capa> s; 
    menu(s);
    return 0; 
}