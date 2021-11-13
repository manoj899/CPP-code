#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<string>
// #include<pair>

using namespace std;


// construction of Generic tree
class Node{
    public:
    int val;
    vector<Node*> children;

    Node(int v){
        this->val = v;
    }
};


Node* GenericTree(vector<int> arr){
    stack<Node*> st;
    Node* head = new Node(arr[0]);
    for(int i=0; i< arr.size() ; i++){
        if(st.size() == 0 && arr[i] != -1){
            st.push(head);
        }
        else{
            if(arr[i] == -1 && st.size() >0){
                st.pop();
            }
            else{
                Node* temp = new Node(arr[i]);
                Node* rem = st.top();
                rem->children.push_back(temp);
                st.push(temp);
            }
        }
    }
    return head;
}

void Display(Node* head){
    if(head == NULL) 
    
    return;

        cout<<head->val<<" -> ";
        for(int i=0; i<head->children.size(); i++){
            cout<<head->children[i]->val<<",";
        }
        cout<<endl;
    

    for(int i=0; i<head->children.size(); i++){
         Display(head->children[i]);
    }
}


/*
          Tree
         ->tree has parent and children while graph has sibling
         ->tree travese parent to children while graph can move in any direction 
*/


//consturction of Graph

class Edge{
    public:
    int ne;
    int wt;
    
    Edge(int n,int w){
        this->ne = n;
        this->wt = w;
    }
};

void addEdge(vector<vector<Edge>>& graph,int v1,int v2,int wt){

    graph[v1].push_back(Edge(v2,wt));
    graph[v2].push_back(Edge(v1,wt));
}

