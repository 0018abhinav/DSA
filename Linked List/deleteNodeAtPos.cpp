#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

Node * deleteAtPos(Node * head , int pos){
    Node * temp = head;

    if(pos == 0){
        head = head -> next;
        return head;
    }
    else{
        int i=0 ;
        while(temp!= NULL && i<pos-1){
            temp = temp -> next;
            i++;
        }
        if(temp != NULL){
            temp->next = temp ->next -> next;
            
            // delete temp -> next;
        }
    }
    return head;
}

void printLL(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp =  temp->next;
    }
}

Node * input(){
    int data;
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

int main(){
    Node * head = input();
    
    cout<<"enter node to be deleted";
    int i;
    cin>>i;
    // printLL(head);
    // printithNode(head ,i);
    head = deleteAtPos(head ,i);
    printLL(head);
}