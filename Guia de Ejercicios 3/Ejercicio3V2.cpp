#include <iostream>
#include <stack>
using namespace std; 

bool isPair(int n)
{
    if(n % 2 == 0)
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

int sum(stack<int> s, int sumPar, int sumImpar)
{
    if(s.empty())
    {
        cout << "Mostrando la suma de los numeros pares: " << sumPar << endl; 
        cout << "Mostrando la suma de los numeros impares: " << sumImpar << endl; 
    }
    else
    {
        if(isPair(s.top()))
        {
            sumPar += s.top(); 
        }
        else
        {
            sumImpar += s.top(); 
        }

        s.pop();
        sum(s, sumPar, sumImpar);
    }
    
}

int main()
{
    stack <int> numStack; 
    
    numStack.push(1);
    numStack.push(2);
    numStack.push(3);
    numStack.push(4);
    numStack.push(5);
    numStack.push(6);
    numStack.push(7);
    numStack.push(8);
    numStack.push(9);
    numStack.push(10);

    int sumPar = 0, sumImpar = 0; 
    sum(numStack, sumPar, sumImpar);
}