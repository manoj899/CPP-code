#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<climits>

using namespace std;

class Edge
{
    public:
    int nbr;
    int wt;

    
};

vector<vector<Edge>> Graph;

void addEdge(int v1,int v2, int wt)
{
  Edge e1;
  e1.nbr = v2;
  e1.wt = wt;
  Graph[v1].push_back(e1);

  Edge e2;
  e2.nbr = v1;
  e2.wt = wt;
  Graph[v2].push_back(e2);   
}

void addEdge(vector<vector<Edge>> &g,int v1,int v2, int wt)
{
  Edge e1;
  e1.nbr = v2;
  e1.wt = wt;
  g[v1].push_back(e1);

  Edge e2;
  e2.nbr = v1;
  e2.wt = wt;
  g[v2].push_back(e2);   
}


class Dpair
{   public:

    int v;
    int c;
    string p;

    Dpair(int v,int c,string p)
    {  
       
        this->v = v;
        this->c = c;
        this->p = p;
    }

    bool operator>(const Dpair& other) const
    {
        return this->c > other.c;
    }
};

void Dijkstra(int s)
{
    priority_queue<Dpair,vector<Dpair>,greater<Dpair>> pq;
    Dpair rtp(s, 0, to_string(s));
    pq.push(rtp);

    vector<bool> visited(Graph.size(),false);

    while(pq.size() >0)
    {
        Dpair rem = pq.top();
        pq.pop();

        if(visited[rem.v] == true)
        {
            continue;
        }

        visited[rem.v] = true;

        cout<<rem.v<<"@"<<rem.c<<"via"<<rem.p<<endl;
        for(int i=0; i<Graph[rem.v].size(); i++)
        {
            Edge ne  = Graph[rem.v][i];

            if(visited[ne.nbr] == false)
            {
                Dpair np(ne.nbr, rem.c+ne.wt, rem.p + to_string(ne.nbr));
                pq.push(np);
            }
        }
    }
}

void display(vector<vector<Edge>>& g)
{
    for(int v = 0; v < g.size(); v++)
    {
        cout << v << " -> ";
        for(int n = 0; n < g[v].size(); n++)
        {
            Edge ne = g[v][n];
            cout << "[" << ne.nbr << "-" << ne.wt << "], ";
        }
        cout << "." << endl;
    }
}

class Ppair
{
     public:
    int av;
    int c;
    int v;

     Ppair(int v, int av, int c){

        this->v = v;
        this->av= av;
        this->c = c;
    }
  
   bool operator>(const Ppair& other) const
    {
        return this->c >other.c;
    }
};

void Prims()
{
    vector<vector<Edge>> MST(Graph.size(), vector<Edge>());
    vector<bool> visited(Graph.size(),false);

    priority_queue<Ppair,vector<Ppair>,greater<Ppair>> pq;
    Ppair rp(0,-1,0);
    pq.push(rp);
    while(pq.size() >0)
    {
        Ppair rem = pq.top();
        pq.pop();

        if(visited[rem.v] == true)
        {
            continue;
        }

        visited[rem.v] = true;

        if(rem.av != -1)
        {
            addEdge(MST,rem.v,rem.v, rem.c);
        }

        for(int n=0; n<Graph[rem.v].size(); n++)
        {
            Edge ne = Graph[rem.v][n];

            if(visited[ne.nbr] == false)
            {
                Ppair np(ne.nbr,rem.v, ne.wt);
                pq.push(np);
            }
        }
    }
    display(MST);
}

int find(int pa[],int v)
{
    if(pa[v] == v)
    {
        return v;
    }
    else{
        int s1 = find(pa,pa[v]);
        return s1;
    }
}

void Union(int pa[],int ra[],int x,int y)
{
    if(ra[x]< ra[y]){
        pa[x]=y;
    }
    else if(ra[x]>ra[y])
    {  pa[y] = y;
    }
    else{
        pa[y] = x;
        ra[x]++;
    }
}

class Khelper{
    public:
    int v1;
    int v2;
    int wt;
   
    Khelper(int v1,int v2, int wt)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->wt = wt;
    }

    bool operator>(const Khelper& other ) const
    {/* const Dpair &other  
       here datatype of parameter is class type so the passed variable is object bydefault
          which will act as 2nd object and can be compared */
        return this-> wt > other.wt;
    }
};


 void Krushkal(){
 vector<vector<Edge>> MST(Graph.size(), vector<Edge>());  
    // vector<bool> visited(Graph.size(),false);
    int pa[Graph.size()];
    int ra[Graph.size()];
     
     for(int i=0;i<Graph.size(); i++)
     {
         pa[i] = i;
         ra[i] = 1;
     }

    priority_queue<Khelper,vector<Khelper>,greater<Khelper>> pq;

    for(int v=0;v<Graph.size();v++)
    {  for(int n=0; n<Graph[v].size(); n++){
        Edge ne = Graph[v][n];
        if(v<ne.nbr){
            Khelper ke = Khelper(v,ne.nbr,ne.wt);
            pq.push(ke);
        } 
    }
    }

    int count =0;
    while(pq.size()>0 && count<Graph.size()-1){
        Khelper ke = pq.top();
        pq.pop();
        int x = find(pa,ke.v1);
        int y = find(pa,ke.v2);

        if(x != y){
            addEdge(MST,ke.v1, ke.v2, ke.wt);
            Union(pa,ra,x,y);
        }
    }
    display(MST);
}

// output of krushkal is not right


int main(int argc,char** argv)
{    
    Graph.push_back(vector<Edge>());
    Graph.push_back(vector<Edge>());
    Graph.push_back(vector<Edge>());
    Graph.push_back(vector<Edge>());
    Graph.push_back(vector<Edge>());
    Graph.push_back(vector<Edge>());
    Graph.push_back(vector<Edge>());


    addEdge(0,1,10);
    addEdge(1,2,10);
    addEdge(2,3,10);
    addEdge(0,3,40);
    addEdge(3,4,2);
    addEdge(4,5,3);
    addEdge(5,6,3);
    addEdge(4,6,8);

    // Dijkstra(0);
    // cout<<endl<<"\n";
    // Prims();
    Krushkal();
}