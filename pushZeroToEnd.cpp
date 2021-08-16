#include <iostream>

using namespace std;

void pushZeroEnd(int* arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0 ;j<n-i ;j++){
            if(arr[j]== 0){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {0,0,1,4,1,0,9};
    pushZeroEnd(arr,7);
    for(int i=0; i<7; i++){
        cout << arr[i] <<" ";
    }

    return 0;
}
