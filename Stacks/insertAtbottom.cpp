#include <iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s,x);

    s.push(num);

}


int main(){
    stack<int> s;
    for(int i=0; i<5; i++){
        s.push(i+1);
    }

    int x = 7;
    insertAtBottom(s,x);
    
    // for(int i=0; i<s.size(); i++){
    //     cout<<s.top();
    //     s.pop();
    // }
    while(!s.empty()){
        int top = s.top();
        cout<<top<<" ";
        s.pop();
    }
    return 0;
}