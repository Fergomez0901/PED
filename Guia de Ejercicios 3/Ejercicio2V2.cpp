#include <iostream>
#include <stack>
using namespace std; 

void showStack(stack<int> s)
{
    stack <int> clone = s;
    bool isEmpty = false; 
    while(!isEmpty)
    {
        if(!clone.empty())
        {
            cout << clone.top() << " ";
            clone.pop(); 
        }
        else
        {
            isEmpty = true; 
        }
    }
}

int main(){
    stack <int> stackPar, stackImpar; 
    int n; 

    cout << endl << "Ingrese el tamano de los arreglos: ";
    cin >> n; 

    int a[n], b[n], prod[n];

    cout << endl << "Llenando primer arreglo..." << endl; 
    for(int i = 0; i < n; i++)
    {
        cout << "Elemento [" << i+1 << "]: ";
        cin >> a[i];
    }

    cout << endl << "Llenando segundo arreglo..." << endl; 
    for(int i = 0; i < n; i++)
    {
        cout << "Elemento [" << i+1 << "]: ";
        cin >> b[i];
    }

    cout << endl << "Calculando producto de los arreglos..." << endl; 
    for(int i = 0; i < n; i++)
    {
        prod[i] = a[i]*b[i];
    }

    cout << endl << "Agrupando los resultados en pares e impares..." << endl; 
    for(int i = 0; i < n; i++)
    {
        if(prod[i] % 2 == 0)
        {
            stackPar.push(prod[i]);
        }
        else
        {
            stackImpar.push(prod[i]);
        }
    }

    cout << endl << "Mostrando pila de numeros pares: " << endl;
    showStack(stackPar);

    cout << endl << "Mostrando pila de numeros impares: " << endl;
    showStack(stackImpar);

    return 0;
}