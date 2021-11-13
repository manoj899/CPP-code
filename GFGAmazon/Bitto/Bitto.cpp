#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


void subsequence(string input, string asf){

    if(input == ""){
        cout<<asf<<" ";
        return;
    }

    char ch = input[0];
    string ros = input.substr(1);

    subsequence(ros, asf);
    subsequence(ros, asf+ch);
}

// //Longest and shortest substring without repeating character
// //  abcd 


// int longestUniSubstr(string str){


//     int ans =0;

//     int i=0 , j =0;
//     unordered_map<char,int> mp;

//     while(true){
//             bool f1= false,f2 = false;
//         //acquire
//         while(i < str.size()-1){
//             f1= true;
//             i++;
//             char ch = str[i];
//             mp[ch]++;

//             if(mp[ch] == 2){
//                 break;
//             }
//             else{
//                 int len = i-j;
//                 if(len > ans){
//                     ans = len;
//                 }
//             }
//         }
    

//         while(j < i){
//             f2 = true;
//             j++;
//             char ch = str[j];
//             mp[ch]--;

//             if(mp[ch] == 1){
//                 break;
//             }
//         }

//         if(f1 == false && f2 == false){
//             break;
//         }
//     }
//      return ans;
// }

// // print all substring of string
// void substring(string str){
// // O(n^2)
//     for(int i=0; i<str.size(); i++){
//         cout<<str[i]<<" ";
//         for(int j=i+1; j<str.size(); j++){
//             string res = str.substr(i,j);
//             cout<<res<<" ";
//         }
//     }
// }

// //O(n)
// int lengthOfLongestSubstring(string s) {
//         unordered_map<char,int> map;// it will keep track of index of character
//         int count=0,p=0,m=-1;
//         //m hold prev index of character
//         //p global count
//         //count hold local count
//         for(int i=0;i<s.length();i++){
//            if(map.count(s[i])>0 && map[s[i]]>m){
//                p=max(p,count);
//                count=i-map[s[i]];// length of string will be curr index - prev occur index
//                m=map[s[i]];
//                map[s[i]]=i;// it keep hold the latest occurance
//            }
//            else{
//                count++;
//                map[s[i]]=i;
//            }
//         }
//         p=max(p,count);
//         return p;
// }

// //checking
// void check(){
//      unordered_map<char,int> map;
//      map['a'] = 0;
//      if(map.count('a') > 0){
//          cout<<"Working";
//      }
// }


// //Minimum window substring
// //given two string s1 and s2..find smallest substring from s1 such that all character of s2 present in it

string MinimumWindowSubstring(string s1,string s2){

    unordered_map<char,int> map1;
    unordered_map<char,int> map2;

    for(int i=0; i<s1.size(); i++){
        map1[s1[i]]++;
    }

    int tmc = s1.size();
    int mc =0;
    int i = -1, j= -1;
    string pans ;
   // bool acquire = false, release = false;

    while(true){
        bool acquire = false, release = false;
        //acquire
        while(mc < tmc && i < s2.size()){
            i++;
            mc++;
            acquire = true;
        }
         if(mc == tmc){
                pans = s2.substr(j+1,i+1);
                break;
         }

        //release
         while(mc == tmc  && map1.count(s2[j]) != 0 ){
             j++;
             mc--;
             if( pans.size() > i-(j+1)){
                 pans = s2.substr(j+1,i+1);
             }
            release = true;
         }

         if(acquire == false && release == false){
             break;
         }
           
    }
    return pans;
}

// //find num of island
//                 //    {1, 1, 0, 0, 0},
//                 //    {0, 1, 0, 0, 1},
//                 //    {1, 0, 0, 1, 1},
//                 //    {0, 0, 0, 0, 0},
//                 //    {1, 0, 1, 0, 1} 
//                 //DFS
void mark_curr_island(vector<vector<char>>& grid,int x,int y,int row,int col){
        if(x<0 || y >= col || x >= row || y < 0 || grid[x][y] != '1')
            return;
        
        grid[x][y] = '2'; // visited
        
        mark_curr_island(grid, x+1, y, row, col);
        mark_curr_island(grid, x-1, y, row, col);
        mark_curr_island(grid, x, y-1, row, col);
        mark_curr_island(grid, x, y+1, row, col);

    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        if(row == 0) return 0;
        
        int col = grid[0].size();
        
        int island_count = 0;
        
        for(int i=0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    mark_curr_island(grid, i, j, row, col);
                    island_count++;
                }
            }
        }
        return island_count;
        
    }
};


