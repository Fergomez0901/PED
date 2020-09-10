#include <iostream>
using namespace std; 

void Hanoi(int, int, int, int);

int main()
{
    int n;
    int t1 = 1, t2 = 2, t3 = 3;

    cout << "Ingrese la cantidad de discos: ";
    cin >> n; 

    Hanoi(n, t1, t2, t3);

    return 0;  
}

void Hanoi(int n, int inicio, int aux, int fin)
{
    if(n == 1)
    {
        cout << "El disco " << n << " se mueve de torre " << inicio << " hacia torre " << fin << endl; 
        return;
    }
    else
    {
        Hanoi(n-1, inicio, aux, fin);
        cout << "El disco " << n << " se nueve de la torre " << inicio << " hacia la torre " << aux << endl;
        Hanoi(n-1, aux, inicio, fin)
    }
    
}