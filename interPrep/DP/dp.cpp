#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<cstring>
#include <bits/stdc++.h> 

using namespace std;
// no of path
// basically this is the approach of fibonacii.. just go to possible index add them
int countPath(vector<int> arr){
    
    int n = arr.size();
    vector<int> strg(n , 0);

    strg[n-1] = 1;
    for(int i = n-2 ; i>= 0 ; i--){
        for(int j = i+1 ; j <= i+ arr[i] && j < arr.size(); j++){
            strg[i] += strg[j];
        }
    }

    return strg[0];
}

///////////


// min steps

int minSteps(vector<int> arr){

    int n = arr.size();
    vector<int> strg(n , 0);

    strg[n-1] = 0;
    for(int i = n-2 ; i>= 0 ; i--){
        if(arr[i] == 0){
            strg[i] = INT_MAX;
        }
      else {  
        for(int j = i+1 ; j <= i+ arr[i] && j < arr.size(); j++){
            strg[i] =  1+ min(strg[j],strg[i]);
        }
        }
    }

    return strg[0];
}

// min cost in 2D maze
void printMinCostPath(vector<vector<int>> GMaze,int i, int j, string s){
        
            if(i == GMaze.size() -1 && j == GMaze.size() -1){
                cout<<endl;
                for(int i=0; i< s.size() ; i++){
                    cout<<s[i]<<" ";
                }
                cout<<endl;
                return;
            }

           if( i == GMaze.size()-1){
               printMinCostPath(GMaze, i, j+1, s +to_string(GMaze[i][j+1]) );
           }
           else if( j == GMaze.size()-1){
               printMinCostPath(GMaze, i+1, j,s + to_string(GMaze[i+1][j]) );
           }
           else {
               if(GMaze[i+1][j] > GMaze[i][j+1])
                printMinCostPath(GMaze, i, j+1, s +to_string(GMaze[i+1][j]) );
                else if(GMaze[i+1][j] < GMaze[i][j+1]){
                printMinCostPath(GMaze, i+1,j,s + to_string(GMaze[i][j+1]) );
                }
                else{
                 printMinCostPath(GMaze, i, j+1, s +to_string(GMaze[i+1][j]));
                 printMinCostPath(GMaze, i+1,j, s +to_string( GMaze[i][j+1]));
                }
           }       
}


int minCostMaze(vector<vector<int>> lMaze){

    vector<vector<int>> GMaze(lMaze.size(),vector<int> (lMaze[0].size(),0));

        for(int i = lMaze.size() - 1; i >= 0; i--){
            for(int j = lMaze[0].size() - 1; j >= 0; j--){
                if(i == lMaze.size() - 1 && j == lMaze[0].size() - 1){
                    GMaze[i][j] = lMaze[i][j];
                } else if(i == lMaze.size() - 1){
                    GMaze[i][j] = lMaze[i][j] + GMaze[i][j + 1];
                } else if(j == lMaze[0].size() - 1){
                    GMaze[i][j] = lMaze[i][j] + GMaze[i + 1][j];
                } else {
                    GMaze[i][j] = lMaze[i][j] + 
                                   min(GMaze[i][j + 1], 
                                   GMaze[i + 1][j]);
                }
            }
        }
        
     printMinCostPath(GMaze, 0, 0, "");
     cout<<endl;
    return GMaze[0][0];
}

int GoldMine(vector<vector<int>> LMine){

    vector<vector<int>> Gmine(LMine.size(), vector<int> (LMine[0].size(),0));
          int Gmax = 0;

        for(int j= LMine[0].size() -1 ; j >=0 ; j--){
             for( int i = 0; i < LMine.size(); i++){

              if(j == LMine[0].size()-1 ){
                  Gmine[i][j] = LMine[i][j];
              }
              else if( i == 0 && j < Gmine[0].size() -1)
              {   Gmine[i][j] = LMine[i][j] + max(Gmine[i+1][j+1] , Gmine[i][j+1]);          
              }
              else if( i == Gmine.size()-1 && j < Gmine[0].size() -1){
                    Gmine[i][j] = LMine[i][j] + max(Gmine[i-1][j+1] , Gmine[i][j+1]);
              }
              else{
                  Gmine[i][j] = LMine[i][j] + max(Gmine[i-1][j+1], max(Gmine[i+1][j+1] , Gmine[i][j+1]));
              }
           }
        }
        for( int j =0 ; j< Gmine.size(); j++){
            Gmax = max( Gmax , Gmine[j][0] );
        }
        return Gmax;
}

