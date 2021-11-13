#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data =0;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void addFirst(int data, Node*& head){
    Node* nn = new Node(data);
    nn->next = head;
    head = nn;
}

void addNode(int data, Node*& tail,Node*& head){
    if(tail == NULL){
        addFirst(data,head);
        tail = head;
    }
    else{
        Node* nn = new Node(data);
        tail->next = nn;
        tail = nn;
    }
}

void PrintLL(Node* head){

    for(Node* it = head; it != NULL; it = it->next){
        cout<<it->data<<",";
    }cout<<endl;
}


//reverse LL
Node* ReverseLL(Node*& head){
    
    if(head == NULL || head->next == NULL) return head;
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    //1->2->3->4->5->6->7

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    
    }
    return prev;
}

//add digits of two LL
Node* SumTwoLL(Node* head1, Node* head2){

    Node* curr1 = ReverseLL(head1);
    Node* curr2 = ReverseLL(head2);
    int carry = 0;
    int rem = 0;
    Node* head = NULL;
    Node* temp;
    while(curr1 != NULL && curr2 != NULL){
        int sum = carry + curr1->data + curr2->data;
        if(sum > 10){
            carry = sum / 10;
            sum = sum % 10;
        }
        else{
            carry = 0;
        }
        Node* nn = new Node(sum);

        if(head == NULL){
            head = nn;
            temp = nn;
        }else{
            temp->next = nn;
            temp = nn;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while(curr1 != NULL){
        int sum = carry + curr1->data ;
        if(sum > 10){
            carry = sum / 10;
            sum = sum % 10;
        }
        else{
            carry = 0;
        }
        Node* nn = new Node(sum);
        temp->next = nn;
        temp = nn;

        curr1 = curr1->next;
    }

    while(curr2 != NULL){
        int sum = carry + curr2->data ;
        if(sum > 10){
            carry = sum / 10;
            sum = sum % 10;
        }
        else{
            carry = 0;
        }
        Node* nn = new Node(sum);
        temp->next = nn;
        temp = nn;

        curr2 = curr2->next;
    }

    return ReverseLL(head);
}

Node* ReverseInGroup(Node* head,int N){

    if(head == NULL) return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < N){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head->next = ReverseInGroup(next,N);
    }
    return prev;

}


//


//

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    addNode(1,tail,head);
    addNode(2,tail,head);
    addNode(3,tail,head);
    addNode(4,tail2,head2);
    addNode(5,tail2,head2);
    addNode(6,tail2,head2);
    addNode(7,tail,head);

    // 
    auto node = SumTwoLL(head,head2);
    // Node* reverse = ReverseLL(node);
    PrintLL(node);
    return 0;
}