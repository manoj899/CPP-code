#include<iostream>
using namespace std;

int main(int argc, char** argv){
    extern int i;
    cout<<i<<endl;
}
int i=20;