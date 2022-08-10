#include<iostream>
using namespace std;

int * addEle(int * arr,int ele){
    int size = sizeof(arr);
    arr[size] = ele;
    return arr;
}

// this function is giving error , how can we delete element from it
// int * deleteEle(int *arr, int pos){
//     int size = sizeof(arr);
//     delete arr[pos];

// }



int main(){
    int size=5;
    // cout<<"enter size of arr";
    // cin>>size;
    int * arr= new int[size];
    if(size> 5){
        int *newArr = new int(arr[2*size]);
        size *= 2;
    }
    cout<<" enter array";
    for(int i=0; i<size; i++){
        cin>>arr[i];

    }
    arr = addEle(arr, 1001);
    for(int i=0; i<size ;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}