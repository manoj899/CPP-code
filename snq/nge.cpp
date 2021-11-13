#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void nge(vector<int> &v){
  //   vector<int> v {4,1,2,7,9,6,5,3,8};    // its output is not correct
    vector<int> res(v.size(),0);
    stack <int> st;

    res[v.size()-1]=-1;
    st.push(v[v.size()-1]);

    for(int i= v.size()-2; i>=0; i--){
        while(v[i]>st.top() && st.size()>0){
            st.pop();
            
        }
    //either stack is empty or the element at top is > v[i]
      
    res[i]=st.size()>0 ? st.top() : -3; //problem is here not working in -1 case
    st.push(v[i]);
  cout<<res[i]<<endl;
   // cout<<"**\n";
 }
   cout<<"&\n";

 /*   for(int p=0;i<res.size();i++){
        cout<<res[i]<<" ";
        cout<<"&\n";
    }
    cout<<endl;  */
}

int main(int argc,char** argv){

  vector<int> v {4,1,2,7,9,6,5,3,8};
   nge(v);
}

