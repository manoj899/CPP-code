#include<iostream>
#include<queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>


void gshow(priority_queue <int>gq){

    while(!gq.empty()){
        cout<<gq.top()<<"\t";
        gq.pop();
    }
    cout<<"\n";
}

int main(int argv,char** argv){

    priority_queue<int> gquiz;

    gquiz.push(10);
    gquiz.push(5);
    gquiz.push(3);
    gquiz.push(7);
    gquiz.push(8);
    gquiz.push(9);

    cout<<"THE PRIORITY QUEUE   gquiz is :";
    gshow(gquiz);

    cout<<"size= "<<gquiz.size()<<endl;
    cout<<"gquiz top ="<<gquiz.top();

}