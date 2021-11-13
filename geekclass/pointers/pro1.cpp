#include<iostream>
using namespace std;

int main(int argc,char** argv)
{
    int x[3]={10,20,30};

     int* a=x;

     cout<<"value="<<a;
     cout<<"\nvalue="<<a[0]<<" "<<a[1]<<" "<<a[2];
}
