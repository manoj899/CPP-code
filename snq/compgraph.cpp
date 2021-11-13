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
    //int v2;

    Edge(int n,int w){
        this-> n=n;
        this-> w=w;
    }
};

void addEdge(vector<vector<Edge>>& graph,int v1,int v2,int w){

    graph[v1].push_back(Edge(v2,w));
    graph[v2].push_back(Edge(v1,w));
}

void display(vector<vector<Edge>>& graph){

  
   
    for(int i=0;i<graph.size();i++){
  cout<<i<<"->";
        for(int v=0;v<graph[i].size();v++){
             Edge ne=graph[i][v];
            cout<<ne.n<<" ";
      
        }
        cout<<endl;
    }
}

 void allpaths(vector<vector<Edge>>& graph ,int src,int dest,vector<bool>& visited,string psf){
   
  if(src == dest){
      cout<<psf<<dest<<endl;
     // return true;
  }
  
     visited[src]= true;
  for(int i=0;i<graph[src].size();i++){
       Edge ne= graph[src][i];
       
       if(visited[ne.n] == false){
           allpaths(graph,ne.n,dest,visited, psf + to_string(src));
           
       }
        
    }
    visited[src] = false;
}  

 string getconnectedcompnent(vector<vector<Edge>>& graph,int src,vector<bool>& visited){
    
    list<int> queue;
    queue.push_back(src);
   string comp;

    while(queue.size()>0){
      
       int rem=queue.front();
       queue.pop_front();

        if(visited[rem]== true){
            continue;
        }else{
            visited[rem] = true;
        }
      comp += to_string(rem);

  
        for(int n=0;n< graph[rem].size();n++){

             Edge ne = graph[rem][n];
                cout<<"neighbour "<<ne.n<< " wt "<<ne.w<<endl;
            if(visited[ne.n]== false){


                queue.push_back(ne.n);
             
            }
            
        }
    }

    return comp;
    
}

  void getconnectedcompnents(vector<vector<Edge>>& graph){

   vector<string> comps;
   vector<bool> visited(graph.size(),false);
  string comp;
    for(int v=0;v<graph.size();v++){
        
         if(visited[v]== false)
       comp=getconnectedcompnent(graph,v,visited);
        comps.push_back(comp);
    }


     for(int i=0;i<comps.size();i++)
   { cout<<comps[i]<<endl;
   }

  }


    string sp="";
    int spd = INT_MAX;
    string lp = "";
    int lpd = INT_MIN;
    string cp ="";
    int cpd = INT_MIN;
    string fp="";
    int fpd = INT_MAX;

    // allpaths_inc(vector<vector<Edge>>& graph,int src,psf + to_string(src),){

    //     if(sp>psf){
    //         sp=psf;
    //         spd = dsf;
    //     }

    //     if(lp<psf){

    //         lp= psf;
    //         lpd = dsf;

    //     }
    //     if()
    // }

   /* class Fhelper{
  public:
        int i;
        int j;
        int t;

        Fhelper(int i,int j,int t){

            this-> i=i;
            this-> j=j;
            this->t=t;
        }
    };

    bool isvalid(vector<vector<int>>& matrix,int i,int j){
   
     

        if(i< 0 || j<0 || i> matrix.size() || j>matrix[0].size() ){

            return false;
        }else
        if( matrix[i][j] == -1){
            return false;
        }
        else if (matrix[i][j]>=0){
            return false;
        }
        else{
             return true;
        }

    }

   void firestorm(vector<vector<int>> matrix){

      list<Fhelper> queue ;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j< matrix[i].size();j++){
              if(matrix[i][j]==0){

                queue.push_back(Fhelper(i,j,0));
                
                }
            }
        }

      while(queue.size() > 0)
           {
        Fhelper rem = queue.front();
        queue.pop_front();
                                                   // ask is not working right ;
        if(matrix[rem.i][rem.j] > 0)
        {
            continue;
        }
        else
        {
            matrix[rem.i][rem.j] = rem.t;
        }

        cout << rem.i << rem.j << " burnt at " << rem.t << endl;
        if(isvalid(matrix, rem.i - 1, rem.j))
            queue.push_back(Fhelper(rem.i - 1, rem.j, rem.t + 1));

        if(isvalid(matrix, rem.i + 1, rem.j))
            queue.push_back(Fhelper(rem.i + 1, rem.j, rem.t + 1));

        if(isvalid(matrix, rem.i, rem.j - 1))
            queue.push_back(Fhelper(rem.i, rem.j - 1, rem.t + 1));

        if(isvalid(matrix, rem.i, rem.j + 1))    
            queue.push_back(Fhelper(rem.i, rem.j + 1, rem.t + 1));
        }
    }    
   /*class islands
   {
       int i;
       int j;

       islands(int k,int l){
           this->i=k;
           this-> j=l;
       }
   };

   
   noislands(vector<vector<int>>& arr){

       list<arr> queue;


      for(int i=0;i<arr.size();i++){
          for(int j=0;j<arr[i].size();j++){
              queue.push_back(islands(i,j));
          }
      }
      
      

       while(queue.size()>0){
          arr rem = queue.front();
         queue.pop_front();

         if(rem.n == true){
             continue;
         }
         else{
              
         }

       }
   }  
  */
  void topolgical_sort(vector<vector<Edge>>& graph,vector<bool>& visited,stack<int> st,int src){

      visited[src] =true;

      for(int i=0;i<graph[src].size();i++){

          Edge ne=graph[src][i];

          if(ne.n== false){
              topolgical_sort( graph, visited,st,ne.n);
          }
      }
      st.push(src);
  }

  void topo_sort(vector<vector<Edge>>& graph){
      vector<bool> visited(graph.size(),false);
  stack<int> st;
      for(int v=0;v<graph.size();v++){

          if(visited[v]== false){

              topolgical_sort(graph,visited,st,v);
          }

      }
      while(st.size()>0){

        cout<<st<<" ";
        st.pop();
      }
  }


  void bridgesAndAPS(vector<vector<Edge>>& graph,vector<bool>& visited,vector<bool>& visited,vector<bool>& aps,
                   vector<int>& discovery,vector<int>& low,int par,int src){
                       int counter =0;
                       visited[src] = true;
                       discovery[src] = low[src ] += timer;

                       for(int n=0;n<graph[src].size();n++){
                           Edge ne = graph[src][n];
                           int nbr =ne.n;
                       } 

                       if(visited[nbr] == true && nbr !=par){
                           low[src]= min(low[src],discovery[nbr]);
                       }
                       else{
                           bridgesAndAPS(graph,visited,aps,discovery,low,src,nbr);
                           counter++;
                           //update low
                           low[src]= min(low[src],low[nbr]);
                           if(counter>=2){
                               aps[src]= true;
                           }
                           else if(low[nbr]>= discovery[src])
                           {
                               aps[src]= true;

                           }

                           // define bridges
                           if(low[nbr]>discovery[src]){
                               cout<<"bridges from"<<src<<"to"<<nbr<<
                           }
                       }
                   }

                   */
int main(int argc,char** argv){
        
        vector<vector<Edge>> graph(7);

        for(int i=0;i<7;i++){
            graph.push_back(vector<Edge>()); // ask   we can mention 

        } 


    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 0, 3, 40);
    //addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);

   // display(graph);


     //vector<bool> visited(graph.size(),false);
         getconnectedcompnents(graph);
    // string psf=" ";
    // allpaths(graph , 0, 6,visited,psf);
    //cout<<"\n"<<d<<endl;
    //   vector<vector<int>> matrix = {
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

//   vector<vector<Edge>> graph(7);

//     graph[0].addEdge(1,1);
//     graph[0].addEdge(4,1);
//     graph[0].addEdge(2,1);
//     graph[0].addEdge(3,1);
//     graph[0].addEdge(3,1);
//     graph[0].addEdge(6,1);
//     graph[0].addEdge(4,1);
//     topo_sort(graph);
}