#include<iostream>
#include<vector>

using namespace std;

int fibnaci(int n ,vector<int>& q)  // int  q[] is same as int *q
{
    if(n == 1 || n == 0)
    {
        return n;
    }

    // if(q[n]!= 0)
    // {
    //     return q[n];
    // }

    int fn1  = fibnaci(n-1,q);
    int fn2 = fibnaci(n-2,q);

    int fn = fn1+ fn2;
   q[n] = fn;
    return fn;
}


int main(int argc, char** argv)
{
     int n;
    cout<<"enter a no."<<endl;
    cin>>n;
    vector<int> q(n+1);
    cout<<fibnaci(n,q);
}