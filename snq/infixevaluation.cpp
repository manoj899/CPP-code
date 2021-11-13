#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int getpriority(char op){
    int rv =-1;

    switch(op){
        case ^ : rv =3;
        break;
        case *:
        case / :
        rv=2;
        break;

        case +:
        case - : rv = 1;
        break;
        default: rv=0;
        break; 
    }
}
    

int eval(int v1,int v2,char op){

    int rv =-1;
    switch(op){
        case'^' :
        rv = pow(v1,v2);
        break;

        case'*' : rv= v1*v2;
        break;

        case'/' : rv = v1*v2;
        break;

        case'+' : rv = v1+v2;
        break;
        case'-' : rv = v1-v2;
        break;
        default :
         break;

    }
    return rv;
}


 int infixeval(string exp){

     stack<char> os;
     stack<int> vs;

     for(int i=0;i<exp.size();i++){
         {
             char ch= exp[i];

             if(ch=='(')
        {
         os.push(ch);
         }

         else if(ch==')'){
       
              while(os.top()!= '('){
                  char op = os.top();
                  postfix += op;
              }
              os.pop();
         }

         else if(ch >='0' & ch<='9')
         {   
               postfix +=ch;

         }

         else{
             //operator
             while(!(os.size()==0) || os.top() == '(' || getpriority(os.top())<getpriority(ch))){

                 char op = os.top(); os.pop();
                 int v2= vs.top(); vs.pop();
                 int v1= vs.top(); vs.pop();
                 vs.push(eval(v1,v2,op));
             } os.push();
         }
         while(!(os.size()==0)){
             char op=os.top(); os.pop();
              int v2= vs.top(); vs.pop();
                 int v1= vs.top(); vs.pop();

         }
     }
 }