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


int midNode(Node*head){
    int l = length(head);
    Node*temp=head;
    int mid;
    if(l%2==0){
        mid=l/2;
    }
    else{
        mid= (l+1)/2;
    }
    int i=1;
    while(i<mid){
        temp= temp->next;
        i++;
    }
    return temp->data;
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
    
    int ans = midNode(head);
    cout<<ans;
}
