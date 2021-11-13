#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//Longest consecutive sequence in O(n)

void LongestConseSequence(vector<int> arr){

    unordered_map<int,bool> mp;

    for(int i=0 ; i< arr.size(); i++){
        mp[arr[i]]  = true;
    }

    for(int i=0; i<arr.size(); i++){

        if(mp.count(arr[i]-1) != 0){
            mp[arr[i]]  = false;
        }
    }

    int mlen = 0;  // max length
    int msp = 0;  //max starting pt

    for(int i=0; i< arr.size();i++){

        int tsp = arr[i];
        int tlen = 1;

      if(mp[arr[i]] == true){
        while( mp.count(tsp + tlen) != 0){
            tlen++;
        }

        if(tlen > mlen){
            mlen = tlen;
            msp = tsp;
        }
        }
    }

    cout<<msp <<"@"<<mlen <<endl;

    for(int i=msp; i<mlen + msp; i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

//count of subarr having sum eq to target
int CountSubarrays(vector<int> arr,int k){

    unordered_map<int,int> map;
    map[-1] = 0;  //  prefix sum when arr dont exist
    // vector<int> presum(arr.size(),0);
    int presum =0;
    int count = 0;

    for(int i=0; i<arr.size(); i++){
     
      presum += arr[i];

      if(map.count(presum) == 0){
          map[presum] = 1;
      }
      else{
          map[presum]++; 
      }

    //   if(presum[i] == k){
    //       count += 1; 
    //   }
      
      if( map.count(k- presum) != 0){
          count += map[k-presum];
      }

    }

    return count;
}

//print longest subarr eq to tar

int LonSubArrTar(vector<int> arr,int tar){
    
    unordered_map<int,int> map;//HM store index of presum
    map[0] = -1;
    int presum = 0;
    int mlen = 0;
    

    for(int i=0; i<arr.size(); i++){
        
        presum += arr[i];

        if(map.count(presum) == 0){
             map[presum] = i;
        }
        else {
           
        }

        if( map.count(presum-tar) ){
                int tlen = i - map[presum - tar];
                if(tlen > mlen){
                    mlen = tlen;
                }  
                // cout<<i<<" "<<map[presum- tar]<<endl;
        }
    } 
    return mlen;
}





int main(int argc,char** argv){
    
    //  vector<int> lp{2,12,9,16,10,5,3,20,25,11,1,8,6};
    //  LongestConseSequence(lp);

     vector<int> arr{2,3,-4,1,2,-3,0,1,1,-5,3,0,2,1,2,4};

    //  cout<<CountSubarrays(arr,3);
     cout<<LonSubArrTar(arr,4);
}