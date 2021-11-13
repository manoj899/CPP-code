#include<iostream>
using namespace std;

class test
{
    int a,b,c;

    public:
    void getdata(int x,int y,int z);
    void operator -();
    void disp();
};

void test:: getdata(int x,int y,int z){
    a =x;
    b = y;
    c = z;
}

void test :: operator - ()
{
    a = -a;
    b= -b;
    c = -c;
}

void test::disp()
{
    cout<<"\n value of A "<<a;
    cout<<"\n value of B "<<b;
    cout<<"\n value of C "<<c;
}

int main(int argv,char** argc)
{
    test obj;
    obj.getdata(-10,20,30);
    obj.disp();
// uniary op doesnt take any argument
    - obj;  // syntax (op x or x op)
    obj.disp();
}