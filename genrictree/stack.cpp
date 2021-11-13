#include<iostream>
#include<vector>
#include<list>
#include<string>



using namespace std;

  /* void fun(vector<int> &vect)      changes reflect back in vector if pass by reference 
  {
      vect.push_back(30);     output : 10,20,30
  } */
  /*
  void fun(vector<int> vect)    // take much time as copy will be creating :: to avoid copying reference is used 
  {
      vect.push_back(30);       // output : 10,20    if not then no changes will be seen:
  } 

  void fun(const vector<int>& vect)   //if dont want to reflect changes and avoid copying too then use const in by reference vector
  {
      vect.push_back(30);       // output : 10,20   
  } 



  int  main(int argc,char** argv){
      vector<int> vect;

      vect.push_back(10);
      vect.push_back(20);

      fun(vect);

      for(int i=0;i<vect.size();i++){
          cout<<vect[i]<<" ";
      } 
  }    */

  class node
{
    public:

    int data;
    vector<node*> children;
    node(int data){
        this->data=data;

    }
};

node* construct(vector<node> &dlist){

    node* ln;
    node* nn;
    vector<node*> nlist;

    for(int i=0;i<dlist.size();i++){
       
       if(dlist[i]==-1){

           nlist.pop_back();
       }else{
           nn= new node(dlist[i])
          
       }

       if(nlist.size()==0){
           root=nn;
           nlist.push_back(nn);
       }
       else{
          ln= nlist.back();
           ln->children.push_back(nn);

       }
       nlist.push_back(nn);

      
       
    }
}

  int main(int argc,char** argv){
  vector<int> dlist { 
      10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1
  };
   node* root = construct(dlist);

  }
 