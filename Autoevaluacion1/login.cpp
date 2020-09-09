#include <iostream>
#include <string>
using namespace std; 

int main ()
{
    string contrasena; 
    int intentos = 0; 

    while (intentos < 3){
        cout << endl << "Digite su contrasena" << endl; 
        cin >> contrasena; 

        if(contrasena == "contrasena")
        {
            cout << "Login Exitoso. Bienvenido!" << endl; 
            break; 
        }
        else
        {
            cout << "Acceso denegado. Intentalo de nuevo." << endl; 
            intentos ++;
        }
    }
if(intentos == 3)
    {
        cout<< "Accesdo Denegado" << endl; 
    }
    
return 0; 
}