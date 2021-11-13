#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<string> substring(vector<string>& s){
       
        if(s.size()==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
        }
    char ch= s[0];
    string ros= s.substr(1,s.length());
    vector<string> rres=substring(ros);
    vector<string> mres;

   
    for(int i=0;i<rres.size();i++){
           string rstr = rres[i];
           mres.push_back("-"+rstr);
           mres.push_back("ch"+rstr);
    }
    return mres;
}




int main(int argc,char** argv){
  string str="abcd";
  //cout<<str.substr(1,str.size());
  vector<string>v= substring(str);
  for(int i=0;i<v.size();i++){
      cout<<v[i]<< " ";
  }
}