#include <iostream>
#include <stack>

using namespace std; 

struct Plato{
    string material; 
    string color; 
    bool estado; 
};
typedef struct Plato plato; 

void showStack(stack<plato> &s){
    stack<plato> clone = s; 

    while(!clone.empty()){
        plato actual = clone.top();
        cout << "Material: " << actual.material << endl;
        cout << "Color: " << actual.color << endl;
        string estado = actual.estado ? "Limpio" : "Sucio";
        cout << "Estado: " << estado << endl; 
        clone.pop();
    }
        cout << endl; 
}

void llenarPilaInicial(stack<plato> &s){
    int n; 

    cout << endl << "Ingrese la cantidad de platos a utilizar: "; 
    cin >> n; 
    cin.ignore(); 

    for(int i = 0; i < n; i++){
        Plato plato;

        cout << "Ingrese el material del plato: ";
        getline(cin, plato.material);
        
        cout << "Ingrese el color del plato: ";
        getline(cin, plato.color);

        plato.estado = true; 
        s.push(plato);
        cout << endl; 
    }
}

void ensuciarPlatos(stack<plato> &clean, stack<plato> &dirty, int n){
    if(clean.size() < n){
        cout << "No se pude ensuciar esa cantidad de platos" << endl; 
        return; 
    }

    for(int i = 0; i < n; i++){
        if(!clean.empty()){
            plato actual = clean.top();
            actual.estado = false; 
            dirty.push(actual);
            clean.pop(); 
        }
    }
}

void limpiarPlatos(stack<plato> &clean, stack<plato> &dirty, int n){
    if(dirty.size() < n){
        cout << "No se pude limpiar esa cantidad de platos" << endl; 
        return; 
    }

    for(int i = 0; i < n; i++){
        if(!dirty.empty()){
            plato actual = dirty.top();
            actual.estado = true; 
            clean.push(actual);
            dirty.pop(); 
        }
    }
}

void menu(stack<plato> &clean, stack<plato> &dirty){
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

        switch (opcion){
        case 1:
            ensuciarPlatos(clean, dirty, 1);
            break;

        case 2:
            int n; 
            cout << "Ingrese la cantidad de platos a ensuciar: ";
            cin >> n; 
            ensuciarPlatos(clean, dirty, n);
            break; 

        case 3: 
            limpiarPlatos(clean, dirty, 1);
            break; 

        case 4: 
            int x;
            cout << "Ingrese la cantidad de platos a limpiar: ";
            cin >> x;
            limpiarPlatos(clean, dirty, n);
            break;

        case 5: 
            cout << "Mostrando pila limpia..." << endl;
            showStack(clean);
            break; 

        case 6:
            cout << "Mostrando pila sucia..." << endl;
            showStack(dirty);
            break; 

        case 7: 
            cout << "Fin del programa" << endl; 
            estado = false; 
            break; 

        default:
            cout << "Opcion invalida" << endl; 
            break;
        }
    }
}

int main()
{
    stack<plato> clean;
    stack<plato> dirty;

    llenarPilaInicial(clean);
    menu(clean, dirty);

    return 0; 
}
