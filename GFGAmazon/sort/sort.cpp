#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> arr){
// find smallest no from unsorted part and replace it with first element
//
    
    for(int i=1; i<arr.size();i++){
        int key = arr[i-1];
        int j = i-1;
        while(j >=0 && arr[i] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}


int main(){
    return 0;
}