#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main()
{
    map<int ,int> gquiz1;

    gquiz1.insert(pair<int,int>(1,10));
    gquiz1.insert(pair<int,int>(2,20));
    gquiz1.insert(pair<int,int>(3,30));
    gquiz1.insert(pair<int,int>(4,40));
    gquiz1.insert(pair<int,int>(5,50));
    gquiz1.insert(pair<int,int>(6,60));
    gquiz1.insert(pair<int,int>(7,70));
    gquiz1.insert(pair<int,int>(8,80));

    map<int,int>::iterator itr;

    cout<<"\t gquiz1 elements are\n";
    cout<<"\tkeyword\t elements\n";

    for(itr= gquiz1.begin();itr!= gquiz1.end(); ++itr){
        cout<<"\t"<< itr->first
        <<"\t"<< itr->second<<"\n";
    } cout<<endl;

    map<int,int> gquiz2(gquiz1.begin(), gquiz1.end());
     cout<<"\t gquiz2 elements are\n";
    cout<<"\tkeyword\t elements\n";

    for(itr= gquiz2.begin();itr!= gquiz2.end(); ++itr){
        cout<<"\t"<< itr->first
        <<"\t"<< itr->second<<"\n";
    } cout<<endl;

    //removal of element upto 3

    gquiz2.erase(gquiz2.begin(),gquiz2.find(3));
     cout<<"\t gquiz2 elements after removal upto 3\n";
    cout<<"\tkeyword\t elements\n";

    
    for(itr= gquiz2.begin();itr!= gquiz2.end(); ++itr){
        cout<<"\t"<< itr->first
        <<"\t"<< itr->second<<"\n";
    } cout<<endl;


    int sum;
    sum = gquiz2.erase(4);
    cout<<sum<<" removed\n";
     for(itr= gquiz2.begin();itr!= gquiz2.end(); ++itr){
        cout<<"\t"<< itr->first
        <<"\t"<< itr->second<<"\n";
    } cout<<endl;
}