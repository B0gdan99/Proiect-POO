/**Minu Bogdan-Adrian
    grupa 212
    Proiectul 10
*/
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 class complex {
private:
    float real;
    float imaginar;
public:
    complex (float, float);                     ///constructor initializare
    complex (complex&);                     ///constructor copiere
    ~complex ();                            ///destructor
    void set_real(float);                     ///set
    void set_imaginar(float);                 ///set
     float get_real(){return real;};           ///get
     float get_imag(){return imaginar;};       ///get
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, complex& z);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, complex& z); ///supraincarcare pe <<
    complex& operator=(complex &z); ///supraincarcarea operatorului de atribuire (doar ca metoda nu ca functie friend)

    friend complex& operator+(complex& z1, complex& z2); ///supraincarcare operator +
    friend complex& operator-(complex& z1, complex& z2); ///supraincarcare operator -
    friend complex& operator*(complex& z1, complex& z2); ///supraincarcare operator *
    friend complex& operator/(complex& z1, complex& z2); ///supraincarcare operator /
};
complex::complex(float real = 0, float imaginar = 0){
    this->real = real;
    this->imaginar = imaginar;
}
complex::complex(complex &z){
    this->real = z.real;
    this->imaginar = z.imaginar;
}
complex::~complex(){
    this->real=0;
    this->imaginar=0;
}
void complex::set_real(float x){
    real = x;
}
void complex::set_imaginar(float y){
    imaginar=y;
}
void complex::citire(istream &in){
    cout<<"Se citeste un numar complex de forma a+b*i \n";
    in>>real;

    in>>imaginar;
}
istream& operator>>(istream& in,complex& z){
    z.citire(in);
    return in;
}
void complex::afisare(ostream &out){
    if (imaginar==0) {
        out<<real;
    }
    else{
        if (imaginar < 0){
            out<<real<<imaginar<<"*i";
        }
        else{
            out<<real<<"+"<<imaginar<<"*i";
        }
    }
}
ostream& operator<<(ostream& out, complex& z){
    z.afisare(out);
    return out;
}

complex& complex::operator=(complex &z){
    real=z.real;
    imaginar=z.imaginar;
}

