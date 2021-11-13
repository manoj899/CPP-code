#include<iostream>
#include<climits>
#include<string>

using namespace std;

void countsort(int arr[]){
int output[strlen(arr)];
    int max=INT_MIN;
    int min=INT_MAX;

    for(int i=0;i<7;i++){

        if(max<arr[i]){
            max =arr[i];
        }else if(arr[i]<min){
            min=arr[i];
        }
    }
   memset(count, 0, sizeof(count)); 
    for(int i=0;i<7;i++){
      ++count[arr[i]];
    }

  for(int i=strlen(arr)-1;i>=0;--i){
      output[count[arr[i]]-1]= arr[i];
      count--;
  }
  
    for (int i = 0;i< arr[i]; ++i)  {
        arr[i] = output[i];  
}
}

int main(int argc,char** argv){

    int arr[]={10,7,12,4,9,13};
    countsort(arr);

    for(int i=0;i<7;i++){
        cout<<arr[i];
    }
}

