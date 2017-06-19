//euclides with menor resto;
#include <iostream>
#include <NTL/ZZ.h>//includ  the lib ntl 
#include <ctime>
#include <fstream>
using namespace std;//using std namespace 
using namespace NTL;//using NTL namespaces
unsigned t0,t1;
/*
void guardar(ZZ a,ZZ b,ZZ times,ZZ resultado)
{
    ofstream archivo;
    //string line = "\\\\hline";
    archivo.open("euclidesMenor.csv",ios::app);
    archivo << a <<"&"<< b<<"&"<<times <<"&" << resultado <<  "\\\\\\hline"<<endl;
    archivo.close();
}*/
void guardar(ZZ a,ZZ b,double times)
{
    ofstream archivo;
    //string line = "\\\\hline";
    archivo.open("euclidesMenor.csv",ios::app);
    archivo << a <<"&"<< b<<"&"<<times  << "\\\\\\hline"<<endl;
    archivo.close();
}
ZZ module(ZZ &x,ZZ &y){
    ZZ q=x/y,r;
    if(q<0)
    {
        q=-1*q;
        q++;
        q=-1*q;
        r=x-(q*y);
    }
    else 
    {
        r=x-(q*y);
    }
    return r;
}
ZZ menor(ZZ x,ZZ y)
{
    if(y<x)
        return y;
    else 
        return x;
}
ZZ euclides(ZZ a, ZZ b)//
{
    //t0=clock();
    ZZ q,q1,r;
    q=a/b;
    q1=q;q1++;
    r=menor(a-(q*b),a-(q1*b));
    //r=a%b;
    while(r!=0)
    {
        q=a/b;
        q1=q;q++;
        r=menor(a-(q*b),a-(q1*b));
        cout << a  << '\t'<<  " = " << q << "(" << b << ")" << "+" << r << endl;//print the euclides algorithm
        //guardar(a,q,b,r);
        a=b;
        b=r;
    }
    return a ;
    //cout << "result is "<< a << endl;
    //t1=clock();
}
//funcion para guardar los datos 

int main()
{
    ZZ a,b,c;
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    t0=clock();
    c=euclides(a,b);
    t1=clock();
    double time=(double(t1-t0)/CLOCKS_PER_SEC);
    guardar(a,b,time);    

    //double time=(double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Execution time:" << time << endl;

}