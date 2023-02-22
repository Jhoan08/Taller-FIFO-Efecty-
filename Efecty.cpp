
/*
    Integrantes:
    Charly Jhoan Murillo Hernandez (12200263)
    Kelly Jhoana Mosquera Urbano (22100171)
    Sebastian Arteaga Castro (12200055)
*/    

#include <iostream>
#include <malloc.h>

using namespace std;

struct cliente
{
    char nombre[30];
    char apellido[30];
    int Ndocumento;
    cliente *sig;
};

int n;
cliente *cab, *aux, *aux2;

int registrar();
int Mostrar();

int main()
{

    int opc=1;
    do{
        cout<<"\nMenu"<<endl;
        cout<<"1. Registrar clientes"<<endl;
        cout<<"2. Mostrar clientes"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opc;
        switch (opc)
        {
            case 1: registrar(); break;
            case 2: Mostrar(); break;
            case 3:cout<<"Adios"; break;
            default:cout<<"Opcion Invalidad."; break;
        }
    }while(opc!=3);

}


int registrar(){

    cout<<"Bienvenido al area de registro"<<endl;
    if (cab==NULL)
    {
        cab = (struct cliente *) malloc (sizeof(struct cliente));
        
        cout<<"Ingresa tu primer nombre: "<<endl;
        cin>>cab->nombre;
        cab-> sig = NULL;
        cout<<"Ingresa tu primer apellido: "<<endl;
        cin>>cab->apellido;
        cab-> sig = NULL;
        cout<<"Ingrese su numero de identificacion: "<<endl;
        cin>>cab->Ndocumento;
        cab-> sig = NULL;
        cout<<"Cliente Registrado."<<endl;
    } else{
        aux = (struct cliente *) malloc (sizeof(struct cliente));
        
        cout<<"Ingresa tu primer nombre: "<<endl;
        cin>>aux->nombre;
        aux-> sig = NULL;
        cout<<"Ingresa tu primer apellido: "<<endl;
        cin>>aux->apellido;
        aux-> sig = NULL;
        cout<<"Ingrese su numero de identificacion: "<<endl;
        cin>>aux->Ndocumento;
        aux-> sig = NULL;
        
        aux2 = cab;
        while (aux2->sig!=NULL)
            
            aux2 = aux2->sig;
            aux2->sig = aux;
            aux2 = aux = NULL;

            free(aux);
            free(aux2);
        cout<<"Cliente Registrado."<<endl;
    }
  n++;             
return 0;
}

int Mostrar(){

    cout<<"Bienvenido al area de Mostrar Clientes"<<endl;
    cout<<"Se han Registrado "<<n<<" Clientes."<<endl;
    cout<<"Estos son los clientes que has Registrado: "<<endl;
    cout<<""<<endl;

    for (aux=cab; aux!=NULL; aux = aux->sig)
    {
        cout<<aux->nombre<<" "<<aux->apellido<<" -- "<<aux->Ndocumento<<endl;  
    }
    return 0;

}