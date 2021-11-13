#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool hasDuplicate(string& str){

    stack<char> st;

    for(int i=0;i< str.size(); i++){

      char ch = str[i];
      
     if(ch == ')'){

          if(st.top() == '('){

              return true;
          }
          else{
              while(st.top() != '('){
                  st.pop();
              }

              st.pop();
              }
          }
     else {
         st.push(ch);
        }
      

    }

    return false;

}

vector<int> NGE1(vector<int> arr){

    vector<int> res(arr.size()-1);
    stack<int> st;

    for(int i=0; i< arr.size(); i++){

        while(st.size() >0 && arr[st.top()] < arr[i]){
            
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

vector<int> NGE2(vector<int> arr){

    stack<int> st;
    vector<int> res(arr.size()-1);

    res[arr.size()-1]  =-1;
    st.push(arr[arr.size()-1]);
   cout<<arr.size()-2<<endl;
    for(int i=arr.size()-2; i>=0; i-- ){

        if(st.size() >0 && st.top() > arr[i]){

            res[i] = st.top();
            st.push(arr[i]);
        }
        else{
          while(st.top() < arr[i]){
        st.pop();
            }
            res[i] = st.top();
            st.push(arr[i]);
    }

    
    }
    return res;
}

// vector<int> nser(vector<int> arr){


//     stack<int> st;
//     vector<int> res;

//     res[arr.size()-1] = -1;

//     for(int i = 0; i< arr.size()-1; i++){

//         if( st.top() < arr[i]){

//             st.push();
//         }
//         else{
//                     int c =i;
//             while(st.top() > arr[i] && st.size() >0){
                
//                 res[c] = arr[i];
//                 c--; // here problem occue that how to access pre index of result
//                 // thats why we have to do it by putting index in stack
//                 st.pop();
//             }
//         }
//     }
// }

vector<int> nser(vector<int> arr){

    vector<int> res(arr.size()-1);
    stack<int> st;

    res[arr.size()-1] = -1;


    for(int i=0; i< arr.size(); i++){

        while(st.size() >0 && arr[st.top()] > arr[i]){
            
            res[st.top()] = arr[i];
            st.pop();
            
        }

        st.push(i);
        

    }

    while(st.size() >0){

        res[st.top()] = -1;
        st.pop();
    }

    return res;
}

vector<int> nsel(vector<int> arr){

    vector<int> res(arr.size()-1);
    stack<int> st;

   

    for(int i= arr.size()-1; i>=0; i--){

        while(st.size() >0 && arr[st.top()] > arr[i]){

            res[st.top()] = arr[i];
            st.pop();
           
        }
         st.push(i);
    }

    while(st.size( ) !=0){
        res[st.top()] = -1;
        st.pop();
    }

    return res;

}

void LargestArHistogram(vector<int>& arr){

    stack<int> st;
    vector<int> rb(arr.size()-1);    // right
     vector<int> lb(arr.size()-1);  //left

    // rb[arr.size()-1] = -1;
// nser
    for(int i=0; i<arr.size() ; i++){

        while(st.size() >0 && arr[st.top()] > arr[i]){
               
                rb[st.top()] = i;
                st.pop();
            
        }
         st.push(i);
    
    }

     while(st.size() > 0){
            
            rb[st.top()] = arr.size();
            st.pop();
        }


        for(int i= arr.size() -1; i >=0 ; i--){

            while(st.size() >0 && arr[st.top()] > arr[i]){

                lb[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(st.size() >0){
            lb[st.top()] = -1;
            st.pop();
        }
cout<<"*****"<<endl;
    int max=0;
    for(int i=0 ;i< arr.size() ; i++){

        int width = rb[i] - lb[i] -1;
        int area = width * arr[i];

        if(max < area){
            max = area;
        }
    }

   cout<< max;
    
}

vector<int> maxInSlidingWindow(vector<int> arr,int k){

    vector<int> nge(arr.size());
    stack<int> st;

    for(int i=0; i< arr.size(); i++){

        while(st.size() >0 && arr[st.top()] < arr[i])
        {
            nge[st.top()] = i;
             st.pop();
        }

         st.push(i);                 
    }

    while(st.size()>0){
            nge[st.top()] = arr.size();
            st.pop();
        }

        int i=0; 
       int j =0;
       vector<int> res(arr.size() - k +1);
        while(i <res.size())
        {       
            if(i > j){
                 j =i;
            }
            
               // j shouldnt exceed window size 
                while(nge[j] < i+k){
            // if nge lies inside window then jump j to that pt.    
                j =nge[i];
                }
        // nge lies outside window then tum hi to answer ho hmare(that current index)     
                res[i] = arr[j];
                i++;
        }
   return res;
}


string ddid(string &s){

    int val =0;
    stack<int> st;

    for(int i=0; i<= s.size(); i++){
           st.push(val++);
         if(i == s.size() || s[i] == 'i'){
             while(st.size() >0){
             cout<<st.top();
             st.pop();
         }

         } 
    }
    
}
int main(int argc,char** argv){

//   string s = "(a + (b+c))";
//     cout<<hasDuplicate(s)<<endl ;

//   vector<int> arr {9,8,7,10,6,5,11};
//   vector<int> arr1{8,9,10,6,7,12,1};
//   vector<int> res = 
// LargestArHistogram(arr);

// vector<int> arr{5,9,3,1,8,2,11,4,17,9};
//     vector<int> res = maxInSlidingWindow(arr,5);
//     for(int i=0; i<res.size(); i++)
//     {
//         cout<<res[i]<<" ";
//     }
//     cout<<endl;

string s = "dddd";
cout<<ddid(s);
//   for(int i=0; i<arr.size(); i++){
//       cout<<res[i]<<" ";
//   }
  cout<<endl;

}