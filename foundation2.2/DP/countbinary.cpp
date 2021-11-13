#include<iostream>
#include<string>


using namespace std;

int countbinary(int n)
{
    int c0=1;
    int c1= 1;

    for(int i=2; i <= n; i++)
    {
        int nc0 = c1;
        int nc1 = c0 + c1;

        c0 = nc0;
        c1 = nc1;

        return  c0 + c1;
    }
}


int countEncodings(int arr){

    int size =  sizeof(arr)/sizeof(int);
        int strg[size];

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
        
        for(int i = 2; i < size; i++){
            if(arr[i] != 0){
                strg[i] = strg[i - 1];
            }

            int num2 = arr[i - 1] * 10 + arr[i];
            if(num2 >= 10 && num2 <= 26){
                strg[i] += strg[i - 2];
            }
        }

        return strg[size - 1];
    }

int main(int argv,char** argc)
{

   //// cout<<countbinary(6);

    int arr[] = {1, 2, 1, 3, 2, 6, 1, 2, 0, 1, 4};
   
    cout<<countEncodings(arr);

}