#include <iostream>
using namespace std;
void reverseArray(int arr[], int n){
    int i = 0;
    int j = n-1;
    while(i<j){
        int temp =arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    reverseArray(arr,n);
    printArray(arr,n);
    
}