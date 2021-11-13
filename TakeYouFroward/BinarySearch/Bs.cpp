#include<bits/stdc++.h>

using namespace std;

//this matrix is sorted
bool FindIn2DMatrix(vector<vector<int>> matrix,int target){

    int m = 0;
    int n = matrix[0].size()-1;

    while(m >=0 && m < matrix.size() && n >= 0 && n < matrix[0].size()){

        if(target == matrix[m][n]) return true;
        else if(target > matrix[m][n]) m++;
        else if(target < matrix[m][n]) n--;
    }
    return false;
}

int main(){

    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<FindIn2DMatrix(matrix,1);
    return 0;
}