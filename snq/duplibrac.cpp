#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool duplicate(string str){
    stack<char> st;

    for(int i=0;i<str.size();i++){
        char ch = str[i];

        if(ch== ')'){

            if(st.top()== '('){
             
                if (st.size()==0)
               { return true;
               }
                
            }
           /* else
             {    
                 while(st.top()!='('){
                     st.top();
                 }
                 st.pop();
            
            } */
        

        else{        // in all case ans is zero
            st.push(ch);
        }
       
    
     return false;}
}

int main(int argv,char** argc){
    
    string s ={"((a+b) +(c+d))"};

    cout<<duplicate(s);

}