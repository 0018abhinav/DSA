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