int countBinary(int n){
    int c0 = 1;
    int c1=1;

    for( int i =2 ; i <= n; i++){
        int nc0 = c1;
        int nc1 = c0 + c1;

        c0 = nc0;
        c1 = nc1;        
    }

    return c0 + c1;
}


int countEncodings(vector<int> arr){
        vector<int> strg(arr.size(),0);

        if(arr[0] == 0){
            return 0;
        }

        strg[0] = 1;
        
        if(arr[1] != 0){
            strg[1] = strg[0];
        }

        int num = arr[0] * 10 + arr[1];
        if(num >= 10 && num <= 26){
            strg[1] += 1;
        }
        
        for(int i = 2; i < arr.size(); i++){
            if(arr[i] != 0){
                strg[i] = strg[i - 1];
            }

            int num2 = arr[i - 1] * 10 + arr[i];
            if(num2 >= 10 && num2 <= 26){
                strg[i] += strg[i - 2];
            }
        }

        return strg[arr.size() - 1];
    }


//Number of subsequences of the form a^i b^j c^k
//you can see GFG or notes for proper explanation
int countABC(string s){
    int a =0;
    int b = 0;
    int c = 0;

    for(int i=0; i< s.size(); i++){
        char ch = s[i];

        if(ch == 'a'){
            a = 1 + 2*a; // 1  -> if its first, 2a -> if it doesnt add + add behind all previous
        } 
        else if(ch == 'b'){
            b = a + 2*b; // a-> for prevous + 2b-> come and doesnt come
        }
        else{
            c = b + 2 *c; 
        }
    }
    // cout<<"*";
        return c; //
}

void ptss(vector<vector<bool>> strg, int i, int j , vector<int> arr, string asf){

        if(i == 0){
                if(j == 0){
                    for(int p = 0; p < asf.size() ; p++)
                        cout<<asf[i]<<"->";    
                }
                else if(j == arr[0] ){
                    cout<<endl;
                    for(int p = 0; p < asf.size() ; p++){
                        cout<<asf[i]<<"->";   }
                        cout<<arr[0];
                    } 
                  }
        else{
                if(strg[i-1][j] == true){
                    ptss(strg, i-1, j , arr, asf);
                }

                if(j >= arr[i]){
                    if(strg[i-1][j-arr[i]] == true)
                    ptss(strg, i-1, j - arr[i], arr, asf + to_string(arr[i]));
                }
            }
}
    


vector<vector<bool>> TargetSumArr(vector<int> arr, int tar){

   
    vector<vector<bool>> strg(arr.size(),vector<bool> (tar,false));

    for(int i=0 ; i< arr.size() ; i++){
        for(int j = 0; j <= tar ; j++){
            
            if( j == 0){
                strg[i][j] = true;
                continue;
            }

            if( i == 0){
                 
                 if(j != arr[i]){
                    strg[i][j] =  false;
                 }
                 else{ strg[i][j] = true; }
                 continue;
            }

            if(arr[i] == j){
                strg[i][j] = true;
            }    
             else if(arr[i] > j){
               if(strg[i-1][j] == true)
                  strg[i][j] = true; 
               else{
                   strg[i][j] = false;
               }
             }
            else{
                   if(strg[i-1][j-arr[i]] == true || strg[i-1][j] == true){
                       strg[i][j] = true;
                   }else strg[i][j] = false;
            }
        }
    }
    return strg;
}

int coinChangePermu(vector<int> coins, int amount){
    vector<int> strg(amount+1, 0);
    strg[0] = 1;   // j is coins  ... i is target or amount

   for(int i = 1 ; i  <= amount ; i++ ){
      for(int j=0 ; j< coins.size() ; j++){ 
           if( i >= coins[j]){
            strg[i] += strg[i - coins[j]];}
        }
    }
    return strg[amount];
}


//

//infinite times


//
int coinChangeComp(vector<int> coins, int amount){
    vector<int> strg(amount+1, 0);
    strg[0] = 1;   // j is coins  ... i is target or amount

    for(int j=0 ; j< coins.size() ; j++){
        for(int i = 1 ; i  <= amount ; i++ ){
           if( i >= coins[j]){
            strg[i] += strg[i - coins[j]];}
        }
    }
    return strg[amount];
}

