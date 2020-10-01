#include <iostream>
#include <stack> 
using namespace std;

void showstack(stack<int> s)
{
    stack<int> clone = s; 
    bool isEmpty = false; 

    while (!isEmpty)
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

void invert(stack<int>* s, stack<int>* i)
{
    if((*s).empty())
    {
        return;
    }
    else
    {
        int aux = (*s).top(); 
        (*s).pop();
        (*i).push(aux);
        invert(s, i);
    }
}

int main()
{
    stack <int> stackO, invStack; 

    stackO.push(1);
    stackO.push(2);
    stackO.push(3);
    stackO.push(4);
    stackO.push(5);
    stackO.push(6);
    stackO.push(7);
    stackO.push(8);
    stackO.push(9);
    stackO.push(10);

    cout << endl << "Mostrando pila original: "<< endl; 
    showstack(stackO);
    cout << endl;

    invert(&stackO, &invStack);

    cout << endl << "Mostrando pila invertida: " << endl; 
    showstack(invStack);
    cout << endl;

    return 0; 
}