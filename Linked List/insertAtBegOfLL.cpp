#include <iostream>
using namespace std;
template <typename T>

class Node{
    public:
    T data;
    Node * next;

    Node(T data){
        this->data = data;
        this->next = NULL;
    }

};

Node<int>* insertAtBegOfLL(Node<int>* head){
    int newData;
    cout<<"enter data to be inserted";
    cin>>newData;
    Node<int>* newNode = new Node<int>(newData);
    if(head==NULL){    
        head = newNode;
    }
    else{
        newNode->next= head;
        head = newNode;
    }
    return head;
}

 Node<int>* Input(){
    int data;
    cin>>data;
    Node<int> * head = NULL;
    Node<int> * tail = NULL;
    while(data != -1){
        Node<int> * newNode = new Node<int>(data);
        if(head == NULL){
            head = newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail= tail->next;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node<int>* head){
    Node<int>* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node<int>* head = Input();
    Node<int>* insertAtBegOfLL(head);
    printLL(head);

}