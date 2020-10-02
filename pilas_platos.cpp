#include <iostream>
#include <string>
#include <stack>
using namespace std; 

struct platos
{
    string material;  
    string color; 
    bool estado; 
};
typedef platos platos; 


void mostrarPila(stack<platos> p)
{
    stack<platos> aux = p; 
    bool vacio = false; 

    while(!vacio)
    {
        if(!aux.empty())
        {
            cout << aux.top() << " ";
            aux.pop(); 
        }
        else
        {
            vacio = true; 
        }
    }
}


void menu(stack<platos> c, stack<platos> d)
{
    int opcion; 
    bool status = true; 

    while(status)
    {
        cout << endl << "Menu de opciones;" << endl; 
        cout << "1) Ensuciar un (1) plato" << endl; 
        cout << "2) Ensuciar N platos" << endl; 
        cout << "3) Limpiar un (1) plato" << endl; 
        cout << "4) Limpiar N platos" << endl;
        cout << "5) Mostrar pila limipia" << endl; 
        cout << "6) Mostrar pila sucia" << endl; 
        cout << "7) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion; 

        switch(opcion)
        {
            case 1: 
            d.push(c.top());
            c.pop(); 
            break;

            case 2: 
            int n; 
            cout << "Ingrese la cantidad de platos a ensuciar: ";
            cin >> n;

            for(int i = 1; i<=n; i++)
            {
                d.push(c.top());            //lo hice de esta manera para mostrar que saco uno de una pilo y lo introduzco en otra
                c.pop();
            }
            break; 

            case 3: 
            c.push(d.top());
            d.pop(); 
            break; 

            case 4:
            int n; 
            cout << "Ingrese la cantidad de platos a limpiar: ";
            cin >> n; 

            for(int i = 1; i <= n; i++)
            {
                c.push(d.top());
                d.pop(); 
            }

            case 5:
            mostrarPila(c);
            break; 

            case 6: 
            mostrarPila(d);
            break; 

            case 7:
            cout << "Fin del programa " << endl; 
            status = false; 

            default: 
            cout << "Opcion invalida" << endl; 
            break; 
        }
    }
}

int main()
{
    stack<platos> clean, dirty; 

    string material; 
    string color;


    cout << endl << "Solicitando informacion de los platos... " << endl; 
    int cantPlatos; 
    cout << "Ingrese la cantidad de platos a utilizar" << endl; 
    cin >> cantPlatos;

    for(int i = 1; i <= cantPlatos; i++)
    {
        cout << "Plato " << i <<": " << endl; 
        cout << "Ingrese el material del plato";
        cin >> material; 
        
        cout << "Ingrese el color del plato: ";
        cin >> color; 

        clean.push(material, color, true);
    }
}