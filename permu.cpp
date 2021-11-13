#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printPerm(int cq, int boxbm, string asf, int tq, int tb)
{
    if(cq > tq)
    {
        cout << asf << endl;
        return;
    }

    for(int b = 0; b < tb; b++)
    {
        if((boxbm & (1 << b)) == 0)
        {
            boxbm = boxbm ^ (1 << b);
            printPerm(cq + 1, boxbm, 
                      asf + "q" + to_string(cq) + "b" + to_string(b) + " + ",
                      tq, tb);
            boxbm = boxbm ^ (1 << b);                      
        }
    }
}

void printPerm(int cq, bool boxes[], string asf, int tq, int tb)
{
    if(cq > tq)
    {
        cout << asf << endl;
        return;
    }

    for(int b = 0; b < tb; b++)
    {
        if(boxes[b] == false)
        {
            boxes[b] = true;
            printPerm(cq + 1, boxes, 
                      asf + "q" + to_string(cq) + "b" + to_string(b) + " ", tq, tb);
            boxes[b] = false;                      
        }
    }
}

void printComb(int cb, int cq, int tb, int tq, string asf)
{
    if(cb == tb)
    {
        if(cq == tq)
        {
            cout << asf << endl;
        }
        return;
    }

    printComb(cb + 1, cq + 1, tb, tq, asf + "q" + to_string(cq) + "b" + to_string(cb) + "+"); // yes
    printComb(cb + 1, cq, tb, tq, asf); // no
}

vector<vector<int>>* gts(int arr[], int tar, int sp, int n)
{
    if(sp == n)
    {
        vector<vector<int>>* bsets = new vector<vector<int>>();
        if(tar == 0)
        {
            vector<int> bv;
            bsets->push_back(bv);
        }
        return bsets;    
    }

    vector<vector<int>>* isets = gts(arr, tar - arr[sp], sp + 1, n);
    vector<vector<int>>* esets = gts(arr, tar, sp + 1, n);
    vector<vector<int>>* msets = new vector<vector<int>>();

    for(int i = 0; i < isets->size(); i++)
    {
        (*isets)[i].push_back(arr[sp]);
        msets->push_back((*isets)[i]);
    }

    for(int i = 0; i < esets->size(); i++)
    {
        msets->push_back((*esets)[i]);
    }

    delete isets;
    delete esets;

    return msets;
}

int main(int argc, char** argv)
{
    bool boxes[5];
    printPerm(1, boxes, "", 2, 5);
    // printPerm(1, 0, "", 2, 4);
    // int arr[] = {10, 20, 30, 40, 50, 60, 70};
    // int tar = 70;
    // vector<vector<int>>* res = gts(arr, tar, 0, 7);
    // for(int i = 0; i < res->size(); i++)
    // {
    //     for(int j = 0; j < (*res)[i].size(); j++)
    //     {
    //         cout << (*res)[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}




