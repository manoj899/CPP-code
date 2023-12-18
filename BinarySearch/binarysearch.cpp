#include<iostream>
#include<vector>

using namespace std;


int firstOccurence(vector<int> num, int target){

    int start = 0, end = num.size()-1;
    int res = -1;

    while(start <= end){

        int mid = start + (end-start)/2; // prevent overflow

        if(target == num[mid]){
            res = mid;
            end = mid-1;
        }
        else if(target < num[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }

    }

    return res;

}

int lastOccurence(vector<int> num, int target){

    int start = 0, end = num.size()-1;
    int res = -1;

    while(start <= end){

        int mid = start + (end-start)/2; // prevent overflow

        if(target == num[mid]){
            res = mid;
            start = mid+1;
        }
        else if(target < num[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }

    }

    return res;

}

//find first and last occurance of x in an sorted array, no ans return {-1,-1}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;

    res.push_back(firstOccurence(nums, target));
    res.push_back(lastOccurence(nums, target));

    return res;

}

int main(){

    vector<int> arr {5,7,7,8,8,10};

    vector<int> res = searchRange(arr,9);

    cout<<res[0]<<","<<res[1]<<endl;

    return 0;
}

