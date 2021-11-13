#include<iostream>
#include<vector>
#include<climits>
#include<list>

using namespace std;

class Edge
{
    public:
        int n;
        int w;

        Edge(int n, int w)
        {
            this->n = n;
            this->w = w;
        }
};

void addEdge(vector<vector<Edge>>& graph, int v1, int v2, int wt)
{
    graph[v1].push_back(Edge(v2, wt));
    graph[v2].push_back(Edge(v1, wt));
}

void display(vector<vector<Edge>>& graph)
{
    cout << "--------------------" << endl;
    for(int v = 0 ; v < graph.size(); v++)
    {
        cout << v << "-> ";
        for(int n = 0; n < graph[v].size(); n++)
        {
            Edge ne = graph[v][n];
            cout << "[" <<v <<"-"<<ne.n << "@" << ne.w << "] ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}


bool hasPath(vector<vector<Edge>>& graph, int src, int dest, 
             vector<bool>& visited)
{
    if(src == dest)
    {
        return true;
    }
    
    visited[src] = true;
    for(int n = 0; n < graph[src].size(); n++)
    {
        Edge ne = graph[src][n];
        if(visited[ne.n] == false)
        {
            if(hasPath(graph, ne.n, dest, visited) == true)
            {
                return true;
            }
        }
    }

    return false;
}

void printAllPaths(vector<vector<Edge>>& graph, int src, int dest, 
                   vector<bool>& visited, string psf)
{
    if(src == dest)
    {
        cout << psf << dest << endl;
        return;
    }
    
    visited[src] = true;
    for(int n = 0; n < graph[src].size(); n++)
    {
        Edge ne = graph[src][n];
        if(visited[ne.n] == false)
        {
            printAllPaths(graph, ne.n, dest, visited, psf + to_string(src));
        }
    }
    visited[src] = false;
}

string sp = "";
int spd = INT_MAX;
string lp = "";
int lpd = INT_MIN;
string cp = "";
int cpd = INT_MAX;
string fp = "";
int fpd = INT_MIN;
void printAllPaths_Inc(vector<vector<Edge>>& graph, int src, int dest, 
                   vector<bool>& visited, string psf, int dsf, int factor)
{                                                  // ask this function to unerstand
    if(src == dest)
    {
        cout << psf << "@" << dsf <<  endl;
        if(dsf < spd)
        {
            spd = dsf;
            sp = psf;
        }                            
        if(dsf > lpd)
        {
            lpd = dsf;
            lp = psf; 
        }
        if(dsf > factor && dsf < cpd)
        {
            cpd = dsf;
            cp = psf;
        }
        if(dsf < factor && dsf > fpd)
        {
            fpd = dsf;
            fp = psf;
        }
        return;
    }
    
    for(int n = 0; n < graph[src].size(); n++)
    {
        Edge ne = graph[src][n];
        if(visited[ne.n] == false)
        {
            visited[ne.n] = true;
            printAllPaths_Inc(graph, ne.n, dest, visited, psf + to_string(ne.n), 
                              dsf + ne.w, factor);
            visited[ne.n] = false;
        }
    }
}

void kthLargest(vector<vector<Edge>>& graph, int src, int dest, int k)
{
    vector<bool> visited(graph.size(), false);
    string kpath = "";
    int limit = INT_MAX;

    for(int i = 0; i < k; i++)
    {
        fp = "";
        fpd = INT_MIN;
        visited[src] = true;
        string psf;
        printAllPaths_Inc(graph, src, dest, visited, psf + to_string(src), 0, limit);
        
        limit = fpd;
        kpath = fp;
    }
}


class FHelper 
{
    public:
        int i;
        int j;
        int t;

        FHelper(int i, int j, int t)
        {
            this->i = i;
            this->j = j;
            this->t = t;
        }
};

bool isValid(vector<vector<int>>& matrix, int i, int j)
{
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
    {
        return false;
    }
    else if(matrix[i][j] == -1)
    {
        return false;
    }
    else if(matrix[i][j] >= 0)
    {                         // portion where fire allready exist
        return false;
    }
    else
    {
        return true;
    }
}

// -2 is normal, -1 is water, 0 is fire 
void firestorm(vector<vector<int>> matrix)
{
    list<FHelper> queue;
    
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                queue.push_back(FHelper(i, j, 0));  // ask what does it mean
            }
        }
    }

    while(queue.size() > 0)
    {
        FHelper rem = queue.front();
        queue.pop_front();

        if(matrix[rem.i][rem.j] > 0)
        {
            continue;
        }
        else
        {
            matrix[rem.i][rem.j] = rem.t;
        }

        cout << rem.i << rem.j << " burnt at " << rem.t << endl;
        if(isValid(matrix, rem.i - 1, rem.j))
            queue.push_back(FHelper(rem.i - 1, rem.j, rem.t + 1));

        if(isValid(matrix, rem.i + 1, rem.j))
            queue.push_back(FHelper(rem.i + 1, rem.j, rem.t + 1));

        if(isValid(matrix, rem.i, rem.j - 1))
            queue.push_back(FHelper(rem.i, rem.j - 1, rem.t + 1));

        if(isValid(matrix, rem.i, rem.j + 1))    
            queue.push_back(FHelper(rem.i, rem.j + 1, rem.t + 1));
    }
}

