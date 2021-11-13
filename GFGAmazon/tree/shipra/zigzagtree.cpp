#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* Bconstruct(vector<int> arr){

    Node* root;
    stack<Node*> st;
    for(int i =0; i<arr.size(); i++){
        
        if(arr[i] == -1){
                st.pop();
        }
        else{
             Node* node = new Node(arr[i]);

            if(st.size() == 0){
                
                root = node;
            }
            else{
                    Node* nn = st.top();
                    if(nn->left == NULL){
                        nn->left = node;
                    }
                    else{
                        nn->right = node;
                    }
                
                }
            st.push(node);
            }
    }
    return root;
}


void BDisplay(Node* root){

    if(root == NULL){
        return;
    }

    if(root->left != NULL && root->right != NULL){
        cout<<root->left->data<<" <-"<<root->data<<"-> "<<root->right->data<<endl;      
    }
    else if(root->left != NULL && root->right == NULL){
        cout<<root->left->data<<" <-"<<root->data<<"->. "<<endl;      
    }
    else if(root->left == NULL && root->right != NULL){
        cout<<".<-"<<root->data<<"->"<<root->right->data<<endl;      
    }
    else if(root->left == NULL && root->right == NULL){
        cout<<".<-"<<root->data<<"->."<<endl;      
    }

    BDisplay(root->left);
    BDisplay(root->right);
}

void zigzag(Node* root){

    stack<Node*> ms,cs;
    ms.push(root);
    

    while(ms.size() >0 || cs.size() >0){

        while(ms.size()> 0){
            Node* rem = ms.top();
            ms.pop();
            cout<<rem->data<<" ";

            if(rem->left){
                cs.push(rem->left);
            }
            if(rem->right){
                cs.push(rem->right);
            }

        }cout<<endl;

        while(cs.size()> 0){
            Node* rem = cs.top();
            cs.pop();
            cout<<rem->data<<" ";

            if(rem->right){
                ms.push(rem->right);
            }
            if(rem->left){
                ms.push(rem->left);
            }
        }cout<<endl;
    }
}

void leftView(Node* root){

    if(root == NULL) return;

    queue<Node*> pq;
    pq.push(root);
    pq.push(NULL);
    vector<int> res;
    res.push_back(root->data);

    while(pq.size() > 0 ){
        Node* front = pq.front();
        pq.pop();

        if(front == NULL){
            cout<<res[res.size()-1]<<" ";
            pq.push(NULL);
            res.clear();
            continue;
        }

        if(front->left) pq.push(front->left);
        if(front->right) pq.push(front->right);

        pq.push(NULL);
        res.push_back(front->data);
    }

    
}

//left and right covered here
void LeftView(Node* root){

    if(root == NULL) return;

    queue<Node*> pq;
    pq.push(root);
    pq.push(NULL);
     vector<int> res;
     res.push_back(root->data);

    while(pq.size()>1){

        Node* removal = pq.front();
        pq.pop();

        if(removal == NULL){

            cout<<res[res.size()-1]<<" ";
            res.clear();
            pq.push(NULL);
            continue;
        }

        if(removal->left){
            pq.push(removal->left); 
        }
        if(removal->right){
            pq.push(removal->right);
        }

        res.push_back(removal->data);

    }
    cout<<res[res.size()-1];
    res.clear();
    pq.pop();
}

//top view..learn it ..its diffifult

void TopView(Node* root){

    if(root == NULL) return;
    
    queue<pair<int,Node*>> q;
    q.push(make_pair(0,root));
    map<int,Node*> res;

    for(auto i = q.front(); !q.empty(); q.pop(), i=q.front()){
        if(! i.second) continue;

        res.insert(i);
        q.push({i.first+1 , i.second->right});
        q.push({i.first-1 , i.second->left});
    }

    for(auto i:res){
        cout<<i.second->data<<" ";
    }

}

//bottom view

void BottomView(Node* root){

    if(root == NULL) return;
//Note:-> imp:::----> pair is like basic element ..  map is like array of pair
    queue<pair<int,Node*>> pq;
    pq.push(make_pair(0,root));
    map<int,int> mp;

    while(pq.size() > 0){
        pair<int,Node*> removed = pq.front();
        pq.pop();
        Node* node = removed.second;

        if(node->left){
         pq.push(make_pair(removed.first-1,node->left));
         mp[removed.first-1] = node->left->data;
        }
        if(node->right)
        {
            pq.push(make_pair(removed.first+1,node->right));
            mp[removed.first+1] = node->right->data;
        }
    }

    for(auto i=mp.begin() ; i != mp.end(); i++ ){
        cout<<i->second<<" ";
    }
}

int isBSTUtil(Node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
     
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return isBSTUtil(node->left, min, node->data-1) &&  isBSTUtil(node->right, node->data+1, max);// Allow only distinct values
}
    
bool isBST(Node* root) 
{   
    return(isBSTUtil(root, INT_MIN, INT_MAX));
}

void verticalOrder(Node *root)
    {
      if(root == NULL) return ; 
      
     unordered_map<int,vector<int>> mp;
      
      queue<pair<Node*,int>> pq;
      pq.push(make_pair(root,0));
      mp[0].push_back(root->data);
      
      while(pq.size() >0){
        auto removed = pq.front();
        pq.pop();
        
        if(removed.first->left)
        {
            pq.push(make_pair(removed.first->left,removed.second-1));
            mp[removed.second-1].push_back(removed.first->left->data);
        }
        
        if(removed.first->right)
        {
            pq.push(make_pair(removed.first->right,removed.second+1));
            mp[removed.second+1].push_back(removed.first->right->data);
        }
        
      }
      

      
      for(auto i=mp.begin(); i != mp.end(); i++){
          cout<<"* ";
          vector<int> temp = i->second;
          cout<<i->first<<" -> ";
          for(int j=0; j < temp.size(); j++){
            //   result.push_back(temp[i]);
            cout<<temp[j]<<",";
          }
          cout<<endl;
      }     
}

int main(){

    vector<int> arr{10,20,40,80,-1,90,-1,-1,50,-1,-1,30,60,100,200,-1,-1,-1,70,110,-1,120};

    Node* root = Bconstruct(arr);
    // BDisplay(root);
    // zigzag(root);

    // LeftView(root);
    // TopView(root);
    // BottomView(root);
    verticalOrder(root);
    return 0;

}