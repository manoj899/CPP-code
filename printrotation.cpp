#include<iostream>
#include<vector>

using namespace std;

void printrotaion(vector<int>& arr,int k){

   for(int i=0;i<k;i++){
       int r=arr.end();
       arr.insert(arr.begin(),r);
   }

   for(int i=0;i<arr.size();i++){
       cout<<arr[i];
   }
}


int main(int argc,char** argv){
    vector<int> v{10,20,30,40,50,60,70,80};
    printrotaion(v,3);

}