#include<iostream>
#include<vector>

using namespace std;

vector<int> WiggleSort(vector<int>& arr){
/* 
LEETCODE 280 locked -- Given an unsorted arr , reorder it in place such that arr[0] <= arr[1] >= arr[1] <= arr[2] ...

just consider if(even index)  arr[i] <= arr[i+1];
              if(odd index)   arr[i] >= arr[i+1];
*/ 
    for(int i=0; i< arr.size()-1; i++){

        if(i%2 == 0){
            if(arr[i] > arr[i+1]){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
        else if(i % 2 == 1){
            if(arr[i] < arr[i+1]){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

int main(int argc,char** argv){

   vector<int> arr {3,4,6,3,67,2,6,7,8};
   vector<int> res =  WiggleSort(arr);

   for(int i=0; i< res.size() ;i++){
       cout<<res[i] <<" ";
   }
}