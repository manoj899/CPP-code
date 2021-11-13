#include<iostream>
#include<vector>
#include<string>

 using namespace std;
 
vector<string> gsp2(vector<int>& src){
  vector<string> stod;
       if(src == 0){
           vector<string> bp;
           bp.push_back("");
           return bp; 
       }

  for(int step=1;step<=3;step++){
    if(src-step > 0){
      int nbr = src - step;
      vector<string> ntod = gsp(nbr);

     for(int i=0;i<ntod.size();i++){

        string ntodpath = ntod[i];
        string stodpath = to_string(step) + ntodpath;
        stod.push_back(stodpath);
     }
    }
  }
   
 }

int main(int argc,char** argv){

vector<string> arr={3,2,0,4,1,2,0,1};
  gsp2(arr);
}