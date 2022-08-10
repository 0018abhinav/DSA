#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int row =0; row < n; row++){
        for(int col=0 ; col<n ;col++){
            cin>>arr[row][col];
        }
    }
    cout<<"before rotating"<<endl;

    for(int row =0; row < n; row++){
        for(int col=0 ; col<n ;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    cout<<"after rotating"<<endl;
    for(int col = 0; col<n; col++){
        for(int row = n-1 ;row >=0; row--){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}
