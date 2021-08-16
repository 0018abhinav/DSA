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
int findNode(Node*head){
    Node* temp= head;
    cout<<"enter data to find"<<endl;
    int value;
    cin>>value;
    int i=0;

    while(i!= -1){
        if(temp->data== value){
            return i;
            
        }
        
        temp=temp->next;
        i++;    
        
    }
    
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
    print(head);
    int ans = findNode(head);
    cout<<ans;
}

