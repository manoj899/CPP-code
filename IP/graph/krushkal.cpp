#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<climits>

using namespace std;

class Edge{
        int src,dest,wt;
    };

class Graph
{
    public:
    int V,E; // no of vertices and edges

    Edge* edges;

};

Graph* createGraph(int V,int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

class subset
{
    public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
    // path compression
    if(subsets[i].parent !=i)
      subsets[i].parent = find(subsets, subsets[i].parent);
   
   return subsets[i].parent;
}

void Union(subset subset[], int x, int y)
{
    int a = find(subsets, x);
    int b = find(subsets,y);

    if(subsets[a].rank < subsets[b].rank)
        subsets[a].parent = b;
    else if(subsets[a].rank > subsets[b].rank)
    subsets[b].parent = a;

    else{    // If ranks are same, then make one as root and  
    // increment its rank by one 
        
         subsets[b].parent = a;
         subsets[a].rank++;
    }     
}

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->wt > b1->wt;
}

void KrushkalMST(Graph* graph)
{
    int V = graph->V;

    Edge result[V];
    int e =0;
    int i =0;

    qsort(graph->edge,graph->E, sizeof(graph->edge[0]), myComp);

    subset *subsets = new subset[(V* sizeof(subset))];

    // Create V subsets with single elements  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    } 

}