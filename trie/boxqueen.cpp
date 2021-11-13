#include<iostream>
#include<vector>
#include<string>

using namespace std;
printperm(cq,boxes,asf ,q)
{
    if(cq>tq)
{cout<<asf<<endl;
return;
}

for(int b=0;b<tb;b++)
{
    if(boxes[b]== false)
    {
        boxes[b] = true;
        printperm(cq+ 1,boxes,asf + "q" +to_string(cq) +"b" = to_string(b) +" ",+q);
        boxes[b]=false;

    }

}
}

int main(int argc,char** argv)
{
     bool boxes[5];
     printperm(1,boxes," ",2,5);
}
