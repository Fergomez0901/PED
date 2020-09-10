#include <iostream>
#include <string>
using namespace std; 

struct Estudiante
{
    string nombre; 
    string apellido; 
    float* notas;
};

void ingresarDatos(int, Estudiante[]);
float *ingresarNotas(int);
float calcPromedio(int, float*);
int encontrarMayor(int, float*);
void devolverEstudiante(int, Estudiante[]);

int main()
{
    int n, cantNotas; 
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n; 

    cout << "Ingrese la cantidad de notas de los estudiantes: " ; 
    cin >> cantNotas;

    struct Estudiante estudiantes[n];

    ingresarDatos(n, estudiantes);

    for(int i = 0; i < n; i++)
    {
        estudiantes[i].notas[cantNotas];

        cout << endl << "Ingresando las notas del estudiante [" << i <<"]" << endl; 
        cin.clear();

        estudiantes[i].notas = ingresarNotas(cantNotas);
    }

    float promedios[n];

    for(int i = 0; i < n; i++)
    {
        promedios[i] = calcPromedio(cantNotas, estudiantes[i].notas);
    }

    int posMayor; 

    posMayor = encontrarMayor(n, promedios);
    
    devolverEstudiante(posMayor, estudiantes);

    return 0; 
}

void ingresarDatos(int n, Estudiante *estudiantes)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Ingrese el nombre del estudiante: " << endl; 
        cin >> estudiantes[i].nombre; 

        cout << "Ingrese el apellido del estudinte: " << endl; 
        cin >> estudiantes[i].apellido;
    }
}

float *ingresarNotas(int cantNotas)
{
    float *notas = new float[cantNotas];

    for(int i = 0; i< cantNotas; i++)
    {
        cout << "Nota [" << i << "]: ";
        cin >> notas[i];
    }

    return notas; 
}

float calcPromedio(int cantNotas, float *notas)
{
    float suma = 0, promedio = 0; 

    for(int i = 0; i < cantNotas; i++)
    {
        suma += notas[i];
    }

    promedio = suma / cantNotas; 

    return promedio; 
}

int encontrarMayor(int n, float *promedios)
{
    float mayor = 0;
    int posicion; 

    for(int i = 0; i < n; i++)
    {
        if(promedios[i] > mayor)
        {
            mayor = promedios[i];
            posicion = i; 
        }
    }

    return posicion; 
}

void devolverEstudiante(int pos, Estudiante *estudiantes)
{
    cout << endl << "El estudiante con el mayor promedio es: " << estudiantes[pos].nombre;
}