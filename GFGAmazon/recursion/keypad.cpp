#include<bits/stdc++.h>

using namespace std;



vector<string> getKPC(string  str){

    if(str.size() == 0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    static vector<string> code={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    
    char ch = str[0];
    string ros = str.substr(1);

    vector<string> rres = getKPC(ros);
    vector<string> mres;

    string codeforch = code[ch - '0'];

    for(int i=0; i < codeforch.size(); i++){
        char c = codeforch[i];
        for(string s:rres){
            mres.push_back(c+s);
        }
    }

    return mres;

}

//get maze path
vector<string> getMazePath( int sc,int sr,int dc,int dr){

    if(sr == dr && sc == dc){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    vector<string> s1;
    vector<string> s2;

    if(sc<dc){
         s1 = getMazePath(sc+1, sr, dc,dr);
    }

    if(sr<dr){
         s2 = getMazePath( sc, sr+1, dc,dr);
    }
    
    vector<string> fs ;

    for(auto i:s1){
        fs.push_back("h"+i);
    }

    for(auto i:s2){
        fs.push_back("v"+i);
    }

    return fs; 
}

vector<string> DynamicMazePath(int sr,int sc,int dr, int dc){

    if(sr == dr && sc == dc){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

   static vector<string> fpath;
    vector<string> hpath;
    vector<string> vpath;
    vector<string> dpath;

    for(int i=1; i<dr-sr; i++){
        cout<<"reached"<<" ";
            vpath  = DynamicMazePath(sr+i, sc, dr, dc);
            for(auto spath:vpath){
                fpath.push_back("v"+ to_string(i) + spath);
            }   
    }
    
    for(int i=1; i<dc-sc; i++){
        cout<<"2 "<<" ";
       
            hpath  = DynamicMazePath(sr, sc+i, dr, dc);
            for(auto spath:hpath){
                fpath.push_back("h"+ to_string(i) + spath);
            }
        
    }
    for(int i=1, j = 1; i<dr-sr && j<dc-sc; i++,j++){
        cout<<"3 "<<" ";
        
            dpath  = DynamicMazePath(sr+i, sc+j, dr, dc);
            for(auto spath:dpath){
                fpath.push_back("d"+ to_string(i) + spath);
            }  
    }

    // cout<<" fpath";
    // cout<<fpath.size()<<: 
    return fpath;
}

//permutation of given string.. this is for n!

void permutation(string str,string asf){

    if(str == ""){
        cout<<asf<<" ";
        return ;
    }
//    cout<<"* ";
    for(int i=0; i <str.size(); i++){
        char ch = str[i];
        string ls ;

        ls = str.substr(0,i);

        string rs = str.substr(i+1);
        string ros = ls+rs;

        permutation(ros,asf+ch);
    }

    return ;
}

//permutation of npr
void permu2(vector<int> box,int ci,int ti){
    static int count =0;
    if(ci  > ti){
         cout<<++count<<" -> ";
        for(int i=0; i<box.size();i++){
           
            cout<<box[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    for(int i=0; i<box.size(); i++){
        if(box[i] == 0){
            box[i] = ci;
            permu2(box,ci+1,ti);
            box[i] = 0;
        }
    }

    return;
}

void subsequence(string str,string asf){

    static int count =0;
    if(str == ""){
        cout<<++count<<" "<<asf<<"\n ";
        return;
    }
    
    char ch = str[0];
    string ros = str.substr(1);

    subsequence(ros, asf+ch);
    subsequence(ros, asf);
}

// rough
void subseq(string str,string asf){

    if(str == ""){
        for(auto i:asf){
            cout<<asf;
        }
        return;
    }
    char ch = str[0];
    string ros = str.substr(1);

    subseq(ros,asf+ch);
    subseq(ros,asf);
}

void TargetSumSubset(vector<int> arr,int index){

    int 
}

bool isPalindrome(string str){

    if(str.size() == 1){
        return true;
    }

    if(str.size() == 0){
        return false;
    }

    int i=0,j=str.size()-1;

    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;

}

//substring of string
void subString(string str){

    int large = 0;
    string ls = "";
    for(int i=0; i<str.size(); i++){
        for(int len=1; len<= str.size()-i; len++){
            // cout<<str.substr(i,len)<<endl;
            string s = str.substr(i,len);
            if(isPalindrome(s)){
                // large = max(s.size(),large);
                if(large < s.size()){
                    ls = s;
                    large = s.size();
                }
                  cout<<str.substr(i,len)<<endl;
            }
        }
    }
    cout<<"Largest is ->";
    for(auto i:ls){
        cout<<i;
    }
}

// Length of the longest substring without repeating characters

bool isunique(string s){
    vector<bool> visited(26);

    for(int j=0; j< s.size(); j++){
        if(visited[s[j] - 'a'] == true){
            return false;
        }
        visited[s[j]-'a'] = true;
    }
    return true;
}

void substringAll(string str){

    int len=0;
    string res;
    for(int i=0; i<str.size(); i++){
        for(int j=1; j <= str.size()-i ; j++){
            string s = str.substr(i,j);
            if(isunique(s)){
                if(len < s.size()){
                   
                    res= s;
                    for(auto i:res) cout<<s[i];

                    len = s.size();
                     cout<<len<<endl;

                }
            }
        }
    }

    cout<<"Length "<<len<<endl;
    for(auto i:res) cout<<res[i];
}

//in linear time O(n)

int longestUniSubstr(string str){


    int ans =0;

    int i=0 , j =0;
    unordered_map<char,int> mp;

    while(true){
            bool f1= false,f2 = false;
        //acquire
        while(i < str.size()-1){
            f1= true;
            i++;
            char ch = str[i];
            mp[ch]++;

            if(mp[ch] == 2){
                break;
            }
            else{
                int len = i-j;
                if(len > ans){
                    ans = len;
                }
            }
        }
    

        while(j < i){
            f2 = true;
            j++;
            char ch = str[j];
            mp[ch]--;

            if(mp[ch] == 1){
                break;
            }
        }

        if(f1 == false && f2 == false){
            break;
        }
    }
     return ans;
}


int main(){

    // vector<string> res = getKPC("78");
    // for(auto i:res){
    //     cout<<i<<",";
    // }

//   vector<string> str = getMazePath(0,0,3,3);
//   vector<string> str = DynamicMazePath(0,0,3,3);
//   cout<<str.size();
//   int count =0;

//   for(auto i:str){
      
//       cout<<++count<<" "<<i<<endl;
//   }

//  permutation("abcd","");
    // subsq("abc","");

    // vector<int> box(4,0);
    // permu2(box,2,3);

    // subsequence("ababa","");
    // subString("abcd", 4);

    // string st = "forgeeksskeegfor";
    // subString(st);

    // substringAll("abcde");

    cout<<longestUniSubstr("geekforgeeks");
    return 0;
}