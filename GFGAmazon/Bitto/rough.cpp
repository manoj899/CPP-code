#include<bits/stdc++.h>

using namespace std;

Node* FindNode(Node* root,Node* node){

    if(root->data == node->data){
        return root;
    }

    if(root->left) FindNode(root->left);
    if(root->right) FindNode(root->right);
}

Node* FindNodeAtKDistance(Node* root, int k){

    queue<Node*> pq;
    pq.push(root);
    unordered_map<Node*,Node*> parent;

    while(pq.size() > 0){
        auto front = pq.front();
        if(front->left) {
            parent[front->left] = front;
            pq.push(front->left);
        } 
        if(front->right){
            parent[front->right] = front;
            pq.push(front->right);
        } 

        pq.pop();
    } 

    unordered_map<Node*,bool> visited;
    queue<pair<Node*,int>> q;
    q.push({target,K});
    visited[root] = 1;

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        if(front.second == 0) break;

        K = front.second;
        auto f = front->first;
        if(f->left != NULL && visited.find(f->left) == visited.end())
            q.push(make_pair(f-left,k-1));
        if(f->right != NULL && visited.find(f->right) == visited.end())
            q.push(make_pair(f-right,k-1));
        if(visited.find(parent[front]) == visited.end())
            q.push(make_pair(parent[f],k-1))

    }


}


int main(){

    return 0;
}