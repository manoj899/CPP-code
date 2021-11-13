#include<iostream>
#include<vector>
#include<string>
using namespace std;

class node
{
    public:

    int data;
    vector<node*> children;

    node(int data){
        this->data=data;
    }
};



int main(int argc,char** argv){
    vector<int> dlist { 
      10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1
  };
   node* root = construct(dlist);
 
   
 display(root);
}