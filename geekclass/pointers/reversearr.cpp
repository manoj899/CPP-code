#include<iostream>
using namespace std;

 

int main(int argc,char** argv)
  {

      int a[]= {1,2,3,4,5};

      int b= sizeof(a)/sizeof(int);
     cout<<b;
      reverse(a,b);
  }

  void reverse(int *p[],int n)
  {   //int j;
      if(n<=0)
      {
          return;
      }
     cout<<"\n"<<p[n];
     
     void reverse(p,n-1);

  } 