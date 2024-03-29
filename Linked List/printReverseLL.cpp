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

void printReverse(Node*head){
    int l = length(head);
    int arr[l];
    Node* temp= head;
    int i=0;
    while(temp!=NULL){
        arr[i]= temp->data;
        i++;
        temp= temp->next;
    }

    for(int i=l-1; i>=0;i--){
        cout<<arr[i]<<" ";
    }
}

void printreverse(Node * head){
    Node * temp = head;
    if(temp == NULL){
        return;
    }
    printreverse(temp->next);
    cout<<temp->data<<" ";
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
    printReverse(head); //by storing it in arr
    printreverse(head); //recersive
}
