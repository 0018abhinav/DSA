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

Node * insert(Node * head , int data , int pos){
    // Node * temp = head;
    Node * newNode = new Node(data);
    if(head == NULL){
        // head = newNode;
        return head;
    }
    if(pos == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    Node * a = insert(head->next , data ,pos -1);
    head ->next = a;
    return head;
}

int main(){
    Node * head = input();
    int data ,i;
    cin>>data>>i;
    head = insert(head , data ,i);
    printLL(head);
}
