#include<bits/stdc++.h>
#include<string>

using namespace std;

//give subarray whose sum equal to k

void SubarrSum(vector<int> arr,int k){ // O(n^2) brute force
    int n = arr.size();
    if(n == 0) return ;

    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j = i; j<n; j++ ){
             sum += arr[j];
            if(sum == k){
                for(int m = i; m <= j; m++){
                    cout<<arr[m]<<",";
                }
                cout<<endl;
                break;
            }
            else if(sum > k){
                break;
            }
           
        }
    }
}

// optimise in O(n);
void SubarrSum2(vector<int> arr,int k){ 
    int n = arr.size();
    if(n == 0) return ;
    unordered_map<int,int> mp;

    int sum = 0;
    for(int i=0; i<arr.size(); i++){
         sum += arr[i];
         
         if(sum == k){
             cout << "Sum found between indexes "
                 << "0"
                 << " to " << i << endl; 
         }
        
        else if(sum > k && mp.find(sum-k) != mp.end()){
             cout << "Sum found between indexes "
                 << mp[sum - k] + 1 
                 << " to " << i << endl; 
        }

        mp[sum] = i;
    }
    
}

//count the triplet
void countTriplet(vector<int> arr)
{
     int n = arr.size() ;
	   set<int> mp;
	    
	    for(int i=0; i<n;i++){
	        mp.insert(arr[i]);
	    }
	    int count=0;
	    
	    for(int i=0; i<n;i++){
	        for(int j=i+1; j<n;j++){
	            if(mp.find(arr[i]+arr[j]) != mp.end()){
	               cout<<"Triplet are "<<arr[i]<<" "<<arr[j]<<endl;
	            }

	        }
	    }	    
}

// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
//brute force
void MaxSumSubarr(vector<int> arr){
    if(arr.size() == 0) return;

    int n = arr.size();

    int sum = INT_MIN;
    
    for(int i=0; i<n;i++){
        int s=0;
        int ls = INT_MIN;
        for(int j=i ; j < n; j++){
            s += arr[i];
            ls = max(ls,s);
        }
        sum = max(sum,ls);
    }

    cout<<"Max sum is "<<sum;
}
/*
 sum = max(lsum,sum);
       max_sum = max( max_sum,sum);
      cout<<sum<<" ";
    //    lmax = max(lmax,arr[i]);
*/ 
// Kadane algo- optimise subarr sum
void MaxSumSubarr2(vector<int> arr){
    if(arr.size() == 0) return;

    int n = arr.size();

    int max_curr = arr[0];
    int max_global = arr[0];

    for(int i=1; i< arr.size(); i++){
        max_curr = max(arr[i],max_curr+arr[i]);
        // cout<<max_curr<<",";
        max_global = max(max_global, max_curr);
    }
    cout<<"Max sum is "<<max_global;
}


//Merge two sorted arrays with O(1) extra space
void mergeArr(vector<int> a1,vector<int> a2){

    // int a1[] = { 1, 5, 9, 10, 15, 20 };
    // int a2[] = { 2, 3, 8, 13 };

    for(int i = a2.size()-1 ; i >=0; i--){
        int j ;
        int last = a1[a1.size()-1];

        //if a1[j] > a2[i] we do shifting to right by 1 position in a1 array
        for(j = a1.size()-2 ; a1[j] > a2[i] && j>=0; j--){
            a1[j+1] = a1[j];
        }

        if(j != a1.size()-1 || last > a2[i]){
            a1[j+1] = a2[i];
            a2[i] = last;
        }
    }

    for(int i:a1){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:a2){
        cout<<i<<" ";
    }
}

// Number of pairs
//brute force
void numPair(vector<int> a1,vector<int> a2){// O(m*n)

    int count=0;
    for(int i=0; i<a1.size(); i++){
        for(int j=0; j < a2.size(); j++){
            if(pow(a1[i],a2[j]) > pow(a2[j],a1[i])){
                count++;
            }
        }
    }

    cout<<"Total pair "<<count;
}

//its optimise version see on GFG special case


//count inversion : --  
// Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
// Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 

//brute force
void countInversion(vector<int> arr){

    int count =0; 

    for( int i=0; i < arr.size()-1; i++){
        for(int j=i+1 ; j = arr.size(); j++){
            if(arr[i] > arr[j]) count++;
        }
    }

    cout<<"Total inversion is "<<count<<endl;
}

//nlogn approach by merge sort 
// ***************************************not done..do it**************************


//Segregate 0s and 1s in an array

