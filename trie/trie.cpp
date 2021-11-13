#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>


using namespace std;

class node
{
    public:
    char data;
    bool eow;
    unordered_map<char,node*> cmap;

    node(char data,bool eow){

        this->data = data;
        this->eow = false;

    }


};

void addword(node* root,string word){

    if(word.size()==0){
        root->eow = true;
        return;
    }
    char ch = word[0];
    string rows = word.substr(1);

    if(root->cmap.count(ch)==0){
        node* child = new node(ch,false);
        root->cmap[ch]=child;
        addword(child,rows);

    }
    else
    {
        node* child = root->cmap[ch];
        addword(child,rows);
    }
}

  /* bool search(node *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}   */

void removeword(node* root,string word){

    if(word.length(==0){
        root->eow = false;
        return;
    }
    char ch = word[0];
    string rows = word.substr(1);

    node* child = root->cmap[ch];
    removeword(child,row);

    if(child->row == false && child->cmap.size()==0){
        root->cmap.erase(ch);
        delete child;
    }
}

/*rf
void populatezarray(zarray.size()){

    int i=1;
    int l=0;
    int r=0;

    while(i<zarray.size()){
        if(i>r){
            l=r=i;
        
        while(r<zarray.size() && str[r] == str[r-l]){
            r++;
        }
        r--;
        zarray[l] = r-l+1;
        
        }
        else{
            int k=i-l;
            if(z[k]< r-i+1){
                z[i] = z[k];
            }
            else {
                r=i;
                while( r<zarray.size() && str[r]== str[r-l]){
                    r++;
                }
            }
        }
    }
}   */

void displaytree(node *root,string words){

    cout<<root-data<<"["<<root->row<<"]";

    for(auto itr = root->map.begin;(); itr!=root-> cmap.end(); itr++){
        cout<< itr->cmap.end()<<",\n";

    }
     for(auto itr = root->map.begin;(); itr!=root-> cmap.end(); itr++){
         displaytree(itr->second,wsf+ itr->first);
     }
    
}



void displayword(node* root,string wsf)
{
    if(root->eow == true)
        {
            cout<<wsf<<"   \n";
        }
            for(auto itr = root->cmap.begin();itr!=root->cmap.end();itr++){

                displayword( itr->second,wsf + itr->first);
            }
        
    
}
int main(int argc,char** argv){

    node* root = new node('s',false);

    addword(root,"are");
    addword(root,"art");
    addword(root,"an");
    addword(root,"and");
    addword(root,"ant");
    addword(root,"as");
    addword(root,"ask");
    addword(root,"see");
    addword(root,"sea");
    addword(root,"seen");
      displayword(root,"");

      removeword(
}