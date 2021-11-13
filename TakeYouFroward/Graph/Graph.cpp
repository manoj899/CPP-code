#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n,vector<int> graph[]){
    vector<bool> visited(n+1,false);
    int count = 0;
    //cout<<"reached"<<endl;
    vector<int> numOfComp;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            queue<int> pq;
            pq.push(i);
            visited[i] = true;
            while(pq.size()){
                auto front = pq.front();
                pq.pop();
                numOfComp.push_back(front);
                for(auto it:graph[front]){
                    if(visited[it] == false)
                    visited[it] = true;
                    pq.push(graph[front][it]); 
                }
            }
        }
    }
    return numOfComp;
}


vector<int> bfsOfGraph(vector<int> adj[],int n){

    vector<bool> visited(n+1,false);
    int count = 0 ;

    for(int i = 1 ; i <=1; i++){
        if(!visited[i]){
            queue<int> pq;
            pq.push(i);
            visited[i] = true;

            while(pq.size() > 0){
                auto front = pq.front();
                     pq.pop();

                for(auto x:adj[front]){
                    if(!visited[x]){
                        visited[x] = true;
                        pq.push(adj[front][x]);
                    }
                }
            }
            count++;
        }
    } 
}

//
for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = -visited[node];
            }
            else if(visited[node] == visited[it]){
                return false;
            }       
        }

        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = -visited[node];
            }
            else if(visited[node] == visited[it]){
                return false;
            }
        }

//
void DFS(vector<int> adj[],int ne,vector<bool>& visited,vector<int>& storeDFS){
    storeDFS.push_back(ne);
    visited[ne] = true;
    for(auto it:adj[ne]){
        if(!visited[it])
        DFS(adj,it,visited,storeDFS);
    }
}

vector<vector<int>> DFSofGraph(vector<int> adj[],int n){

   vector<bool> visited(n+1,0);
   vector<int> store;
   vector<vector<int>> res;

   for(int i = 1; i <= n; i++){
       if(!visited[i]){
          DFS(adj,i,visited,store);
          res.push_back(store);
          store.clear();
       }
   }

   return res;
}

// check graph is cyclic by BFS approach
bool IsCyclic(vector<int> adj[],vector<bool>& Visited,int i){

    queue<pair<int,int>> q;
    q.push({i,-1});
    Visited[i] = true;

    while(q.size()){
        auto front = q.front();
        q.pop();
        int node = front.first;
        int parent = front.second;

        for(auto it: adj[node]){
            if(!Visited[it]){
                Visited[it] = true;
                q.push({it,node});
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}

//check graph is cyclic by DFS approach

bool IsCyclicDFS(vector<int> adj[],vector<bool>& visited,int i, int prev){

    visited[i] = true;
    
    for(auto it:adj[i]){
        if(!visited[it]){// its not visited
           if(IsCyclicDFS(adj,visited,it,i)){
               return true;
           }
        }
        else if(it != prev) return true; // if visited then not equal to prev;
        //if(visited[it] && i == prev){return false;}  
    }
    return false;
}

bool IsCyclicGraph(vector<int> adj[],int n){
    
    vector<bool> Visited(n+1,false);

    for(int i =1; i <= n; i++){
        if(!Visited[i]){
        //    if(IsCyclic(adj,Visited,i)){
        //        return true;
        //    }
           if(IsCyclicDFS(adj,Visited,i,-1)){
               return true;
           }
        }
    }
    return false;
}

bool IsBiPartiteBFS(vector<int> adj[],int src,vector<int>& visited){

    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while(q.size() > 0){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = -visited[node];
            }
            else if(visited[node] == visited[it]){
                return false;
            }       
        }
    }
    
    return true;
}

bool IsBiPartiteDFS(vector<int> adj[],vector<int>& visited,int node){

    for(auto it:adj[node]){
        if(!visited[it]){
            visited[it] = -visited[node];
            if(!IsBiPartiteDFS(adj,visited,it)){
                return false;
            }
        }
        else if(visited[it] == visited[node]){
            return false;
        }
    }
    return true;
}

bool IsGraphBiPartiteBFS(vector<int> adj[],int n){

    vector<int> visited(n+1,0);

    for(int v = 1 ; v <= n; v++){
        if(!visited[v]){
            //for bfs
            // if(!IsBiPartiteBFS(adj,v,visited)){
            //     return false;
            // };
            //for dfs
            visited[v] = 1;
             if(!IsBiPartiteDFS(adj,visited,v)){
               return false;
             };
        }
    }
    return true;
}

//Cycle Detection in Directed Graph : DFS approach

bool checkCycle(int node, vector<int> adj[],int vis[],int dfsVis[]){
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycle(it,adj,vis,dfsVis)){
                return true;
            }
        }
        else if(dfsVis[it]){// node is in same dfs recursion and visited
            return true;
        }
    }
    dfsVis[node] = 0; //dfs recursion backtracking
    return false;
}

