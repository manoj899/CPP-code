#include<iostream>
#include<vector>

using namespace std;

vector<int> Segregate(vector<int> arr){
    int right = arr.size()-1;
    int left =0;

    while(left < right){

        while(arr[left] == 0 && left < right){
            left++;
        }

        while(arr[right] == 1 && left < right){
            right--;
        }

        if(left < right){
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }

    return arr;
}

/*
Function to put all 0s on left and all 1s on right
void segregate0and1(int arr[], int size)  
{  GFG
//     /* Initialize left and right indexes */
//     int left = 0, right = size-1;  
  
//     while (left < right)  
//     {  
//         /* Increment left index while we see 0 at left */
//         while (arr[left] == 0 && left < right)  
//             left++;  
  
//         /* Decrement right index while we see 1 at right */
//         while (arr[right] == 1 && left < right)  
//             right--;  
  
//         /* If left is smaller than right then there is a 1 at left  
//         and a 0 at right. Exchange arr[left] and arr[right]*/
//         if (left < right)  
//         {  
//             arr[left] = 0;  
//             arr[right] = 1;  
//             left++;  
//             right--;  
//         }  
//     }  
// } 


int main(int argc,char ** argv){

  vector<int> arr{0,0,0,1,1,0,1,0,1,1,1,0};
   vector<int> res=  Segregate(arr);

   for(int i=0; i<res.size(); i++){
       cout<<res[i]<<" ";
   }
   cout<<endl;
}