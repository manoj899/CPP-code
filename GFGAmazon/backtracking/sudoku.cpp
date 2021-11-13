#include<bits/stdc++.h>

using namespace std;

bool isValid(vector<vector<int>> board, int x,int y,int val){
    for(int j=0; j<board[0].size(); j++){
        if(board[x][j] == val){
            return false;
        }
    }

    for(int i=0; i < board.size(); i++){
        if(board[i][y] == val){
            return false;
        }
    }

    int smi = x/3*3;
    int smj = y/3*3;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[smi +i][smj +j] == val){
                return false;
            }
        }
    }
    return true;
}

void display(vector<vector<int>>& board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            cout<<board[i][j]<<",";
        }
        cout<<endl;
    }
}

void sudoku(vector<vector<int>> &board, int i, int j){

    if(i == board.size()){
        display(board);
        return;
    }
    
    int ni= 0; // next i
    int nj= 0;

    if(j == board[0].size() -1){
        ni = i+1;
        nj =0;
    }
    else{
        ni = i;
        nj = j+1;
    }

    if(board[i][j] !=0){
        sudoku(board, ni,nj);
    }
    else{
        for(int po=0; po <= 9 ; po++){
            if(isValid(board, i ,j , po) == true){
                board[i][j] = po;
                sudoku(board, ni , nj);
                board[i][j] = 0;
            }
        }
    }
}


int main(){

    vector<vector<int>> board={{3,0,6,5,0,8,4,0,0},
                               {5,2,0,0,0,0,0,0,0},
                               {0,8,7,0,0,0,0,3,1},
                               {0,0,3,0,1,0,0,8,0},
                               {9,0,0,8,6,3,0,0,5},
                               {0,5,0,0,9,0,6,0,0},
                               {1,3,0,0,0,0,2,5,0},
                               {0,0,0,0,0,0,0,7,4},
                               {0,0,5,2,0,6,3,0,0}};
    sudoku(board,0,0);

    


    return 0;
}