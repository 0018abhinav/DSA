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

int length(Node*head){
    Node*temp= head;
    int i=0;
    while(temp!= NULL){
        temp= temp->next;
        i++;
    }
    return i;
}
Node * midNode(Node*head){
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
    return temp;
}

Node * merge(Node * head1 , Node * head2 ){
    Node * fh = NULL;
    Node * ft = NULL;
    
    if(head1->data < head2->data){
            fh = head1;
            ft = head1;
            head1 = head1->next;
    }
    else{
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2 -> data){
            ft->next = head1;
            head1 = head1->next;
            ft = ft->next;
        }
        else{
            ft->next = head2;
            head2 = head2 -> next;
            ft = ft->next;
        }
        
    }
    
    if(head1 != NULL){
        ft->next = head1;
    }
    else{
        ft->next = head2;
    }
    return fh;
}

Node * mergeSort(Node * head){
    if(head->next == NULL){
        return head;
    }
    Node * m = midNode(head);
    
    //divide the LL in two halves
    Node * temp1 = head;
    Node * temp2= m->next;
    m->next = NULL;
    
    //call rescursion in two halves
    temp1 = mergeSort(temp1);
    temp2 = mergeSort(temp2);
    Node * ans = merge(temp1 ,temp2);
    
    return ans;
}

int main(){
    Node*head = input();
    head = mergeSort(head);
    
    print(head);
}

