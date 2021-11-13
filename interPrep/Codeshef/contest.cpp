#include <iostream>
using namespace std;

int fight(long int P,long int H){
    if(P >= H){
        return 1;
    }else
    if(P == 0 && H != 0){
        return 0;
    }
    else
    if(P == 1 && H >1 ){
        return 0;
    }
    
    
    H = H-P;
    P = P/2;
    
    int Z= fight(P,H);
   
   return Z;
}

int main() {
	long int T;
	// scanf("%s",T);
    cin>>T;
	
	while(T>0){
	    long int P,H;
	    // scanf("%s",H);
	    // scanf("%s",P);
        cin>>P>>H;
	    
	    cout<<fight(P,H)<<endl;
	    T--;
	}
	
	return 0;
}