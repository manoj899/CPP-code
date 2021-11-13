#include<iostream>
#include<unordered_map>
#include<vector>

//#include<

using namespace std;

// auto hfc(string &word){

//     unordered_map<string,int> fmap;

//     for(int i=0;i<word.size();i++){

//     char ch = word[i];
//         if(fmap.count("word[i]")==0){

//             fmap["word[i]"]=1;
//         }
//         else{
//             fmap["word[i]"]=+1;
//         }
//     }

//     char mfc = 0;
//     for(auto itr=fmap.begin();itr != fmap.end();itr++){
//         if(itr->second>fmap[mfc]->second){
//             mfc=itr->second;
//         }
//     }cout<<mfc<<endl;
// }

//     for(auto itr =fmap.begin();itr !=fmap.end(); itr++){

//     cout<<itr->first<<" "<<itr->second<<endl;
//     }
// }

void pce1(vector<int>&one ,vector<int>& two){  //print common element

 unordered_map<int,int> pmap;

   for(int i=0;i<one.size();i++){

       pmap[one[i]]++;
   }

   for(int j=0;j<two.size();j++){

       if(pmap.count(two[j])==1)
       {cout<<two[j];
  pmap.erase(two[j]);     
   }
   cout<<" ";
}
}


void pce2(vector<int>&one ,vector<int>& two){
    
    unordered_map<int,int> pmap;

   for(int i=0;i<one.size();i++){

       pmap[one[i]]++;
   }

   for(int j=0;j<two.size();j++){

       if(pmap.count(two[j])==1 && pmap[two[j]]>0)
       {cout<<two[j];
  //pmap.erase(two[j]);   
  pmap[two[j]]--;  
   }
   cout<<" ";
}
}

void longconsearr(vector<int>& arr){

    unordered_map<int,bool> pmap;

    for(int i=0;i<arr.size();i++){
        pmap[arr[i],true];
    }

    for(in
}

int main(int argc,char** argv){
    // string s= "abbccddaccbdacdaba";
    // hfc(s);

    vector<int> a{2,1,5,1,3,2,1};
    vector<int> b{4,5,2,1,2,1,2};

  //  pce1(a,b);
    pce2(a,b);
}