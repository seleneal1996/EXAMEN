#include <iostream>
#include <stdlib.h>

using namespace std;
class Moneda
{
    int monto_nuevoSol;
    public:
    //CONSTRUCTOR
    Moneda(int);
    int sumaNS(Moneda moneda1,Moneda moneda2);
    int restaNS(Moneda moneda1,Moneda moneda2);
    //SOBRECARGA DE OPERADORES
    Moneda& operator+(Moneda &moneda2)
    {
    return *(new Moneda( monto_nuevoSol+moneda2.monto_nuevoSol));
    }
    Moneda& operator-(Moneda &moneda2)
    {
    return *(new Moneda( monto_nuevoSol-moneda2.monto_nuevoSol));
    }
    void imprimir()
    {
        cout<<" "<<monto_nuevoSol<<"SOLES."<<endl;
    }
};
Moneda::Moneda(int _MontonuevoSol)
{
    monto_nuevoSol=_MontonuevoSol;
}
int Moneda::sumaNS(Moneda a, Moneda b)
{
    int suma=a.monto_nuevoSol+b.monto_nuevoSol;
}
int Moneda::restaNS(Moneda a, Moneda b)
{
    int resta=a.monto_nuevoSol-b.monto_nuevoSol;
}
class Billetera
{
    Moneda *a;
    int n=0;
    public:
        Billetera(Moneda&);
        void addM(Moneda&);
        void quitM();
        void consulta();
};
Billetera::Billetera(Moneda&  m)
 {
    a = (Moneda *) malloc (10*sizeof(Moneda));
    a=&m;
    n++;
 }
void Billetera :: addM(Moneda& m)
 {
    Moneda* c=a+n;
    c=&m;
    n++;
 }
void Billetera::quitM()
 {
    n--;
 }

 void Billetera::consulta()
 {
    cout<<n<<"MONEDAS"<<endl;
 }
int main()
{
    Moneda a (7);
    Moneda b (5);
    Moneda &c = a+b;
    Moneda &d = a-b;
    cout<<"SUMA:";
    c.imprimir();
    cout<<"RESTA:";
    d.imprimir();


    Billetera Mi_billetera(a);
    Mi_billetera.addM(a);
    Mi_billetera.addM(b);
    cout<<"\nACTUALMENTE TIENES:";
    Mi_billetera.consulta();
    Mi_billetera.quitM();
    cout<<"\nRESTIRASTE UNA MONEDA:";
    Mi_billetera.consulta();
}

