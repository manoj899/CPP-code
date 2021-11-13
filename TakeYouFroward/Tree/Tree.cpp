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


// BFS
void BFS(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 0){
        Node* node = q.front();
        q.pop();
        
        cout<<node->data<<",";
        if(node->left) {q.push(node->left);}
        if(node->right) {q.push(node->right);}
        if(node == NULL) {
            cout<<endl;
            q.push(NULL);
        }
    }
}

//Height of BTree
int HeightOFTree(Node* root){

    if(root == NULL) return 0;

    int ldepth = HeightOFTree(root->left);
    int rdepth = HeightOFTree(root->right);

    return max(ldepth, rdepth)+1;
}

//LCA

bool LCA(Node* root, int a, int b){

    if(root == NULL) return false;
    
    if(root->data == a || root->data == b) return true;

    bool left = LCA(root->left,a,b);
    bool right = LCA(root->right,a,b);

    if(left && right) cout<<"LCA ->"<<root->data;
    if(left || right) return true;

    return false;
}

//Diameter of Btree
int Diameter(Node* root, int *height){
    if(root == NULL) 
     {
         return 0;
         height = 0;
     }   
    
    int left = 0;
    int right = 0;
    int lh =0 , rh = 0;
    left = Diameter(root->left , &lh);
    right = Diameter(root->right, &rh);

    *height = max(lh,rh)+1;

    return max(lh+rh+1, max(left,right));

}

int main(int arc,char** argv){

    vector<int> arr{10,20,40,80,-1,90,-1,-1,50,-1,-1,30,60,100,-1,-1,70,110,-1,120};

    Node* root = Bconstruct(arr);
   // BDisplay(root);
    // Morris(root);
    // LevelOrder(root);

    // cout<<endl;
    // findleaves(root);
    //  cout<<height(root,0);
    // vector<int> res;
    // res.push_back(root->data);
    // vector<int> ar= TopView(root,0,res);
    // for(auto i : ar){
    //     cout<<i<<" ";
    // }

    // BottomView(root);
    //   Diagonaltraverssal(root);
    // LCA(root,40,120);
    // vector<int> arr{1,7,5,30,50,40,10};
    // PostToBST(arr,arr.size()-1);
    //  vector<int> arr2{10,5,1,7,40,30,50};
    //  PreToBST(arr2,0);

    // BFS(root);
    // cout<<HeightOFTree(root);
    LCA(root,80,100);
}