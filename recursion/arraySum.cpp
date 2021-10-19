#include<iostream>
using namespace std;

int sum(int arr[], int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }

    int smallerSum= sum(arr+1,size-1);
    return arr[0] + smallerSum;
}

int main(){
    int size;
    cin>> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans= sum(arr,size);
    cout<<ans<<" ";

}