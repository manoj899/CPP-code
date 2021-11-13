#include<iostream>

using namespace std;


int swap(int *a,int *b){
    int t=*b;
    b*=a*;
    a*=t;

  return(a,b);
}


int partition(int low,int high)

int main(int argc,char** argv)
 {
   int arr[]={7,2,9,5,3,2};
   int n= sizeof(arr)/sizeof(int);

   cout<<partition(arr,0,n); 
 }