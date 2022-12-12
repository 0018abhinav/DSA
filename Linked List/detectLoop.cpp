#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
//using maps
bool isLoopPresent(Node * head){
    if(head == NULL){
        return false;
    }
    unordered_map <Node *,bool> m;
    Node * temp = head;

    while(temp !=  NULL){
        if(m[temp] == 1){
            //loop present
            cout<<"loop present at "<<temp->data<<endl;
            return true;
        }
        m[temp] = 1;
        temp = temp->next;
    }
    return false;
}

//floyd cycle algo
Node * floydCycleDetection(Node * head){
    Node * slow = head;
    Node * fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow -> next;

        if(slow == fast){
            // cout<<"loop node "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node * startingLoopNode(Node * head){
    if(head == NULL) return NULL;
    
    Node * slow = head;
    Node * intersection = floydCycleDetection(head);

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection -> next;
    }
    return slow;
}
int lengthOfLoop(Node * head){
    if(head ==NULL) return 0;

    Node * temp = floydCycleDetection(head);
    Node * intersection = floydCycleDetection(head);
    if(intersection ==NULL) return 0;
    int cnt =1;
    while(temp->next != intersection){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void removeLoop(Node * head){
    Node * start = startingLoopNode(head);
    Node * temp = start;

    while(temp->next != start){
        temp = temp->next;
    }
    temp->next = NULL;
  
}
int main(){

    //creating a cyclic LL
    Node * head = new Node(2);
    Node * n2 = new Node(5);
    Node * n3 =  new Node(6);
    Node * n4 = new Node(8);
    head -> next = n2;
    n2 -> next = n3 ;
    n3 -> next =  n4 ;
    n4 -> next = n2;
    
    // removeLoop(head);   //removing Loop

    if(isLoopPresent(head)!= true){
        cout<<"loop is not present"<<endl;
    }
    Node * isLoop= floydCycleDetection(head);
    if(isLoop != NULL){
        cout<<"loop is present"<<endl;
    }
    Node * ans = startingLoopNode(head);
    cout<<"loop starts at "<<ans->data<<endl;
    int length = lengthOfLoop(head);
    cout<<"length of loop is "<<length;

}    