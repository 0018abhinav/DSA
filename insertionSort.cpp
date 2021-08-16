#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=0 ; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]< arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }
}

int main(){
    int arr[6]= {5 ,8, 6, 1, 2, 7};
    insertionSort(arr,6);

    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
}