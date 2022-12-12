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

Node * reverse(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node * prev = NULL;
    Node * curr = head;
    Node * nxt = head ->next ;

    while(curr != NULL){
        nxt = curr -> next;
        curr -> next = prev;
        prev =curr;
        curr = nxt ;

    }
    return prev;
}

int main(){
    Node*head = input_better();
    Node * ans = reverse(head);
    print(ans);
    
}
