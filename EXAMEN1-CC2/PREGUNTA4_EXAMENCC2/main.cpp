
#include <iostream>

using namespace std;

class Pila {
    private:
    class Nodo
    {
    public:
        int info;
        Nodo *sig;
    };

    Nodo *raiz;
public:
    Pila();
    ~Pila();
    void insertar(int x);
    int extraer();
    void imprimir();
    bool consulta();
};

Pila::Pila()
{
    raiz = NULL;
}

void Pila::insertar(int x)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    if (raiz == NULL)
    {
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

void Pila::imprimir()
{
    Nodo *reco = raiz;
    cout << "Listado de todos los elementos de la pila.\n";
    while (reco != NULL)
    {
        cout << reco->info << "\n\n";
        reco = reco->sig;
    }
    cout << "\n";
}

int Pila::extraer()
{
    if (raiz != NULL)
    {
        int informacion = raiz->info;
        Nodo *bor = raiz;
        raiz = raiz->sig;
        delete bor;
        return informacion;
    }
    else
    {
        return -1;
    }
}
bool Pila::consulta()
{
    if(raiz==NULL)
        return true;
    else
        return false;
}

Pila::~Pila()
{
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}
int main()
{
    for(;;)
    {
    int x,rpta;
    Pila *pila1;
    pila1= new Pila();
    cout<<"1)AGREGAR ELEMENTOS A LA PILA"<<endl;
    cout<<"2)CONSULTAR SI LA PILA ESTA VACIA"<<endl;
    cout<<"3)ELIMINAR EL ULTIMO ELEMENTO AGREGADO A LA PILA"<<endl;
    cout<<"4)RETORNAR REFERENCIA DEL ULTIMO ELEMENTO ADICIONADO A LA PILA"<<endl;
    cin>>rpta;
    if(rpta==1)
    {
        do
        {
        cout<<"Ingrese numero a apilar:";cin>>x;
        pila1->insertar(x);
        cout<<"¿DESEAS AGREGAR UN ELEMENTO NUEVO A PILA 1=SI/0=NO?"<<endl;
        cin>>rpta;
        }
        while(rpta!=0);
        pila1->imprimir();
    }
    else if(rpta==2)
    {
        if(pila1->consulta()!=true)
            pila1->imprimir();
        else
            cout<<"PILA VACIA..!"<<endl;
    }
    else if(rpta==3)
    {
        cout<<"Extraemos de la pila:" <<pila1->extraer()<<"\n";
    }
    else
    {
        cout<<"OPCION INVALIDA..!"<<endl;
    }
    }
}
