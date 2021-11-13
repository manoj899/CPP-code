#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<queue>


using namespace std;

    
//  int vis[5][5];
  
//         memset(vis,0,sizeof(vis));
// for(int i=0; i<5; i++){
//     for(int j=0; j<5; j++){
// cout<<vis[i][j]<<" ";
//     }
//     cout<<endl;
// }
/*
In this section we will see what is the purpose of memset() function in C++. 
This function converts the value of a character to unsigned character and 
copies it into each of first n character of the object pointed by the given 
str[]. If the n is larger than string size, it will be undefined.*/ 

// ** SWIM IN RISING WATER -- LEET CODE 778
// On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

// Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

//   typedef pair<int,pair<int,int> > pi;
//     int swimInWater(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int vis[m][n];
  
//         memset(vis,10000,sizeof(vis));
        
//                priority_queue<pi,vector<pi>,greater<pi> >pq;
//         vis[0][0]=grid[0][0];
//         int dx[4]={0,0,-1,1};
//         int dy[4]={1,-1,0,0};
//         pq.push({grid[0][0],{0,0}});
//         while(!pq.empty())
//         {
//             pi p=pq.top();
//             pq.pop();
//             int hei=p.first;
//             int x=p.second.first;
//             int y=p.second.second;
//            int xnew,ynew;
//             for(int i=0;i<4;i++)
//             {
//                 xnew=x+dx[i];
//                 ynew=y+dy[i];
//                 if(xnew <0 || ynew<0 || xnew >=m || ynew >=n)
//                     continue;
//                 if(vis[xnew][ynew] > max(hei,grid[xnew][ynew]))
//                 {
//                     vis[xnew][ynew] =  max(hei,grid[xnew][ynew]);
//                     cout<<vis[xnew][ynew]<<" ";
//                     pq.push({ max(hei,grid[xnew][ynew]),{xnew,ynew}});
//                 }
//                 cout<<endl;
                
//             }
            
            
//         }
        
//         return vis[m-1][n-1];
//     }
 typedef pair<int,pair<int,int>> pi;
int swimInWater(vector<vector<int>>& grid){

   
    priority_queue<pi, vector<pi>, greater<pi> >  pq;

    int m = grid.size();
    int n = grid[0].size();
    int vis[m][n];

    memset(vis,1,sizeof(vis));

    vis[0][0] = grid[0][0];
   
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
     pq.push({grid[0][0],{0,0}});

    
    while(!pq.empty()){

        pi p = pq.top();
        pq.pop();

        int val = p.first;
        int x = p.second.first;
        int y = p.second.second;
        int nx,ny;

        for(int i=0; i<4; i++){

            nx = x + dx[i];
            ny = y + dy[i];

            if(nx >= m || ny >= n || nx<0 || ny < 0){
                continue;
            }
            if(vis[nx][ny] > max(val,grid[nx][ny])){

                vis[nx][ny] = max(val,grid[nx][ny]);
                cout<<vis[nx][ny]<<" ";
                pq.push({max(val,grid[nx][ny]),{nx,ny}});
            }
        }


    }
    return vis[m-1][n-1];

}



int main(int argc,char** argv){

    vector<vector<int>> arr {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<swimInWater(arr)<<endl;
}
 
