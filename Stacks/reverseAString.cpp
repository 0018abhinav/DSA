#include <iostream>
#include<stack>
using namespace std;

int main(){
    string s="abhinav";
    
    stack<char> stack;

    for(int i=0; i<s.length();i++){
        char ch= s[i];
        stack.push(ch);
    }

    string ans="";

    while(!stack.empty()){
        char ch= stack.top();
        ans.push_back(ch);
        stack.pop();
    }

    cout<<ans;
    return 0;
}
