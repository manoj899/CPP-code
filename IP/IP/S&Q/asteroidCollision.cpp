#include<iostream>
#include<stack>
#include<vector>

using namespace std;


vector<int> asteroidCollision(vector<int>& arr) {
       
    vector<int> res;
    stack<int> st;
    // if(st.size() == 0){
    //     st.push(arr[0]);
    // }

    for(int i=0; i<arr.size(); i++){
       cout<<"@@@"<<endl;
        if(st.size() == 0){
            cout<<"###"<<endl;
            st.push(arr[i]);
        }
        
         else if(st.top() >0){
             cout<<st.top()<<"<--top"<<endl;
             if( arr[i]< 0 ){
                 
                 if(st.top() == (-arr[i])){
                     st.pop();
                     exit;
                 }
                 cout<<"$$$"<<endl;
                 while(st.top() < (-arr[i])){
                     
                     st.pop();
                     if(st.size() == 0){
                         break;
                     } 
                 }
             }
             else{
                 cout<<"%"<<endl;
                 st.push(arr[i]);
             }
         }
        else if(st.top() == arr[i]){
            st.pop();
        }
        else{cout<<st.top()<<"<--top"<<endl;
            cout<<"****"<<endl;
                st.push(arr[i]);
            }
           
    }
     cout<<"ooo"<<endl;
    int j=0;
    while(st.size() > 0){
        cout<<"KK"<<endl;
        
        // res[j] = arr[st.top()];
        //
        res.push_back(st.top());
        j++;
        // cout<<"["<<st.top()<<" ,"<<"]";
        st.pop();
    }
        
        return res;
}


int main(int argc,char** argv){

  vector<int> arr{10,5,-5,-10,2,-11};

  vector<int> res = asteroidCollision(arr);
  cout<<"reached"<<endl;
//   cout<<res.size()<<"GGGGGGGGG"<<endl;
  for(int i=res.size()-1 ;i >= 0; i--){
      cout<<"ffff"<<endl;
      cout<<res[i]<<" ,";
  }

}
