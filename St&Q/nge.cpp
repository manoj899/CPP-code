#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> NextSmallerElement1(vector<int> arr)
{     // left to right
    stack<int> st;
    vector<int> res(arr.size());

    for(int i=0; i<arr.size(); i++)
    {
        while(st.size()>0 && arr[st.top()] > arr[i]){

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
// the main diffrence btw method 1 & 2 are loop traversal 
// and insertion in res array..in forward loop l to r res
// updated in while while in method 2  reverse travesal res get
// updated outside of while loop

// index get stored in method 1 ,in 2 value of arr get stored
vector<int> nge2(vector<int> arr){

    stack<int> st;
    vector<int> res(arr.size());;
    res[arr.size() -1] = -1;    // last element always has -1
    st.push(arr[arr.size() -1]);

    for(int i= arr.size() -2 ; i >=0; i--){

        while(st.size() >0 && arr[i] > st.top()){
           st.pop();
            
        }

        res[i] = st.size()==0?-1: st.top();
        st.push(arr[i]);
    }

    return res;
}

vector<int> NextSmallerElement2(vector<int> arr){
  //smaller right side element
    stack<int> st;
    vector<int> res(arr.size());
    res[arr.size()-1] = -1;
    st.push(arr[arr.size() -1]);

    for(int i = arr.size()-2; i>= 0; i--)
    {
        while(st.size() >0 && arr[i] < st.top())
        {
            st.pop();
        }

        res[i] = st.size() ==0? -1:st.top();
        st.push(arr[i]);
    }

    return res;

}

vector<int> smallEleLeft(vector<int> bars)
{  //smaller left side element
    stack<int> st;
    vector<int> lb(bars.size());

    for(int i = bars.size() -1; i>= 0; i--)
    {  // smallest element on left
        while(st.size() > 0 && bars[st.top()] > bars[i])
        {
            lb[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(st.size() >0)
    {
        lb[st.top()] = -1;
        st.pop();
    }
    
    vector<int> res(lb.size());
    for(int i=0; i< lb.size(); i++){
        res[i] = bars[lb[i]];
    }

    return res;

}


vector<int> NGE(vector<int> arr){
    
    vector<int> res(arr.size());
    stack<int> st;
    
    for(int i = 0; i < arr.size() ; i++){
    
        while(arr[i] > arr[st.top()] && st.size() > 0){
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }


    while(st.size() > 0){
        res[st.top()] = -1;
        st.pop();
    }

    return res;

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



int main(int argv, char** argc)
{
   vector<int> arr {10,2,5,8,7,9,6};

//    nge1()
    vector<int> res = NGE(arr);
    for(int i=0; i< res.size(); i++)
    {
        cout<<res[i] <<" ";
    }
}