void zoKnapSack(vector<int> wts, vector<int> prices, int amount){

    vector<vector<int>> strg( wts.size(), vector<int> (amount+1,0));

    for(int i=0; i< strg.size() ; i++){
        for(int j = 1 ; j <= strg[i].size() ; j++){
             if(i == 0){
                 if(j >= wts[0]){
                     strg[i][j] = prices[0];
                 }
             }
             else{
                 strg[i][j] = strg[i-1][j];

                 if(j >= wts[i]){
                     int factor = strg[i-1][j-wts[i]] +prices[i];

                     if(factor > strg[i][j]){
                         strg[i][j] = factor;
                     }
                 }
             }
    }
   }

    for(int i=0 ; i < wts.size(); i++){
        for( int j =0; j <= amount ; j++){
        cout<<strg[i][j]<<" ";
        }
        cout<<endl;
    }

}

int uboundzoKnapsack(vector<int> arr,vector<int> prices ,int amount){

    vector<int> strg(amount+1, 0);
    strg[0] = 0;
    for(int i = 1 ; i <= amount ; i++){
        int ma =0;
        for(int j = 0 ; j < arr.size() ; j++){
        
           if( i >= arr[j] ){
                 ma = max(ma,strg[i - arr[j]]+ prices[j]);   
           }
        }
        strg[i] = ma;
    }

    for(int i=0; i< strg.size() ; i++){
      cout<<strg[i]<<" ";
    }
    return strg[amount+1];
}

// Longest Common Subsequence
void LCS(string s1, string s2){

    vector<vector<int>> strg(s1.size()+1,vector<int> (s2.size()+1,0));

    for(int i= strg.size()-2 ; i >= 0 ; i--){
        for(int j = strg[i].size()-2 ; j >= 0 ; j--){

            if(s2[j] == s1[i]){
               strg[i][j] = 1 + strg[i+1][j+1];
             
            }
            else{
                strg[i][j] = max(strg[i+1][j] , strg[i][j+1]);      
            }
        }
    }

    for(int i=0 ;i< strg.size() ;i++){
        for(int j=0 ;j< strg[i].size() ; j++){
            cout<<strg[i][j]<<" ";
        }
        cout<<endl;
    }

}

// Longest Palindromic Substring
int lpsq(string s){
    int strg[s.size()][s.size()];

    for(int g= 0; g< s.size(); g++){
        for(int i =0; i< s.size() - g; i++){
            int j = i + g;

            if(g == 0){
                strg[i][j] = 1;
            } else if( g == 1){
                strg[i][j] = s[i] == s[j] ? 2:1;
            } else {
                if(s[i] == s[j])
                strg[i][j] = 2 + strg[i+1][j-1];
                else 
                strg[i][j] = max(strg[i][j - 1], strg[i+1][j]);
            }
        }
    }
    return strg[0][s.size()-1];
}

//count of Palindromic subsequence
int CountLpsq(string s){
    vector<vector<int>> strg(s.size(),vector<int> (s.size(),0));


    for(int g= 0; g< s.size(); g++){
        for(int i =0; i< s.size() - g; i++){
            int j = i + g;

            if(g == 0){
                strg[i][j] = 1; //_a, _b
            } else if(g == 1){
                strg[i][j] = s[i] == s[j] ? 3:2;
            }
            else{
                if(s[i] == s[j]){
                    strg[i][j] = strg[i+1][j] + strg[i][j-1] + 1;
                }
                else{
                    strg[i][j] = strg[i+1][j] + strg[i][j-1] - strg[i+1][j-1]; 
                }
            }
        }
    }

     for(int i=0 ;i< strg.size();i++){
        for(int j=0 ;j< strg[i].size() ; j++){
            cout<<strg[i][j]<<" ";
        }
        cout<<endl;
    }

    return strg[0][s.size()-1];
}

//Longest Palindromic substring
void lpss(string s){
   vector<vector<bool>> strg(s.size(), vector<bool> (s.size(), false));
   int count =0;
   int length =0;
  
    for(int g = 0 ; g< s.size() ; g++){
        for(int i = 0 ; i < s.size() - g ; i++){
            int j =  i + g;

            if(g == 0){
                strg[i][j] = true;
                count++;
               length = g+1;
            }
            else if( g == 1){
                if(s[i] == s[j]){
                    strg[i][j] = true;
                    count++;
                    
                  length = g+1;

                }
                else
                strg[i][j] = false ;
                
            }
            else{
                if(s[i] == s[j] && (strg[i+1][j-1] == true)){
                    strg[i][j] = true;
                    count++;
                    length = g+1;
                }
                else{
                    strg[i][j] = false;
                }
            }
        }
    }
    cout<<"Largest Palindrome of lenth "<< length<<endl;
     cout<<"NO. of Palindromic substring "<< count<<endl;
     for(int i=0 ; i< s.size() ; i++){
         for( int j =0 ;j< s.size() ; j++){
             cout<<strg[i][j]<<" ";
         }cout<<endl;
     }
    
}

