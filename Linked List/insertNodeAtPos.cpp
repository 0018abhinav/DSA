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

Node * insertAtPos(Node * head ,int data ,int pos){
    Node * newNode = new Node(data);
    Node * temp =  head;
    if(pos==0){
        //insrt at beg
        newNode -> next = head;
        head = newNode;
    }
    else{
        int i=0;
        while(i< pos-1 && temp!= NULL){
            temp = temp->next;
            i++;
        }
        if(temp != NULL){
            newNode ->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

void printithNode(Node * head , int i){
    Node * temp = head;
    int j=0;
    while(j<i){
        temp = temp->next;
        j++;
    }
    cout<<temp->data;
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
    cout<<"enter data to be inserted";
    int data;
    cin>>data;
    cout<<"enter index at which it inserted";
    int i;
    cin>>i;
    // printLL(head);
    // printithNode(head ,i);
    head = insertAtPos(head ,data,i);
    printLL(head);
}