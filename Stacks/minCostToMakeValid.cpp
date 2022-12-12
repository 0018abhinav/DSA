#include<iostream>
#include<stack>
using namespace std;

int solve(string s){
    if(s.length() %2 !=0) return -1;
    stack<char> st;
    //pop the valid brackets
    for(int i = 0; i<s.length();i++){
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else{
            //closing bracket
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
    }
    //remaining brackets are not valid
    int a=0; //no of closing brackets
    int b = 0;//no of opening brackets
    while(!st.empty()){
        if(st.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        st.pop();
    }
    // cout<<a<<" "<<b<<endl;
    int ans =  ((a+1)/2) + ((b+1)/2);
    return ans;

}

int main(){
    string s;
    cin>>s;

    int ans = solve(s);
    cout<<ans;
}