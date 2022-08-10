#include<iostream>
using namespace std;

void printArr(int* arr,int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }

}

// int* sortZeroOne(int*arr, int n){
//     for(int i=0; i<n-1;i++){
//         for(int j=i+1; j<n ;j++){
//             if(arr[i]>arr[j]){
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     return arr;
// }

int * sortZeroOne2(int* arr, int n){
    int i=0; 
    int j=n-1;
    while (i<j)
    {
        if(arr[i]==1 && arr[j]==0 && i<j){
            swap(arr[i],arr[j]);
            //printArr(arr,n);
            i++;
            j--;
        }
        else if(arr[i]==0 && i<j){
            i++;
            //cout<<"executed from beg";
        }
        else{
            j--;
            //cout<<"executed from end";
        }
    }
    return arr;
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int* ans=sortZeroOne2(arr,n);
    printArr(arr,n);
}
