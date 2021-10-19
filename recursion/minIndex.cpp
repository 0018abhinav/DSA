#include<iostream>
using namespace std;

int minIndex(int arr[], int n, int x){
    if(n==0){
        return -1;
    }
    if(arr[0]==x){
        return 0;
    }
    int smallAns= minIndex(arr+1, n-1,x);
    if(smallAns==-1){
        return -1;
    }
    else{
        return smallAns + 1;
    }
}
int main(){
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    int ans= minIndex(arr,n,x);
    cout<< ans;
}    