#include <iostream>
using namespace std;

void arrange(int arr[] , int n){
    if(n % 2 == 0){
        int num =1;
        for(int i =0; i<n/2 ;i++){
            arr[i] = num;
            num+=2;

        }
        int temp= n;
        for(int i= n/2 ; i<n ;i++){
            arr[i] = temp;
            temp = temp -2;

        }
    }
    else{
        int num = 1;
        for(int i=0; i< (n+1)/2 ; i++){
            arr[i] = num;
            num +=2;
        }
        int temp= n-1;
        for(int i= (n+1)/2 ; i<n ;i++){
            arr[i] = temp;
            temp = temp -2;

        }
    }
}

void print(int arr[], int n){
    for(int i=0; i<n ;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    
    arrange(arr,n);
    print(arr,n);

    return 0;
}

