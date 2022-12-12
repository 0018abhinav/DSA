#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int n, int count){
    //int middle = s.size()/2;
    //base case
    if(count == n/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    solve(s,n,count+1);

    s.push(num);

}

void deleteMiddle(stack<int> & s, int n){
    int count =0;
    solve(s,n,count);
    return;
}
// void deleteMiddle(stack<int>& st ,int n ){
//     int mid = n/2;
//     vector<int> elements;
//     int i=0;
//     while(i<mid){
//         // cout<<st.top()<<" ";
//         // cout<<endl;
//         elements.push_back(st.top());
//         st.pop();
//         i++;
//     }
//     int del = st.top();
//     st.pop();
    
//     for(int i = elements.size()-1 ;i>=0;i--){
//         st.push(elements[i]);
//     }
// }



int main(){
    stack<int> s;
    for(int i=0; i<6; i++){
        s.push(i+1);
    }
    int n = s.size();

    deleteMiddle(s,n);
    
    // for(int i=0; i<s.size(); i++){
    //     cout<<s.top();
    //     s.pop();
    // }
    while(!s.empty()){
        int top = s.top();
        cout<<top<<" ";
        s.pop();
    }


}
