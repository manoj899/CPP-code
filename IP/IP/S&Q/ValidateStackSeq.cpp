#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool validStackSequence(vector<int> pushed, vector<int> poped){

    stack<int> st;
    int j=0;
    int i=0;
    for(; i<pushed.size(); i++){
    //   cout<<"*"<<endl;
      st.push(pushed[i]);
      
      while(poped[j] == st.top() && st.size() != 0){
        //   cout<<"pop"<<endl;
          j++;
          st.pop();
          
      }
     
    }

    if(i == j)
    {
        return true;
    }
    else{
        return false;
    }
}


int main(int argc,char** argv){

  vector<int> pushed = {1,2,3,4,5};
  vector<int> popped = {4,5,3,2,1};

  cout<<validStackSequence(pushed,popped);


}