// count no of subseq which are divisible by 6
int CountSsM6(string s, int d){

    vector<vector<int>> strg(s.size(), vector<int> (d,0));

    strg[0][0] = 1;
    strg[0][(s[0] - 48) % d] = 1;

    for(int i = 0 ; i < s.size()-1 ; i++){
        for( int j = 0; j< d ; j++){
             strg[i+1][j] +=  strg[i][j];

             int num = s[i+1] - 48;
             strg[i+1][(10 * j + num) % d] += strg[i][j];
              
        }
    }
    return strg[s.size()-1][0];
}

//Minimum palindromic cut  --> its little tricky
int MPC(string s){

    vector<vector<int>> strg(s.size(), vector<int> (s.size(),0));

    for(int g = 0 ; g < s.size() ; g++){
        for( int i = 0; i < s.size() - g; i++){
              int j = g + i;
              if(g == 0){
                  continue;
              }
              
              if(g == 1){
                 strg[i][j] = s[i] == s[j] ? 0:1;
              }
              else if(s[i] == s[j] && strg[i+1][j-1] == 0 ){
                          strg[i][j] = 0;
                      }
            else{
                int min = s.size();
        // jitna gap g hota he utna hi left or right part hota he
        // Eg:- abcc :-- a-bcc,ab-cc,abc-c, gap is 0,1,2,3..3-0 = 3 = gap
        // in left part of cut row is common strg[i][?], in right part column is common strg[?][j]
        // right part varies in row and left part in column

        //left part always start at diagonal
                
                for( int k = 0 ; k< g ; k++){
                    int left = strg[i][i + k];
                    int right = strg[i + 1 + k][j];
                
                    if(left + right < min){
                        min = left + right;
                    }
                }

                strg[i][j] = min +1;
                  
              }
        }
    }
    for(int i =0; i< strg.size() ;i++){
        for(int j=0 ; j< strg[i].size() ;j++ ){
            cout<<strg[i][j]<<" ";
        }cout<<endl;
    }
    return strg[0][s.size()-1];
        
}

// string stockShare(vector<int> stock){
    
// }

int eggDrop(int eggs, int floors){ // answer is not coming
    vector<vector<int>> strg(eggs+1, vector<int> (floors+1,0));

    for(int e = 0 ; e < eggs ; e++){
        for(int f = 0; f <= floors ; f++ ){
            if(e == 1 || f == 0 || f == 1){
                strg[e][f] = f;
            }
            else{
                int minimum = INT_MAX;

                for(int  k = 1; k <= f ; k++ ){
                    int maeb = strg[e - 1][k - 1];
                    int maes = strg[e][f - k];
                    int maln = max(maeb , maes);
                    minimum = min(minimum,maln);
                }
                strg[e][f] = minimum + 1;
            }
        }
    }
    return strg[eggs][floors];
}

int mcm(vector<int> dims){ // matrix chain multiplication
    vector<vector<int>> strg(dims.size()-1 , vector<int> (dims.size()-1,0));

    for(int g = 0 ; g< strg.size(); g++){
        for(int i =0 ; i < strg.size() - g; i++){
            int j = i+ g;

            if(g == 0){
                strg[i][j] = 0;
            } else if( g == 1){
                strg[i][j] = dims[i] * dims[j] * dims[j + 1];
            }
            else{
                int minimum = INT_MAX;
                  for(int k = 0; k < g; k++){
                      int left  = strg[i][i + k];
                      int right = strg[i+ 1 + k][j];
                      int multc = dims[i] * dims[j+1] * dims[i + 1 + k];
                  
                      int totalc = left + right + multc;
                      if(totalc < minimum){
                          minimum = totalc;
                      }
                  }
                 strg[i][j] = minimum;  
            }

        }
    }
    return strg[0][strg.size()-1];
}


