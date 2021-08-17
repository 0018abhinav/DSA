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
    Node* ans= merge(h1,h2);
    print(ans);
}

