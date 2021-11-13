#include<bits/stdtr1c++.h>

using namespace std;

int Merge(vector<int>& arr, vector<int> temp, int left, int mid, int right){

    int i = left;
    int inv_count = 0;
    int j = mid;
    int k = left;

    while((i <= mid-1) && j <= right){
        if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
        }
        else{
            inv_count += mid-i;
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid-1){
        temp[k++] = arr[i++];
    }

    while(j <= right){
        temp[k++] = arr[j++];
    }

    for(int i = left ; i <= right; i++){
        arr[i] = temp[i];
    }
    return inv_count;
}

int MergeSort(vector<int>& arr,vector<int> temp, int left, int right){

    int inv_count = 0;
    int mid;

    if(left < right){
         mid = (left+right)/2;
        inv_count += MergeSort(arr, temp, left, mid);
        inv_count += MergeSort(arr, temp, mid+1, right);

        inv_count += Merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}


int merge(int arr[], int temp[], int left, int mid, int right){
    int i , j ,k;
    int inv_count = 0;

    i = left;// i is index of left subarray
    j = mid; // j is index of right subarray;
    k =  left; //index of resultant merge subarray
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            // mid-i is the length of right part of left array which is greater than element of arr2
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid -1)
        temp[k++] = arr[i++];
    
    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right){

    int mid, inv_count = 0;
    if(right > left) {// till the point there is only single element 

        mid = (right + left)/2;

        //breaking till one single element
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);

        //start merging when all breaking done
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int main(){

    // int arr[] = { 1, 20, 6, 4, 5};
    // int n  = sizeof(arr)/sizeof(arr[0]);
    // int temp[n];
    vector<int> arr{1, 20, 6, 4, 5};
    vector<int> temp(arr.size());
    cout<<MergeSort(arr,temp,0,arr.size()-1);
    //int ans = _mergeSort(arr, temp, 0 , n-1);
    //cout<<ans;
    for(auto it:arr)cout<<"\n"<<it<<",";
    return 0;
}