int optimalBST(vector<int> nodes, vector<int> freq){

    vector<vector<int>> strg(nodes.size(),vector<int> (nodes.size(), 0));

    vector<int> fpsa(freq.size(),0);
    fpsa[0] = freq[0];
    for(int i = 1; i  < freq.size(); i++){
        fpsa[i] = fpsa[i] + fpsa[i - 1];
    }


    for(int g = 0 ; g < strg.size(); g++ ){
        for(int i = 0; i < strg.size() - g; i++){
            int j = i + g;

            if(g == 0){
                strg[i][j] = freq[i];
            }else if (g == 1){
                strg[i][j] = min(freq[i] + 2 * freq[j], 2* freq[i] + freq[j]);
            }
            else{

            int minimum = INT_MAX;
            for(int k = 0; k <= g; k++){
                int left = k == 0? 0 : strg[i][i + k - 1];
                int right = k == g ? 0 : strg[i + k + 1][j];

                minimum = min(left + right, minimum);
            }
            strg[i][j] = minimum + fpsa[j] ;
            if(i > 0){
                strg[i][j] -= fpsa[i-1];
            }

            }
        }
    }
    return strg[0][nodes.size()-1];
}

//Longest increasing subsequence
int LIS(vector<int> arr){//arr = 10,21,9,33,22,50,41,60,80,7   O(n^2)
    vector<int> strg(arr.size(),0);
   //Meaning - LIS till arr 33 and all subseq end at 33..  
    strg[0] = 1;
    int omax = 0; // overall max
    for(int i = 1; i < strg.size() ; i++){
        int max = 0;

// inner loop will run for each element of arr..bcoz to find max till arr[i] point considering only minimum than arr[i] to that pt  
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){ // value only that is smaller than arr[i] can be analysize to update max..bcoz if greater than Increase subseq not possible
                if(strg[j] > max){
                    max = strg[j];
                }
            }
        }

        strg[i] = max + 1;
        if(strg[i] > omax){
            omax = strg[i];
        }
    }
    return omax;
}

//Longest bitonic subsequences
// int LBS(vector<int> arr){

//     vector<int> strgL(arr.size(),0);
//     vector<int> strgR(arr.size(),0);

//     strgL[arr.size()-1] = 1;
//     strgR[0] = 1;

  
//    int omax = 0;
//     int max;

//     for(int i = 1; i < arr.size() ; i++){
//         max = 0;
//         for(int j = 0; j< i; j++){
//            if(arr[j] < arr[i]){
//                if(strgR[j] > max){
//                    max = strgR[j];
//                }
//            }
//         }
//         strgR[i] = max +1;   
//     }

//     for( int i = arr.size()-2; i >= 0 ; i--){
//         max = 0;
//         for(int j = i; j < arr.size() ; j++){
//             //   if(arr[j] > arr[i]){
//                   if(max < strgL[j])
//                   max = strgL[j];
//               }
//         }
//         strgL[i] = max+1;  
//         cout<<strgL[i]<<" ";
//     }

    // for( int i =0 ; i< strgL.size() ; i++){
    //     // strgL[i] = strgL[i] + strgR[i] - 1;
    //     // if(omax < strgL[i]){
    //     //     omax = strgL[i];
    //     // }
    //     cout<<strgL[i]<<"L "<<endl;
    //     cout<<strgR[i]<<"R ";
    // }

//     return omax;
     
// }

int rodcut(vector<int> arr){
    vector<int> strg(arr.size(), 0);
    strg[0] = 0;
    strg[1] = arr[1];

    for(int i = 2; i < strg.size(); i++){
        strg[i] = arr[i];

        int left = 1;
        int right = i - 1;
        while(left <= right){
            if(strg[left] + strg[right] > strg[i]){
                strg[i] = strg[left] + strg[right];   
            }
            left++;
            right--;
        } 
    }
    return strg[strg.size()-1];
}


int  maxsumNoAdjacent(vector<int> arr){
    int exc = 0;
    int inc = arr[0];

    for(int i = 1; i < arr.size(); i++){
        int nInc = exc + arr[i];
        int nExe = max(exc, inc);

        inc = nInc;
        exc = nExe;
    }
    return max(inc, exc);
}

int jump(vector<int>& nums, int k = 0) {

    if(nums.size() == 0){
        return 0;
    }

    int n = nums.size()-1;
    vector<int> strg(nums.size() ,0);
    strg[n] = 0;

    for(int i = nums.size()-2; i >= 0; i--)
    {   
        if(nums[i] == 0){
            strg[i] = INT_MAX;    
        }
        else{
        for(int j = i+1; j <= nums[i] + i && j < nums.size(); j++){
            strg[i] = 1+ min(strg[j],strg[i]);
        }
        }
    }
    return strg[0];
}     

// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
// Maximum size square sub-matrix with all 1s

int SqMatrix(vector<vector<int>> g){

    vector<vector<int>> strg(g.size(), vector<int> (g[0].size(),0));
    int z = 0;

    for(int i= 0 ; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            if(i == 0){
                strg[i][j] = g[i][j];         
             }
            else if(j == 0){
                strg[i][j] = g[i][j]; 
            }
            else{
                if(g[i][j] == 0){
                    strg[i][j] = 0;
                }
                else{
                strg[i][j] = min(strg[i-1][j-1], min(strg[i-1][j] , strg[i][j-1])) +1;
                 if(z < strg[i][j]){
                    z = strg[i][j];
                }
                 }  
            }
        }
    }

    return z;
}

int longIncSubseq(vector<int> arr){// O(n^2)

    vector<int> strg(arr.size(),0);

    strg[0] = 1;
    int omax = 0;

    for(int i = 1 ; i < arr.size() ; i++){
        int maxx = 0;
        for(int j = 0; j < i; j++ ){
            if(arr[j] < arr[i]){
                maxx = max(maxx, strg[j]);
            }
        }
        strg[i] = maxx + 1;
        omax = max(strg[i], omax);
    }
    return omax;

}


struct CityPair{
    int north, south;
};

bool compare(struct CityPair a, struct CityPair b){
  if (a.south == b.south) 
        return a.north < b.north; 
    return a.south < b.south; 
}

int Building_Bridges(struct CityPair values[], int n){
    

    int lis[n]; 
    for (int i=0; i<n; i++) 
        lis[i] = 1; 
          
    sort(values, values+n, compare); 
      
    // logic of longest increasing subsequence 
    // applied on the northern coordinates 
    for (int i=1; i<n; i++) 
        for (int j=0; j<i; j++) 
            if (values[i].north >= values[j].north  
                && lis[i] < 1 + lis[j]) 
                lis[i] = 1 + lis[j]; 
          
          
    int max = lis[0]; 
    for (int i=1; i<n; i++) 
        if (max < lis[i]) 
            max = lis[i]; 
      
    // required number of bridges 
    // that can be built         
    return max; 
}

// class Box
// {
//     public:
//     int l,b,h;
// };

// int maxx(int x, int y){
//    return (x > y) ? x : y;
// }

// int minn(int x, int y){
//     return (x < y) ? x : y;
// }

// int compare(const void *a,const void* b){
//   const  int *x = (const int*)a;
//   const  int *y = (const int*)b;

//     return *x - *y;
// }

struct Box 
{ 
  // h --> height, w --> width, d --> depth 
  int h, w, d;  // for simplicity of solution, always keep w <= d 
}; 
  
// A utility function to get minimum of two intgers 
int min (int x, int y) 
{ return (x < y)? x : y; } 
  
// A utility function to get maximum of two intgers 
int max (int x, int y) 
{ return (x > y)? x : y; } 
  
/* Following function is needed for library function qsort(). We 
   use qsort() to sort boxes in decreasing order of base area.  
   Refer following link for help of qsort() and compare() 
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare (const void *a, const void * b) 
{ 
    return ( (*(Box *)b).d * (*(Box *)b).w ) - 
           ( (*(Box *)a).d * (*(Box *)a).w ); 
} 
  
/* Returns the height of the tallest stack that can be 
   formed with give type of boxes */
