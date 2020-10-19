#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

struct Product{
    string name; 
    int id; 
    float price; 
};
vector<Product> products; 

struct Client{
    string name; 
    string last; 
    vector<Product> prod; 
};

struct Product product; 
struct Client client;
queue<Client> clients; 

void addClient()
{
    bool status = true; 
    int option; 
    
    cout << "Ingrese el nombre del cliente: " << endl;      getline(cin, client.name);
    cout << "Ingrese el apellido del cliente: " << endl;    getline(cin, client.last);

    while(status)
    {
        cout << "1) Agregar un producto al inicio" << endl; 
        cout << "2) Agregar un producto al final" << endl;
        cout << "3) Salir" << endl; 
        cout << endl << "Ingrese una opcion: ";             cin >> option; cin.ignore(); 
        
        switch (option)
        {
        case 1:
            cout << "Ingrese el nombre del producto: ";     getline(cin, product.name);
            cout << "Ingrese el ID del producto: ";         cin >> product.id; cin.ignore(); 
            cout << "Ingrese el precio del producto: ";     cin >> product.price; cin.ignore(); 
            client.prod.insert(client.prod.begin(), product);
            cout << "\nProducto agregado exitosamente!" << endl << endl; 
            break;
        case 2:
            cout << "Ingrese el nombre del producto: ";     getline(cin, product.name);
            cout << "Ingrese el ID del producto: ";         cin >> product.id; cin.ignore(); 
            cout << "Ingrese el precio del producto: ";     cin >> product.price; cin.ignore(); 
            client.prod.insert(client.prod.end()-1, product);
            cout << "\nProducto agregado exitosamente!" << endl << endl; 
            break;
        case 3: 
            cout << "Saliendo... " << endl << endl; 
            status = false;
            break; 
        default:
            cout << "Opcion invalida. Intentalo de nuevo" << endl << endl; 
            break;
        }
    }
    clients.push(client);
}

void charge()
{
    float total = 0; 

    if(clients.empty())
    {
        cout << "La cola esta vacia" << endl << endl;
        return; 
    }

    while(!clients.empty())
    {
        for(int i = 0; i < clients.front().prod.size(); i++)
        {
            total += clients.front().prod[i].price; 
        }

        cout << endl << "Informacion del cliente: " << endl; 
        cout << "Nombre: " << clients.front().name << " -Apellido: " << clients.front().last << endl; 
        cout << "Lista de productos: " << endl; 
        for(int i = 0; i < clients.front().prod.size(); i++)
        {
            cout << i+1 << ") Producto: " << clients.front().prod[i].name << " -ID: " << clients.front().prod[i].id <<" -Precio: " << clients.front().prod[i].price << endl;
        }
        cout << "Monto total de pago: $" << total << endl << endl;
        clients.pop(); 
    } 
}

void menu()
{
    int option; 
    bool status = true;
    
    while(status)
    {
        cout << "***** Menu - Caja *****" << endl; 
        cout << "1) Agregar un cliente" << endl; 
        cout << "2) Cobrar a los clientes" << endl; 
        cout << "3) Salir del programa" << endl; 
        cout << "\nIngrese una opcion: "; cin >> option; cin.ignore(); 

        switch (option)
        {
        case 1:
            addClient(); 
            break;
        case 2:
            charge();
            break; 
        case 3:
            cout << "Fin del programa" << endl << endl;
            status = false; 
            break; 
        default:
            cout << "Opcion invalida. Intentalo de nuevo" << endl << endl; 
            break;
        }
    }
}

int main()
{
    menu(); 
    return 0; 
}
