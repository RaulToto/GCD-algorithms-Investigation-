#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
unsigned t0,t1;
void guardar(ZZ a,ZZ b,ZZ times,ZZ aux, ZZ s)
{
    ofstream archivo;
    archivo.open("lsbgcd.csv",ios::app);
    archivo << a <<"&"<< b<<"&"<<times<<"&"<< aux<<"&"<<s << "\\\\\\hline"<< endl;
    archivo.close();
}

ZZ menor(ZZ x,ZZ y)
{
    if(y<x)
        return y;
    else 
        return x;
}
ZZ potencia(ZZ a,ZZ b)
{
    ZZ result;
    result=1;
    for (int i = 0; i < b; i++)
    {
         result=a*result;
    }
    return result;
}
ZZ  lsbgcd(ZZ u, ZZ v)
{
    t0=clock();
    ZZ a,b,t,aux,s,two;
    two=2;
    a=abs(u);
    b=abs(v);
    cout << "a" << '\t'<< '\t' << "b" << '\t'<< '\t' << "t" << '\t'<< '\t' << "aux" << '\t'<< '\t' << "s" << endl;
    while(b!=0)
    {
        s=0;
        while(b*potencia(two,s)<=a)
        {
            s=s+1;
        }
        s=s-1;
        t=menor(a-b*potencia(two,s),b*potencia(two,s+1)-a);
        a=b;
        b=t;
        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        cout << a << '\t'<< '\t' << b << '\t'<< '\t' << t << '\t' << '\t'<< aux << '\t'<< '\t' << s <<endl; 
        
        guardar(a,b,t,aux,s);
    }   
    return a;
    t1=clock();
}
//save data 
int main()
{
    ZZ a,b;
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    lsbgcd(a,b);   
    //int cont=0;
    /*
    while(cont<5)
    {
        cout << "input a:" ; cin >> a; //imput the numbers 
        cout << "input b:" ; cin >> b;
        t0=clock();
        cout << "maximo comun divisor" << lsbgcd(a,b) << endl;
        t1=clock();
        double time=(double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution time:" << time << endl;
        guardar(a,b,time);
        cont++;
    }*/
}