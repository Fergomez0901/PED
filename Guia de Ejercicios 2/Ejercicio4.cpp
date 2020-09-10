#include <iostream>
using namespace std; 

int raizDigital(int);

int main ()
{
    int n;

    cout << "Ingrese un numero positivo: "; 
    cin >> n; 

    cout << "La raiz digital es: " << raizDigital(n);

}

int raizDigital(int num )
{
    int suma = 0; 
    if(num <= 9)
    {
        return num; 
    }
    else
    {
        while(num > 0)
        {
        suma = suma + num%10;
        num = num/10;
        }
        return raizDigital(suma);
    }
}