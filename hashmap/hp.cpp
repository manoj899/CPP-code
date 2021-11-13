#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(int argc,char** argv){

    unordered_map<int ,int>mp;

    mp[1]=10;
    mp[2]=20;
    mp[3]=30;
    mp[4]=40;
    mp[5]=50;
    mp[6]=60;

 /*  mp.insert(pair<int,int>(1,7));
   mp.insert(pair<int,int>(2,8));
   mp.insert(pair<int,int>(3,8));
    
   mp.insert(pair<int, int>(4, 20)); 
   mp.insert(pair<int, int>(5, 50)); 
   mp.insert(pair<int, int>(6, 50)); 
   mp.insert(pair<int, int>(7, 10));
*/
  //  map<int,int> itr;
     cout << "\nThe mapmp is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for(auto itr=mp.begin();itr<mp.end(); itr++){
        cout<<"\t"<<itr->first<<"\n";
        cout<<"\t"<<itr->second<<"\n";
    }
    cout<<endl;

}