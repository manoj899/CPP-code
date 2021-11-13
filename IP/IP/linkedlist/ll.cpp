#include<iostream>

using namespace std;

class Node{

    public:
    Node *next;
    int data;

    Node(){
        this->data = 0;  
        this->next =  NULL;     
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};;

// addlast and display

void addfirst(Node*& head, Node*& tail, int data){

    Node* nn = new Node(data,head);
    head = nn; 
}

void addAt(Node*& head, Node*& tail, int data,int pos){
 int j = 1;
    for(Node* i; i->next != NULL; i = i->next){
        if(j = pos-1){
         Node* nn = new Node(data,i->next);
         i->next = nn;
         exit;
        }
         j++;
    }
    
  
}

void addlast(Node*& head, Node*& tail, int data){

    if(head == NULL){
        head = tail = new Node(data, NULL);
    }
    else{
        Node* nn = new Node(data,NULL);
        tail->next = nn;
        tail = nn;
    }
}

void display(Node* head){

    for(Node* i = head; i->next != NULL ; i = i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
}



int main(int argc,char** argv){

    Node* head = NULL;
    Node* tail = NULL;

    addlast(head, tail, 1);
    addlast(head, tail, 2);
    addlast(head, tail, 3);
    addlast(head, tail, 4);
    addlast(head, tail, 5);
    addfirst(head,tail, 55);
    addlast(head, tail, 6);
    addAt(head,tail, 33,3);

    display(head);



}