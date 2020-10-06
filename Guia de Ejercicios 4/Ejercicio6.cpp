#include <iostream>
#include <queue>
using namespace std;

void showQueue(queue<int> q)
{
    queue<int> clone = q; 
    while(!clone.empty())
    {
        cout << clone.front() << " "; 
        clone.pop(); 
    }
    cout << endl; 
}

void evenOdd(queue<int> n, queue<int> e, queue<int> o)
{
    while(!n.empty())
    {
        if(n.front()%2 == 0)
        { 
            int a = n.front(); 
            e.push(a);;
        }
        else
        {
            int b = n.front(); 
            o.push(b);
        }
        n.pop(); 
    }

    showQueue(e);
    showQueue(o);
}

int main()
{
    queue<int> numeros, even, odd; 
    numeros.push(1);
    numeros.push(2);
    numeros.push(3);
    numeros.push(4);
    numeros.push(5);
    numeros.push(6);
    numeros.push(7);
    numeros.push(8);
    numeros.push(9);
    numeros.push(10);

    evenOdd(numeros, even, odd);

    return 0; 
}