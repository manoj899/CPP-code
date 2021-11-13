#include<iostream>
#include<vector>
#include<stack>

using namespace std;


void  sliding_window(vector<int> &arr,int k){

    stack<int> st;
  vector<int> nge[arr.size()-1] = arr.size();
   st.push(arr.size() -1);

    for(int i = arr.size()-2; i>= 0; i--){
        while(st.size()>0 && arr[st.top()]<arr[i]){

            st.pop();
        }
        nge[i] = st.size()== 0 ? arr.size() : st.top();
        st.push[i];
  //cout<<nge[i]<<endl;
    }

    vector<int> res(arr.length -k +1);
    int j=0;

    for(int i=0;i<arr.length - k +1;i++){

        if(j<i){
            j=i;
        }
        while(nge[j]< i+k){

            j=nge[j];
        }
        res[i]= j;
        cout<<res[i];
    } 
   // return res;   
}


int main(int argv,char** argc){

    vector<int> v {4,1,2,7,9,6,5,3,8};
  //  nge(v);
     sliding_window( v,4);
}