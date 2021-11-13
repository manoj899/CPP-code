#include<iostream>


using namespace std;

class kstack
{
    private :
    int cap;   // capacity
    int *da;   // data arr
    int *pa;  // pointer array
    int *sha;    // stack head array
    int fh; //free head

    public:

    
    kstack(int cap,int k){
        this->da = new int[cap];
        this->pa = new int[cap];
        this->sha = new int [k];
        this->fh = 0;
this->cap=cap;
        for(int i=0;i<cap;i++){
            da[i];
            pa[i]= i+1;


        } 
        pa[cap-1]=-1;
    

    for(int i=0;i<k;i++){
        this->sha[i] = -1;

    }
    }
    bool isfull(){
        if(this->fh == -1){
            return this->fh == -1;
        }
    }

    bool isempty(int s){
        return sha[s] ==-1;
    }
    void push(int val,int s){
        if(isfull()){
            cout<<"stack overflow";
        }
        else{
             int temp = fh;
             fh = pa[fh]; // f is free
             pa[temp] = sha[s]; 
             sha[s] = temp;
             da[temp] = val;


        }
    }

    int top(int s){
        if(isempty(s)){

            cout<<"underflow"<<endl;
            return -1;
        }
        else{
            return da[sha[s]];
        }
    }

    int pop(int s){

         if(isempty(s)){

            cout<<"underflow"<<endl;
            return -1;
        }
        else{
           int temp = sha[s];
            sha[s]= pa[temp];
            pa[temp] =fh;
            fh = temp;
            da[temp] =0;
        }
    }
};


int main(int argv,char** argc){

    kstack ks(10,3);

    ks.push(10,0);
    ks.push(20,0);
    ks.push(30,1);
    ks.push(40,2);
    ks.push(50,2);
    ks.push(60,1);
    ks.push(70,1);
    ks.push(80,2);
    ks.push(90,0);
    ks.push(100,0);

    for(int i=0;i<=2;i++){

        cout<<i<<" :";
        while(ks.isempty(i) == false){
            int val = ks.top(i); ks.pop(i);
            cout<<val<<" ";

        }
        cout<<endl;
    }
}



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