void Gdisplay(vector<vector<Edge>>& graph)
{
    cout << "--------------------" << endl;
    for(int v = 0 ; v < graph.size(); v++)
    {
        cout << v << "-> ";
        for(int n = 0; n < graph[v].size(); n++)
        {
            Edge rem = graph[v][n];
            cout << "[" << rem.ne << "@" << rem.wt << "] ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

//BFS travel
void BFS(vector<vector<Edge>> graph,int s){

    queue<int> q;

    vector<bool> visited(graph.size(),false);
    q.push(s);
    vector<int> even;
    vector<int> odd;
    int counter =1;

    while(q.size() !=0){

        int rem = q.front();
        q.pop();

        if(visited[rem] == true){
            continue;
        }

        visited[rem] = true;


        for(int i=0; i<graph[rem].size(); i++){
            Edge nei = graph[rem][i];

            if(visited[nei.ne] == false){
                q.push(nei.ne);
               if(counter%2==0){
                    even.push_back(nei.ne);
                }
                else{
                    odd.push_back(nei.ne);
                }  
            }
        }
        counter++;

         for(int i=0;i<even.size();i++){
            cout<<even[i]<<" ";
            }
            cout<<endl;
            
            for(int i=0;i<odd.size();i++){
                cout<<odd[i]<<" ";
            }
            cout<<endl; 
        // for(int i:arr){
        //     cout<<i<<",";
        // }
        // cout<<endl;
        // arr.clear();
    }
}




bool bipartite(vector<vector<Edge>> &graph, int v,vector<int>& visited){

    queue<int> q;
    q.push(v);

    while(q.size() >0){
        int curr = q.front();
        q.pop();

        int color = 0;
        if(visited[curr] != -1){
          color = visited[curr];
        }

        cout<<"curr value => "<<curr<<" neighbour -> ";
        for(int n=0; n < graph[curr].size(); n++){
            Edge nei = graph[curr][n];

            if(visited[nei.ne] == -1){
                q.push(nei.ne);
                cout<<nei.ne<<" ";
                visited[nei.ne] = 1-color;
            }
            else{
                cout<<nei.ne<<" ";
                if(color == visited[nei.ne] ){
                    
                    return false;
                }
            }
            
        }
        cout<<endl;
    }
    return true;
}

bool isBipartite(vector<vector<Edge>> graph){

    int n = graph.size();
    vector<int> color(n , -1);

    for(int v=0; v < n; v++){
        cout<<" * "<<endl;
      if(!bipartite(graph, v,color)){
          cout<<"Not bipartite";
          return false;
      }  
    }
    return true;
}

// class Ppair
// {
//     public:
//     int v;
//     int av;  //acquiring vertex . it doesnt have allprevious sum like Dijikstra
//     int c;    // it has only one step code
//     Ppair(int v, int av, int c){

//         this->v = v;
//         this->av= av;
//         this->c = c;
//     }
//     //"other" is an object too..in parameter you are giving (classname as Datatype and variable as object)
//     //below syntax is similar like "const int a = 10"..only pass by reference
//     //operator is predefined name..like sort, min,max..only u need to pass symbol(> , < ,+ ,/ , etc) with operator function
//     // conclusion 
//     //return_type function_name(const dataType(i.e classname,)& variable_name(ie. object)) const
//     bool operator>(const Ppair& other) const
//     {
//         return this->c > other.c;
//     }
// };

// class edge{
//     public:
//     int nbr;
//     int wt;
// };

// void addedge(vector<vector<edge>>& g,int v1,int v2,int wt){
//     edge e1,e2;
//     e1.nbr = v2;
//     e2.nbr = v1;
//     g[v1].push_back(e2);
//     g[v2].push_back(e1);
    
// }

// void PrimsDisplay(vector<vector<edge>> g){

//     for(int v=0; v < g.size(); v++){
//         cout<<v<<"->";
//         for(int n=0; n<g[v].size(); n++ ){
//             edge ne = g[v][n];
//             cout<<"["<<ne.nbr<<"-"<<ne.wt<<"]";
//         }
//         cout<<"."<<endl;
//     }
// }

// void Prims(vector<vector<Edge>> &graph){
    
//     vector<vector<edge>> mst(graph.size(),vector<edge>());
//     vector<bool> visited(graph.size(), false);

//     priority_queue<Ppair , vector<Ppair>, greater<Ppair>> pq;
//     Ppair rp(0,-1,0);

//     pq.push(rp);

//     while(pq.size() > 0){
//         Ppair rem = pq.top();
//         pq.pop();

//         if(visited[rem.v] == true) continue;

//         visited[rem.v] = true;

//         if(rem.av != -1){
//             addedge(mst,rem.v,rem.av,rem.c);
//         }

//         for(int i=0; i<graph[rem.v].size(); i++){
//             Edge n = graph[rem.v][i];

//             if(visited[n.ne] == false){
//                 Ppair np(n.ne,rem.v,n.wt);
//                 pq.push(np);
//             }
//         } 
//     }

//     PrimsDisplay(mst);

// };

// class Ppair{
//     public:
//     int v;
//     int av;
//     int c;

//     Ppair(int v,int ac,int c){
//         this->v = v;
//         this->av = av;
//         this->c = c;
//     }

//     bool operator > (const Ppair& other) const{
//         this->c > other.c;
//     }
// };

// class edge{
//     public:
//     int ne;
//     int wt;
// };

// void addedge(vector<vector<edge>>& m,int v1,int v2,int w){

//     edge e1,e2;
//     e1.ne = v2;
//     e1.wt = w;
//     e2.wt = w;
//     e2.ne = v1;

//     m[v1].push_back(e2);
//     m[v1].push_back(e1);
// }

// void Prims(vector<vector<Edge>> & graph){

//     vector<vector<edge>> mst(graph.size(),vector<edge>());
//     vector<bool> visited(graph.size(),false);

//     priority_queue<Ppair,vector<Ppair>, greater<Ppair>> pq; // this will give smallest first

//     Ppair rp(0,-1,0); // initially acquiring vertex is none so -1;
//      pq.push(rp);

//     while(pq.size() > 0){

//         Ppair rem  = pq.top();
//         pq.pop();

//         if(visited[rem.v] == true){
//             continue;
//         }

//         visited[rem.v] = true;

//         if(rem.av != -1){
//             addedge(mst,rem.v,rem.av,rem.c);
//         }

//         for(int n=0; n<graph[rem.v].size(); n++){
//             Edge p = graph[rem.v][n];

//             if(visited[p.ne] == false){
//                 Ppair np(p.ne,rem.v,p.wt);
//                 pq.push(np);
//             }
//         }
//     }
// }

class Dpair{
    public:
    int v;
    int c;
    string p;

    Dpair(int v,int c,string p){
        this->v = v;
        this->c = c;
        this->p = p;
    }

    bool operator>(const Dpair& other ) const
    {/* const Dpair &other  
       here datatype of parameter is class type so the passed variable is object bydefault
          which will act as 2nd object and can be compared */
        return this-> c > other.c;
    }
};

void Djikstra(vector<vector<Edge>> graph,int s){
    priority_queue<Dpair, vector<Dpair>, greater<Dpair>> pq;
    Dpair rtp(s,0,to_string(s));
    pq.push(rtp);

    // vector<int> (graph.size(), INT_MAX);
    vector<bool> visited(graph.size(),false);

    while(pq.size() >0 ){
        Dpair rem = pq.top();
        pq.pop();

        if(visited[rem.v] == true){
            continue;
        }

        visited[rem.v] = true;

        cout<<rem.v<<"@"<<rem.c<<"via"<<rem.p<<endl;

        for(int n=0; n  <graph[rem.v].size();n++){
            Edge ne = graph[rem.v][n];

            if(visited[ne.ne] == false){
                Dpair dp(ne.ne,ne.wt+rem.c, rem.p +to_string(ne.ne));
                pq.push(dp);
            }
        }
    }
}

void DFS(vector<vector<Edge>> &graph,int src){

   static vector<bool> visited(graph.size(),false);
   if(visited[src] == true) return;
    
    visited[src] = true;
    cout<<src<<" ";


    for(int i=0; i<graph[src].size(); i++) {
        Edge ne = graph[src][i];
        if(visited[ne.ne] == false){
          DFS(graph,ne.ne);
        }
    }
}


/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
/*
void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s]=true;
    cout<<s<<" ";
    for(auto x:g[s])
    {
        if(!vis[x])
        {
            dfs(x,g,vis);
        }
    }
    // Your code here
}
*/ 


string gscc(int r,vector<bool>& visited,vector<vector<Edge>>& graph){

      queue<int> q;
      q.push(r);

      string comp="";

      while(q.size()>0){
         
         int rem = q.front();
         q.pop();

         if(visited[rem]== true){
             continue;
         }
         visited[rem]= true;

         comp += to_string(rem);

         for(int n=0; n<graph[rem].size(); n++){
             
             Edge ne =graph[rem][n];
             if(visited[ne.ne] == false){

                 q.push(ne.ne);  
             }
         }
      }
      return comp;
}


vector<string> gcc(vector<vector<Edge>> graph){

    vector<bool> visited(graph.size(),false);
     vector<string> comps;
    for(int v = 0; v < graph.size(); v++ ){
      
      if(visited[v] == false){
      string comp = gscc(v,visited, graph);
      comps.push_back(comp);

    }
    }
    return comps;
}



int main(){

    // vector<int> arr{10,20,50,-1,60,-1,-1,30,70};
    // Node* head =  GenericTree(arr);
    // Display(head);

    vector<vector<Edge>> graph;
    for(int v = 0; v < 5; v++)
    {
        graph.push_back(vector<Edge>());
    }


    addEdge(graph,1,2,10);
    addEdge(graph,1,0,10);
    addEdge(graph,2,3,10);
    addEdge(graph,0,3,40);
    addEdge(graph,3,4,2);
  
    addEdge(graph,4,5,3);
    addEdge(graph,5,6,3);
    addEdge(graph,4,6,8);

    // Gdisplay(graph);

    // BFS(graph,0);

    // cout<<isBipartite(graph);

    // Prims(graph);
    // Djikstra(graph,0);

   vector<string> s = gcc(graph);
   for(int i=0; s.size(); i++){
       cout<<s[i]<<endl;
   }

    return 0;
}