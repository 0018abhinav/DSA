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
void deleteNodes(Node * head, int m , int n){
    if(m==0) {
        head = NULL;
    }
    Node * headCopy = head;
    while(headCopy != NULL){
        int i =1;
        while(i<m && headCopy ->next != NULL){
            headCopy= headCopy ->next;
            i++;
        }
        Node * temp = headCopy -> next;
        if(temp == NULL || temp -> next == NULL) {
            headCopy ->next = NULL;
            break;
        }
        int j = 1;
        while(j<n && temp->next != NULL){
            temp  = temp->next;
            j++;
        }
        headCopy->next = temp->next ;
        headCopy = temp->next;
    }
    // return headCopy;
}
int main(){
    Node*head = input_better();
    int m,n;
    cin>>m>>n;
    deleteNodes(head,m , n);

    print(head);
}

