#include <iostream>
using namespace std;
int n;
void inputArray(){
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
        
    
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

int main(){
    int arr[5];
    inputArray();
    printArray(arr,5);


}