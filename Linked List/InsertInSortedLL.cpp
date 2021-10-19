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
Node * insertsorted(Node* head)
{
    cout<<"enter data to be inserted"<<endl;
    int data;
    cin>>data;
    Node* newNode= new Node(data);
    Node * current = head;
    
    if(head==NULL || head->data >= newNode->data){
        
        newNode->next= head;
        head= newNode;
    }
    
    while(current->next != NULL && current->next->data < newNode->data){
        current= current->next;
        
    }
    newNode->next= current->next;
    current->next = newNode;

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
    Node * head = input_better();
    Node* insert = insertsorted(head);
    print(head);

}