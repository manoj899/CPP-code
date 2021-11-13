#include<bits/stdc++.h>

using namespace std;




int main(){

    int N = 0;
    int parent[N];
    int key[N];  // store min wt till node(index)  // store key  value..what is the index with min possible key value
    bool mstSet[N];  // store whether a node is part of mst or not

    for(int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;
/*
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < N -1; count++){
        
        int mini = INT_MAX, u; // to store the min key value pair

        for(int v = 0; v < N; v++){
            if(mstSet[v] == false && key[v] < mini)
            mini = key[v], u = v;
        }

        mstSet[u] = true;

        for(auto it: adj[u]){ // its N+E complexity not N^2
            int v = it.first;
            int weight = it.second;
            if(mstSet[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }
    }
    */

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});
    for(int count = 0; count < N-1; count++){ // loop on edges

        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for(auto it: adj[u]){ // it will check all adjacent edges of all the nodes
            int v = it.first;
            int weight = it.second;
            if(mstSet[v] == false && weight < key[v]){
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }

    for(int i = 1; i < N; i++)
        cout<<parent[i] <<" - "<<i<<"\n";
    

    return 0;
}