int maxStackHeight( Box arr[], int n ) 
{ 
   /* Create an array of all rotations of given boxes 
      For example, for a box {1, 2, 3}, we consider three 
      instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
   Box rot[3*n]; 
   int index = 0; 
   for (int i = 0; i < n; i++) 
   { 
      // Copy the original box 
      rot[index].h = arr[i].h; 
      rot[index].d = max(arr[i].d, arr[i].w); 
      rot[index].w = min(arr[i].d, arr[i].w); 
      index++; 
  
      // First rotation of box 
      rot[index].h = arr[i].w; 
      rot[index].d = max(arr[i].h, arr[i].d); 
      rot[index].w = min(arr[i].h, arr[i].d); 
      index++; 
  
      // Second rotation of box 
      rot[index].h = arr[i].d; 
      rot[index].d = max(arr[i].h, arr[i].w); 
      rot[index].w = min(arr[i].h, arr[i].w); 
      index++; 
   } 
  
   // Now the number of boxes is 3n 
   n = 3*n; 
  
   /* Sort the array 'rot[]' in non-increasing order 
      of base area */
   qsort (rot, n, sizeof(rot[0]), compare); 
  
   // Uncomment following two lines to print all rotations 
   // for (int i = 0; i < n; i++ ) 
   //    printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d); 
  
   /* Initialize msh values for all indexes  
      msh[i] --> Maximum possible Stack Height with box i on top */
   int msh[n]; 
   for (int i = 0; i < n; i++ ) 
      msh[i] = rot[i].h; 
  
   /* Compute optimized msh values in bottom up manner */
   for (int i = 1; i < n; i++ ) 
      for (int j = 0; j < i; j++ ) 
         if ( rot[i].w < rot[j].w && 
              rot[i].d < rot[j].d && 
              msh[i] < msh[j] + rot[i].h 
            ) 
         { 
              msh[i] = msh[j] + rot[i].h; 
         } 
  
  
   /* Pick maximum of all msh values */
   int max = -1; 
   for ( int i = 0; i < n; i++ ) 
      if ( max < msh[i] ) 
         max = msh[i]; 
  
   return max; 
} 

int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;
        
        vector<int> buy(prices.size(),0);
        vector<int> sell(prices.size(),0);
        
        buy[0]= -prices[0];
        
        for(int i = 1 ; i < prices.size() ; i++){
            buy[i] = max(sell[i-1] , max(buy[i-1], sell[i] - prices[i]));
            sell[i] = max(sell[i-1] ,prices[i]- buy[i-1]-fee );
            cout<<buy[i]<<" "<<sell[i]<<endl;
        }
        return sell[prices.size()-1];
        
    }

bool isMatch(string s, string p) {
    
    vector<char> pattern;
    
    int writeIndex = 0;
    bool isFirst = true;
    for( int i = 0 ; i < p.size(); i++){
        if(p[i] == '*'){
            if(isFirst){
                pattern.push_back(p[i]);
                // cout<<p[i];
            }
            else {continue;};
        } 
        else{
            pattern.push_back(p[i]);
            // cout<<p[i];
            writeIndex++;
            isFirst = true;
        } 
    }

     vector<vector<bool>> T(s.size()+1,vector<bool>(writeIndex+1,0));
            
            if(writeIndex > 0 && pattern[0] == '*'){
                T[0][1] = true;
            }
            
            T[0][0] = true;
            
            for(int i = 1; i < T.size(); i++){
                for(int j = 1; j < T[0].size(); j++){
                    if(pattern[j-1] == '?' || s[i-1] == pattern[j-1]){
                        T[i][j] = T[i-1][j-1];
                    }
                    else if (pattern[j-1] == '*'){
                        T[i][j] = T[i-1][j] || T[i][j-1];
                    }
                }
            }
          
        for(int i = 0 ; i<= T.size(); i++){
            for(int j = 0 ; j<= T[0].size(); j++){
                cout<<T[i][j];
            }cout<<endl;
        }

          return T[T.size()-1][T[0].size()-1];
}


// int countAllPalinSubseq(string s){

//     vector<vector<int>> strg(s.sizse(),vector<int> (s.size(),0));

//     for(int i = 0 ; i < s.size(); i++){
//         for(int j = 0 ; j < s.size() ; j++){
//             k = i + j -1;
//         }
//     }
// }

//binary string wothour consecutive 1 GFG
int CountBinaryString(int n){
    
    vector<int> a(n,0); //ending with 0;
    vector<int> b(n,0); // ending with 1;
    a[0] = 1;
    b[0] = 1;
    for(int i = 1 ; i < n; i++){
        a[i] = a[i-1] + b[i-1];
        // cout<<a[i]<<endl;
        b[i] = a[i-1];
        // cout<<b[i]<<endl;
    }

    return a[n-1]+b[n-1];
}

// Maximum sum such that no two elements are adjacent

int maxSum(vector<int> arr){

    int incl = arr[0];
    int exc = 0;
    int incN,excN;
    for(int i = 1 ; i < arr.size(); i++){
       
        excN = exc > incl ? exc: incl;
        incl = exc+ arr[i];
        exc = excN;
        
    }

    return incl > exc ? incl:exc;
}


