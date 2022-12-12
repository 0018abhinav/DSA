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

Node*input(){
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


Node * reverse1(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node * smallAns = reverse1(head->next);
    Node * temp = smallAns;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next =  NULL;
    return smallAns;
}

class Pair{
    public:
    Node * head;
    Node * tail;
};

Pair reverse2(Node * head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverse2(head->next);
    smallAns.tail -> next = head;
    head-> next= NULL;

    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node * reverse_better(Node * head){
    return reverse2(head).head;
}

Node * reverse3(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node * smallAns = reverse3(head->next);
    
    Node * tail = head -> next;
    tail -> next = head;
    head -> next =  NULL;
    return smallAns;
}


int main(){
    Node*head = input();
    // head = reverse1(head); //approach1
    // head = reverse_better(head); // using pair class
    head = reverse3(head); // modified of approach1 
    
    
    print(head);
}

