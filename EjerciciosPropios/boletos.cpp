#include <iostream>
#include <vector>
using namespace std; 

struct Boleto{
    string pelicula; 
    Butaca *butaca;
    Persona *persona; 
    float precio = 4.50;
};

struct Butaca{
    int numero;
    bool ocupado = false; 
};

struct Persona{
    string nombre; 
    string apellido; 
};

Boleto unBoleto; 
Persona unaPersona; 
Butaca unaButaca; 
vector<Boleto> butacas(50);
vector<Boleto> butacas2(50);
vector<Boleto> butacas3(50);

void mostrarDisponible()
{
    for(int i = 0; i < 50; i++)
    {
        if(butacas.at(i).butaca->ocupado == false)
        {
            cout << "Butaca #" << i+1 << "  -  "; 
        }
    }
}

void comprarBoleto(){
    int opcion, puesto; 
    bool status = true; 
    while(status)
    {
        cout << "Peliculas" << endl; 
        cout << "1) Pelicula 1" << endl; 
        cout << "2) Pelicula 2" << endl; 
        cout << "3) Pelicula 3" << endl; 
        cout << "4) Salir" << endl; 
        cout << "Ingrese una opcion: "; cin >> opcion; cin.ignore(); 

        switch (opcion)
        {
        case 1:
            cout << "Mostrando butacas disponibles: " << endl; 
            mostrarDisponible(); 
            cout << "Que butaca desea? Ingrese el numero de la butaca: "; cin >> puesto; cin.ignore();
            int pos = puesto-1;
            if(butacas.at(pos).butaca->ocupado == false)
            {
                cout << "Ingrese su nombre: "; getline(cin, butacas.at(pos).persona->nombre);
                cout << "Ingrese su apellido: "; getline(cin, butacas.at(pos).persona->apellido); 
                butacas.at(pos).pelicula = "Pelicula 1";
                butacas.at(pos).butaca->ocupado = true; 
            }
            cout << "Imprimiendo boleto..." << endl << endl;
            cout << "-------------------------" << endl;
            cout << "Pelicula: "; butacas.at(pos).pelicula; 
            cout << "Numero de butaca: "; butacas.at(pos).butaca->numero;
            cout << "Precio: $" << butacas.at(pos).precio;
            cout << "-------------------------" << endl;
            cout << "Datos del cliente: " << endl; 
            cout << "Nombre: " << butacas.at(pos).persona->nombre;
            cout << "Apellido: " << butacas.at(pos).persona->apellido;
            cout << "-------------------------" << endl;
            cout << "Disfrute la pelicula!" << endl << endl;             
            break;
        
        case 4: 
            status = false;
            cout << "Saliendo..." << endl << endl; 
            break; 

        default:
            cout << "Opcion invalida. Intentalo de nuevo. " << endl << endl; 
            break;
        }
    }
}

void menu(){
    int opcion; 
    bool status = true; 
    while(status)
    {
        cout << "*------ MENU ------*" << endl; 
        cout << "1) Comprar boleto" << endl; 
        cout << "2) Salir" << endl; 
        cout << "Ingrese una opcion: "; cin >> opcion; cin.ignore();

        switch(opcion)
        {
            case 1: break;
            case 2: status = false; cout << "Saliendo..." << endl << endl; break; 
            default: cout << "Opcion invalida. Intentalo de nuevo. " << endl << endl; break; 
        }
    }
}

int main(){
    //Llenando vector de butacas: 
    for(int i = 0; i < 50; i++)
    {
        butacas.at(i).butaca->numero = i+1;
    }
    menu();
}