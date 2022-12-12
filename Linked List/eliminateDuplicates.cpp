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

Node* eliminateDuplicate(Node*head){
    Node*t1 = head;
    Node*t2 = head->next;
    if(head== NULL || head->next==NULL){
        return head;
    }

    while(t2 != NULL){
        if(t1->data == t2->data){
            t2 = t2->next;

        }
        else{
            t1= t1->next;
            t2= t2->next;
        }
        t1->next= t2;
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
    Node*temp = eliminateDuplicate(head);
    print(temp);
}
