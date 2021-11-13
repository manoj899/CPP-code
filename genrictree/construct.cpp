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


node* construct(vector<int>& dlist){
    node* root=NULL;
    vector<node*> nlist;
    node* ln;
    node*  nn;

    for(int i=0;i<dlist.size();i++)
    {
        if(dlist[i]==-1)
        {
            nlist.pop_back();
        }
        else{
          nn=new node(dlist[i]);}
           
         if(nlist.size()==0){
            root=nn;
        }else{
            ln=nlist.back();
             ln->children.push_back(nn);
           
        }
        nlist.push_back(nn);     
        }
    } 
      return root;
}


node* display(node *root){

    string s=to_string(root->data)+ "->";

    for(int i=0;i<root->children.size();i++){
       s+=to_string(root->children[i]->data)+",";

    }
    cout<<s<<" "<<endl;

     for(int i=0;i<root->children.size();i++){
     display(root->children[i]);

    }
}

 int  mymax(node* root){
     int rm=root->data;

      for(int i=0;i<root->children.size();i++){
       int cm = mymax(root->children[i]);
       rm=max(rm,cm);
       
       }
      return rm;

      
    }

 int mysize(node* root){
    int sz=0;
 
    for(int i=0;i<root->children.size();i++){
       int cs = mysize(root->children[i]);
       sz=cs;
       }
       sz+=1;
       return sz;
 }

//int myheight(node* root){}

vector<int>* n2rpath(node* root,int dtf)
{
     if(root->data==dtf){
      vector<int>* bs=new vector<int>();

    bs->push_back(root->data);
    return bs;
    }
    


    for(int i=0;i<root->children.size();i++){
        vector<int>* n2rpath(root->children[i],dtf);
        
        
        if(n2cpath!=NULL){
          vector<int> n2cpath;
            n2cpath->push_back(root->data);
            return n2cpath;
        }
    }
}


int lca(node* root,int d1,int d2){
   
    
    vector<int>* p1= n2rpath(root,d1);
    vector<int>* p2= n2rpath(root,d2);

    int i=p1->size()-1;
      int j=p2->size()-1;  
    int prev;
    while((*p1)[i]==(*p2)[j]&& i>=0 && j>=0)
    {  
        prev = (*p1)[i];
        i--;
        j--;
    }

    return prev;
    
    }

}

void mirror(node* root){
    for(int i=0;i<root->.size();i++){
        mirror(root->children[i]);

    }
    int left =0;
    int right = root->children.size()-1;
    while(left<right){
        node* ln=root->children[left];
         node* rn=root->children[right];

         root->children[left]=rn;
         root->children[right]=ln;

         left++;
         right--;
    }
}

int distance(node* root,int d1,int d2){

    vector<int>* p1= n2rpath(root,d1);
    vector<int>* p2= n2rpath(root,d2);

    int i=p1->size()-1;
      int j=p2->size()-1;  
    
    while((*p1)[i]==(*p2)[j]&& i>=0 && j>=0)
    {
        i--;
        j--;
    }

    return (i+1)+(j+1)+1;
    
    }


bool find(node* root,int dtf){

    if(root->data==dtf){
        return true;
    }

    for(int i=0;i<root->children.size();i++){
        bool fic= find(root->children[i],dtf);
        if(fic==true){
            return true;
        }
         return false;        
    }
}

node* linearize2(node* root){

    node* ol=root->children.back();
    node* olt=linearize2(ol);

    while(root->children.size()>1){
        node* s1= root->children[root->children.size()-2];
        node* slt= linearize2(s1);
        node* last = root->children[root->children()-1];
        root->children.pop_back();
        slt->children.push_back(last);

    }
    return olt;
}

bool ass(node* r1,node* r2){  //are similar structure
    if(r1->children.size()!=r2->children.size())
    {
        return false;
    }
    for(int i=0;i<r1->children.size();i++){
        node* c1=r1->children[i];
        node* c2=r2->children[i];

        if(ass(c1,c2)==false)
          {
              return false;
          }
    
    }
    return true;
    
        
    
}

void multisolver(node *root,int depth,int max,int min,int size, int hiet,int dataa ){
    size++;
    hiet= depth>hiet? depth : hiet;
    max = root->data >max ? root-> data :max;
    min = root->data < min ? root-> data : min;

    for(int i=0;i<root->children.size();i++)
    {   if(data == root->children[i])
        multi(root->multisolver[i],depth +1,max,min,size,heit);
    }
}

void preandsucc2(node* root,int key,int& pre,int& curr,int& pred,int &succ ){
    prev=curr;
    curr= root->data;

    if(prev==key){
        pred = prev;
    }
    else if(prev == key){
        succ=curr;
    }

    for(int i=0;i<root->children.size();i++){
        preandsucc2(root->children[i],key,pre,curr,pred,succ);
    }
}

 void floorforkthlargest(node* root,int &fr,int key){
    fr = root->data<key && root->data>fr? root->data:fr;

    for(int i=0;i<root->children.size();i++){
        floorforkthlargest(root->children[i],fr,key)
    }
}

int kthlargest(node* root,int k){
    int res = INT_MIN;
    int key =INT_MAX;

    for(int i=0;i<k;k++){
        floorforkthlargest(root,res,key);
        key = res;
        res= INT_MIN;
    }
    return key;

}

void levelo(node* root){
    list<node*> queue;
    queue.push_back(root);

    while(queue.size()>0){

        node* fr= queue.front();
        queue.pop_front();

        cout<<fr->data<<" ";

        for(int i=0;i<fr->children.size();i++){
            queue.push_back(fr->children[i]);
        }
    }

    cout<<endl;
}


void 
void levelolwzz(node* root){
    list<node*> *curr =new list<node*>(); //new linkedlist

    list<node*>* next=new list<node*>();
    curr->push_back(root); //add

    while(curr->size()>0)
    {
        node* fr = curr->front();
        curr->pop_front();
        cout<<fr->data<<" ";
    
       if(ltr){
        for(int i=0;i<fr->children;i++)
        {
            next->push_front(fr->children[i]); //addlast
        }
        else{
            for(int i=front->children.size()-1;i>=0;i--){
                next->push_front(fr->children[i]);
            }
        }
        if(curr.size()==0){
            delete curr;
            curr=next;
            next = new link<>();
            cout<<endl;
            ltr=!ltr;
        }
    }
}



int main(int argc,char** argv){
  vector<int> dlist { 
      10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1
  };
   node* root = construct(dlist);
 
   // linearize2(root);
 //display(root);
 //mysize(dlist);
 //cout<<mymax(dlist)
 
// int mx = INT_MIN;  // for multisolver fucn
// int mn = INT_MAX;
// int size =0;
// int hiet =0;  

//multisolver(root,0,max,min,size,heit)

//floorforkthlargest();

levelo(root);
   }  