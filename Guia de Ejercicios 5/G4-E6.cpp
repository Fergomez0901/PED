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
}

bool isEven(int n)
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

void parImpar(queue<int> numbers, queue<int> even, queue<int> odd)
{
    int num; 
    while(!numbers.empty())
    {
        if(isEven(numbers.front()))
        {
            num = numbers.front();
            even.push(num);
        }
        else
        {
            num = numbers.front(); 
            odd.push(num);
        }
        numbers.pop();
    }
    showQueue(even);
    cout << endl; 
    showQueue(odd);
}


int main()
{
    queue<int> numbers, even, odd; 

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    numbers.push(4);
    numbers.push(5);
    numbers.push(6);
    numbers.push(7);
    numbers.push(8);
    numbers.push(9);
    numbers.push(10);

    parImpar(numbers, even, odd);

    return 0; 
}