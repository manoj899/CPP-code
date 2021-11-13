#include<bits/stdc++.h>

using namespace std;

//Dutch national flag
void SortIT(vector<int> arr){

    int low = 0;
    int mid = 0;
    int high = arr.size()-1;

    while(mid <= high){
        switch (arr[mid])
        {
        case 0:
            swap(arr[low++],arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid],arr[high--]);
            break;
        
        default:
            break;
        }
    }

    for(auto it:arr){
        cout<<it<<",";
    }
}


//Kadane algo
void KadaneAlgo(vector<int> arr){

    int lmax = arr[0];
    int gmax = arr[0];

    for(int i = 1 ; i < arr.size(); i++){
        lmax = max(arr[i],lmax+arr[i]);
        gmax = max(gmax,lmax);
    }

    cout<<"Largest Sum -> "<<gmax<<endl;
}

bool compare(int a,int b){
    return a < b;
}
//merge interval
// void MergeInterval(vector<pair<int,int>> interval){
//     if(interval.size() == 0 || interval.size() == 1){return ;}

//     int st = interval[0].first;
//     int ed = interval[0].second;

//     sort(interval.begin(),interval.end(),compare);

//     for(int i = 1 ; i < interval.size() ; i++){
//         if()
//     }
// }

//Merge Two sorted array
void MergeTwoArray(vector<int>& A,vector<int>& B){

    int m = A.size();
    int n = B.size();
    
    for(int i = n-1 ; i >= 0 ; i--){
        int j = m-1;
        int last = A[j];
        for(j = m-2 ; j >= 0 && B[i] <A[j]; j--){
            A[j+1] = A[j];
        }

        if(j != m-2 || last > A[i]){
            A[j+1] = B[i];
            B[i] = last;
        }
    }

    for(auto it:A){
        cout<<it<<",";
    }
    for(auto it:B){
        cout<<it<<",";
    }

}

int main(){
    
    // vector<int> arr{0,1,2,0,1,2};
    // SortIT(arr);

    // vector<int> arr{-2,-3,4,-1,-2,1,5,-3};
    // KadaneAlgo(arr);

    vector<int> A{1,3,5,7};
    vector<int> B{2,4,6,8};
    MergeTwoArray(A,B);
    return 0;
}
