#include<iostream>

using namespace std;

class test
{
    int a;
    int b;
    public:

    test()  // default constructor
    {
        a =0;
        b=0;
    }

    test(int x,int y)  // parameterized const
    {
        this->a= x;
         this->b = y;
    }

    test operator + (test t);
    void disp();
};

test test:: operator +(test t)
{
    test temp;
    temp.a = a+t.a;
    temp.b = b + t.b;

    return temp;
}

void test:: disp()
{
    cout<<"\n value of A "<<a;
    cout<<" value of B "<<b;
}


int main(int argc,char** argv)
{
   test t1,t2,t3;
   t1 = test(10,20);
   t2 = test(30,40);
   t3 = t1 +t2;
   t1.disp();
   t2.disp();
   t3.disp();
}