#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter no. of elements in array ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    n = n+1;
    
    cout<<"enter position at which you want to insert element";
    int pos;

    cin>>pos;
    for(int i=n; i>=pos;i--){
        arr[i] = arr[i-1];
    }
    int elem;
    cout<<" enter element you want to insert ";
    cin>>elem;
    arr[pos] = elem;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
      
}