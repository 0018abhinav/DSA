#include <iostream>
using namespace std;
#include <stack>

void insertSorted(stack<int>&s , int num){
    if(s.empty()|| (!s.empty()&& s.top()< num)){
        s.push(num);
        return;
    }
    int ele = s.top();
    s.pop();

    insertSorted(s,num);

    s.push(ele);

}

void sort(stack<int>& s){
    if(s.empty()){
        return;

    }

    int num = s.top();
    s.pop();

    sort(s);

    insertSorted(s, num);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);
    

    sort(s);

    while(!s.empty()){
        int top = s.top();
        cout<<top<<" ";
        s.pop();
    }
    
    return 0;

}
