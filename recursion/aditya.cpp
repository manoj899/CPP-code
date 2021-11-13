#include<bits/stdc++.h>

using namespace std;

//RECURSION is all about how to think , not what to think.
// first think ->(choice ,decision ) if not possible then other step
//  make input smaller 

//3 part : base condition, hypothesis, induction



//sort array using recursion
void insertIt(vector<int>& arr,int temp){

    if(arr.size() == 0 || arr[arr.size()-1] <= temp){
        arr.push_back(temp);
        return;
    }
    
    int val = arr[arr.size()-1];
    arr.pop_back();
    insertIt(arr,temp);
    arr.push_back(val);

    return;
}

void sortIt(vector<int>& arr){

    if(arr.size() == 1){
        return ;
    }
    
    int val = arr[arr.size()-1];
    arr.pop_back();
    sortIt(arr);

    insertIt(arr,val);

    // arr.push_back(val);
    return;
}

void insertST(stack<int>& st,int val){
    cout<<"Reached";
    //base condition
    if(st.size() == 0 || st.top() < val){
        st.push(val);
        return;
    }

    //hypothesis
    int temp = st.top(); st.pop();
    insertST(st,val);
    
    //induction
    st.push(temp);

    return; 
}

//sort a stack
void sortStack(stack<int>& st){
    cout<<"Reached---";

    //base condition
    if(st.size() == 1){
        return;
    }
    
    //hypothesis
    int val = st.top();
    st.pop();
    sortStack(st);

    //induction
    insertST(st,val);

    return;

}


void solve(stack<int>& st,int k){

    if(k == 1){
        st.pop();
        return;
    }

    //hypothesis
    int temp = st.top(); st.pop();
    solve(st,--k);
    
    //induction
    st.push(temp);

    return;
}

//delete middle element of stack
void deleteMiddle(stack<int>& st){

    int k = st.size();
    if(k%2 == 0) {
        k = (k/2)+1;
    }
    else{
        k = k/2;
    }


    solve(st,k);

    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

//tower of honoi
void TOH(int s,int h,int d,int n){
    if(n == 1){
        cout<<"moving plate "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }

    //hypothesis :for n-1
    TOH(s,d,h,n-1);
    cout<<"moving plate "<<n<<" from "<<s<<" to "<<d<<endl;
    TOH(h,s,d,n-1);
    return;


}

void Strings(string s){

    string st = s.substr(1,3);
    cout<<st<<" ";
}

int main(){

    vector<int> arr{4,6,25,7,8,2,5,1,3};

    // sortIt(arr);

    // for(auto i:arr){
    //     cout<<i<<" ";
    // }

    // stack<int> st;

    // for(auto i:arr){
    //     st.push(i);
    // }
    // sortStack(st);

    // while(st.size()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    // deleteMiddle(st);
    // int s=1;
    // int h=2;
    // int d=3;
    // TOH(s,h,d,3);

    Strings("hello");

    return 0;
}