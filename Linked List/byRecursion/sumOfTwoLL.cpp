#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

Node(int data){
    this-> data= data;
    this->next = NULL;
}    
};

Node*input_better(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while (data != -1)
    {
        Node* newNode = new Node(data);
        
        if(head== NULL){
            head = newNode;
            tail= newNode;
        }
        else{
            tail->next= newNode;
            tail = tail->next;
            
        }

        cin>>data;
    }
    return head;
    
}

void print(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        
    }
}

Node * reverse3(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node * smallAns = reverse3(head->next);
    
    Node * tail = head -> next;
    tail -> next = head;
    head -> next =  NULL;
    return smallAns;
}

Node * addLL(Node * head1 , Node * head2){
    if(head1 == NULL && head2 == NULL) return NULL;

    head1 = reverse3(head1);
    head2 = reverse3(head2);
    Node * res = NULL , * newNode;
    int carry =0;
    while(head1 != NULL || head2 != NULL){
        int sum = 0;
        
        sum = head1->data + head2->data + carry;
        carry = (sum >= 10) ? 1 : 0;

        sum =  sum % 10;
        newNode = new Node(sum);

        if(res == NULL){
            res = newNode;
        }
        else{
            res->next = newNode;
        }

        if(head1){
            head1 = head1 ->next;
        }
        if(head2){
            head2 = head2->next;
        }

    }
    if(carry >0 ){
        Node * lastNode = new Node(carry);
        res->next = lastNode;
    }

    return res;

}

int main(){
    Node * head1 = input_better();
    Node * head2 = input_better();
    Node * ans = addLL(head1 ,head2);
    ans = reverse3(ans);
    print(ans);
}