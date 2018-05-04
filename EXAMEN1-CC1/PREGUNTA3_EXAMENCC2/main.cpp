#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Avion
{
    char *matricula,*tipo,*marca;
    public:
        Avion(char*,char*,char*);
        void setMatricula(char* matricula);
        void setTipo(char* tipo);
        void setMarca(char* marca);
        char *getMatricula();
        char *getTipo();
        char *getMarca();
        virtual void imprimir();
        virtual string toString();
        virtual void recibir_mensaje(string);
        friend ostream& operator << (ostream &o, Avion &p)
        {
            o << p.toString();
            return o;
        }
};
Avion::Avion(char*_matricula="VIY421",char*_tipo="Comercial",char*_marca="Airbus")
{
    matricula=_matricula;
    tipo=_tipo;
    marca=_marca;
}
void Avion::setMatricula(char*_matricula)
{
    matricula=_matricula;
}
void Avion::setTipo(char*_tipo)
{
    tipo=_tipo;
}
void Avion::setMarca(char*_marca)
{
    marca=_marca;
}
char*Avion::getMatricula()
{
    return matricula;
}
char*Avion::getTipo()
{
    return tipo;
}
char*Avion::getMarca()
{
    return marca;
}
void Avion::imprimir()
{
    cout<<"***DATOS DEL AVION***"<<endl;
    cout<<"1)MATRICULA:"<<matricula<<endl;
    cout<<"2)TIPO:"<<tipo<<endl;
    cout<<"3)MARCA:"<<marca<<endl;
}
string Avion::toString()
{
    string retorno ="\nMATRICULA:"+string(getMatricula())+"\nTIPO:"+string(getTipo())+"\nMARCA:"+string(getMarca());
    return retorno;
}
void Avion::recibir_mensaje(string mensaje)
{
    cout<<"AVION RECIBIO MENSAJE:   "<<mensaje<<endl;
}
class aeroplano:public Avion
{
    char*color;
    public:
        aeroplano(char*matricula,char*tipo,char*marca,char*Color);
        void setColor(char*color);
        char*getColor();
        virtual void imprimir();
        virtual void recibir_mensaje(string);
        string toString();
};
aeroplano::aeroplano(char *_matricula="ABC123",char *_tipo="Militar",char *_marca=" Gulfstream G650 ",char *_color="VERDE")
:Avion(_matricula,_tipo,_marca)
{
    setColor(_color);
}
void aeroplano::setColor(char*_color)
{
    color=_color;
}
char*aeroplano::getColor()
{
    return color;
}
void aeroplano::imprimir()
{
    Avion::imprimir();
    cout<<"COLOR:"<<color<<endl;
}
string aeroplano::toString()
{
    char newchar[10];
    string retorno =Avion::toString()+"\nCOLOR:"+string(getColor());
    return retorno;
}
void aeroplano::recibir_mensaje(string mensaje)
{
    cout<<"AEROPLANO RECIBIO MENSAJE:   "<<mensaje<<endl;
}
class Torre
{
    Avion* listaAviones[2];
    int actualAvion;
    public:
    Torre();
    void ingresar(Avion*);
    void envio_mensaje(string);
};
Torre::Torre()
{
    actualAvion=0;
}
void Torre::ingresar(Avion* MiAvion)
{
    listaAviones[actualAvion]=MiAvion;
    actualAvion++;
}
void Torre::envio_mensaje(string mensaje)
{
    for(int i=0;i<actualAvion;i++)
    {
        listaAviones[i]->recibir_mensaje(mensaje);
    }
}
int main()
{
    Torre T;
    T.ingresar(new Avion);
    T.ingresar(new aeroplano);
    T.envio_mensaje("FELIZ VIAJE :v!!");
    //Avion Avion1;
    //Avion1.imprimir();
    /*Avion *Estacion[5];
    Estacion[0]=new Avion;
    Estacion[1]=new aeroplano;
    Estacion[2]=new aeroplano;
    for(int i=0;i<2;i++)
        cout<<(*Estacion[i])<<endl;*/
}
