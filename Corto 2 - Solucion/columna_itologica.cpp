#include <iostream>
using namespace std; 

struct Capa{
    string tipo; 
    float grosor; 
    int dureza; 
};
typedef struct Capa capa; 

struct Node{
    capa element; 
    struct Node *next;
};
typedef struct Node *Stack; 

void initialize(Stack *s){
    *s = NULL; 
}

bool empty(Stack *s){
    return *s == NULL; 
}

void push(Stack *s, Capa e){
    struct Node *node; 
    node = new Node;
    node -> element = e; 
    node -> next = *s; 

    *s = node; 
}

void pop(Stack *s){
    if(!empty(s)){
        struct Node *aux = *s;
        *s = (*s)->next; 
        delete(aux);
    }else{
        return; 
    }
}

void showStack(Stack *s){
    struct Node *clone = *s; 
    bool isEmpty = false;
    
    while(!isEmpty){
        if(!empty(&clone)){
            cout << "Tipo de Suelo: " << clone->element.tipo << endl;
            cout << "Grosor: " << clone->element.grosor << endl; 
            cout << "Dureza: " << clone->element.dureza << endl;
            clone = clone->next; 
        }else{
            isEmpty = true; 
        }
    }
    cout << endl;
}

void agregarCapa(Stack *s){
    Capa capa; 
    cout << "Ingrese el tipo de suelo: ";
    getline(cin, capa.tipo);

    do{
        cout << "Ingrese el grosor: ";
        cin >> capa.grosor;
    }while(capa.grosor <= 0);

    do{
        cout << "Ingrese la dureza: ";
        cin >> capa.dureza; 
    }while(capa.dureza <= 0);

    push(s, capa);
}

void borrarPila(Stack *s){
    while(!empty(s)){
        pop(s);
    }
}

void promedioDureza(Stack *s){
    float suma = 0, promedio; 
    int contador = 0;               //Cantidad de elementos 

    struct Node *clone = *s; 
    bool isEmpty = false; 

    while (!isEmpty)
    {
        if(!empty(&clone)){
            suma += clone->element.dureza;
            clone = clone->next;
            contador++;
        }else{
            isEmpty = true; 
        }
    }
    promedio = suma / contador; 
    cout << "El promedio de durezas es: " << promedio << endl;
}

void menu(Stack *s){
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
                pop(s);
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
    
    Stack pila; 
    initialize(&pila);
    menu(&pila);
    return 0; 
}