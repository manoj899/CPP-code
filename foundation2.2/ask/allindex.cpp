#include<iostream>
#include<string>

using namespace std;
                            //  not understanding syntax 

int* allindex(int *arr[],int index,int psf,int key){
     
     if(index>7){
         return res;
     }
     if(arr[index]==key){  
         int *res=new int[8];
            res[index]=allindex(arr,index+1,psf+1,key);
         res[psf] = index;
         return *res;   //in recursion dont use i++,++i,i-- precerding operator ....isntead use i+1
     }
     else{
         int res=new int[8];
        res[index]=allindex(arr,index,psf+1,key)
         return *res;   // ptr of array should be return if you return local array then it will 
                        // wipe out from stack so ptr would be dangling ..so arr return sould be of heap
            
     }
   
}

int main(int argc,char** argv){

 int arr[8]={5,4,7,2,1,8,1,1};
   int *res=allindex(arr,0,0,1);
   for(int i=0;i<=7;i++){
       cout<<*res(i)<<" ";
   }
}


