#include<iostream>
#include<vector>
#include<string>

using namespace std;


// output is wrong..every time output is different
int countpath(vector<int>& arr)
 {
      int strg[15]; 

        strg[15 - 1] = 1;
        for(int i = 15 - 2; i >= 0; i--){
            for(int j = i + 1; j <= i + arr[i] && 
                               j < 15; j++){
                strg[i] += strg[j];
            }
        }

        return strg[0];
    }

  int minsteps(vector<int>& arr)
  {
      int strg[15];

      strg[15-1] =0;

      for(int i = 13; i>= 0; i--)
      {
          int min = 15;

          for(int j = i+1; j<= i + arr[i] && j< arr.size() ;j++)
          {
              if(strg[j] < min)
              {
                  min = strg[j];
              }
          }

          strg[i] = min+1;
      }

      return strg[0];
  }
 

int main(int argc,char** argv)
{
  vector<int> arr{4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};

 cout<< countpath(arr);
  //cout<< minsteps(arr);
}
