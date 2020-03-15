///Proiectul 10
///Minu Bogdan-Adrian
///Grupa 212

#include <iostream>
#include <math.h>
#include<stdio.h>
using namespace std;

class polinom
{
private:
    int n;
    double v[100];
public:
    polinom (int );      ///constructor initializare
    polinom (polinom&);               ///constructor copiere
    ~polinom ();                      ///destructor
    void set_n(int);                  ///set
    int get_n(){return n;};          ///get
    void set_v(double v[100]);          ///set
    double get_v();
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, polinom& z);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, polinom& z); ///supraincarcare pe <<
    double valoare_in_punctul(double,polinom& p);
    friend polinom& operator+(polinom& v1, polinom& v2); ///supraincarcare operator +
    friend polinom& operator-(polinom& v1, polinom& v2); ///supraincarcare operator -
    friend polinom& operator*(polinom& v1, polinom& v2); ///supraincarcare operator *
};


polinom::polinom(polinom& p)
{
    this->n=p.n;
    for(int i=0;i<n+2;i++)
        this->v[i]=p.v[i];
}



polinom::polinom(int n=0)
{
    this->n=n;
    for(int i=0;i<n+2;i++)
        this->v[i]=0;
}



polinom::~polinom()
{
    n=0;
}


void polinom::set_n(int x){
    n = x;
}



double polinom::get_v()
{
    return *v;
}


istream& operator>>(istream& in,polinom& z){
    z.citire(in);
    return in;
}


ostream& operator<<(ostream& out, polinom& z){
    z.afisare(out);
    return out;
}


void polinom::afisare(ostream &out)
{
    /// grad maxim
    cout<<v[n]<<"*X^"<<n;
   /// gradele de la n-1 la 2

   for(int i=n-1;i>=2;i--)
   {
     if(v[i]>0)
        cout<<"+"<<v[i]<<"*X^"<<i;
    else
        cout<<v[i]<<"*X^"<<i;

   }
   /// grad=1
   if(v[1]>0)
        cout<<"+"<<v[1]<<"*X";
    else
        cout<<v[1]<<"*X";

   ///grad=0
   if(v[0]>0)
        cout<<"+"<<v[0]<<"\n";
    else
        cout<<v[0]<<"\n";
}


void polinom::citire(istream &in)
{
    cout<<"Cititi un polinom de grad n!!\n n= ";
    in>>n;
    cout<<"Cititi coeficientii polinomului\n";
    for(int i=0;i<n+1;i++){
        cout<<"v["<<i<<"]=";
        in>>v[i];
    }

}

void polinom::set_v(double v[100])
{
    for (int i=0;i<=n+2;i++)
        v[i]=0;
}

double polinom::valoare_in_punctul(double x,polinom& p)
{double valoare=0;
    for(int i=0;i<p.n+1;i++)
    {
        valoare=valoare+p.v[i]*(x*(i-1));
    }
    return valoare;
}

inline polinom& operator+(polinom &v1,polinom& v2)
{
   polinom* z= new polinom;
   z->n=max(v1.n,v2.n);

   for(int i=0;i<z->n+1;i++)
    if(v1.v[i] && v2.v[i])
        z->v[i]=v1.v[i]+v2.v[i];
    else
        if(v1.v[i])
            z->v[i]=v1.v[i];
        else
            z->v[i]=v2.v[i];
    return *z;
}
inline polinom& operator*(polinom &v1,polinom& v2)
{
   polinom* z= new polinom;
   z->n=v1.n*v2.n;
   for(int i=0;i<z->n+1;i++)
        z->v[i]=0;

   for(int i=0;i<v1.n+1;i++)
        for(int j=0;j<v2.n+1;j++)
            z->v[i+j]=z->v[i+j]+v1.v[i]*v2.v[j];


    return *z;
}
inline polinom& operator-(polinom &v1,polinom& v2)
{
   polinom* z= new polinom;
   z->n=max(v1.n,v2.n);
   for(int i=0;i<z->n+1;i++)
    if(v1.v[i] && v2.v[i])
        z->v[i]=v1.v[i]-v2.v[i];
    else
        if(v1.v[i])
            z->v[i]=v1.v[i];
        else
            z->v[i]=-v2.v[i];
    return *z;
}
void menu_output()
{
    printf("\n Minu Bogdan-Adrian 212 - 10 - Polinom: \n");
    printf("\n\t MENIU:");
    printf("\n===========================================\n");
    printf("\n");
    printf("1. Citire de n polinoame "); printf("\n");
    printf("2. Afisare de polinoame"); printf("\n");
    printf("3. Calculeaza valoarea unui polinom intr-un punct"); printf("\n");
    printf("4. Adunarea a doua polinoame"); printf("\n");
    printf("5. Scaderea a doua polinoame"); printf("\n");
    printf("6. Inmultirea a doua polinoame"); printf("\n");
    printf("0. Iesire."); printf("\n");
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    int nr=0;
    polinom *p;
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
            p= new polinom[nr];
            for (int i=0;i<nr;i++)
            {
                cout<<"Se citeste polinomul"<<i;
                cin>>p[i];
        }
        }
        if (option==2)
        {
            ///afisare de n obiecte
            if(nr)
            for(int i=0;i<nr;i++)
            {
                cout<<"Se afiseara polinomul "<<i+1<<endl;
                cout<<p[i];
            }
            else
                cout<<"Nu s-au citit polinoame";
        }

        if (option==3)
        {
            ///Calculeaza valoarea unui polinom intr-un punct
            cout<<"Se citeste polinomul";
            polinom p;
            cin>>p;
            cout<<"In ce punct se calculeaza valoarea?"<<endl;
            int x;
            cin>>x;
            ///valoare_in_punctul(x,p);
            cout<<"Rez:"<<p.valoare_in_punctul(x,p);

        }

        if (option==4)
        {
           ///Adunarea a doua polinoame
           cout<<"Se citeste primul polinomul";
            polinom p1;
            cin>>p1;
            cout<<"Se citeste al doilea polinomul";
            polinom p2;
            cin>>p2;
            polinom z;
            z=p1+p2;
            cout<<"Polinomul rezultat este:";
            cout<<z;
        }
        if (option==5)
        {
            ///Scadere a doua polinoame
            cout<<"Se citeste primul polinomul";
            polinom p1;
            cin>>p1;
            cout<<"Se citeste al doilea polinomul";
            polinom p2;
            cin>>p2;
            polinom z;
            z=p1-p2;
            cout<<"Polinomul rezultat este:";
            cout<<z;
        }
        if (option==6)
        {
            ///Inmultire a doua polinoame
            cout<<"Se citeste primul polinomul";
            polinom p1;
            cin>>p1;
            cout<<"Se citeste al doilea polinomul";
            polinom p2;
            cin>>p2;
            polinom z;
            z=p1 * p2;
            cout<<"Polinomul rezultat este:";
            cout<<z;
        }
        if (option==0)
        {
            printf("\nEXIT!\n");
        }
        if (option<0||option>6)
        {
            printf("\nSelectie invalida\n");
        }
        printf("\n");
       // system("pause"); ///Pauza - Press any key to continue...
        //system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

int main()
{

    menu();
    return 0;
}
