#include <iostream>
#include <string>
using namespace std; 

struct Nodo
{
    string tipoSuelo; 
    float grosor;
    int dureza;
    struct Nodo *siguiente; 
};

typedef struct Nodo *Stack; 

void initialize(Stack *s)
{
    *s = NULL;
}

bool empty(Stack *s)
{
    return *s == NULL; 
}

void push(Stack *s, string tipoSuelo, float grosor, int dureza)
{
    struct Nodo *node; 
    node = (struct Nodo *)malloc(sizeof(struct Nodo));
    node -> tipoSuelo = tipoSuelo; 
    node -> grosor = grosor; 
    node -> dureza = dureza; 
    node -> siguiente = *s;

    *s = node; 
}

void pop(Stack *s)
{
    if(!empty(s))
    {
        struct Nodo *aux = *s;
        *s = (*s)->siguiente;
        delete(aux);
    }
    else
    {
        return; 
    }
} 

void vaciarPila(Stack *s)
{

    while(!empty(s))
    {
        pop(s);
    }
    
}

float promDureza(Stack *s)
{
    float suma = 0, promedio, contador = 0; 

    while(!empty(s))
    {
        suma += (*s)->dureza; 
        pop(s);
        contador++; //total de elementos en la pila
    }

    promedio = suma / contador; 
}


void menu(Stack *s)
{
    int opcion = 0; 
    bool estado = true; 
    float grosor = 0; 
    int dureza = 0;
    string tipoSuelo; 
    int n = 0;     

    while(estado)
    {
        cout << endl << "Menu de opciones" << endl; 
        cout << "1) Ingresar elementos a la pila" << endl; 
        cout << "2) Eliminar la ultima capa agregada" << endl; 
        cout << "3) Eliminar toda la pila" << endl; 
        cout << "4) Calcular promedio de dureza de la pila" << endl;
        cout << "5) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion; 
        cout << endl; 

        switch(opcion)
        {
        case 1:

            cout << "Ingrese la cantidad de capas que desea agregar a la pila: ";
            cin >> n; 
            cout << endl; 

            for(int i = 1; i<=n; i++)
            {
            cout << "Datos capa " << i << ": " << endl; 
            cout << "Ingrese el tipo de capa: ";
            cin >> tipoSuelo;                   //Al usar getline el programa para de funcionar, no se porque

            while(grosor <= 0)          //un valor de 0 o negativo no tiene sentido 
            {
                cout << "Ingrese el grosor de la capa: ";
                cin >> grosor; 
            }

            cout <<"Ingrese el indice de dureza de la capa: "; 
            cin >> dureza; 
            cout << endl; 
                
            push(s, tipoSuelo, grosor, dureza);
            }

        break;

        case 2: 
        if(empty(s))
        {
            cout << "Underflow!" << endl; 
        }
        else
        {
            pop(s);
        }
        break; 
        
        case 3: 
            vaciarPila(s);
        break; 

        case 4:
        cout << "El promedio de dureza de la pila es: " << promDureza(s);; 
        break; 

        case 5: 
        cout << "Fin del programa" << endl; 
        estado = false; 
        break; 
 

        default:
            cout <<"Opcion Invalida" << endl; 
            break;
        }
    }
}

int main()
{
    Stack pila; 
    initialize(&pila);

    menu(&pila);
}