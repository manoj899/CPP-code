#include<iostream>

using namespace std;

//add two linked list and return result in LL

// Node* reverse(Node* head){
//     Node *cur = head,*prev = NULL, *n = NULL;
//     while(cur!=NULL){
//         n = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = n;
//     }
//     return prev;
// }

// struct Node* addTwoLists(struct Node* first, struct Node* second)
// {
//    Node* f = reverse(first);
//    Node* s =reverse(second);
//    Node *r= new Node(-1);
//    Node *temp = r;
//    int c = 0;
//    while(f!=NULL ||  s!=NULL){
//         if(f==NULL){
//             int d = s->data+c;
//             s->data = d%10;
//             if(d>=10){
//                 c = 1;
                
//             }
//            else c = 0;
//             r->next = s;
//             r = r->next;
//             s = s->next;
//             continue;
//        }
//         if(s==NULL){
//             int d = f->data+c;
//             f->data = d%10;
//             if(d>=10){
//                 c = 1;
//             }
//             else c = 0;
//             r->next = f;
//             r = r->next;
//             f = f->next;
//             continue;
//        }
//        int d= f->data + s->data+c;
//        if(d>=10) c = 1;
//        else c = 0;
//        if(r->data == -1)
//              r->data = d%10;
//         else{
//             Node *nn = new Node(d%10);
//             r->next = nn;
//             r = r->next;
//         }
//        f = f->next;
//        s = s->next;
//    }
//    if(c==1){
//        Node* nn = new Node(1);
//        r->next = nn;
//    }
//    return reverse(temp);
// }


// binary to doubly linked list inorder

void btoDDL(Node* curr,Node* head){

    if(curr == NULL) return;

    static Node* Prev = NULL;

    btoDDL(curr->left, head);
    
    if(head == NULL){
        head = curr;
    }
    else{
        curr->left = prev;
        prev->right = curr;
    }

    Prev = curr;

    btoDDL(curr->right,head);
}

// Node* addLL(Node* f, Node* s){

//     Node* t = new Node();
//     int sum = 0;
//     int rem = 0;
//     Node* head = new Node();
//     head = t;

//     while(f != NULL || s != NULL){
//         Node nn = new Node();
//         if(f->data){
//             sum += f->data;
//         }
//         if(s->data){
//             sum += s->data;
//         }
//         if(rem){
//             sum += rem;
//         }

//         if(sum > 9){
//             rem = sum/10;
//             sum = sum%10;
//         }

//         nn->data = sum;

//         if(t == NULL){
//             t = nn;
//             t = t->next;
//         }
//         else{
//             t->next = nn;
//         } 
//     }
// }


//reverse in group

Node* reverseInGroup(Node* head, int k){
    if(head == NULL){
        return NULL;
    }

    Node* curr  = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count=0;

    while(curr != NULL || count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
        count++;
    }

    if(next != NULL){
        head->next = reverseInGroup(next,k);
    }

    return prev;
}


//LL is palindrome or not
O(1) space;
bool isPalindrome(struct Node* head) 
{ 
    struct Node *slow_ptr = head, *fast_ptr = head; 
    struct Node *second_half, *prev_of_slow_ptr = head; 
    struct Node* midnode = NULL; // To handle odd size list 
    bool res = true; // initialize result 
 
    if (head != NULL && head->next != NULL) { 
        /* Get the middle of the list. Move slow_ptr by 1 
        and fast_ptrr by 2, slow_ptr will have the middle 
        node */
        while (fast_ptr != NULL && fast_ptr->next != NULL) { 
            fast_ptr = fast_ptr->next->next; 
 
            /*We need previous of the slow_ptr for 
            linked lists with odd elements */
            prev_of_slow_ptr = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
 
        /* fast_ptr would become NULL when there are even elements in list. 
        And not NULL for odd elements. We need to skip the middle node 
        for odd case and store it somewhere so that we can restore the 
        original list*/
        if (fast_ptr != NULL) { 
            midnode = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
 
        // Now reverse the second half and compare it with first half 
        second_half = slow_ptr; 
        prev_of_slow_ptr->next = NULL; // NULL terminate first half 
        reverse(&second_half); // Reverse the second half 
        res = compareLists(head, second_half); // compare 
 
        /* Construct the original list back */
        reverse(&second_half); // Reverse the second half again 
 
 //here basically regainging original ll
        // If there was a mid node (odd size case) which 
        // was not part of either first half or second half. 
        if (midnode != NULL) { 
            prev_of_slow_ptr->next = midnode; 
            midnode->next = second_half; 
        } 
        else
            prev_of_slow_ptr->next = second_half; 
    } 
    return res; 
}

//method 2 is from stack..O(n) space;


//implement Queue using LL

class QNode{
    public:
    int data ;
    QNode next;

    QNode(int x){
        this->data=x;
        next = NULL;
    }

};

class Queue{
    public:
    QNode* rear = NULL, front = NULL;

    void enQueue(int x){
          QNode temp = new QNode(x);
        if(rear == NULL){
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void deQueue(){
        if(front == NULL){
            return NULL;
        }

        QNode* temp;
        temp = front;
        front = front->next;
        delete(temp);
    }

}

int main(){


    return 0;
}