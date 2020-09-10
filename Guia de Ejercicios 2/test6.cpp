#include <iostream>
#include <string>
using namespace std; 

struct Estudiante
{
    string nombre; 
    string apellido; 
    float notas[];
};

void llenarDatos(int, Estudiante[]);
float *ingresarNotas(int);
float calcPromedio(int, float[]);
int encontrarMayor(int, float[]);
void devolverEstudiante(int, Estudiante[]);

int main()
{
    int nEstud = 0, nNotas = 0;
    cout << "Introduzca el numero de estudiantes: ";
    cin >> nEstud;
    cout << "Introduzca el numero de notas por estudiante: ";
    cin >> nNotas;

    struct Estudiante estudiantes[nEstud];

    llenarDatos(nEstud, estudiantes);

    for(int i = 0; i < nEstud; i++)
    {
        estudiantes[i].notas[nNotas];
        cout << "Ingresando notas del estudiante " << i+1 << endl; 
        cin.clear();

        estudiantes[i].notas = ingresarNotas(nNotas);
    }


    return 0;
}

void llenarDatos(int cantEstud, Estudiante estudiantes[])
{
    for(int i = 0; i < cantEstud; i++)
    {
        cout << endl << "Introduzca el nombre del estudiante: ";
        cin >> estudiantes[i].nombre;
        cout << "Ingrese el apellido del estudiante: ";
        cin >> estudiantes[i].apellido;
    }
}

float *ingresarNotas(int cantNotas)
{
    float *notas = new float [cantNotas];
    cout << "Ingrese las notas: "; 

    for(int i = 0; i < cantNotas; i++)
    {
        cout << "Nota " << i+1 << ": " <<;
        cin >> notas[i];
    }
    return notas;
}

float calcPromedio(int cantNotas, float notas[])
{
    float suma = 0, promedio; 

    for(int i = 0; i < cantNotas; i++)
    {
        suma = suma + notas[i];
    }
    promedio = suma / cantNotas; 
    return promedio; 
}

int encontrarMayor(int n, float promedios[])
{
    float mayor = 0; 
    int pos; 

    for(int i = 0; i < n; i++)
    {
        if(promedios[i] > mayor)
        {
            mayor = promedios[i];
            pos = i; 
        }
    }

    return pos;
}

void devloverEstudiante(int pos, Estudiante estudiantes[])
{
    cout << "El estudiante con el mayor promedio es: " << estudiantes[pos].nombre << " " << estudiantes[pos].apellido;
}