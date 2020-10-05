#include <iostream>
using namespace std; 

struct Plato{
    string material; 
    string color; 
    bool estado; 
};
typedef struct Plato plato; 

struct Node{
    plato element; 
    struct Node *next; 
};
typedef struct Node *Stack; 

void initialize(Stack *s){
    *s = NULL; 
}

bool empty(Stack *s){
    return *s == NULL; 
}

void push(Stack *s, Plato e){
    struct Node *node; 
    node = new Node; 
    node->element = e; 
    node->next = *s;

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

int cantidadPlatos(Stack *s){
    struct Node *node = *s;
    int contador = 0; 
    bool isEmpty = false; 

    while(!isEmpty){
        if(!empty(&node)){
            node = node->next;
            contador++;
        }else{
            isEmpty = true;
        }
    }
    return contador; 
}

void llenarPilaInicial(Stack *s){
    int n; 

    cout << "Ingrese la cantidad de platos a utilizar: "; 
    cin >> n; 
    cin.ignore(); 

    for(int i = 0; i < n; i++){
        Plato plato;

        cout << "Ingrese el material del plato: ";
        getline(cin, plato.material);
        
        cout << "Ingrese el color del plato: ";
        getline(cin, plato.color);

        plato.estado = true; 
        push(s, plato);
    }
}

void ensuciarPlato(Stack *clean, Stack *dirty, int n){

    if(cantidadPlatos(clean) < n){
        cout << "No se puede ensuciar esa cantidad de platos" << endl; 
        return; 
    }

    for(int i = 0; i < n; i++){
        if(!empty(clean)){
            plato actual = (*clean)->element;
            actual.estado = false; 
            push(dirty, actual);
            pop(clean);
        }
    }
}

void limpiarPlatos(Stack *clean, Stack *dirty, int n){
    if(cantidadPlatos(dirty) < n){
        cout << "No se puede limpiar esa cantidad de platos" << endl; 
        return; 
    }

    for(int i = 0; i < n; i++){
        if(!empty(dirty)){
            plato actual = (*dirty)->element; 
            actual.estado = true; 
            push(clean, actual);
            pop(dirty);
        }
    }
}

int main(){
    Stack clean, dirty; 
    initialize(&clean);
    initialize(&dirty);
}