string getconnnectedcomponent(vector<vector<Edge>>& graph, 
                              vector<bool>& visited, 
                              int src)
{
    string comp;

    list<int> queue;
    queue.push_back(src);
    while(queue.size() > 0)
    {
        int rem = queue.front();
        queue.pop_front();

        if(visited[rem] == true)
            continue;
        else                                  // ask sahil
            visited[rem] = true;
        
        comp += to_string(rem);
        for(int n = 0; n < graph[rem].size(); n++)
        {
            Edge ne = graph[rem][n];
            cout << ne.n <<"-"<<ne.w<<endl;
            if(visited[ne.n] == false)   // make graph of this loop
            {
                queue.push_back(ne.n);
            }
        }
    }

    return comp;
}

vector<string> getconnectedcomponents(vector<vector<Edge>>& graph)
{
    vector<string> comps;
    vector<bool> visited (graph.size(), false);

    for(int v = 0; v < graph.size(); v++)
    {
        if(visited[v] == false)
        {
            string comp = getconnnectedcomponent(graph, visited, v);
            comps.push_back(comp);
        }
    }

    return comps;
}

bool isValidForIslands(vector<vector<int>>& matrix, int i, int j)
{
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
    {
        return false;
    }
    else if(matrix[i][j] == -1)
    {
        return false;
    }
    else if(matrix[i][j] > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void islandscomp(vector<vector<int>>& matrix, int i, int j)
{
    int tc = matrix[0].size();
                                    // ask sahil
    list<int> queue;
    queue.push_back(i * tc + j);   //this line ask 

    while(queue.size() > 0)
    {
        int rem = queue.front();
        queue.pop_front();

        if(matrix[rem / tc][rem % tc] > 0)
        {
            continue;
        }
        else
        {
            matrix[rem / tc][rem % tc] = 1;
        }

        if(isValidForIslands(matrix, rem / tc - 1, rem % tc))
            queue.push_back(rem - tc);

        if(isValidForIslands(matrix, rem / tc + 1, rem % tc))
            queue.push_back(rem + tc);

        if(isValidForIslands(matrix, rem / tc, rem % tc - 1))
            queue.push_back(rem - 1);

        if(isValidForIslands(matrix, rem / tc, rem % tc + 1))    
            queue.push_back(rem + 1);

    }
}

int islands(vector<vector<int>> matrix)
{
    int count = 0;

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                islandscomp(matrix, i, j);
                count++;
            }
        }
    }

    return count;
}

bool isCyclicComponent(vector<vector<Edge>>& graph, 
                              vector<bool>& visited, 
                              int src)
{
    list<int> queue;
    queue.push_back(src);
    while(queue.size() > 0)
    {
        int rem = queue.front();
        queue.pop_front();

        if(visited[rem] == true)
            return true;
        else
            visited[rem] = true;
        
        for(int n = 0; n < graph[rem].size(); n++)
        {
            Edge ne = graph[rem][n];
            if(visited[ne.n] == false)
            {
                queue.push_back(ne.n);
            }
        }
    }

    return false;
}

bool isCyclic(vector<vector<Edge>>& graph)
{
    vector<bool> visited (graph.size(), false);

    for(int v = 0; v < graph.size(); v++)
    {
        if(visited[v] == false)
        {
            bool res = isCyclicComponent(graph, visited, v);
            if(res == true)
            {
                return true;
            }
        }
    }

    return false;
}