// //In BFS loop:

// // we create a queue and push the current position so that we can start our process of assigning the surrounding ones to '0'.

// // Now, we enter the loop:

// // First we need to make a condition to exit the loop i.e, here it is !neighbours.empty()
// // Now, as we have already assigned the grid value current position as '0' we pop it from the queue.
// // Before doing so, we copy the current positions to a temporary variable so that we can iterate through the surrounding positions.
// // Now, if at all the grid value of the surrounding position is found to be '1' we push the position and make the grid value to be '0'.
// // Hence, we make the surrounding grid values as '0' and count the number of such groups.

// // Check : while checking the nearest positions we first check whether the position is valid or not ..XD

class Solution {
public:    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int r = grid.size(),c = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';                                    //assign the grid value of current position to '0'
                    queue<pair<int,int>> neighbours;                     //Creating a queue to store the current and positions which we need to iterate
                    neighbours.push(make_pair(i,j));
                    while(!neighbours.empty()){
                        auto curr = neighbours.front();
                        neighbours.pop();                               //remove the current block
                        int row = curr.first,col = curr.second;
                        if(row>0 && grid[row-1][col] == '1'){
                            neighbours.push(make_pair(row-1,col));      //push the surrounding position iff grid value is '1' and assign the grid value to '0'
                            grid[row-1][col] = '0';
                        }
                        if(col>0 && grid[row][col-1] == '1'){
                            neighbours.push(make_pair(row,col-1));     //push the surrounding position iff grid value is '1' and assign the grid value to '0'
                            grid[row][col-1] = '0';
                        }
                        if(row<r-1 && grid[row+1][col] == '1'){
                            neighbours.push(make_pair(row+1,col));     //push the surrounding position iff grid value is '1' and assign the grid value to '0'
                            grid[row+1][col] = '0';
                        }
                        if(col<c-1 && grid[row][col+1] == '1'){
                            neighbours.push(make_pair(row,col+1));     //push the surrounding position iff grid value is '1' and assign the grid value to '0'
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int  LongestSubstrWithoutRepeatingChar(string str){
    int ans =0;
    int i = 0;    
    int j = 0;

    unordered_map<char,int> map;
    while(true){
            // cout<<"*";
            bool f1 = false;
            bool f2 = false;
            
            //acquire
            while(i < str.size()-1){//one while loop mean run till it become one time invalid..1 loop mean 1 substring
                //cout<<"L1";   // just for checking  
                f1 = true;
                char ch = str[i];
                i++;
                map[ch]++;

                if(map[ch] == 2){
                    break;
                }
                else{
                    int len = i - j;
                    if(len > ans){
                        ans = len;
                    }
                }
            }
        
        cout<<endl;
        while(j < i){//make invalid into valid..1 loop mean 1 substring
            
          //  cout<<"L2"; // just for checking
            f2 = true;
            char ch = str[j];
            j++;   

            map[ch]--;

            if(map[ch] == 1){
                break;
            }
        }

        if(f1 == false && f2 == false){ // this mean that i and j traverse whole string
            // cout<<"r";
            break;
        }
    }

    return ans;    
}


//Connect n ropes with minimum cost
//There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect 
//two ropes is equal to the sum of their lengths. We need to connect the ropes with minimum cost.

//Approach : find minimum two and add them put them back in pq;

int MinRopeCost(vector<int> arr){

    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int cost =0;
    
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        cost += (first + second);
        pq.push(first + second);
    }

    return cost;
}

//List : new data structure
void showList(list<int> g){
    
    for(auto it = g.begin(); it != g.end() ; it++){
        cout<<"\t"<<*it;
    }
    cout<<endl;
}


//


int main(){

        // cout<<longestUniSubstr("geekforgeeks");
        // subsequence("abcd","");
        // substring("abcd");
        // check();
    string s = "aab";
    cout<<LongestSubstrWithoutRepeatingChar(s);

    // vector<int> arr{ 4, 3, 2, 6};
    // cout<<MinRopeCost(arr);

    // list <int> gqlist1, gqlist2;
  
  
    // for (int i = 0; i < 10; ++i)
    // {
    //     gqlist1.push_back(i * 2);
    //     gqlist2.push_front(i * 3);
    // }
    // cout << "\nList 1 (gqlist1) is : ";
    // showList(gqlist1);
  
    // cout << "\nList 2 (gqlist2) is : ";
    // showList(gqlist2);

    return 0;
}