#include <iostream>
using namespace std;

void merge(int *arr1, int n, int *arr2, int m, int *arr3)
{
    //Write your code here a
    int z = n + m;
    int arr3[z];
    
    int i=0, j=0, k=0;
    
    while( i<n &&  j<m){
        if(arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        
        else{
            arr3[k] = arr2[j];
            z++;
            k++;
        }
    }
    
    while( i<n){
        arr3[k]= arr1[i];
        i++;
        k++;
    }
    while( i<m){
        arr3[k]= arr2[j];
        j++;
        k++;
    }

    for(int k=0; k<z; k++){
        cout<<arr3[k]<<" ";
    }
    
}

int main(){
    int n =5;
    int m =4;
    int arr1[5] = {1,4,5,8,9};
    int arr2[4] = {2,3,7,9};
    int arr3[9];
    merge(arr1,n,arr2,m,arr3);

}