#include <iostream>
#include <string>
using namespace std; 

struct Estudiante 
{
    string nombre; 
    string apellido; 
    string estado = "Indefinido";
    float notas[];
};

struct Estudiante estudiante; 

void llenarDatos();
void ingresarNotas(int, float[]);
float calcPromedio(int, float[]);
string verEstado(float);
void printInfo(string, string, string, float[], float, int);

int main()
{
    llenarDatos();

    int cantNotas; 
    cout << "Ingrese la cantidad de notas: "; 
    cin >> cantNotas;
    estudiante.notas[cantNotas];

    ingresarNotas(cantNotas, estudiante.notas);
    float promedio = calcPromedio(cantNotas, estudiante.notas);
    estudiante.estado = verEstado(promedio);
    printInfo(estudiante.nombre, estudiante.apellido, estudiante.estado, estudiante.notas, promedio, cantNotas);

    return 0; 
}

void llenarDatos()
{
    cout << endl << "Introduzca el nombre del estudiante: ";
    cin >>  estudiante.nombre;
    cout << "Ingrese el apellido del estudiante: ";
    cin >> estudiante.apellido;
}

void ingresarNotas(int n, float notas[])
{
    cout << endl <<  "Ingrese las notas del estudiante: " << endl; 

    for(int i = 0; i < n; i++)
    {
        cout << "Ingrese la nota " << i+1 << ": "; 
        cin >> notas[i];
    }
}

float calcPromedio(int n, float notas[])
{
    float suma = 0, promedio; 

    for(int i = 0; i < n; i++)
    {
        suma = suma + notas[i];
    }

    promedio = suma / n; 
    return promedio; 
}

string verEstado(float promedio)
{
    string estado;
    if(promedio < 6)
    {
        estado = "Reprobado"; 
    }
    else
    {
        estado = "Aprobado";
    }
}

void printInfo(string nombre, string apellido, string estado, float notas[], float promedio, int cantNotas)
{
    cout << "Mostrando informaciond el estudiante: " << endl; 

    cout << "Nombre: " << nombre << endl; 
    cout << "Apellido: " << apellido << endl; 
    cout << "Notas: ";

    for(int i = 0; i < cantNotas; i++)
    {
        cout << "Nota " << i+1 << ": " << notas[i] << endl;
    }

    cout << "Promedio: " << promedio;
    cout << "Estado: " << estado; 
}