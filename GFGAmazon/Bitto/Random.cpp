#include<bits/stdc++.h>
#include<stack>

using namespace std;


//largest sum subarray

//brute force
//-2,-3,4,-1,-2,1,5,-3 .. I(n^2)

void findSum(vector<int> arr){

    if(arr.size() == 0) cout<<"Size is Zero";
    int gsum =0;
    int count =0;
    for(int i=0; i < arr.size(); i++){
        int lsum = 0;
        for(int j = i; j < arr.size(); j++){
            lsum += arr[j];
            gsum = max(lsum,gsum);
        } 
    }
    cout<<"Largest subarray ->"<<gsum;
}

//O(n);

void LargestSumSubArray(vector<int> arr){

    int lmax = 0, gmax = INT_MIN ;
    int pmax = arr[0];

    for(int i=1; i < arr.size(); i++){

        lmax = max(arr[i] , pmax + arr[i]);
        gmax = max(gmax,lmax);
        cout<<gmax<<" ";
        pmax = lmax;

    }
    cout<<"Maximum sum is "<<gmax;
}


//nge

void NGE(vector<int> arr){
    cout<<"*";
    int n = arr.size();
    vector<int> res(arr.size(),n);
    res[n-1] = n;

    stack<int> st;

    for(int i = 0; i < n-2 ; i++){
    
            while(arr[i] > arr[st.top()] && st.size() != 0){
                
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        
    }

    while(st.size() > 0){
        res[st.top()] = n;
        st.pop();
    }

    for(auto i:res){
        cout<<i<<" ,";
    }

}

vector<int> nge1(vector<int> arr)
{   // left to right
    stack<int> st;
    vector<int> res(arr.size());

    for(int i=0; i<arr.size(); i++)
    {
        while(st.size() >0 && arr[st.top()] < arr[i])
        {
           res[st.top()] = arr[i];
           st.pop();
        }

        st.push(i);
    }

    while(st.size() >0)
    {
        res[st.top()] = -1;
        st.pop();
    }

    return res;

}

vector<int> nge(vector<int> arr){
    stack<int> st;
    vector<int> res(arr.size());
    
    for(int i = 0; i < arr.size() ; i++){
        
        if(st.size() > 0 && arr[st.top()] < arr[i]){
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    
    while(st.size() > 0){
        res[st.top()] = arr.size()-1;
        st.pop();
    }
    return res;
}
    
vector<int> maxSlidingWindow(vector<int>& a, int k) {

    vector<int> res = nge(a); // index of nge
    vector<int> result;
    
    int j =0;
    for(int i = 0; i <= a.size()-k ; i++){
        j = i;
        while( res[j] < i+k){//as one loop completed we get max of
            j = res[j];
        }
        result.push_back(a[j]); 
    }
    
    return result;
}
    
//reverse LL
//1->2->3->4->5->6
Node* ReverseLL(Node* head,int k){

    Node* temp = NULL, Next = NULL, Prev = NULL;
    Node* curr = head;
    int count = 0;
    while(curr != NULL && count < K){
        count++;
        prev = curr;
        next = curr->next;
        curr->next = prev;
        curr = next;
    }

    if(next != NULL){
       head->next = ReverseLL(next,k);
    }
     
    return prev;
}

int main(){
    // vector<int> arr{-2,-3,4,-1,-2,1,5,-3};
    // LargestSumSubArray(arr);
    vector<int> aar{1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(aar,3);
    for(auto i:res){
        cout<<i<<" ,";
    }
    return 0;
}