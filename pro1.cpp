#include<iostream>

using namespace std;
void pd(int n){

if(n==0){

return;

}
pd(n-1);
cout<<n<<" "<<endl;
}


void pi(int n){

if(n==0){

return;

}
cout<<n<<" ";
pi(n-1);
cout<<n<<" ";
}


void pzz(int n){
    if(n==0){
        return;
    }
    cout<<n<<"pre"<<endl;
    pzz(n-1);
    cout<<n<<"in"<<endl;
    pzz(n-1);
    cout<<n<<"post"<<endl;
}

int tot=1;
int factorial(int n){
  
  if(n==0){
      return tot;
  }
   tot=tot*n;
  factorial(n-1);

}
int pow=1;
int power(int x,int n){
   if(n==0){
       return pow;
   }
  pow*=x;
   power(x,n-1);
}

int poh(int s,int h,int d){
  
  poh()
}



int main(int argv,char** argc){

    pd(5);
    pi(5);
    pzz(3);
    int p=factorial(5);
    cout<<p<<endl;
    int res=power(2,0);
    cout<<res<<endl;
    //,everything working fine
}