#include<iostream>
#include<map>
#include<vector>

using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
        int min = 0;
        int fresh = 0; // fresh oranges count
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
        }

        // instead of writing many line of codes for checking direction run loop of direction
        vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        while(!q.empty()) {
            int n = q.size();
            bool rotten = false; // to keep track of time like 
            //to keep track of one layer of BFS
            for(int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                for(auto cur: dirs) {
                    int i = x.first + cur.first;
                    int j = x.second + cur.second;
                    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten) min++;
        } 

        //if fresh oranges left then return -1 else return time 
        return fresh ? -1 : min;
    }

Node* TreeFromInPostOrder(vector<int> inOrder,vector<int> postOrder, int inStart, int inEnd,int postStart,int postEnd){

    if(inStart > inEnd) return null;

    int rootVal = postOrder[postEnd];
    Node* root = new Node(rootVal);

    int rootIndex = inStart;
    for(; rootIndex <= inEnd; rootIndex++){ // finding position of root index in inorder array
        if(inOrder[rootIndex] == rootVal){
            break;
        }
    }

    int leftTreeSize = rootIndex - inStart;
    int rightTreeSize = inEnd - rootIndex;

    root->left = TreeFromInPostOrder(inOrder, postOrder, inStart, rootIndex - 1, postStart, postStart + leftTreeSize - 1); 
    root->right = TreeFromInPostOrder(inOrder, postOrder, rootIndex+1, inEnd, postEnd - rightTreeSize , postEnd - 1); // postEnd - 1 bcoz 
    return root;
}

Node* TreeFromInPostOrder(vector<int> inOrder,vector<int> postOrder,int inStart, int inEnd, int postStart, int postEnd){

    if(inStart > inEnd) return;
    int rootVal = postOrder[postEnd];
    Node* root = new Node(rootVal);

    int rootIndex = inStart;
    for(; rootIndex <= inEnd; rootIndex++){
        if(inOrder[rootIndex] == rootVal){
            break;
        }
    }

    int leftTreeSize = rootIndex-instart;
    int rightTreeSize = inEnd - rootIndex;

    root->left = TreeFromInPostOrder(inOrder, postOrder, inStart, rootIndex-1, postStart, postStart + leftTreeSize - 1);
    root->left = TreeFromInPostOrder(inOrder, postOrder, rootIndex + 1, inEnd, postEnd - rightTreeSize,  postEnd-1;
}
/////////////////////////////////////////////////////
/*
Node* TreeFromInPostOrder(vector<int> inOrder,vector<int> postOrder, int inStart, int inEnd,int postStart,int postEnd){

    if(inStart > inEnd) return NULL;

    Node* rootVal = postOrder[postEnd];
    Node* root = new Node(rootVal);

    int rootIndex = inStart;
    for(; rootIndex <= inEnd; rootIndex++){
        if(inOrder[rootIndex] == rootVal){
            break;
        }
    }

    int leftTreeSize = rootIndex - inStart;
    int rightTreeSize = inEnd - rootIndex;

    root->left = TreeFromInPostOrder(inOrder, postOrder, inStart, rootIndex - 1 , postStart, postStart+ leftTreeSize -1);
    root->right = TreeFromInPostOrder(inOrder, postOrder, rootIndex+1, inEnd , postEnd - rightTreeSize, postEnd -1);
    return root;
}
 */
//count distinct element of every window

void countDistinct(vector<int> arr, int k){
    int n = arr.size();

    map<int,int> hm;

    int dist_count = 0 ;

    for(int i = 0; i < k ; i++){
        if(hm[arr[i]] == 0){
            dist_count++;
        }
        hm[arr[i]]++;
    }

    cout<<dist_count<<" ";

    for(int i = k; i < n; i++){

        if(hm[arr[i-k]] == 1){
            dist_count--;
        }
        hm[arr[i-k]]--;

        if(hm[arr[i]] == 0){
            dist_count++;
        }
        hm[arr[i]]++;

        cout<<dist_count<<" ";
    }

}

int main(){

    vector<int> arr{1,2,1,3,4,2,3};
    countDistinct(arr,4);
    return 0;
}