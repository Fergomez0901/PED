#include <iostream>
#include <queue>
using namespace std; 

void searchChar(queue<char> q, char carS){
    bool found = false; 
    queue<char> clone = q; 
    
    while(!clone.empty())
    {
        if(clone.front() == carS)
        {
            found = true; 
            cout << "Se encontro el caracter. \nBorrando cola..." << endl; 
            clone.pop();
            while(!q.empty())
            {
                q.pop();
            }
        }
        else
        {
            clone.pop(); 
        }
    }

    if(!found)
    {
        cout << "No se encontro el caracter. " << endl;
    }
}

void menu(queue<char> q){
    int opcion; 
    bool estado = true; 
    char car, carS; 
    while(estado)
    {
        cout << endl << "----- Menu -----" << endl; 
        cout << "1) Ingresar un caracter a la cola" << endl; 
        cout << "2) Buscar un caracter en la cola" << endl; 
        cout << "3) Salir del programa" << endl;
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion; 

        switch (opcion)
        {
        case 1:
            cout << "Ingrese un caracter: ";
            cin >> car; 

            q.push(car);
            break;
        
        case 2: 
            cout << "Ingrese el caracter que desea buscar: ";
            cin >> carS; 
        
            searchChar(q, carS);
            break; 

        case 3: 
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
    queue<char> charQ; 
    menu(charQ);
}