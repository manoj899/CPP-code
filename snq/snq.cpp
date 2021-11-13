#include<iostream>
#include<stack>


using namespace std;

/*void stack_demo(){


   stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);

while(st.size()>0){
    cout<<st.top()<<endl;
    st.pop();
}
cout<< endl;
}

int main(int argc,char** argv){
    stack_demo();
}
*/

void ddi(string s){
  int val=1;
    stack<int> st;

    for(int i=0;i<s.size();i++){

        char ch= s[i];

        st.push(val++);

        if(ch=='i'){
            while(st.size()>0){

                cout<<st.top();
                st.pop();

            }
        }
    }
   
     st.push(val++);

    while(st.size()>0){
        cout<<st.top();
        st.pop();
    }
      cout<<endl;
}

int main(int argv,char** argc){

    //stack demo(;
    
    ddi("dddddddd");
    cout<<"\t -----------\t";
    ddi("iiiiiiii");
    cout<<"\t -----------\t";
    ddi("ddidddid");
    cout<<"\t -----------\t";
    ddi("idddiddd");
    cout<<"\t -----------\t";
    ddi("diddd");


}