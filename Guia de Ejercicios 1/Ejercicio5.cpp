#include <iostream>
#include <string.h>
using namespace std; 

int main() 
{
    char palabra [7] = {'p','u','n','t','e','r','o'};
    char *p = palabra;
    
    cout << *p << p[1] << 'n' << endl; 
    cout << *(p+3) << *(p+4) << *(p+5) << *(p+6) << endl; 

    return 0;
}
