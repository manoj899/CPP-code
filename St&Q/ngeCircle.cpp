#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> NGE2(vector<int>& arr){ //straight nge

    vector<int> res(arr.size());
    // res[arr.size() -1] = -1;
    stack<int> st;
     int flag = 0;
    
    for(int i=0; i< arr.size(); i++){
        

        // while(st.size() !=0 && st.top() < arr[i]){
        //     // res[i] = arr[i]; --> the reason why we should enter index in stack as index will not change in 
        //     //loop and result arr wont get update at all place
        //     st.pop();
        // }
       

        while(st.size() != 0 && arr[st.top()] < arr[i]){

            res[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
       

     if(flag == 0){
        if(i == arr.size()-1){
            
            flag = 1;
            i =0;

        }
     }
      
    }

    
    //    while(st.size() !=0){
    //        res[st.top()] = -1;
    //        st.pop();
    //    }

     
       while(st.size() != 1){
        st.pop();   
       }
       res[st.top()] = -1;
    
       return res;
}

// circular nge





int main(int argc,char** argv){

   vector<int> arr{5,3,11,10,11,4,9}; // output  {7,7,9,9,-1}

   vector<int> res = NGE2(arr);
   for(int i=0; i< res.size(); i++){
       cout<<res[i]<<" ";
   }   
}