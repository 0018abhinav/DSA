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

int length(Node * head){
    Node * temp= head ;
    if(temp == NULL){
        return 0;
    }
    int ans;
    if(temp != NULL){
        ans += length(temp->next) +1;
    }
    return ans;
}

int main(){
    Node * head = input();
    int len = length(head);
    cout<<"length = "<<len;
    
    // printLL(head);
}