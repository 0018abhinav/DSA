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
int length(Node * head){
    Node * temp = head ;
    int len=0;
    while (temp != NULL)
    {
        temp = temp-> next;
        len++;
    }
    return len;
}

Node * midNode(Node * head){
    int len = length(head);
    int mid;
    if(len % 2 == 0){
        mid = len /2;
    }
    else{
        mid = (len+1)/2;
    }
    int i=1;
    Node * temp = head;
    while(i<mid){
        temp = temp->next;
        i++;
    }

    return temp;
}
Node * reverse(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node * smallAns = reverse(head->next);
    
    Node * tail = head -> next;
    tail -> next = head;
    head -> next =  NULL;
    return smallAns;
}

bool isPalindrome(Node * head){
    if(head == NULL || head->next == NULL) return true;
    
    Node * temp1 = head;
    
    Node * mid = midNode(head);
    Node * temp2 = mid ->next;
    mid -> next = NULL;

    temp2 = reverse(temp2);
    bool flag = true;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data == temp2 -> data){
            flag = false;
            break;
        }
        temp1 = temp1 ->next;
        temp2 = temp2 ->next;
    }
    return flag;
    
}

int main(){
    Node*head = input_better();
    // print(head);
    bool ans = isPalindrome(head);
    cout<<ans;
}

