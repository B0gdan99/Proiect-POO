#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<vector>

using namespace std;
static int r;

class cont
{
protected:
    string detinator;
    double sold;
    int zi,luna,an;
public:
    cont(string,double,int,int,int);
    cont(cont&);
    virtual ~cont();
    void set_detintor(string);
    void set_sold(double);
    void set_zi(int);
    void set_luna(int);
    void set_an(int);
    int get_an(){return an;};
    int get_luna(){return luna;};
    int get_zi(){return zi;};
    double get_sold(){return sold;};
    string get_detinator(){return detinator;};
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    cont& operator=(cont &c);
    friend istream& operator>>(istream&, cont&);
    friend ostream& operator<<(ostream&, cont&);
};
istream& operator>>(istream& in,cont& c)
{
    c.citire(in);
    return in;
}

ostream& operator<<(ostream& out, cont& c)
{
    c.afisare(out);
    return out;
}

cont::cont(string num="",double s=1,int z=1,int l=1,int a=0)
{
    this->detinator=num;
    try
    {
        if (s<0)
            throw s;
    }
    catch (double x)
    {
        cout<<"Eroare in constructor, soldul nu poat fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    this->sold=s;
    try
    {
        if (z<1)
            throw z;
        if (z>31)
            throw z;
    }
    catch (int x)
    {
        cout<<"Eroare in constructor, ziua nu poat fi negativa sau mai mare de 31.\n";
        exit(EXIT_FAILURE);
    }
    this->zi=z;
     try
    {
        if (l<1)
            throw a;
        if (l>12)
            throw a;
    }
    catch (int x)
    {
        cout<<"Eroare in constructor, luna nu poat fi negativa sau mai mare de 12.\n";
        exit(EXIT_FAILURE);
    }
    this->luna=l;
     try
    {

        if (a>2020)
            throw a;
    }
    catch (int x)
    {
        cout<<"Eroare in constructor, anul nu poate sa fie mai mare decat anul curent.\n";
        exit(EXIT_FAILURE);
    }
    this->an=a;
}
cont::cont(cont &c)
{
    this->detinator=c.detinator;
    this->sold=c.sold;
    this->zi=c.zi;
    this->luna=c.luna;
    this->an=c.an;
}
cont::~cont()
{

}
cont& cont :: operator= (cont &c)
{
    if (this!=&c)
    {
        detinator=c.detinator;
        sold=c.sold;
        zi=c.zi;
        luna=c.luna;
        an=c.an;
    }
    return *this;
}

void cont::citire(istream &in)
{   double s;
    int x;
    cout<<"Detinator cont:";
    in>>detinator;
    cout<<"Are soldul egal cu ";
    in>>s;
    try
    {
        if (s<0)
            throw s;
    }
    catch (double y)
    {
        cout<<"Eroare in constructor, soldul nu poat fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    sold=s;
    cout<<"A fost deschis in ziua:";
    in>>x;
    try
    {
        if (x<1)
            throw x;
        if (x>31)
            throw x;
    }
    catch (int y)
    {
        cout<<"Eroare in constructor, ziua nu poat fi negativa sau mai mare de 31.\n";
        exit(EXIT_FAILURE);
    }
    zi=x;
    cout<<"Luna:";
    in>>x;
    try
    {
        if (x<1)
            throw x;
        if (x>12)
            throw x;
    }
    catch (int y)
    {
        cout<<"Eroare in constructor, luna nu poat fi negativa sau mai mare de 12.\n";
        exit(EXIT_FAILURE);
    }
    luna=x;
    cout<<"Anul:";
    in>>x;
    try
    {

        if (x>2020)
            throw x;
    }
    catch (int y)
    {
        cout<<"Eroare in constructor, anul nu poate sa fie mai mare decat anul curent.\n";
        exit(EXIT_FAILURE);
    }
    an=x;
}
void cont::afisare(ostream &out)
{
    out<<"Acest cont apartine "<<detinator<<"\n";
    out<<"Sold cont="<<sold<<"\n";
    out<<"A fost deschis in data "<<zi<<"."<<luna<<"."<<an<<"\n";

}


///========================================
class cont_economii: public cont
{
private:
    int rata_dobanda;
    int nr_actualizari;
    vector<double> actualizari;
public:

    cont_economii(string,double,int,int,int,int,int,vector<double>);
    cont_economii(cont_economii&);
    ~cont_economii();
    int get_rata(){return rata_dobanda;};
    void citire(istream &in);
    void afisare(ostream &out);
    cont_economii& operator=(cont_economii&);
    friend istream& operator>>(istream&, cont_economii&);
    friend ostream& operator<<(ostream&, cont_economii&);


};
cont_economii::~cont_economii()
{
    rata_dobanda=0;
    nr_actualizari=0;

}
cont_economii::cont_economii(string num="",double s=1,int z=1,int l=1,int a=0,int rata=3,int act=0,vector<double> v={}):cont(num,s,z,l,a)
{
    r=0;
    this->rata_dobanda=rata;
    try
    {
        if(rata_dobanda==3)
            r=1;
        if(rata_dobanda==12)
            r=1;
        if(rata_dobanda==6)
            r=1;
        if(r==0)
            throw(r);
}
    catch(int x)
    {
        cout<<"Eroare in constructor, rata poate sa fie doar pe 3, 6 sau 12 luni.\n";
        exit(EXIT_FAILURE);
    }
    this->nr_actualizari=act;
    this->actualizari=v;
}
cont_economii::cont_economii(cont_economii &c):cont(c)
{
    this->rata_dobanda=c.rata_dobanda;
    this->nr_actualizari=c.nr_actualizari;
    this->actualizari=c.actualizari;
}
void cont_economii::citire(istream &in)
{
    double x;
    cont::citire(in);
    cout<<"Contul are o rata de dobanda de 3, 6 sau 12 luni?\n";
    in>>rata_dobanda;
   /* try
    {   int a=0;
        if(a==3)
            a=1;
        if(a==6)
            a=1;
        if(a==12)
            a=1;
        if(a==0)
            throw a;
    }
    catch(int i)
    {
        cout<<"Eroare constructor, rata dobanzii poate sa fie doar de 3, 6 sau 12 luni.\n";
        exit(EXIT_FAILURE);
    }*/
    cout<<"Contul a actualizat soldul de cate ori?\n";
    in>>nr_actualizari;
    for(int i=0;i<nr_actualizari;i++)
        {
            cout<<"Actualizarea numarul "<<i+1<<":";
            in>>x;
            actualizari.push_back(x);
        }

}

void cont_economii::afisare(ostream &out)
{
    cont::afisare(out);
    out<<"Contul are rata pe durata de "<<rata_dobanda<<" luni.\n";
    out<<"Soldul contului a fost actualizat de "<<nr_actualizari<<" ori \n";
    for(int i=0;i<nr_actualizari;i++)
        out<<"Actualizarea nr "<<i+1<<": "<<actualizari[i]<<endl;

}

istream& operator>>(istream& in,cont_economii& c)
{
    c.citire(in);
    return in;
}

ostream& operator<<(ostream& out, cont_economii& c)
{
    c.afisare(out);
    return out;
}
cont_economii& cont_economii::operator=(cont_economii& x)
{
    if(this!=&x)
    {
        cont::operator=(x);
        nr_actualizari=x.nr_actualizari;
        actualizari=x.actualizari;


    }
    return *this;
}
///=====================================
class cont_curent:public cont
{
private:
    int tranzactii_gratuite;
    double cost_tranz;


public:
    cont_curent(string,double,int,int,int, int, double );
    cont_curent(cont_curent&);
    ~cont_curent();

    void citire(istream &in);
    void afisare(ostream &out);

    cont_curent& operator=(cont_curent&);
    friend istream& operator>>(istream&, cont_curent&);
    friend ostream& operator<<(ostream&, cont_curent&);

};
cont_curent::cont_curent(string num="",double s=0,int z=1,int l=1,int a=0, int trg=0,double ct=0 ):cont(num,s,z,l,a)
{
    this->tranzactii_gratuite=trg;
    this->cost_tranz=ct;

}
cont_curent::cont_curent(cont_curent& c):cont(c)
{
    this->tranzactii_gratuite=c.tranzactii_gratuite;
    this->cost_tranz=c.cost_tranz;

}
cont_curent::~cont_curent()
{

}
istream& operator>>(istream& in,cont_curent& c)
{
    c.citire(in);
    return in;
}

ostream& operator<<(ostream& out, cont_curent& c)
{
    c.afisare(out);
    return out;
}
void cont_curent::afisare(ostream &out)
{
    cont::afisare(out);
    out<<"Contul are "<<tranzactii_gratuite<<" tranzactii gratuite.\n";
    out<<"Orice tranzactie peste costa : "<<cost_tranz<<endl;

}
void cont_curent::citire(istream &in)
{
    cont::citire(in);
    cout<<"Cate tranzactii gratuite are contul:";
    in>>tranzactii_gratuite;
    cout<<"Orice tranzactie peste costa?";
    in>>cost_tranz;
}
cont_curent& cont_curent::operator=(cont_curent &x)
{
    if(this!=&x)
    {
        cont::operator=(x);
        tranzactii_gratuite=x.tranzactii_gratuite;
        cost_tranz=x.cost_tranz;


    }
    return *this;
}



template <class t> class GestionareConturi
{
    t *v;
    int nr;
public:
    GestionareConturi(t *p=NULL,int n=0)
    {
        nr=n;
        if (n!=0){
            v=new t[n];
            for(int i=0;i<n;i++)
            {
                v[i]=p[i];
            }
        }

    }
    GestionareConturi(GestionareConturi &a)
    {
         nr=a.nr;
        v=new t[nr];
        for(int i=0;i<nr;i++)
        {
            v[i]=a.v[i];
        }
    }
    ~GestionareConturi()
    {
        delete [] v;
    }
    int get_nr(){return nr;};
    t get_v(int i) {return v[i];}

    friend istream& operator >>(istream &in, GestionareConturi <t> &c)
    {
        cout<<"Introduceti numarul de conturi: ";
        in>>c.nr;
        c.v=new t[c.nr];
        cout<<"Introduceti conturile: \n";
        for(int i=0;i<c.nr;i++){
           in>>c.v[i];
           cout<<"\n";
        }
        return in;
    }
    friend ostream& operator <<(ostream &out, GestionareConturi<t> &c)
    {
        out<<"In gestionarea conutilor se gasesc urmatoarele "<<c.nr<<" conturi:"<<"\n";
        for(int i=0;i<c.nr;i++)
            out<<c.v[i]<<"\n";
        return out;
    }
};
 template <> class GestionareConturi <cont_economii>
 {
      cont_economii *v;
    int nr;
    int nr_cont_un_an;
public:
    GestionareConturi(cont_economii *p=NULL,int n=0)
    {
        nr_cont_un_an=0;
        nr=n;
        if (n!=0){
            v=new cont_economii[n];
            for(int i=0;i<n;i++)
            {
                v[i]=p[i];
                if(v[i].get_rata()==12)
                    nr_cont_un_an++;
            }
        }

    }
    GestionareConturi(GestionareConturi &a)
    {
        nr_cont_un_an=0;
         nr=a.nr;
        v=new cont_economii[nr];
        for(int i=0;i<nr;i++)
        {
            v[i]=a.v[i];
            if(v[i].get_rata()==12)
                nr_cont_un_an++;

        }
    }
    ~GestionareConturi()
    {
        delete [] v;
    }
    int get_nr(){return nr;};
    cont_economii get_v(int i) {return v[i];}

    friend istream& operator >>(istream &in, GestionareConturi <cont_economii> &c)
    {
        cout<<"Introduceti numarul de conturi: ";
        in>>c.nr;
        c.v=new cont_economii[c.nr];
        cout<<"Introduceti conturile: \n";
        for(int i=0;i<c.nr;i++){
           in>>c.v[i];
           if(c.v[i].get_rata()==12)
                c.nr_cont_un_an++;
           cout<<"\n";
        }
        return in;
    }
    friend ostream& operator <<(ostream &out, GestionareConturi<cont_economii> &c)
    {
        out<<"In gestionarea conutilor se gasesc urmatoarele "<<c.nr<<" conturi:"<<"\n";
        for(int i=0;i<c.nr;i++)
            out<<c.v[i]<<"\n";
             out<<"Dintre acestea, "<<c.nr_cont_un_an<<" au dobanda pe un an.\n";
        return out;
    }
 };


///=====================================

void tip(cont *&p, int &i) {
    string s;
    cout<<"\n";
    cout<<"Introduceti tipul contului "<<i+1<<": ";
    cin>>s;
    try
    {

            if(s=="cont_economii")
            {
                p=new cont_economii;
                cin>>*p;
                i++;
            }
            else
                if(s=="cont_curent")
                {
                    p=new cont_curent;
                    cin>>*p;
                    i++;
                }
                else
                    throw 10;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus un cont valid. Incercati cont_economii sau cont_curent.\n ";
    }
}
void menu_output()
{
    cout<<"\nPRODUCTIE CINEMATOGRAFICA\n";
    cout<<"\n\t\tMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste informatii despre conturile implicate. --- UPCAST & LATE-BINDING";
    cout<<"\n";
    cout<<"2. Gestionare cont --- TEMPLATE (cont_economii-SPECIALIZARE).";
    cout<<"\n";
    cout<<"3. Gestionare cont --- TEMPLATE (cont_curent).";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    int n=0;
    cont **v;
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {
            cout<<"Introduceti numarul de obiecte citite: ";
            cin>>n;
            v=new cont*[n];
            if (n>0)
            {
                for(int i=0;i<n;)
                   tip(v[i],i);
                cout<<"\nAfisam personalul citit anterior:\n";
                for(int i=0;i<n;i++)
                   {
                        cout<<"\n"<<*v[i];
                        cout<<"--------------------------\n";
                   }
            }
            else
                cout<<"Numarul introdus trebuie sa fie pozitiv.\n";
        }
        if (option==2)
        {
            GestionareConturi <cont_economii> x;
            cin>>x;
            cout<<x;

        }
        if (option==3)
        {
            GestionareConturi <cont_curent> x;
            cin>>x;
            cout<<x;
        }


        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
        if (option<0||option>3)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
int main()
{
    menu();
    return 0;

}
