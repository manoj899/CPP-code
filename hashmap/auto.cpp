// #include<iostream>
// #include<iterator>
// #include<map>
// #include<typeinfo>
// #include<unordered_map>

// using namespace std;
// /*
// int main(){

//     auto i=5;
//     auto j='v';
//     auto k=&i;

//     cout<<typeid(i).name()<<endl;
//     cout<<typeid(j).name()<<endl;
//     cout<<typeid(k).name()<<endl;
// return 0;
// }   */

// /*
// int main(){

//     unordered_map<string ,int>  mp;
//     mp["aaa" ]= 5;
//     mp["bbb"] = 4;
//     mp["vvv"] =6;
//     mp["jjj"]= 2;

//     for( auto i: mp)
//     {
//         cout<<"\t"<<i.first
//         <<"\t"<<i.second<<endl;
//     }
// }  

// /*
// int main() 
// { 
//     // Declaring umap to be of <string, int> type 
//     // key will be of string type and mapped value will 
//     // be of double type 
//     unordered_map<string, int> umap; 
  
//     // inserting values by using [] operator 
//     umap["GeeksforGeeks"] = 10; 
//     umap["Practice"] = 20; 
//     umap["Contribute"] = 30; 
  
//     // Traversing an unordered map 
//     for (auto x : umap) 
//       cout << x.first << " " << x.second << endl; 
  
// } */

// int main(){

//     unordered_map<string,double> ump;

//     ump["PI"]=3.14;
//     ump["ROOT2"]=1.41 ;
//     ump["ROOT3"]=1.71;
//     ump["LOG 10 "]= 1;

//     ump.insert(make_pair("e",2.718));
    
//     ump.insert(pair<string,int>( "hh",54));
//     string key ="PI";
//     if(ump.find(key)== ump.end())
//     {
//         cout<<"\n\t not found"<<"\t";

//     }
//     else{
//         cout<<"found\n";
//     }

//     for(auto itr= ump.begin(); itr != ump.end();itr++){
//      cout<<"a\n";
//         cout<<"\t"<<itr->first<<" "<<itr->second<<endl;
//     }
// }

#include<iostream>
#include<unordered_map>
//#include<

using namespace std;

auto hfc(string &word){

    unordered_map<string,int> fmap;

    for(auto i=0;i<word.size();i++){

        if(fmap.count["word[i]"]==0){

            fmap["word[i]"]=1;
        }
        else{
            fmap["word[i]"]=+1;
        }
    }

    char mfc = word[0];
    for(auto itr=fmap.begin();itr != fmap.end();itr++){
        if(itr->second>fmap[mfc]->second){
            mfc=itr->second;
        }
    }cout<<mfc<<endl;
}


int main(){
    string s= "aassddffgghhjjjjkkklllddddd";
    hfc(s);
}