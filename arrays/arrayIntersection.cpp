#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

// void arrIntersection(int arr1[] , int arr2[], int n, int m){
//     for(int i=0; i< n; i++){
//         for(int j=0 ;j<m; j++){
//             if(arr1[i] == arr2[j]){
//                 cout<<arr1[i]<<" ";
//                 arr2[j]= INT_MIN;
//                 break;
//             }
//         }
//     }
// }


//optimised
void arrIntersection2(int arr1[], int arr2[], int n,  int m){
    int i=0 , j=0;
    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i]< arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0; i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }
    //arrIntersection(arr1, arr2 ,n ,m);
    arrIntersection2(arr1, arr2 ,n ,m);

}