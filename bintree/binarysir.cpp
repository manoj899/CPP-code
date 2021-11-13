#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node 
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* construct(vector<int>& arr)
{
    Node* root = NULL;

    vector<Node*> stack;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == -1){
            stack.pop_back();
        } else {
            Node* node = new Node(arr[i]);
            
            if(stack.size() == 0){
                root = node;
                       } 
            else {
                      Node* tos = stack.back();
                     if(tos->left == NULL)
                     {
                      tos->left = node;
                     }      
                     else {
                      tos->right = node;
                     }
                }

            stack.push_back(node);
        }
    }

    return root;
}

void display(Node* root)
{
    if(root->left != NULL && root->right != NULL){
        cout << root->left->data << " <- " << root->data << " -> " << root->right->data << endl; 
        display(root->left);
        display(root->right);        
    } else if(root->left != NULL){
        cout << root->left->data << " <- " << root->data << " -> " << "." << endl;
        display(root->left);
    } else if(root->right != NULL){
        cout << "." << " <- " << root->data << " -> " << root->right->data << endl; 
        display(root->right);
    } else {
        cout << "." << " <- " << root->data << " -> " << "." << endl; 
    }
}

int size(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int ls = size(root->left);
    int rs = size(root->right);
    return ls + rs + 1;
}

int sum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int ls = sum(root->left);
    int rs = sum(root->right);
    return ls + rs + root->data;
}

int mymax(Node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    int ls = mymax(root->left);
    int rs = mymax(root->right);
    return max(root->data, max(ls, rs)); // Math.max
}

int height(Node* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1; // Math.max
}

int size2(Node* root)
{
    int ls = 0, rs = 0;

    if(root->left != NULL)
        ls = size2(root->left);

    if(root->right != NULL)   //   ask what is thesse two function size2,3;
        rs = size2(root->right);

    return ls + rs + 1;
}

int size3(Node* root)
{
    int ls = 0, rs = 0;

    if(root->left != NULL && root->right != NULL){
        ls = size3(root->left);
        rs = size3(root->right);
    }
    else if(root->left != NULL){
        ls = size3(root->left);
    }
    else if(root->right != NULL){
        rs = size3(root->right);
    }
    else {
    }
        
    return ls + rs + 1;
}

bool find(Node* root, int data)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->data == data)
    {
        return true;
    }

    bool filc = find(root->left, data);
    if(filc == true)
    {
        return true;
    }

    bool firc = find(root->right, data);
    if(firc == true)
    {
        return true;
    }

    return false;
}

vector<int>* n2rp(Node* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root->data == data)
    {
        vector<int>* bl = new vector<int>();
        bl->push_back(root->data);
        return bl;     // returning address of vector not actual vector
    }

    vector<int>* n2lfp = n2rp(root->left, data); //getting address of vector..no new vector get created here
    if(n2lfp != NULL)
    {
        n2lfp->push_back(root->data); //accessing vector through its address by pointer and pusing in that vector
        return n2lfp;
    }

    vector<int>* n2rgp = n2rp(root->right, data);
    if(n2rgp != NULL)
    {
        n2rgp->push_back(root->data);
        return n2rgp;
    }

    return NULL;
}

void kdown(Node* root, Node* pbt, int k)
{
    if(root == NULL || root == pbt)
    {
        return;
    }

    if(k == 0)
    {
        cout << root->data << " ";
        return;
    }
    kdown(root->left, pbt, k - 1);
    kdown(root->right, pbt, k - 1);
}

vector<Node*>* n2rp2(Node* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root->data == data)
    {
        vector<Node*>* bl = new vector<Node*>();
        bl->push_back(root);
        return bl;
    }

    vector<Node*>* n2lfp = n2rp2(root->left, data);
    if(n2lfp != NULL)
    {
        n2lfp->push_back(root);
        return n2lfp;
    }

    vector<Node*>* n2rgp = n2rp2(root->right, data);
    if(n2rgp != NULL)
    {
        n2rgp->push_back(root);
        return n2rgp;
    }

    return NULL;
}

