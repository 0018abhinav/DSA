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

Node * solve(Node * head){
    Node * oH = NULL ,* oT = NULL;
    Node * eH = NULL ,* eT = NULL;

    Node * temp = head;
    
    while(temp != NULL){
        if(temp->data % 2 !=0){
            //odd
            if(oH == NULL){
                oH = temp;
                oT = temp;
            }
            else{
                oT -> next = temp ;
                oT = oT->next;
            }
            // 
        }
        else{
            //even
            if(eH == NULL){
                eH = temp;
                eT = temp;
            }
            else{
                eT -> next = temp ;
                eT = eT -> next;
            }
            // 
        }
        temp = temp -> next;
    }
    // eT -> next = NULL;
    // oT -> next = NULL;
    oT -> next = eH;
    eT ->next = NULL;
    return oH;

}

int main(){
    Node*head = input_better();
    Node * ans = solve(head);

    print(ans);
}

