#include<iostream>
#include<vector>
#include<math>
#include<algorithm>

using namespace std;

string infixtipostfix(string exp){

    string postfix;
    stack<char> os;

    for(int i=0;i<exp.size();i++){
        char ch=exp[i];
        
        if(ch =='('){
            os.push(ch);
        }
        else if(ch ==')')
        {
            while(os.top!='('){

                char op= os.top();
                os.top();
                postfix + = op;

            }
            os.pop();

        }
    }
    else if(ch>= '0' && ch<= '9'){
        postfix += ch;

    } else{
        while(os.size()>0 && os.top()! = '(' && getpriority(os.top)) >getpriority(ch){

            char op = os.top();
            postfix += op;
        }
        op.push(ch);
    }
}
return  postfix;
}


int main(int argc,cahr** argv){
    
}