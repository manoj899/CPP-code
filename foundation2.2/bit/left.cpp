#include<iostream>
#include<String>
#include<vector>

using namespace std;

int countBits(int n){
  // complexity  O(no of bits)
    int count =0;
    while(n>0){
        count += (n&1);   // iteration is 4 times for 1101
        n= n>>1;
    }
    return count;
}

int countBitfast(int n){

    // complexity  O(no of set bit bits)
    int count = 0;
    while(n){           // for 1101 iteration is 3times
        count++;
        n =n & (n-1);
    }
    return count;
}

int getIthbit(int n,int i){    // get ith bit of a numb 
    return (n & (1<<i))!=0?1:0;
}

void setIthbit(int &n,int i){
    int mask = 1<<i;
    n = (n|mask);

}

// void clearBit(int n,int i){
//     int mask = ~(i<<i);
//     n = n&mask;
// }

// void filterChars(char *a, int no){
//     // a = "abc"  no =5 ___ (101)__output should  ac.
//       // a recieve first element address of array

//     int i=0;
//     while(no>0){
//             (no&1)?cout<<a[i]:cout<<"";     // 5 =   101
//             i++;                            //        &1  on 0&1 =0 & it print nothing 
//             no = no>>1;    // right shift         -------
//     }                                       //    -------   so on
//     cout<<endl;
// }

// void generatesubsets(char *a){
//     // Generate a range of number from 0 to 2^n-1
//     int n = sizeof(a)/sizeof(char);
//     int range = (1<<n) -1;   // 2^n -1   for 3 it is 7       1<<n give range

//     for(int i=0; i<=range; i++){
//         filterChars(a,i);
//     }  // output   a
// // b
// // ab
// // c
// // ac                                                                                bc
// // bc
// // abc
// }



void print()
{
    vector<int> fruits ={ 1,2,3,4,5 };
  cout<<"VVV";
    for (int fruit : fruits) {
    cout<< fruits[fruit]<<" ";// fruit is an element of the `fruits` array.
    }
}

/* always put extra bracket in bitmasking as operator precedence  is low 
eg :- x&y == 0   here y == 0 is executed first then  its result with x&  
        correct one is (x&y) == 0 ;
        */



/*  1,1,2,5,7,2 find unique nos with bit masking   
      soln  ->
        take XOR of all 5 and 7 will remain left   
        take XOR of 5 and 7    101^111 = 010
        as set bit is at 1st positon so seperate all arr in two part
        on the basis of set bit at 1st pstion of all binary
       1= 001  2= 010, 5 = 101, 7 = 111
       xor of arr1  =  2^7^2    7 left
       xor of arr2 = 1^5^1     5 left
       */

//  void findUnique2(int *a, int n){

//      int res =0;
//      for(int i=0; i<n; i++){
//          res = res^a[i];                     //{1,2,3,5,7,3,2,1};
//      }

//      cout<<res<<"**";
//      // find the right most set bit in res
//      int i=0;
//      int temp =res;
//      while(temp>0){
//          if(temp&1){
//              break;
//          }
//          i++;
//          temp = temp>>1;
//      }

//      int mask = (1<<i);

//      int firstNo = 0;
//      for(int i=0; i<n ;i++){
//          if((mask&a[i]) != 0){     // here curly braces is imp as bcoz bcoz of precedence & get exexute before ! ans would be wrong
//              firstNo = firstNo^a[i];
//          }
//      }

//      int secondNo = res^firstNo;
//      cout<<firstNo<<endl;
//      cout<<secondNo<<endl;
//  }      
 
///  a hulk on level 1 and a enemy on level 13..in how many jump hulk will reach enemy
/*    ans-> for 13 = 1  1  0  1 so ans is 3 jumps 

                    2^3 2^2    2^1 = 13      
                     for 5 ->  its 2 jump
                     so ans it no of setbits  */

/* find lucky no. from arr   44,56,76,78 ,99,88,45,67,57    ans -> all no with 7 and 4 at decimal place...76,78 ,44, 45 */                    


int main(int argc,char** argv){
// change ith bit of no to 1
    // int n;
    // int i;
    // // cin>>n;
    // // cin>>i;

    // // cout<<countBits(n)<<endl;
    // // cout<<countBitfast(n);
    // // cout<<getIthbit(13,2);

    // // setIthbit(n,i);
    // // clearBit(n,i);
    // // cout<<n;
    // char A[10];
    // cin>>A;

    // vector<vector<char>>  p{{c0,c2,c3},
    //                         {c1,c3}, 
    //                          {c0,c2}};
    // generatesubsets(A);

      void print();
   
    // int arr[10] = {1,2,3,5,7,3,2,1};
    // findUnique2(arr,8);

    /* robber ask a person to give him 65 rupees..
      person has  notes of 10,15,20,25,30
      find how  many ways of notes he can give to robber   */  
    
    // cout<<n;
    // cout<<(1<<4);

}
