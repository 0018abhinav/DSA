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
Node* deleteNode(Node*head){
    Node*temp = head;
    cout<<"enter position to be delete"<<endl;
    int pos;
    cin>>pos;
    if(pos==0){
        head= temp->next;
    }
    else{
        int i=0;
        while(i<pos-1){
            temp= temp->next;
            i++;
        }
        temp->next= temp->next->next;
    }
    return head;
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
    
    Node*temp=deleteNode(head);
    print(temp);
}
