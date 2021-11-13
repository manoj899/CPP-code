#include<bits/stdc++.h>
#include<stack>

using namespace std;

int celebrity(vector<vector<int>> arr){
    
    int n = arr.size();
    stack<int> st;

    for(int i=0; i<n;i++){
        st.push(i);
    }

    while(st.size()>1){

        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(arr[a][b] == 1){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int a = st.top();

    for(int i:)
}

int main(){
    return 0;
}