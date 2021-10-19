#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data= data;
        this->next= next;
    }

};

class Stack{
    Node* head;
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    
    bool isEmpty(){
        
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }


    void push(int elem){
        Node*head;
        Node * newNode = new Node(elem);
        newNode->next=  head;
        head= newNode;
        size++;
        
    }

    int pop(){
        if(size==0){
            return 0;
        }
        int ans = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    int top(){
        if(size==0){
            return 0;
        }
        return head->data;
    }
    int getSize(){
        return size;
    }
};

int main(){
    Stack s ;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}

