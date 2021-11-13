#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> mazepath(int sr, int sc,int dr,int dc){

   vector<string> paths;
   vector<string> nh;
   vector<string> nv;
 if(sr==dr && sc == dc){
     vector<string> bp;
     bp.push_back("");
     return bp;
 } 

  if(sr<dr){
     nv=mazepath(sr+1,sc,dr,dc);     
  }

  if(sc<dc){
      nh=mazepath(sr,sc+1,dr,dc);
  }
  for(int i=0;i<nh.size();i++){
      paths.push_back("h"+ nh[i]);
  }

  for(int i=0;i<nv.size();i++){
      paths.push_back("v"+ nv[i]);
  }
  return paths;
}

int main(int argc,char** argv){
    vector<string>res= mazepath(0,0,2,2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
