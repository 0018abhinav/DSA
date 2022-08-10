#include <iostream>
using namespace std;
int linearSearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]== x){
            return i;
            
        }
    }
    return -1;
}
// void printArray(int arr[], int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

// }
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    
    int ans = linearSearch(arr,n,5);
    cout<<ans;
    
}