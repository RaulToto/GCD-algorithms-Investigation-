#include <iostream>
#include <NTL/ZZ.h>
#include <ctime>
#include <fstream>
using namespace std;
using namespace NTL;
unsigned t0,t1;
void guardar(ZZ a,ZZ b,int times)
{
    ofstream archivo;
    //string line = "\\\\hline";
    archivo.open("euclidesExtendido.csv",ios::app);
    archivo << a <<"&"<< b<<"&"<<times  <<  "\\\\\\hline"<<endl;
    archivo.close();
}

ZZ binary_gcd( ZZ u,ZZ v)
{
  int i;
  if (u == 0) return v;
  if (v == 0) return u;
  //cout << "a" << '\t' << "b" <<'\t' << "i" <<  endl;
  for (i = 0; ((u | v) & 1) == 0; ++i) {
         u >>= 1;
         v >>= 1;
         cout << u << '\t' << v  << '\t' << i << endl;
         guardar(u,v,i);      
  }

  while ((u & 1) == 0)
    u >>= 1;
    
  do {
       guardar(u,v,i);
       cout << u << '\t' << v  << '\t' << i << endl;
       while ((v & 1) == 0)  
           v >>= 1;
       if (u > v) {
          ZZ t = v; v = u; u = t;}  
       v = v - u;                       
     } while (v != 0);
  cout << "i " << i << endl;
  return u << i;
}
//funcion para guardar los datos

int main()
{
    ZZ a,b,c;
    int cont=0;
    cout << "input a:" ; cin >> a; //imput the numbers 
    cout << "input b:" ; cin >> b;
    t0=clock();
    binary_gcd(a,b);
    t1=clock();
    double time=(double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution time:" << time << endl;
     /*
    //for save data;
    while(cont <5)
    {
      cout << "input a:" ; cin >> a; //imput the numbers 
      cout << "input b:" ; cin >> b;
      t0=clock();
      c=binary_gcd(a,b);
      t1=clock();
      double time=(double(t1-t0)/CLOCKS_PER_SEC);
      //cout << "Execution time:" << time << endl;
      guardar(a,b,time);
      cont++;
   }*/
}