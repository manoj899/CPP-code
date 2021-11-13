#include<bits/stdc++.h>

using namespace std;

//DP is all about tabulation and memoisation

//fibonacci  ... 0,1,1,2,3,5,8....

int findFibonacci(int n , vector<int>& A){
       
    if(n == 0 || n == 1){
        return n;
    }

    if(A[n] != 0){
        return A[n];
    }

    int n1 = findFibonacci(n-1,A);
    int n2 = findFibonacci(n-2,A);

    A[n] = n1+n2;
    // cout<<A[n]<<" ";
    return n1+n2;
}

int fibonacci(int n){
 
   vector<int> Arr(n+1,0);
   return findFibonacci(n,Arr);
}

//climb down stair..u can takek step of 1,2,3 and have to climb down n stair. find total possible way

int findTotalPath(int n,vector<int>& A){// here memoisation is used
    if(n == 0 ||n == 1){
        return 1;
    }
    else if(n <0){
        return 0;
    }

    if(A[n]!= 0){
        return A[n];
    }

    int n1 = findTotalPath(n-1,A);
    int n2 = findTotalPath(n-2,A);
    int n3 = findTotalPath(n-3,A);

    A[n] = n1+n2+n3;

    return A[n];

}




int climbDownStair(int n){

    vector<int> A(n+1,0);
    return findTotalPath(n,A);
}

//dynamic stair..stair arr is given in which at every index max step that can be taken is given
//tell total number of possible path.

//here tabulation is being used..in maximum no recursion is used.
int DynamicStair(vector<int> stairs){

    vector<int> res(stairs.size(),0);
    res[stairs.size()-1] = 1;

    for(int i=stairs.size()-2; i >=0 ; i--){
        int n = stairs[i];
        if(n == 0) res[i] = 0;
        else if(n>0){
            int j=0;
            for(int k = 0; k<n;k++){
                j += res[k+i+1];
            }
            res[i] = j;
        }
    }

    for(auto i:res) cout<<i<<" ";
    cout<<endl;
    return res[0];

}

int DynamicStair(vector<int> stairs){

    vector<int> res(stairs.size(),0);
    res[stairs.size()-1]  =1;

    for(int i = stairs.size()-2; i >= 0; i--){
        int step = stairs[i];
        int j = 0;
        for(int k = 0 ; k < step; k++){
            j += res[k+i+1];
        }
    }
    
}

//minimum possible steps
int minStep(vector<int>& stairs){

    vector<int> res(stairs.size(),0);

    for(int i = stairs.size()-2; i>=0; i--){
        int n = stairs[i];

        if(n == 0) res[i] = 0;
        else if(n >0){

            int j = INT_MAX;
            for(int k=0; k<n; k++){
                if((i+k)<stairs.size()){
                    j = min(res[k+i+1],j)+1;
                }
                
            }
            res[i] = j;
        }
    }

    
    return res[0];
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

// Find all N-digit binary strings without any consecutive 1’s

// method 1 : by recursion
//here the time complexity is 2^n and n stack level
int countString(int n,int last_digit){

    //base condition
    if(n == 0) return 0;

    if(n == 1){
        if(last_digit) return 1; // if last digit is 1
        else return 2;  // if the last digit is 0, we can have both 0 and 1 at the current position
    }
    else{
        
        if(last_digit) return countString(n-1,0);
        else{
            // if the last digit is 0, we can have both 0 and 1 at the current position
            return countString(n-1,1) + countString(n-1,0);
        }
    }
}

//method 2: in O(n) time and O(1) space 
void countStrings(int n){

    int C1 = 1;
    int C0 = 1;
    int nc1,nc0;

    for(int i = 2; i<=n;i++){

        nc0 = C0+C1;
        nc1 = C0;
        C1 = nc1;
        C0 = nc0;

    }

    cout<<"Total string -> "<<C0+C1;
}

// Number of subsequences of the form a^i b^j c^k
int countABC(string s){
    int a =0;
    int b =0;
    int c =0;

    for(int i=0; i<s.size(); i++){

        if(s[i] == 'a'){
            a = 1+2*a;
        }
        else if(s[i] == 'b'){
            b = a+ 2*b;// 2b-> b can append with those subsequence 'a' and can not append..that why 2b..
        }
        else if(s[i] == 'c'){
            c = b + 2*c;
        }
    }

    return c;
}



int main(){

    // int n;
    // cin>>n;
    // vector<int> arr(n+1,0);
    // cout<<findFibonacci(n,arr);
    // cout<<fibonacci(8);

    // cout<<climbDownStair(5);
    // cout<<factoria(4);

    //  vector<int> stairs{4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};
     vector<int> stairs{1,1,1,0};
    // cout<<DynamicStair(stairs);
    cout<<endl;
     cout<<minStep(stairs);

    //    vector<vector<int>> arr = {
    //         {1, 5, 1, 0, 3},
    //         {1, 4, 0, 2, 3},
    //         {4, 0, 1, 3, 2},
    //         {2, 4, 0, 4, 1},
    //         {1, 2, 3, 2, 0},
    //     };

    //     cout<<GoldMine(arr);

    // cout<<countString(5,0);
    // countStrings(5);
    // cout<<countABC("aabbcc");


    return 0;
}