void kfar(Node* root, int d, int k)
{
    vector<Node*>* path = n2rp2(root, d);

    for(int i = 0; i <= k && i < path->size(); i++)
    {
        if(i == 0)
        {
            kdown(path->at(i), NULL, k - i);
        }
        else
        {
            kdown(path->at(i), path->at(i - 1), k - i);
        }
    }
}

// wont work
void removeLeaves1(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        root = NULL;
        return;
    }
    removeLeaves1(root->left);
    removeLeaves1(root->right);
}

void removeLeaves2(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
    {
        delete root->left;
        root->left = NULL;
        return;
    }

    if(root->right != NULL && root->right->left == NULL && root->right->right == NULL)
    {
        delete root->right;
        root->right = NULL;
        return;
    }

    removeLeaves2(root->left);
    removeLeaves2(root->right);
}

Node* removeLeaves3(Node* root)
{   
    if(root == NULL)
    {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    root->left = removeLeaves3(root->left);
    root->right = removeLeaves3(root->right);
    return root;
}

void psc(Node* root)
{
    if(root->left != NULL && root->right != NULL)
    {
        psc(root->left);
        psc(root->right);
    }
    else if(root->left != NULL)
    {
        cout << root->left->data << endl;
        psc(root->left);
    }
    else if(root->right != NULL)
    {
        cout << root->right->data << endl;
        psc(root->right);
    }
    else
    {
        // none
    }
}

void pir(Node* root, int lo, int hi, vector<int>& path, int sum)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {    
        path.push_back(root->data);
        sum = sum + root->data;

        if(sum >= lo && sum <= hi)
        {
            for(int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        path.pop_back();
        return;
    }


    path.push_back(root->data);
    pir(root->left, lo, hi, path, sum + root->data);
    pir(root->right, lo, hi, path, sum + root->data);
    path.pop_back();
}

void posto(Node* root)    
    {
        if(root==NULL){
            return ;
        }
       posto(root->left);
          posto(root->right);
        
       
        cout<<root->data<<endl;

    }

void preo(Node* root)    
    {
        if(root==NULL){
            return ;
        }

          cout<<root->data<<endl;
       preo(root->left);
          preo(root->right);
        
       
    }    

void ino(Node* root)    
    {
        if(root==NULL){
            return ;
        }

         
       ino(root->left);
        cout<<root->data<<endl;
          ino(root->right);
        
       
    }  

Node* construct2(vector<int>& preo,vector<int>& ino,int prstr ,int prend,int instrt,int inend)
{

    if(prstr >prend || instrt >inend){
        return NULL;

    }

    Node* root = new Node(preo[prstr]);
    int lhs=0;

    for(int i=instrt;i<=inend;i++){
        if(inend=preo[prstr]){
            break;
        }

        else{
            lhs++;
        }

    }

    root->left=construct2(preo,ino,prstr+1,prstr+lhs,instrt,instrt+lhs-1);
    root->left=construct2(preo,ino,prstr+lhs+1,prend,instrt+lhs+1,inend);

    return root;
}   

/*Node* construct2(vector<int>& preo,vector<int>& ino,int prstr ,int prend,int instrt,int inend)
{

    if(prstr >prend || instrt >inend){
        return NULL;

    }

    Node* root = new Node(preo[prstr]);
    int lhs=0;

    for(int i=instrt;i<=inend;i++){
        if(inend=preo[prstr]){
            break;
        }

        else{
            lhs++;
        }

    }

    root->left=construct2(preo,ino,prstr+1,prstr+lhs,instrt,instrt+lhs-1);
    root->left=construct2(preo,ino,prstr+lhs+1,prend,instrt+lhs+1,inend);

    return root;
}  */

Node* construct3(vector<int>& preo,vector<int>& posto,int prestr,int prend,int poststr,int postend){
  
    if(prestr>prend){
        return NULL;
    }

    if(prestr== prend){
        Node* root = new Node(preo[prestr]);
        root->left = NULL;
        root->right =NULL;

        return root;
    }

    Node* root= new Node(preo[prestr]);
    int lhs=1;

    for(int i=prestr;i<=postend-1;i++){
        if(preo[prestr +1] == posto[i]){
            break;
        }
        else{
            lhs++;
        }
    }

    root->left=construct3(preo,posto,prestr+1,prestr+lhs,poststr,poststr+lhs-1);
    root->right = construct3(preo,posto,prestr+lhs+1,prend,poststr+lhs,postend-1);

   
}

Node* construct4(vector<int>& da,vector<int>&pa){
    
    Node root=NULL;
    Node* narr[101]={NULL};

    for(int i=0;i<da.size();i++){
        narr[da[i]] = new Node[da[i]];  // hashing
    }
  
   for(int i=0;i<da.size();i++){
    if(pa[i]==-1){
      root = narr[da[i]];
    }
    else{
        Node* node = narr[da[i]];
        Node* parent = narr[pa[i]];

        if(parent->left == NULL){
           parent->left = node;
        }
        else{
            parent->right = node;
        }
    }
   }
   return root;

}

class diapair
{
    public:
    int ht =0;
    int dai = 0;

}

diapair* daimeter2(Node* root);
{

    if(root== NULL){
        diapair* bp = new diapair();
        bp->ht=0;
        bp->dia =0;
        return bp;
    }
    diapair lp= daimeter2(root->left);
    diapair rp= daimeter2(root->right);

    diapair* mp = new diapair();
    mp->dai = max((lp->ht+rp->ht),max(lp->dia,rp->dia));

    mp->ht= max(lp->ht,rp->ht)+1;
    return mp;
}

 void isbalance(Node* root){

        
  if(root==NULL){
   cout<<"balanced"<<endl;
  }
  int ls = isbalance(root->left);
  int rs = isbalance(root->right);

  if(ls-rs== -1 ||ls-rs= 0 || ls-rs = 1){
      cout<<"\nbalanced tree"<<endl;
  }else{
      cout<<"not balanced"<<endl;
  }

  
}
    
 

 
int main(int argc, char** argv)
{
    vector<int> dlist {50, 25, 12, -1, 37, 30, -1, -1, -1, 75, 62, 60, -1, -1, -1, -1};
    Node* root = construct(dlist);
    display(root);

    // cout << find(root, 30) << endl;
    // vector<int>* res = n2rp(root, 30);
    // for(int i = 0; i < res->size(); i++)
    // {
    //     cout << res->at(i) << " ";
    // }
    // cout << endl;

    // vector<int> list1 {
    //     1, 2, 4, -1, 5, 6, 8, 20, 22, -1, -1, 21, -1, -1, 9, 12, 14, -1, 15, 18, -1, 19, -1, -1, -1, 13, -1, -1, -1, 7, 10, -1, 11, 16, -1, 17, -1, -1, -1, -1, -1, 3, -1, -1
    // };
    // Node* nr = construct(list1);
    // kfar(nr, 9, 3);

    // cout << "*****************************************" << endl;
    // removeLeaves(root);
    // display(root);
    // psc(root);

//     preo(root);
//     cout<<endl<<"**********\n";
//    //  posto(nr);
//     posto(root);
//    vector<int> preo {50,25,12,10,37,30,75,62,87,90};
//    vector<int> ino  {10,12,25,30,37,50,62,75,87,90};
//    vector<int> posto {10,12,30,37,25,62,90,87,75,50};
  // Node *nnn =construct2( preo, ino, 0 ,11, 0,9);
 //  display(nnn);
   
//    Node *mmm =construct3( preo, posto, 0 ,11, 0,9);

//     display(mmm);

//     vector<int> dataarr {30,40,37,12,25,75,62,87,50};
//     vector<int> parentarr{37,37,25,25,50,50,75,75,-1}
//     Node *jj=construct4(dataarr,parentarr);
//     display(jj);
}