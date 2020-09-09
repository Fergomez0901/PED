#include <iostream>
using namespace std; 

void sales(int ROWS, int COLS, int sales[][5], int s1, int s2)
{
    s1 = 0; 
    s2 = 0; 
    for (int i = 0; i < COLS; i++)
    {
        s1 += sales[0][i];
    }

    for(int j = 0; j < COLS; j++)
    {
        s2 += sales[1][j];
    }
    
    cout << endl << "Ventas de la semana 1: " << s1 << endl; 
    cout << "Ventas de la semana 2: " << s2 << endl; 

    if(s1>s2)
    {
        cout << "Semana con mas ventas: Semana 1 " << "\t" << s1 << " unidades vendidas" << endl;
    }
    else if(s2>s1)
    {
        cout << "Semana con mas ventas: Semana 2 " << "\t" << s2 << " unidades vendidas" << endl;
    }
    else 
    {
        cout << "Ambas semanas vendieron lo mismo " << "\t" << s1 << " unidades vendidas" << endl;
    }

}

int main()
{
    int fils = 2; 
    int cols = 5; 
    int ventas[2][5];
    int sem1 = 0, sem2 = 0; 

    cout << endl << "Ingrese las unidades vendidas: " << endl; 

    for(int i = 0; i < fils; i ++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "Semana: " << i+1 << "\tDia: " << j+1 << endl; 
            cin >> ventas[i][j];
        }
    }

    sales(fils, cols, ventas, sem1, sem2);

    return 0; 
}