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

Node * deleteMiddle(Node * head){
    if(head == NULL || head->next==NULL){
        return NULL;
    }
    
    Node * slow =  head;
    Node * fast = head;
    Node * prev ;
    while(fast->next != NULL && fast != NULL){
        fast = fast -> next ->next;
        prev = slow;
        slow = slow -> next;
    }
    prev ->next = slow -> next;
    delete slow;
    return head;
}

int main(){
    Node * head = input();
    head = deleteMiddle(head);
    printLL(head);
}