void segregate01(vector<int> arr){

    int i=0,j=arr.size()-1;

    while(i < j){
        while(arr[i] !=1){
            i++;
        }
        while(arr[j] !=0){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else{
            break;
        }
       
    }

    for(int k:arr){
        cout<<k<<" ";
    }

}

//equilibriumPoint
void equilibriumPoint(vector<int> a) {
    int n = a.size();
    if(n == 1) { cout<<a[0]; return;}
    else if(n == 2) {cout<<"none";return;}
    int rsum,lsum;
    
    int arr[n];
    int sum =0;
    
    for(int i=0; i<n; i++){
        sum += a[i];
        arr[i]=sum;
    }
    
    for(int i=1; i<n-1;i++){
        
        lsum = arr[i]-a[i];
        rsum = sum-arr[i];
        
        if(lsum == rsum){
            cout<<i+1;
            return;
        }    
    }
}

// number of platform
void nmofPlatform(vector<int> arr,vector<int> depar){

    if(arr.size() == 0) return ;

    sort(arr.begin(),arr.end());
    sort(depar.begin(),depar.end());

    int platform =1;
    int max_platform =1;
    int j=0;
    int i=1;
   while(i < arr.size() && j < arr.size()){
        
        if(arr[i] <= depar[j]){//as new train arrive before any departure happen ,so new platform needed 
           
            cout<< ++platform<<" ";
            i++;
           
        }
        else if(arr[i] > depar[j]){//as departure happen so platform decreased
            cout<< --platform<<" ";
            j++;
        }
         max_platform = max(max_platform, platform);
    }
    cout<<"max platform required = "<<max_platform;
}

//kth smallest element
// 1st approach..sort array and return kth element; nlogn
// 2nd approach...priority ququ   nlogn 
void kthSmallest(vector<int> arr,int k){

    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i< arr.size(); i++){
        pq.push(arr[i]);
    }
    
    while(k-->1){
        pq.pop();
    }
    
    int res = pq.top();
    cout<<"Kth smallest "<<res;
    // return res;
    
}

//spirally traversing matrix

// void spiralMatrix(vector<vector<int>> a){

//      int i, k = 0, l = 0;
//      int m = A.size();
//      int n = A[0].size();
 
//     /* k - starting row index
//         m - ending row index
//         l - starting column index
//         n - ending column index
//         i - iterator
//     */
 
//     while (k < m && l < n) {
//         /* Print the first row from
//                the remaining rows */
//         for (i = l; i < n; ++i) {
//             cout << a[k][i] << " ";
//         }
//         k++;
 
//         /* Print the last column
//          from the remaining columns */
//         for (i = k; i < m; ++i) {
//             cout << a[i][n - 1] << " ";
//         }
//         n--;
 
//         /* Print the last row from
//                 the remaining rows */
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 cout << a[m - 1][i] << " ";
//             }
//             m--;
//         }
 
//         /* Print the first column from
//                    the remaining columns */
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 cout << a[i][l] << " ";
//             }
//             l++;
//         }
//     }
// }

//Arrange the element of array to make the largeest number;

int mycompare(string s1,string s2){

    string xy = s1.append(s2);
    string yx = s2.append(s1);

    return xy.compare(yx) > 0 ? 1:0;
}

void LargestNum(vector<string> str){

    sort(str.begin() , str.end(),mycompare);

    for(auto i:str)
        cout<<i;
}



void swap(vector<int>& arr,int a,int b){
    int temp = arr[a+1];
    arr[a+1] = arr[a];
    arr[a] = arr[a+1];

}

//Zig-Zag array
void ZigZag(vector<int> arr)
{
    int flag =0;
    int i=0;
    while(i<arr.size()){
     
        if( flag == 0 ){
            if(arr[i] < arr[i+1]){
               continue; 
            }
            else{
                swap(arr,arr[i],arr[i+1]);
            }
        }
        else
        if( flag == 1 ){
            if(arr[i] > arr[i+1]){
               continue; 
            }
            else{
                swap(arr,i,i+1);
            }
        }
        flag = !flag;
        i++;
    }

    for(auto i:arr){
        cout<<i<<" ";
    }
}

//****************************************************************** STRINGS QUESTIONS *******************************************************************

//Reverse words in a given string ;

void ReverseWord(string s){

    for(int i=0; i<s.size(); i++){
        int j=i;

        while(s[i] != ' '){
            j++;
        }
        
        reverse(s.begin()+i,s.begin()+i+j);
        i = j;
        i++;
    }

    reverse(s.begin(),s.end());

    for(auto i:s){
        cout<<i<<" ";
    }
}



int main(){

    // vector<int> arr{10, 2, -2, -20, 10};
    // SubarrSum(arr,33);
    // SubarrSum2(arr,-10);
    //   vector<int> arr2{-2, -3, 4, -1, -2, 1, 5, -3};
    // countTriplet(arr2);
    // MaxSumSubarr2(arr2);

    //  vector<int> a1 = { 1, 5, 9, 10, 15, 20 };
    //  vector<int> a2 = { 2, 3, 8, 13 };

    //  mergeArr(a1,a2);

    // vector<int> a1 = {2, 1, 6}; 
    //  vector<int> a2 = {1, 5};  

    //  numPair(a1,a2);

    // vector<int> arr{8, 4, 2, 1};
    // countInversion(arr);

    // vector<int> arr{0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    // segregate01(arr);

    // vector<int> arr{4 ,42, 27, 16, 28, 3 ,4 ,5, 9, 3, 31, 5 ,5, 29, 10, 18, 35 ,35 ,33 ,19 ,41 ,23 ,8, 32, 9, 5, 8, 18, 35, 13, 6, 7, 6, 10, 11, 13, 37 ,2 ,25, 7 ,28, 43};
    // equilibriumPoint(arr);

    // vector<int> arr{ 50,120,200,550,700,850 };
    // vector<int> depar{ 500,550,600,700,900,1000};

    // nmofPlatform(arr,depar);

    // vector<int> arr{ 12, 3, 5, 7, 4, 19, 26 };
    // kthSmallest(arr,3);

    // vector<vector<int>> A{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // spiralMatrix(A);

    // vector<string> arr;
    // arr.push_back("54");
    // arr.push_back("546");
    // arr.push_back("548");
    // arr.push_back("60");

    // LargestNum(arr);

    // vector<int> arr{5,10,18,12,6,9,4,2};
    // ZigZag(arr);

    ReverseWord("Geek for Geeks");

    return 0;
}