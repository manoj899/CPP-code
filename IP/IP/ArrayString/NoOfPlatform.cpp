#include<iostream>
#include<vector>

using namespace std;
/*
Given arrival and departure times of all trains that reach a railway station, 
the task is to find the minimum number of platforms required for the railway station so that no train waits.*
*/ 

int NoOfPlatform(vector<int> arrival,vector<int> departure){

    int i=0; 
    int j=0;
    int n = arrival.size();
    int Tp = 0;
    int CP = 0;

    while(i < n && j < n){
        
        if(arrival[i] < departure[j]){
            i++;
            CP++;
            Tp = max(Tp,CP);
        }
        else{
            j++;
            CP--;
        }
    }
    
    return Tp;
}


int main(int argc, char** argv){

   vector<int> arrival{900,940,950,1100,1500,1800};
   vector<int> departure{910,1120,1130,1200,1900,2000};
   
   cout<<NoOfPlatform(arrival,departure);
}