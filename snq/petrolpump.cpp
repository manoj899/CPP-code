#include<iostream>
#include<stack>


using namespace std;


petrolpump(vector<int>& oil,vector<int>& dist){

    int i=0; int j=0;
    int spare =0;
    while(true){
        
        
        if(spare +oil[j]>= dist[j]){
           spare =spare + oil[j] = dist[j];
           i=(j+1) %oil.size();
           if(j==i){
               cout<<i<<endl;
               break;
           }
           else{

               if(j<i){

                   cout<<"no solution";
                   break;
               }                             // refers to khudans algo

               spare =0;
               i= j+1;
               j=i;
           }
        }

    }
}


int main(int argv,char** argvc){

    stack<int> ps;

    ps.push
}