vector<int> getccforastronauts(vector<vector<Edge>>& graph, 
                              vector<bool>& visited, 
                              int src)
{
    vector<int> comp;

    list<int> queue;
    queue.push_back(src);
    while(queue.size() > 0)
    {
        int rem = queue.front();
        queue.pop_front();

        if(visited[rem] == true)
            continue;
        else
            visited[rem] = true;
        
        comp.push_back(rem);
        for(int n = 0; n < graph[rem].size(); n++)
        {
            Edge ne = graph[rem][n];
            if(visited[ne.n] == false)
            {
                queue.push_back(ne.n);
            }
        }
    }

    return comp;
}

vector<vector<int>> getccsforastronauts(vector<vector<Edge>>& graph)
{
    vector<vector<int>> comps;
    vector<bool> visited (graph.size(), false);

    for(int v = 0; v < graph.size(); v++)
    {
        if(visited[v] == false)
        {
            vector<int> comp = getccforastronauts(graph, visited, v);
            comps.push_back(comp);
        }
    }

    return comps;
}

int astronauts(vector<int> a1, vector<int> a2, int n)
{
    vector<vector<Edge>> graph (n);

    for(int i = 0; i < a1.size(); i++)
    {
        addEdge(graph, a1[i], a2[i], 1);
    }

    int sum = 0;
    vector<vector<int>> comps = getccsforastronauts(graph);
    for(int n1 = 0; n1 < comps.size(); n1++)
    {
        for(int n2 = n1 + 1; n2 < comps.size(); n2++)
        {
            int teams = comps[n1].size() * comps[n2].size();
            sum += teams;
        }
    }

    return sum;
}

class BHelper
{
    public:
        int v;
        int level;

        BHelper(int v, int level)
        {
            this->v = v;
            this->level = level;
        }
};

