/*//g++ hola.cpp -o m -lntl -lgmp -lm*/
        
#include <iostream>
#include <NTL/ZZ.h>//includ  the lib ntl 
#include <ctime>
#include <iomanip>
#include <string>
//#include <stdio.h>
#include <fstream>
using namespace std;//using std namespace 
using namespace NTL;//using NTL namespaces
unsigned t0,t1;
void guardar(ZZ a,ZZ b,ZZ times,ZZ resultado)
{
    ofstream archivo;
    //string line = "\\\\hline";
    archivo.open("euclidesClasico.csv",ios::app);
    archivo << a <<"&"<< b<<"&"<<times <<"&" << resultado <<  "\\\\\\hline"<<endl;
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
ZZ euclides(ZZ a, ZZ b)//
{
    ZZ q,r;
    q=a/b;
    r=module(a,b);
    //r=a%b;
    while(r!=0)
    {
        q=a/b;
        r=module(a,b);
        //r=a%b;
        cout << a  << '\t'<<'\t'<<'\t'<<'\t'<<  " = " << q << "(" << b << ")" << "+" << r << endl;//print the euclides algorithm
        guardar(a,b,q,r); 
        a=b;
        b=r;
               
    }

    return b;
}

int main()
{
    ZZ a,b,c;
    //b=5;
    int i=0;
    //cout << euclides(a,b) << endl;
    
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    
    euclides(a,b);  
    //ofstream archivo;
    //archivo.open("euclidesClasico.csv");
    /*
    while(i<5)
    {
        cout << "input a:" ; cin >> a; //imput the numbers 
        cout << "input b:" ; cin >> b;
        //b=i;
        t0=clock();    
        c=euclides(a,b);
        t1=clock();    
        double time=(double(t1-t0)/CLOCKS_PER_SEC);
        //cout << "Execution time:" << time << endl;
        //guardar(time,a,b);
       
        i++;
        //archivo << a <<";"<< b<<";"<<time << endl;
    }
    //archivo.close();
    */
}

 
