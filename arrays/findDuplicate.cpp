#include <iostream>
using namespace std;

int main(){
    cout<<"size of array";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter array";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans =0;
    for(int i=0; i<n; i++){
        ans = ans^arr[i];
    }
    // int arr2[n-1];
    // for(int i=1; i<=n-1; i++){
    //     arr2[i] =i;

    // }
    
    // for(int i=0; i<n ;i++){
    //     ans = ans ^arr2[i];
    // }

    for(int i=1; i<n; i++){
        ans = ans^i;
    }
    cout<<ans;


}