bool isBipartiteComponent(vector<vector<Edge>>& graph, 
                              vector<int>& visited, 
                              int src)
{
    list<BHelper> queue;
    queue.push_back(BHelper(src, 0));
    while(queue.size() > 0)
    {
        BHelper rem = queue.front();
        queue.pop_front();

        if(visited[rem.v] != -1)
        {
            // cycle, something to think over
            if(visited[rem.v] % 2 != rem.level % 2)
            {
                return false;
            }
            continue;
        }
        else
            visited[rem.v] = rem.level;
        
        for(int n = 0; n < graph[rem.v].size(); n++)
        {
            Edge ne = graph[rem.v][n];
            if(visited[ne.n] == -1)
            {
                queue.push_back(BHelper(ne.n, rem.level + 1));
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<Edge>>& graph)
{
    vector<int> visited (graph.size(), -1);

    for(int v = 0; v < graph.size(); v++)
    {
        // if(visited[isBipartiteComponent] == -1)
        {
            bool res = (graph, visited, v);
            if(res == false)
            {
                return false;
            }
        }
    }

    return true;
}
/*
void hamiltonian(vector<vector<Edge>& graph){
    vector<bool> visited(graph.size(),false);

    if(psf.size()== graph.size()-1)
    {
        for(int i=0;i<psf.size();i++){
            cout<<psf[i]<<" ";
        }
        cout<<src<<" ";

    }  
        int first = psf[0];
        int last =src;

        bool cycle = false;
        for(int i=0;i<graph.size[first].size();i++){
            Edge ne = graph[first][i];
            if(ne.n == false){
                cycle = true;
            }
        }
}

void hamiltonhelper(int src,vector<int>& psf,vector<vector<Edge>>& graph, vector<bool> visited){

   
    visited[src] = true;

    for(int n=0;n<graph[src].size();n++){
        Edge ne =graph[src][n];
        if(visited[ne.n]== false){
            hamiltonhelper(ne.n,psf,graph,visited)
        }
    }
    visited[src] = false;
}


bool isValid(vector<vector<int> chess,int row,int col){

      if(row<0 || row >= chess.size() || col >=chess.size()){
          return false;
      }
      else if(chess[row][col]!=-1){
          return false;
      }
      else {
          return true;
      }
    
}

void knightour(vector<vector<int>& chess,int row,int col ,int mov){
      
       if(move == chess.size()-1){
          chess [row][col] = move;
      }

    if(isValid(chess,row-2,col+1))
    {knightour((chess,row-2,col+1,move +1));
    }
    if(isValid(chess,row-2,col-1))
    {knightour((chess,row-2,col-1,move +1));
    }
    if(isValid(chess,row+2,col+1))
    {knightour((chess,row+2,col+1,move +1));
    }
    if(isValid(chess,row+2,col-1))
    {knightour((chess,row+2,col-1,move +1));
    }
    if(isValid(chess,row+1,col+2))
    {knightour((chess,row+1,col+2,move +1));
    }
    if(isValid(chess,row-1,col+2))
    {knightour((chess,row-1,col+2,move +1));
    }
    if(isValid(chess,row+1,col-2))
    {knightour((chess,row+1,col-2,move +1));
    }
    if(isValid(chess,row-1,col-2))
    {knightour((chess,row-1,col-2,move +1));
    }
    
    chess[row][col]=0;

    cout<<"--------------------------"<<endl;

    if(move == chess.size())

    chess[row][col] = move;

    for(int i=0;i< chess.size();i++){
        for(int j=0;j< chess[i].size();j++){
           cout<< chess[i][j]<<" ";
        }
        cout<<endl;
    }
    chess[row][col] =-1;

    cout<<"---------------------------"<<endl;
    return;
} */
/*
void floydwarshall(vector<vector<Edge>>& graph){
    vector<vector<int>> res{ graph.size()}
    vector<int> graph.size(),INT_MAX}

    // t=0, all path with intermediate 0

    for(int i=0;i< graph.size();i++){

        for(int =0;n<graph[i].size();n++){
            Edge ne = graph[i][j];
            res[i][ne.n] = ne.w;
        }
    }

    for(int i=0;i< graph.size();i++){

        for(int =0;n<graph[i].size();n++){
            for(int d=0; d<gr.size();d++)
            {
                if(i== s ||i== d|| s ==d){
                    continue;
                }
                else if(res[i][d] == INT_MAX){
                    continue;
                }
                else if(res[s][i] + res[i][d] < res[s][d]){
                    res[s][d] =res[s][i] + res[i][d];
                }
        }    }    }

    }
    for(int s=0;s<graph.size();s++){
        for(int d=0;d<graph.size(); d++){
            cout<<res[s][d]<<" ";
        }
    }
}  */

int main(int argc, char** argv)
{
    vector<vector<Edge>> graph(7);
    // for(int v = 0; v < 7; v++)
    // {
    //     graph.push_back(vector<Edge>());
    // }

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 0, 3, 40);
    //addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
   vector<string> comp=  getconnectedcomponents(graph);
   for(int i=0;i<comp.size();i++){
       cout<<comp[i]<<endl;
   }
    //display(graph);
    // addEdge(graph, 2, 5, 5); //edge added

    // cout << isCyclic(graph) << endl;
  //  cout << isBipartite(graph) << endl;

    // // display(graph);
 ////////////////////////////////////////////////
    //   vector<bool> visited(graph.size(), false);
    //   string psf = "";
    //  // printAllPaths(graph, 0, 6, visited, psf);
    
    //  visited[0] = true;
    //  printAllPaths_Inc(graph, 0, 6, visited, psf + "0", 0, 51);
    //  //////////////////////////////////////////////////////////
    // cout << "Smallest -> " << sp << "@" << spd << endl;
    // cout << "Largest -> " << lp << "@" << lpd << endl;
    // cout << "Ceil -> " << cp << "@" << cpd << endl;
    // cout << "Floor -> " << fp << "@" << fpd << endl;

    // vector<vector<int>> matrix = {
    //     {-2, -2, 0, -2, -2, -2},
    //     {-2, -1, -1, -2, -1, -1},
    //     {-2, -2, -1, -2, -2, -2},
    //     {-2, -2, -2, -2, -1, -1},
    //     {-2, -1, -1, 0, -2, -2}
    // };
    // firestorm(matrix);

    // vector<vector<int>> arr = {
    //     {0, 0, -1, 0, 0},
    //     {0, -1, -1, -1, -1},
    //     {-1, 0, 0, 0, 0},
    //     {0, -1, 0, -1, 0},
    //     {0, -1, -1, -1, 0}
    // };
    // cout << islands(arr);

 //   vector<int> a1 {1, 6, 8, 2, 9, 10, 0};
  //  vector<int> a2 {2, 9, 3, 5, 5, 3, 11};
   // cout << astronauts(a1, a2, 12) << endl;

//    vector<vector<Edge> fwg(4);
//    fwg[0].push_back(Edge(1,2));
//    fwg[0].push_back(Edge(3,8));
//    fwg[0].push_back(Edge(2,4));
//    fwg[1].push_back(Edge(2,1));
//    fwg[1].push_back(Edge(3,5));
//    fwg[2].push_back(Edge(3,1));
//    floydwarshall(fwg);

}












