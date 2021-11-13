#include<iostream>
#include<string>


using namespace std;





void swap2(char *str1,char *str2)
   {
       char *temp= (char*)malloc((strlen(str)+1)*sizeof(char));
       strcpy(temp,str1);
       strcpy(str1,str2);
       strcpy(str2,temp);
       free(temp);
   }

int main(int argc,char** argv)
 {
    char str1[10] = "geek";
    char str2[10] = "forgeeks";
    swap2(str1,str2);
     
     cout<<str1<<"\n"<<str2;
 

 }