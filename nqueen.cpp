#include <iostream>
#include <vector>
using namespace std;

int counter = 0;  
void nqueens2(vector<vector<bool>> &board, int cq, int lqr, int lqc, string asf)
{    
    if (cq == board.size())
    {
        counter++;
        return;
    }

    for(int i = lqr; i < board.size(); i++)
    {
        for(int j = (i == lqr? lqc + 1: 0); j < board.size(); j++)
        {
            if(board[i][j] == 0)
            {
                board[i][j] = 1;
                nqueens2(board, cq + 1, i, j, asf + to_string(i) + to_string(j) + " ");
                board[i][j] = 0;
            }
        }
    }
}

bool isTheQueenSafe(vector<vector<bool>>& board, int i, int j)
{
    // horizontal
    for(int jj = 0; jj < board.size(); jj++)
    {
        if(board[i][jj] == true && jj != j)
        {
            return false;
        }
    }

    // vertical
    for(int ii = 0; ii < board.size(); ii++)
    {
        if(board[ii][j] == true && ii != i)
        {
            return false;
        }
    }

    // se
    for(int ii = i + 1, jj = j + 1; 
        ii < board.size() && jj < board.size(); 
        ii++, jj++)
    {
        if(board[ii][jj] == true)
        {
            return false;
        }
    }

    
    // sw
    for(int ii = i + 1, jj = j - 1; 
        ii < board.size() && jj >= 0; 
        ii++, jj--)
    {
        if(board[ii][jj] == true)
        {
            return false;
        }
    }

    // nw
    for(int ii = i - 1, jj = j - 1; 
        ii >= 0 && jj >= 0; 
        ii--, jj--)
    {
        if(board[ii][jj] == true)
        {
            return false;
        }
    }

    // ne
    for(int ii = i - 1, jj = j + 1; 
        ii >= 0 && jj < board.size(); 
        ii--, jj++)
    {
        if(board[ii][jj] == true)
        {
            return false;
        }
    }

    return true;
}

bool isnightsafe(vector<vector<bool>>& chess,int r,int c){
    if(r >=1 && c>=2 && chess[r-1][c-2]== true){
        return false;
    }
    else if(r>=2 && c>=1 && chess[r-2][c-1] == true){
        return false;
    }
    else if(r>=2 && c<chess.size()-1 && chess[r-2][c+1] == true){
        return false;
    }
    else if(r>=1 && c<chess.length -2 && chess[r-1][c+2]== true){
        return false;
    }
    else {
        true;
    }
}

// knight by box at choices
  void nknights(vector<vector<bool>>& chess,int i,int j,int ksf,string asf){
      if(i == chess.size() && j==0){
          if(ksf)
      }
      else if( chess,i+1,0,)
  }
bool isTheBoardSafe(vector<vector<bool>>& board)
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j] == true)
            {
                if(isTheQueenSafe(board, i, j) == false)
                {
                    return false;
                }
            }
        }
    }

    return true;
}


void nqueens(vector<vector<bool>> &board, int cq, int lqi, string asf)
{    
    if (cq == board.size())
    {
        if(isTheBoardSafe(board) == true)
        {
            counter++;
            cout << asf << endl;
        }
        return;
    }

    for (int cb = lqi+ 1; cb < board.size() * board.size(); cb++)
    {
        int i = cb / board.size();
        int j = cb % board.size();
        if (board[i][j] == 0)
        {
            board[i][j] = 1;
            nqueens(board, cq + 1, cb, asf + to_string(i) + to_string(j) + " ");
            board[i][j] = 0;
        }
    }
}

void nqueensp(vector<vector<bool>> &board, int cq, int lqi, string asf)
{    
    if (cq == board.size())
    {
        counter++;
        cout << asf << endl;
        return;
    }

    for (int cb = lqi+ 1; cb < board.size() * board.size(); cb++)
    {
        int i = cb / board.size();
        int j = cb % board.size();
        if (board[i][j] == 0 && isTheQueenSafe(board, i, j) == true)
        {
            board[i][j] = 1;
            nqueensp(board, cq + 1, cb, asf + to_string(i) + to_string(j) + " ");
            board[i][j] = 0;
        }
    }
}

int main(int argc, char **argv)
{
    vector<vector<bool>> board{
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    nqueensp(board, 0, -1, " ");
    cout << counter;
}