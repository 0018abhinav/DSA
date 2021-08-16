#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

 Node(int data){
     this->data=data;
     this->next=NULL;
 }
};

int main(){
    //statically
    Node n1(10);
    Node n2(20);
    Node n3(30);
    
    Node* head = &n1;
    Node* n1= &n2;
    Node* n2= &n3;
    cout<<n1.data<<" ";
    cout<<n2.data<<" "<<endl;
    cout<<head->next;

    //dynamically
    Node *n4= new Node(40);
    Node* n5 = new Node(50);
    
    

    }