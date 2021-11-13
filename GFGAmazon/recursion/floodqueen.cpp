#include<bits/stdc++.h>

using namespace std;

void FloodFill(vector<vector<int>>& maze, int sr,int sc,int dr, int dc,string asf,vector<vector<bool>>& visited){
    static int count =0;
    if(sr <0 || sc < 0 || sr == dr+1 || sc == dc+1 || maze[sr][sc] == 1|| visited[sr][sc] == true){
        return;
    }
     if(sc == dc && sr == dr){
        cout<<++count<<" ";
        for(auto i:asf){
            cout<<i;
        }
        cout<<endl;
    }
    

             
             visited[sr][sc] = true;
                // cout<<asf<<endl;
             FloodFill(maze, sr-1,sc,dr,dc, asf+"t",visited);   
             FloodFill(maze, sr,sc-1,dr,dc, asf+"l",visited);   
             FloodFill(maze, sr+1,sc,dr,dc, asf+"b",visited);   
             FloodFill(maze, sr,sc+1,dr,dc, asf+"r",visited);   

             visited[sr][sc] = false;
        
         return; 
}

void TargetSumSubset(vector<int> arr,int Tsum,int index,int total,string asf){

    if(index == arr.size() ||  Tsum == total){
        for(auto i:asf){
            cout<<i<<",";
        }
        cout<<endl;
        return;
    }
    
    if(Tsum < total || index >= arr.size()-1){
        return;
    }
    

        TargetSumSubset(arr,Tsum,total+arr[index],index+1,asf+to_string(arr[index]));
        TargetSumSubset(arr,Tsum,total,index+1,asf);
    

    return;
}





int main(){

    // vector<vector<int>> maze={
    //                             {0,1,0,0,0,0,0},    
    //                             {0,1,0,1,1,1,0},    
    //                             {0,0,0,0,0,0,0},    
    //                             {1,0,1,1,0,1,1},   
    //                             {1,0,1,1,0,1,1},    
    //                             {1,0,0,0,0,0,0}    
    //                             };
    // vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));

    // FloodFill(maze,0,0,5,6,"",visited);           

    vector<int> arr{10,20,30,40,50};

    TargetSumSubset(arr,60,0,0,"");                 


    return 0;
}