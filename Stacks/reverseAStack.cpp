#include <iostream>
using namespace std;
#include <stack>

void insertAtBottom(stack<int>& s,int top){
    if(s.empty()){
        s.push(top);
        return;

    }

    int num = s.top();
    s.pop();

    insertAtBottom(s,top);
    s.push(num);

}
void reverseAStack(stack<int>& s){
    

    if(s.empty()){
        
        return;
    }
    int top = s.top();
    s.pop();

    //recursive call
    reverseAStack(s);

    insertAtBottom(s, top);

}

int main(){
    stack<int> s;
    for(int i=0; i<5; i++){
        s.push(i+1);
    }

    reverseAStack(s);

    while(!s.empty()){
        int top = s.top();
        cout<<top<<" ";
        s.pop();
    }
    
    return 0;

}
