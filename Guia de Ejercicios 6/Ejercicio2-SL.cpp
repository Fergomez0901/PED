#include <iostream>
using namespace std;

struct Node
{
    int element; 
    struct Node *next; 
};
Node *pInicio; 

bool compare(int a, int b)
{
    return (a == b);
}

int cantidadDaots()
{
    Node *s = pInicio; 
    int contador = 0; 

    while(s != NULL)
    {
        s = s->next; 
        contador ++;
    }
    return contador;
}

void insertBegin(int e)
{
    Node *newNode = new Node;
    newNode->element = e;
    newNode->next = pInicio; 

    pInicio = newNode; 
}

void insertEnd(int e)
{
    Node *newNode = new Node;
    newNode->element = e; 
    newNode->next = NULL; 

    if(pInicio == NULL)
    {
        pInicio = newNode;
    }
    else
    {
        Node *p = pInicio; 
        Node *q = NULL; 

        while(p != NULL)
        {
            q = p;
            p = p->next; 
        }
        q->next = newNode; 
    }
}

void insertAfter(int e)
{
    int ref;
    cout << "Ingrese el dato de referencia: "; cin >> ref; 

    Node *s = pInicio; 

    while(s != NULL && !compare(s->element, ref))
    {
        s = s->next; 
    }
    if(s == NULL)
    {
        cout << "Dato de referencia NO existe" << endl;
        return;  
    }

    Node *newNode = new Node; 
    newNode->element = e; 
    newNode->next = s->next; 

    s->next = newNode; 
    cout << "Dato agregado exitosamente!" << endl; 
}

void insertBefore(int e)
{
    int ref; 
    cout << "Ingrese el dato de referencia: ";  cin >> ref; 

    Node *s = pInicio, *q = NULL; 

    while(s != NULL && !compare(s->element, ref))
    {
        q = s; 
        s = s->next; 
    }
    if(s == NULL)
    {
        cout << "Dato de referencia NO existe" << endl; 
        return;
    }

    Node *newNode = new Node; 
    newNode->element = e; 
    newNode->next = s;

    if(q == NULL)
    {
        pInicio = newNode; 
    }
    else
    {
        q->next = newNode; 
    }
    cout << "Dato agregado exitosamente!" << endl; 
}

void showList()
{
    Node *s = pInicio; 

    while(s != NULL)
    {
        cout << s->element << endl;
        s = s->next; 
    }
}

void showEven()
{
    Node *s = pInicio; 

    while(s != NULL)
    {
        if((s->element) % 2 == 0)
        {
            cout << s->element << endl; 
        }
        s = s->next; 
    }
}

void showOdd()
{
    Node *s = pInicio; 

    while(s != NULL)
    {
        if((s->element) % 2 != 0)
        {
            cout << s->element << endl; 
        }
        s = s->next; 
    }
}

void DeleteNUm()
{
    int ref; 
    cout << "Ingrese el dato a eliminar: "; cin >> ref;

    Node *p = pInicio, *q = NULL; 

    while(p != NULL && !compare(p->element, ref))
    {
        q = p; 
        p = p->next; 
    }
    if(p == NULL)
    {
        cout << "El dato de referencia NO existe" << endl ;
        return; 
    }
    if (q == NULL)
    {
        pInicio = p->next; 
    }
    else
    {
        q->next = p->next; 
    }
    delete(p);
    cout << "Dato eliminado exitosamente!" << endl; 
}

void search()
{
    int ref; 
    cout << "Ingrese el dato a buscar: ";   cin >> ref;
    
    Node *s = pInicio; 

    while(s != NULL && !compare(s->element, ref));
    {
        s = s->next; 
    }

    if(s == NULL)
    {
        cout << "El dato NO se encuentra" << endl; 
    }
    else
    {
        cout << "El dato SI se encuentra" << endl; 
    }
}

void clear(Node** nodeStart)
{
    Node *current = *nodeStart; 
    Node *next; 

    while(current != NULL)
    {
        next = current->next; 
        delete(current);
        current = next; 
    }
    *nodeStart = NULL; 
}

int countOcurrences()
{
    int ref;
    cout << "Ingrese el dato de referencia:a "; cin >> ref; 

    Node* current = pInicio; 
    int contador = 0; 

    while(current != NULL)
    {
        if(compare(current->element, ref))
        {
            contador++;
        }
        current = current->next; 
    } 
}

void addNumber()
{
    int option, element; 
    bool status = true; 

    while(status)
    {
        cout << "1) Agregar un numero al inicio" << endl; 
        cout << "2) Agregar un numero al final" << endl; 
        cout << "3) Agregar un numero antes de" << endl;
        cout << "4) Agregar un numero despues de" << endl; 
        cout << "5) Salir" << endl; 
        cout << endl << "Ingrese una opcion: ";     cin >> option; 
        
        switch(option)
        {
            case 1: 
                cout << "Ingrese el numero que desea agregar: ";    cin >> element; 
                insertBegin(element);
                break;
            case 2:
                cout << "Ingrese el numero que desea agregar: ";    cin >> element; 
                insertEnd(element);
                break;
            case 3:
                cout << "Ingrese el numero que desea agregar: ";    cin >> element; 
                insertBefore(element);
                break; 
            case 4:
                cout << "Ingrese el numero que desea agregar: ";     cin >> element; 
                insertAfter(element); 
                break; 
            case 5:
                cout << "Saliendo..." << endl << endl; 
                status = false; 
                break; 
            default: 
                cout << "Opcion invalida. Intentalo de nuevo" << endl; 
                break; 
        }
    }
}

void menu()
{
    int option, element; 
    bool status = true;

    while(status)
    {
        cout << "***** Menu: Lista de numeros *****" << endl; 
        cout << "1) Ingresar elementos a la lista" << endl; 
        cout << "2) Mostrar todos los elementos" << endl; 
        cout << "3) Mostrar solo los elementos pares" << endl; 
        cout << "4) Mostrar solo los elementos impares" << endl;
        cout << "5) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: "; cin >> option; 

        switch (option)
        {
            case 1: addNumber(); break;
            case 2: showList(); break; 
            case 3: showEven(); break; 
            case 4: showOdd(); break;
            case 5: cout << "Fin del programa" << endl << endl; status = false; break; 
            default: cout << "Opcion invalida. Intentalo de nuevo" << endl; break;
        }
    }
}

int main()
{
    menu();
    return 0; 
}