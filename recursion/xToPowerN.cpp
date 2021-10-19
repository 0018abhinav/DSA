#include<iostream>
using namespace std;
int power(int x,int n){
    if(n==0){
        return 1;
    }
    int smallAns=power( x,  (n-1));
    return x* smallAns;
}

int main(){
    int x,n;
    cin>>x;
    cin>>n;
    int ans= power(x,n);
    cout<<ans;
}