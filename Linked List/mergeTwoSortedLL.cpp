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

Node* merge(Node*h1, Node*h2){
    Node* fh ,*ft = NULL;
    if(h1->data < h2->data){
        fh = h1;
        ft = h1;
        h1 = h1->next;
        while(h1->next!=NULL ){
        if(h1->data < h2->data){        
            ft = h1;
            h1 = h1->next;
        }
        else{
            ft = h2;
            h2 = h2->next;
        }
        
    }
    }
    else{
        fh = h2;
        ft = h2;
        h2 = h2->next;
        while(h1->next!=NULL ){
        if(h1->data < h2->data){        
            ft = h1;
            h1 = h1->next;
        }
        else{
            ft = h2;
            h2 = h2->next;
        }
        
    }
    }
    
    return fh;

}

Node * merge2(Node * head1 , Node * head2 ){
    Node * fh = NULL;
    Node * ft = NULL;
    
    if(head1->data < head2->data){
            fh = head1;
            ft = head1;
            head1 = head1->next;
    }
    else{
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2 -> data){
            ft->next = head1;
            head1 = head1->next;
            ft = ft->next;
        }
        else{
            ft->next = head2;
            head2 = head2 -> next;
            ft = ft->next;
        }
        
    }
    
    if(head1 != NULL){
        ft->next = head1;
    }
    else{
        ft->next = head2;
    }
    return fh;
}

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

int main(){
    Node*h1 = input_better();
    Node*h2= input_better();
    Node* ans= merge2(h1,h2); //better than merge function
    print(ans);
}