bool isCyclicc(int N,vector<int> adj[]){
    int vis[N+1] ;
    int dfsVis[N+1];// to keep track of index of recursion stack
    memset(vis, 0 , sizeof(vis));
    memset(dfsVis, 0 , sizeof(dfsVis));
    cout<<"reached";
    for(int i = 1; i <= N; i++){
        cout<<i<<",";
        if(!vis[i]){
            if(checkCycle(i,adj,vis,dfsVis)){
                return true;
            }
        }
    }
    return false;
}

//All Node shortest distance from source
void Dijkstra(vector<pair<int,int>> adj[],int n,int src){
    
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // min queue
    vector<int> distArray(n+1,INT_MAX); // 1 based index
    distArray[src] = 0;
    pq.push(make_pair(0,src));  //(from,dist)

    while(pq.size()){
        auto rem = pq.top();
        pq.pop();
        int dist = rem.first;
        int prev = rem.second; // node

        vector<pair<int,int>>::iterator it;
        for(auto it:adj[prev]){
            int next = it.first;
            int nextDist = it.second;
            if(distArray[next] > dist + nextDist){

                distArray[next] = distArray[prev] + nextDist;
                pq.push(make_pair(distArray[next],next));
                
            }
        }
    }

    cout<<"The distances from source, "<<src<<", are: \n";
    for(int i = 1; i <= n; i++) cout<< distArray[i]<<" ";
    return;
}

int main(){

    // int n,m;
    // cin>>n>>m;
    //m = num of edges , n = num of nodes 
    // vector<int> adj[11];
    // adj[1].push_back(3);
    // adj[3].push_back(4);
    // adj[4].push_back(6);
    // adj[6].push_back(8);
    // adj[2].push_back(9);
    // adj[5].push_back(7);
    // adj[7].push_back(10);
    // adj[10].push_back(7);
    // adj[7].push_back(5);
    // adj[9].push_back(2);
    // adj[8].push_back(6);
    // adj[6].push_back(4);
    // adj[4].push_back(3);
    // adj[3].push_back(1);

    
  /*  for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    */
    // cout<<"______________"<<"\n";
    // for(int i = 1; i <= 10 ; i++){
    //     cout<<i<<"-> ";
    //     for(int j = 0; j < adj[i].size(); j++){
    //         cout << "[" << adj[i][j]<< "] ";
    //         // cout<<adj[i][j]<<",";
    //     }cout<<endl;
    // }

// vector<vector<int>> arr =  DFSofGraph(adj,10);
//     for(int i =0 ;i < arr.size(); i++)
//     {
//         for(auto res:arr[i]){
//         cout<<res<<",";}
//         cout<<endl;
//     }

/*
    //cyclic graph
    vector<int> adj[12];
    // vector<int> adj[9];
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[3].push_back(5);
    adj[5].push_back(6);
    adj[5].push_back(3);
    adj[5].push_back(10);
    adj[6].push_back(7);
    adj[6].push_back(5);
    adj[7].push_back(8);
    adj[7].push_back(6);
    adj[8].push_back(9);
    adj[8].push_back(11);
    adj[8].push_back(7);
    adj[9].push_back(10);
    adj[9].push_back(8);
    // adj[9].push_back(7);
    // adj[7].push_back(9);// this code make 2nd component of graph cyclic
    adj[10].push_back(5);
    adj[10].push_back(9);
    adj[11].push_back(8);
    
    //  adj[1].push_back(4);// this code make 1st component of graph cyclic
    //  adj[4].push_back(1);


    // cout<<IsCyclicGraph(adj,11);
    cout<<IsGraphBiPartiteBFS(adj,11);
    */

    //  vector<int> adj[9];
    // vector<int> adj[9];
    // adj[2].push_back(3);
    // adj[3].push_back(4);
    // adj[3].push_back(6);
    // adj[4].push_back(5);
    // adj[4].push_back(5);
    // adj[6].push_back(5);
    // adj[7].push_back(8);
    // adj[7].push_back(2);
    // adj[8].push_back(9);
    // adj[9].push_back(7);
    
    // cout<<isCyclicc(9,adj);

    //graph having single component
    //all node shortest path from source

    vector<pair<int,int>> adj[5];
    
    // AllNodeShortestDistance(adj,9);
    adj[1].push_back({2,2});
    adj[1].push_back({4,1});
    adj[2].push_back({1,2});
    adj[2].push_back({3,4});
    adj[2].push_back({5,5});
    adj[3].push_back({4,3});
    adj[3].push_back({2,4});
    adj[3].push_back({5,1});
    adj[4].push_back({3,3});
    adj[4].push_back({1,1});
    adj[5].push_back({3,1});
    adj[5].push_back({2,5});

    Dijkstra(adj,5,1);
    return 0;
}