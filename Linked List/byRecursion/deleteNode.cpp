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

void printLL(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp =  temp->next;
    }
}

Node * deleteNode(Node * head , int i){
    if(head == NULL){
        return NULL;
    }
    if(i==0){
        head = head -> next;
        return head;
    }
    Node * a = deleteNode(head->next ,i-1);
    head -> next = a;
    return head;
}

int main(){
    Node * head = input();
    int i;
    cin>>i;
    head = deleteNode(head ,i);
    printLL(head);
}