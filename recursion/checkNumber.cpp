#include<iostream>
using namespace std;

bool checkNumber(int arr[], int n, int x){
    if(n==0){
        return false;
    }
    if(arr[0]==x){
        return true;
    }
    else{
        return false;
    }

    bool smallCheck= checkNumber(arr+1, n-1,x);
    return smallCheck;
}

int main(){
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    bool ans= checkNumber(arr,n,x);
    cout<< ans;
}