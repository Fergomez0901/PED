#include <iostream>
#include <queue>
using namespace std; 

void showQ(queue<char> charQ){
    queue<char> clone = charQ;
    while(!clone.empty())
    {
        cout << clone.front() << " " << endl; 
        clone.pop();
    }
}

void searchChar(queue<char> charQ, char c){
    queue<char> clone = charQ; 
    bool found = false; 
    while(!clone.empty()){
        if(clone.front() == c){
            found = true; 
            cout << "Se encontro el caracter, borrando cola..." << endl; 
            clone.pop();
            while(!charQ.empty()){
                charQ.pop();
            }
            cout << "Mostrando cola vacia: " << endl; 
            showQ(charQ);
        }
        else{
            clone.pop(); 
        }
    }
    if(!found)
    {
        cout << "No se encontro el caractrer" << endl;
        cout << "Mostrando cola..." << endl;
        showQ(charQ);
    }
}

void menu(queue<char> charQ){
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar un caracter a la cola" << endl;
        cout << "2. Buscar un caracter y vaciar" << endl;
        cout << "3. Salir del programa" << endl;
        
        
        cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                char c; 

                cout << "Ingrese el caracter que desea agregar a la cola: ";
                cin >> c; 

                charQ.push(c);
                break;
            case 2:
                char cS; 
                showQ(charQ);

                cout << "Ingrese el caracter que desea buscar dentro de la cola: ";
                cin >> cS; 

                searchChar(charQ, cS);
                break;
            case 3:
                cout << "Fin del programa" << endl; 
                status = false; 
                break;
            default:
                cout << "Opcion Invalida" << endl;
                break;
        }
    }
}

int main(){
    queue<char> charQ; 

    menu(charQ);
}