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
int findNode(Node * head , int data ){
    Node * temp = head;
    int i=0;
    while(temp != NULL){
        if(temp->data == data){
            
            return i;
        }
        else{
            temp = temp -> next;
            i++;
        }
    }
    return -1;
}

int main(){
    Node * head = input();
    int data;
    cin>>data;

    int ans =findNode(head,data);
    cout<<ans;
}