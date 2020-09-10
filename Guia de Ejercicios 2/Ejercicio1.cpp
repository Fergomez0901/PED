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

void ingresarDatos();
void ingresarNotas(int, float[]);
float calcPromedio(int, float[]);
string verificarPromedio(float);
void imprimirStruct(string, string, string, float[], float, int);

int main()
{
    ingresarDatos();
    
    int n; 

    cout << "Ingrese la cantidad de notas: ";
    cin >> n;
    estudiante.notas[n];

    ingresarNotas(n, estudiante.notas);

    float promedio = calcPromedio(n, estudiante.notas);

    estudiante.estado = verificarPromedio(promedio);

    imprimirStruct(estudiante.nombre, estudiante.apellido, estudiante.estado, estudiante.notas, promedio, n);

    return 0; 
}

void ingresarDatos()
{
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Ingrese el apellido del estudiante: ";
    cin >> estudiante.apellido; 
}

void ingresarNotas(int n, float *notas)
{
    cout << endl << "Ingrese las notas del estudiante" << endl; 

    for(int i = 0; i < n; i++)
    {
        cout << "Nota [" << i+1 << "]: ";
        cin >> estudiante.notas[i];
    }
}

float calcPromedio(int n, float *notas)
{
    float suma = 0, promedio = 0; 

    for(int i = 0; i < n; i++)
    {
        suma = suma + notas[i];
    }

    promedio = suma/n;

    return promedio;
}

string verificarPromedio(float promedio)
{
    string estado; 
    if(promedio >= 6)
    {
        estado = "Aprobado";
    }
    else
    {
        estado = "Reprobado";
    }
    return estado; 
}

void imprimirStruct(string nombre, string apellido, string estado, float *notas, float promedio, int n)
{
    cout << endl << "Imprimiendo datos del estudiante..." << endl;  
    cout << "Nombre: " << nombre << endl; 
    cout << "Apellido: " << apellido << endl; 

    for(int i = 0; i < n; i++)
    {
        cout << "Nota " << i+1 <<": " << notas[i] << endl; 
    }

    cout << "Promedio: " << promedio << endl; 
    cout << "Estado: " << estado << endl; 
}

