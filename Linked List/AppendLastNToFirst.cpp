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

int length(Node*head){
    Node*temp= head;
    int i=0;
    while(temp!= NULL){
        temp= temp->next;
        i++;
    }
    return i;
}

Node* appendLastNToFirst(Node*head){
    int n;
    cin>>n;
    Node*temp= head;
    Node*temp1 = head;
    Node*headCopy = head;
    while(temp1->next!= NULL){
        temp1= temp1->next;
    }
    int i=0;
    while(i<length(head)-n-1){
        temp= temp->next;
        i++;
    }
    head= temp->next;
    temp->next=NULL;
    temp1->next=headCopy;
    return head;

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
    Node*head = input_better();
    Node*temp= appendLastNToFirst(head);
    print(temp);
}