int main(int argc, char** argv){

//    vector<int > res{4,2,0,0,2,4,6,3,1,0,1,2,3,1,1} ;
    vector<int> res{1,1,1};
//    cout<<countPath(res);
    cout<<minSteps(res);

//    vector<vector<int>> lMaze{{2,7,3,8,0,3,7},
//                              {4,0,1,2,4,3,4},
//                              {3,8,5,9,0,8,1},
//                              {1,6,0,4,5,5,2},
//                              {6,2,9,5,7,0,6},
//                              {0,8,7,9,6,3,0},
//                              {1,3,5,0,5,1,0}
//                             };

//    cout<<minCostMaze(lMaze);     

//    vector<vector<int>> arr = {
//             {1, 5, 1, 0, 3},
//             {1, 4, 0, 2, 3},
//             {4, 0, 1, 3, 2},
//             {2, 4, 0, 4, 1},
//             {1, 2, 3, 2, 0},
//         };

//         cout<<GoldMine(arr);

//  int res = countBinary(5);
//  cout<<res;

//    vector<int> arr = {1, 2, 1, 3, 2, 6, 1, 2, 0, 1, 4};
//    cout<<countEncodings(arr);   

//   cout<<countABC("abcabc");

// vector<int> arr {3,2,5,1,8};
// vector<vector<bool>> res = TargetSumArr(arr,9);

//   for(int i=0; i < res.size() ; i++){
//       for(int j = 0 ;j<= res[i].size() ; j++){
//           cout<<res[i][j]<<" ";
//       }cout<<endl;
//   }

//  ptss(res, res.size()-1 , res[0].size()-1 , arr, "");
  
//   vector<int> coins{1,2,5,10};
//   cout<<"Permutation of coins "<<coinChangePermu(coins, 7)<<endl; 
//   cout<<"Combination of coins "<<coinChangeComp(coins, 5)<<endl;
//   vector<int> wt = {2, 5, 1, 3, 4};
//   vector<int> prices = {15, 14, 10, 45, 30}; 
//   zoKnapSack(wt , prices , 7);

    //  cout<<unboundzoKnapsack(wt,prices, 7);
    
    // LCS("abcd","aebd");
    // CountLpsq("abckycbc");

//   cout<< lpsq("abckycbc");  
   // lpss("abccbc");

//    cout<<CountSsM6("235168",6);
//    cout<<MPC("abccbc");

//  cout<<eggDrop(2,10)<<endl;
//    vector<int> dimensions{10,20,30,40,50,60};
//   cout<<mcm(dimensions)<<endl;

// vector<int> nodes{10,20,30,40,50,60,70};
// vector<int> freq{2,1,4,1,1,3,5};
// cout<<optimalBST(nodes, freq);

// vector<int> arr = {10,21,9,33,22,50,41,60,80,7};
// cout<<LIS(arr)<<endl;
// cout<<LBS(arr)<<endl;

//  vector<int> arr{0,3,5,6,15,10,25,12,24};
//  cout<<rodcut(arr)<<endl;

// vector<int> arr {5,6,10,100, 10, 5};
// cout<<maxsumNoAdjacent(arr)<<endl;
//    vector<int> res{1,2,3} ;
//    cout<<minSteps(res)<<endl;
//    jump(arr);

// vector<vector<int>>M{{0, 1, 1, 0, 1},  
//                     {1, 1, 0, 1, 0},  
//                     {0, 1, 1, 1, 0},  
//                     {1, 1, 1, 1, 0},  
//                     {1, 1, 1, 1, 1},  
//                     {0, 0, 0, 0, 0}};  

//  cout<<SqMatrix(M)<<endl;  

// vector<int> arr = {10,21,9,33,22,50,41,60,80,7};
// cout<<longIncSubseq(arr)<<endl;

//    struct CityPair values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}}; 
//     int n = 4; 
//     cout<<Building_Bridges(values,n)<<endl;

// Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
//   int n = sizeof(arr)/sizeof(arr[0]); 
  
//   cout<<maxStackHeight (arr, n)<<endl; 

// vector<int> arr{1, 3, 2, 8, 4, 9};
// cout<<maxProfit(arr,2);

//  cout<<isMatch("aa","a*")<<endl;
//  cout<<CountLpsq("aaa")<<endl;

// cout<<CountBinaryString(5)<<endl;
// vector<int> arr{5, 5, 10, 100, 10, 5};
// cout<<maxSum(arr)<<endl;



 
   
}