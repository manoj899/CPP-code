#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


void pce(vector<int> &one,vector<int>& two){

    unordered_map<int,int> fmap;

    for(int  itr=0;itr<one.size();itr++){

        fmap[one[itr]]++;
    
    }

    for(int  i=0;i<two.size();i++){

        if(fmap.count(two[i])== 1){

     cout<<two[i];
     fmap.erase(two[i]);

    }
    cout<<endl;

    }

}

void pce2(vector<int> &one,vector<int>& two){

    unordered_map<int,int> fmap;

    for(int  itr=0;itr<one.size();itr++){

        fmap[one[itr]]++;
    
    }

    for(int  i=0;i<two.size();i++){

        if(fmap.count(two[i])== 1 && two[i]>0){

     cout<<two[i];
     fmap[(two[i])]--;

    }
    cout<<" ";

    }
}


  lca(vector<int>& arr){   // longest common array
      
      unordered_map<int,int> map;

      for(int i=0;i< arr.size();i++){
         map[arr[i]]= 1;
      }
     
      for(auto p: map){

        if(map.count(p.first -1)> 0){ // map.count(p.first -1) ==1)
          map[p.first] =0;   //marking it false
        }
      }

      int gc=1;
      int ts = -1; // total size
      for(auto p:map){
        int lc=1;
        if(p.second >0){

          while(map.count(p.first + lc)>0){
            lc++;
          }
        }

        if(lc>gc){
          gc=lc;
          ts = p.first;
        }
      }

      while(gc>0){
        cout<<ts<<" ";
        ts+=1;
        gc--;
      }

   }


int main(int argc,char** argv){

  vector<int> a{2,1,5,1,3,2,1};
  vector<int> b{4,5,2,1,2,1,2};
  // pce(a,b);
  //  pce2(a,b);

   vector<int> c{11,3,5,9,12,2,6,8,1,10,15,25,20,16};
   lca(c);
}