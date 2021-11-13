#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> gmp2(int sr, int sc,int dr,int dc){

   vector<string> stod;
   vector<string> nh;
   vector<string> nv;
   vector<string> nd;
 if(sr==dr && sc == dc){
     vector<string> bp;
     bp.push_back("");
     return bp;
 } 

   for(int ms =1;ms<=dc-sc;ms++){
       vector<string> ntod = gmp2(sr,sc+ms,dr,dc);
       for(int i=0;i<ntod.size();i++){
           stod.push_back("h"+ to_string(ms)+ ntod[i]);
       }
   }
   
   for(int ms =1;ms<=dr-sr;ms++){
       vector<string> ntod = gmp2(sr+1,sc,dr,dc);
       for(int i=0;i<ntod.size();i++){
           stod.push_back("v"+ to_string(ms)+ ntod[i]);
       }
   }
   
   for(int ms =1;ms<=dc-sc && ms<= dr-sr;ms++){
      
       vector<string> ntod = gmp2(sr,sc+ms,dr+1,dc);
       for(int i=0;i<ntod.size();i++){
           stod.push_back("d"+ to_string(ms)+ ntod[i]);
       }
   }

  return stod;
}

int main(int argc,char** argv){
    vector<string>res= gmp2(0,0,2,2);
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