inline complex& operator+(complex &z1, complex& z2){
    complex *z = new complex;
    z->real = z1.real + z2.real;
    z->imaginar = z1.imaginar + z2.imaginar;
    return *z;
}
inline complex& operator-(complex &z1, complex& z2){
    complex *z = new complex;
    z->real = z1.real - z2.real;
    z->imaginar = z1.imaginar - z2.imaginar;
    return *z;
}
inline complex& operator*(complex &z1, complex& z2){
    complex *z=new complex;
    z->real = z1.real * z2.real - z1.imaginar * z2.imaginar;
    z->imaginar = z1.real * z2.imaginar + z2.real * z1.imaginar;
    return *z;
}
complex& operator/(complex &z1, complex &z2){
    complex *z=new complex;
    z->real = (z1.real*z2.real + z1.imaginar * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    z->imaginar = (z2.real * z1.imaginar - z1.real * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    return *z;
}

///==============================
class matrice
{
protected:
    complex **v;
    static int n,m;
public:
    matrice();
     matrice(complex**);
    matrice(matrice&);
    virtual ~matrice();
    void set_v(complex ** );
    complex get_v(){return **v;};
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    matrice& operator=(matrice &z);
    friend istream& operator>>(istream&, matrice&);
    friend ostream& operator<<(ostream&, matrice&);

};
int matrice::n;
int matrice::m;
matrice::matrice()
{

}
matrice::matrice(complex **v)
{

}
matrice::matrice(matrice& M)
{

}
matrice::~matrice()
{

}
void matrice::set_v(complex **mat)
{

}
void matrice::citire(istream &in)
{

}
void matrice::afisare(ostream &out)
{

}
istream& operator>>(istream& in,matrice& p){
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, matrice& p){
    p.afisare(out);
    return out;
}
///=================
class matrice_oarecare: public matrice
{
private:
    int lin,col;
public:
    matrice_oarecare(complex**,int,int);
    matrice_oarecare(matrice_oarecare&);
     ~matrice_oarecare();
    void set_v(complex ** );
    complex** get_v(){return v;};
    int get_lin(){return lin;};
    int get_col(){return col;};
    void set_lin(int );
    void set_col(int);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    matrice_oarecare& operator=(matrice_oarecare &z);
    friend istream& operator>>(istream&, matrice_oarecare&);
    friend ostream& operator<<(ostream&, matrice_oarecare&);


};
matrice_oarecare::matrice_oarecare(complex **v=NULL,int lin=0,int col=0):matrice(v)
{
    this->lin=lin;
    this->col=col;
    for(int i=0;i<lin;i++)
        for(int j=0;j<col;j++)
            this->v[i][j]=v[i][j];
}
matrice_oarecare::matrice_oarecare(matrice_oarecare& x):matrice(x)
{
    this->lin=x.lin;
    this->col=x.col;
    for(int i=0;i<lin;i++)
        for(int j=0;j<col;j++)
            this->v[i][j]=x.v[i][j];
}
matrice_oarecare::~matrice_oarecare()
{
    lin=0;
    col=0;
    v=NULL;
}
void matrice_oarecare::set_v(complex **x)
{
    v=x;
}
void matrice_oarecare::set_lin(int x)
{
    lin=x;
}
void matrice_oarecare::set_col(int x)
{
    col=x;
}
istream& operator>>(istream& in,matrice_oarecare& p){
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, matrice_oarecare& p){
    p.afisare(out);
    return out;
}
void matrice_oarecare::citire(istream &in)
{
    ///matrice::citire();
    cout<<"Vreti sa cititi o matrice de dimenisiune lin,col"<<endl;
    cout<<"lin=";
    in>>lin;
    cout<<"col=";
    in>>col;
    for(int i=0;i<lin;i++)
        for(int j=0;j<col;j++)
        {
            cout<<"v["<<i<<"]["<<j<<"]=";
            in>>v[i][j];
        }
}
void matrice_oarecare::afisare(ostream &out)
{
    ///matrice::afisare();
    cout<<"Se afiseaza matricea"<<endl;
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}

///===============
class matrice_patratica: public matrice
{
private:
    int dim;
public:
      matrice_patratica(complex**,int);
    matrice_patratica(matrice_patratica&);
    virtual ~matrice_patratica();
    void set_v(complex ** );
    complex** get_v(){return v;};
    void set_dim(int );
    int get_dim(){return dim;};
     void citire(istream &in);
    virtual void afisare(ostream &out);
    matrice_patratica& operator=(matrice_patratica &z);
    int matrice_triunghiulara(matrice_patratica&);
    friend istream& operator>>(istream&, matrice_patratica&);
    friend ostream& operator<<(ostream&, matrice_patratica&);

};
matrice_patratica::matrice_patratica(complex **v=NULL,int dim=0) :matrice(v)
{
    this->dim=dim;
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            this->v[i][j]=v[i][j];
}
matrice_patratica::matrice_patratica(matrice_patratica& x) :matrice(x)
{
    this->dim=x.dim;
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            this->v[i][j]=x.v[i][j];
}
matrice_patratica::~matrice_patratica()
{
    dim=0;
    v=NULL;
}
void matrice_patratica::set_dim(int x)
{
    dim=x;
}
void matrice_patratica::set_v(complex **x)
{
    v=x;
}

int matrice_patratica::matrice_triunghiulara(matrice_patratica& x)
{
    int ts=1,ti=1; ///ts=triunghiular superior, ti=triunghiular inferior
    for(int i=1;i<x.dim-1;i++)
        for(int j=0;j<i;j++)
            if(x.v[i][j].get_real()!=0 or x.v[i][j].get_imag()!=0 )
                ti=0;
    for(int i=0;i<x.dim-1;i++)
        for(int j=x.dim;j>i;j--)
            if(x.v[i][j].get_real()!=0 or x.v[i][j].get_imag()!=0 )
                ts=0;
    if(ts==1 and ti==1)
        return 1;
    else return 0;
}
istream& operator>>(istream& in,matrice_patratica& p){
    p.citire(in);
    return in;
}

ostream& operator<<(ostream& out, matrice_patratica& p){
    p.afisare(out);
    return out;
}
void matrice_patratica::citire(istream &in)
{
    cout<<"Vreti sa cititi o matrice de dimenisiune dim"<<endl;
    cout<<"dim=";
    in>>dim;
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
        {
            cout<<"v["<<i<<"]["<<j<<"]=";
            in>>v[i][j];
        }
}
void matrice_patratica::afisare(ostream &out)
{
    cout<<"Se afiseaza matricea"<<endl;
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    complex z;
    if(dim==2)
        {
         z=(v[0][0]*v[1][1]-v[0][1]*v[1][0]);

        }
    else
        if(dim==3)
    {

        z=v[0][0]*v[1][1]*v[2][2]+v[0][1]*v[1][2]*v[2][0]+v[0][2]*v[1][0]*v[2][1];
        z=z-v[0][2]*v[1][1]*v[2][0]-v[0][1]*v[1][0]*v[2][2]-v[0][0]*v[1][2]*v[2][1];

    }
    else
        cout<<"Matrice prea mare sa calculez determinant :)";
        double x;
        x=sqrt(z.get_real()*z.get_real()+z.get_imag()*z.get_imag());
    cout<<"Matricea are determinantul egal cu: "<<x;
}
void menu_output()
{
    printf("\n Minu Bogdan-Adrian 212 - 10 - Polinom: \n");
    printf("\n\t MENIU:");
    printf("\n===========================================\n");
    printf("\n");
    printf("1. Citire de n matrici "); printf("\n");
    printf("2. Afisare de matrici"); printf("\n");
    printf("3. Verifica daca o matrice triunghiulara este diagonala? "); printf("\n");

    printf("0. Iesire."); printf("\n");
}

void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    int nr=0;
    int tip;
    matrice **M;
    do
    {
        menu_output();

        printf("\nIntroduceti numarul actiunii: ");
        scanf("%d", &option);

        if (option==1)
        {
            ///citire de n obiecte
           while(nr<=0)
            {cout<<"Cate obiecte se citesc?\n";
            cin>>nr;
            if(nr<=0)
                cout<<"Trebuie introdus un numar natural >0"<<endl;
            }
            M=new matrice*[nr];
            for (int i=0;i<nr;i++)
            {
                cout<<"Ce tip de matrice doriti sa cititi? \n";
                cout<<"1- matrice oarecare \n 2-matrice patratica \n";
                cin>>tip;
                if(tip>2 or tip<1)
                    errno;
               if(tip==1)
               {
                    *M=new matrice_oarecare;
                    cin>>**M;
               }
                else
                  {*M=new matrice_patratica;
                  cin>>**M;
                  }
            }
        }
        if (option==2)
        {
            ///afisare de n obiecte
            if(nr)
            for(int i=0;i<nr;i++)
            {
                cout<<"Se afiseara matricea "<<i+1<<endl;
                cout<<M[i];
            }
            else
                cout<<"Nu s-au citit matrici";
        }

        if (option==3)
        {
            matrice_patratica m;
            cin>>m;
           /** if(m.matrice_triunghiulara()==1)
                cout<<"Matrice diagonala";      Nu mai am timp sa rezolv eroarea asta
            */
        }

        if (option==0)
        {
            printf("\nEXIT!\n");
        }
        if (option<0||option>3)
        {
            printf("\nSelectie invalida\n");
        }
        printf("\n");

    }
    while(option!=0);
}

int main()
{
    menu();
    return 0;
}

