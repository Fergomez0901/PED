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

void showStack(Stack *s){
    struct Node *clone = *s;
    bool isEmpty = false; 

    while(!isEmpty){
        if(!empty(&clone)){
            cout << "Material: " << clone->element.material << endl; 
            cout << "Color: " << clone->element.color << endl;
            string estado = clone->element.estado ? "Limpio" : "Sucio"; 
            cout << "Estado: " << estado << endl;
            cout << endl; 
            clone = clone->next; 
        }else{
            isEmpty = true; 
        }
    }
    cout << endl; 
}

void menu(Stack *clean, Stack *dirty){
    int opcion; 
    bool estado = true;

    while(estado){
        cout << "***** Menu *****" << endl; 
        cout << "1) Ensuciar un (1) plato" << endl; 
        cout << "2) Ensuciar N platos" << endl; 
        cout << "3) Limpiar un (1) plato" << endl; 
        cout << "4) Limpiar N platos" << endl; 
        cout << "5) Mostrar pila limpia" << endl; 
        cout << "6) Mostrar pila sucia" << endl;
        cout << "7) Salir del programa" << endl; 

        cout << endl << "Ingrese una opcion: ";
        cin >> opcion; 
        cin.ignore(); 

        switch (opcion)
        {
        case 1:
            ensuciarPlato(clean, dirty, 1);
            break;

        case 2: 
            int n; 
            cout << "Ingrese la cantidad de platos a ensuciar: ";
            cin >> n; 
            ensuciarPlato(clean, dirty, n);
            break; 

        case 3: 
            limpiarPlatos(clean, dirty, 1);
            break;
        
        case 4: 
            int x; 
            cout << "Ingrese la cantidad de platos a limpiar: ";
            cin >> x;
            limpiarPlatos(clean, dirty, x);
            break; 

        case 5: 
            cout << "Mostrando pila limpia" << endl; 
            showStack(clean);
            break; 

        case 6: 
            cout << "Mostrando pila sucia" << endl; 
            showStack(dirty);
            break;

        case 7:
            cout << "Fin del programa" << endl; 
            estado = false; 
            break; 
        
        default:
            cout << "Opcion Invalida" << endl; 
            break;
        }
    }
}

int main(){
    Stack clean, dirty; 
    initialize(&clean);
    initialize(&dirty);

    llenarPilaInicial(&clean);
    menu(&clean, &dirty);

    return 0; 
}