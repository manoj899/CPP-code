#include<iostream>
#include<vector>

using namespace std;

void celebrity(vector<vector<bool>> mat){

     int left = 0;
     int right = mat.size()-1;

    while(left != right){

        if(mat[left][right]== true){
            left++;
        }
        else
        {
            right --;
        }
       

    }  


    for(int i=0;i<mat.size();i++){


        if(i != left){
        if(mat[i][left]==false || mat[left][i] == true){
          
          cout<<-1<<endl;
          return ;
        }
        

    }
    cout<<left<<endl;
}


int main(int argv,char** argc){

  
     
     vector<vector<bool>> mat {{false,true,true,false,true,true},
                             {true,false,true,true,true,true},
                             {true,false,true,true,true,true},
                             {true,true,true,true,true,false},
                             {false,false,false,false,false,false},
                             {true,false,true,true,true,false}
     };

     celebrity(mat);
}

