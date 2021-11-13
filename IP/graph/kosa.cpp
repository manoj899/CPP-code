#include<iostream>
#include<vector>
#include<stack>
#include<list>

using namespace std;

class Edge
{
    public:
    int nbr;
     
    
};

vector<vector<Edge>> Graph;
vector<vector<Edge>> trans;

void addEdge(int src,int dest)
{
    Edge e1;
    e1.nbr = dest;
    Graph[src].push_back(e1);
}

void addEdge2(int src,int dest)
{
    Edge e1;
    e1.nbr = dest;
    trans[src].push_back(e1);
}

void DFS(int s,vector<bool>& visited,stack<int>& st)
 {
       visited[s] = true;

      for(int i=0; i< Graph[s].size(); i++)
      {   Edge ne = Graph[s][i];

         if(visited[ne.nbr] == false)
         {
             DFS(ne.nbr,visited,st);
         }
         
      }
      st.push(s);
      return; // if node ends or it is leaf node
}
 
void transpose()
{
       
    for(int i=0; i<Graph.size(); i++)
    {
        for(int j=0; j<Graph[i].size(); j++)
        {
             addEdge2(j,i);
        }
    }
}

void display(vector<vector<Edge>> g)
{
    for(int i=0; i<g.size(); i++)
    {  cout<<i<<"->";
        for(int j=0; j<g[i].size(); j++)
        {
            Edge ne = g[i][j];
            cout<<"["<<ne.nbr<<"],";
        }cout<<endl;
    }
}

void SCC()
{
     vector<bool> visited(5,false);
  stack<int> st;
    DFS(0,visited,st);

    //  vector<vector<int>> trans;
    transpose();

    display(Graph);

    cout<<"******"<<"\n";
    display(trans);

}

int main(int argc,char** argv)
{
       
     Graph.push_back(vector<Edge>());
     Graph.push_back(vector<Edge>());
     Graph.push_back(vector<Edge>());
     Graph.push_back(vector<Edge>());
     Graph.push_back(vector<Edge>());

    addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4); 

  
     void SCC();



}