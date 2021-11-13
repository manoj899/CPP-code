#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(arr.size() == 0){
            return 0;
        }
        int c=0;
        int m = 0;
        for(int i = 0 ; i < arr.size(); i++){
            m = max(arr[i],m);
        }
        vector<int> nums(m+1,0);
        
        for(int i = 0 ; i < arr.size(); i++){
            nums[arr[i]]++;
        }
        
        if(k == 0){
            for(int i = 0 ; i < nums.size();i++){
            if(nums[i] != 0){
                c++;
            }
         } return c;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < nums.size(); i++){
            
            if(k == 0){
                exit;
            }
            if(nums[i] == 0){
                continue;
            }
            
            if(nums[i] <= k){
                k = k-nums[i];
                nums[i] = 0;
            }
            else if(nums[i] > k){
                k = 0;
                nums[i] = nums[i]-k;
            }           
        }   

        for(int i = 0 ; i < nums.size();i++){
            if(nums[i] != 0){
                c++;
            }
        }
        return c;  
       
    }


int main(int argc,char** argv){
    vector<int> arr{5,5,4};
  cout<<"____"<<findLeastNumOfUniqueInts(arr,1);
}