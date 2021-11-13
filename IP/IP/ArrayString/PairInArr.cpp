#include<iostream>
#include<vector>
// #include<algorithm>
#include<bits/stdc++.h>

using namespace std;

/*  
This function internally uses IntroSort. In more details it is implemented using hybrid of QuickSort, 
HeapSort and InsertionSort.By default, it uses QuickSort but if QuickSort is doing unfair partitioning 
and taking more than N*logN time, it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort.
The prototype for sort is :

sort(startaddress, endaddress)

*/ 

int NoPairSum(int arr[],int size,int sum){
   
//  
   int count;
   sort(arr, arr+ size);

   int i=0, j = size-1;

   while(i < j){
  cout<<"*";
       if(arr[i] + arr[j] < sum){
           i++;
       }
       else if(arr[i] + arr[j] > sum) {
           j--;
       }
       else if(arr[i] + arr[j] == sum) {
         return  count++;
       }
   }
}

// Find a pair with the given difference

// #include <bits/stdc++.h> 
// using namespace std; 
  
// The function assumes that the array is sorted  
bool findPair(int arr[], int size, int n)  
{  
    // Initialize positions of two elements  
    int i = 0;  
    int j = 1;  
    sort(arr, arr+size);
  
    // Search for a pair  
    while (i < size && j < size)  
    {  
        if (i != j && arr[j] - arr[i] == n)  
        {  
            cout << "Pair Found: (" << arr[i] << 
                        ", " << arr[j] << ")";  
            return true;  
        }  
        else if (arr[j]-arr[i] < n)  
            j++;  
        else
            i++;  
    }  
  
    cout << "No such pair";  
    return false;  
}  
  
// Driver program to test above function  


int main(int argc,char **argv){

    // int A[] = { 1, 4, 45, 6, 10, -8 }; 
    // int s = 16; 
    //   int n = sizeof(A)/sizeof(int);
    // cout<<NoPairSum(A,n,s);


     int arr[] = {1, 8, 30, 40, 100};  
    int size = sizeof(arr)/sizeof(arr[0]);  
    int si = 60;  
    findPair(arr, size, si);  
    // return 0;  
}