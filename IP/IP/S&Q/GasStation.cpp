#include<iostream>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

int GasStation(vector<int>& gas, vector<int>& cost){

      vector<int> Delta(gas.size());
      vector<int> PrefixSum(gas.size());
      int sum =0;
      int min = INT_MAX;
      int index = 0;
      int TotGas =0;
      int TotCost = 0;
    
      for(int i=0; i< gas.size(); i++){
    
          TotCost += cost[i];
          TotGas += gas[i]; 
          Delta[i] = gas[i] - cost[i];
          sum += Delta[i];
          PrefixSum[i] = sum;
        
          if(min > PrefixSum[i]){
              min = PrefixSum[i];
              index = i;
          }          
      }

      if(TotGas >= TotCost){
         
          if(index+1 != gas.size()){
          return index+1;
          }
          else{
              return 0;
             }
        
     }
     else {
         return -1;
          }
}

/*Ask this solution and understand*/

/*  from leetcode comment 

 int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int startStation = 0;
        int currGas = 0;
        
        // Greedy cycling algorithm
        for (int station = 0; station < gas.size(); ++station) {
            if (currGas < 0) {
                currGas = 0;
                startStation = station;
            }
            
            currGas += gas[station];
            currGas -= cost[station];
        }
        
        // Check if cycle is even possible
        int station = startStation;
        currGas = 0;
        for (int i = 0; i < gas.size(); ++i) {
            currGas += gas[station];
            currGas -= cost[station];
            
            if (currGas < 0) {
                return -1;
            }
            
            ++station;
            station %= gas.size();
        }
        
        return startStation;
    }
    */ 
 
int main(int argc,char** argv){

  vector<int>gas {3,1,1};
  vector<int> cost = {1,2,2};
  cout<< "station no -> "<<GasStation(gas , cost)<<endl;
}