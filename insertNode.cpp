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

Node* insertNode(Node*head ,int data, int pos){
    
    Node* temp= head;
    Node* newNode = new Node(data);
    int i=0;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next=newNode;
    return head;
    }
    


void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    n1 -> next = n2;
    n2-> next= n3;
    n3->next= n4;
    int data;
    int pos; 

    Node* newNode= insertNode(head,50,5);
    print(newNode);
    return 0;

}