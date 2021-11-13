#include<iostream>
#include<vector>
#include<stack>


/* lowest memory consumption code among 100% and fastes 78% of 103184 submissions*/ 


using namespace std;
vector<int> asteroidCollision(vector<int>& arr) {
          
    stack<int> st;
    int k=0;
        cout<<arr.size()<<endl;
        for(int i=0; i<arr.size(); i++){
            cout<<"**->"<<arr[i]<<"<-**"<<endl;
            if(st.size() == 0 ){           // stack is 0
                cout<<"empty"<<endl;
                k++;
           
                st.push(arr[i]);
            }//{-2,-2,1,-2}
           else if(st.top() <0 && arr[i] <0 ){    // for both -ve
                st.push(arr[i]);
                  k++;
            
                  cout<<arr[i]<<"UUUU"<<endl;
                cout<<"consecutive -ve"<<endl;
            } //{10,5,-5,-10,2,-11,10,4,2,-3,-15}
            else{
            
            // oppositeGreatMagArr(int p){}

            while( st.size() != 0 && arr[i] <0 && st.top() >0 ){    //top +ve and arr is -ve
                cout<<"while"<<endl;
                if(st.top() < -arr[i]){
                    cout<<"Greater magnitute"<<endl;
                    st.pop();
                    if(st.size() == 0){
                        st.push(arr[i]);
                        break;
                    }
                      k++;
                if(st.top() == arr[i] || (st.top() < 0 && arr[i] <0)){
                     cout<<"pushed"<<endl;
                     st.push(arr[i]);
                       k++;
                       }
            
                }                                           
                else if( st.top() == -arr[i]){
                    cout<<"same value"<<endl;
                      k++;
                    st.pop();
                    break;
                }
                else{
                    break;
                }  
            }

            if(arr[i] >0 && st.size() != 0 )
            {
                cout<<"+ve "<<endl;
                st.push(arr[i]);
                  k++;
              
            }
            }
            
        }

      vector<int> res(st.size());

       cout<<"stack size ="<<st.size()<<endl;
               
        for(int i=st.size()-1; i >=0; i--){
             k++;
              
            cout<<"*"<<endl;
            res[i] = st.top();
            st.pop();
        }

cout<<"k->"<<k<<endl;
        return res;
}


int main(int argc,char** argv){

  vector<int> arr{1,-2,-2,-2};

  vector<int> res = asteroidCollision(arr);
  cout<<"reached and size="<<res.size()<<endl;

  for(int i=0; i< res.size(); i++){
    
      cout<<res[i]<<" ,";
  }

}