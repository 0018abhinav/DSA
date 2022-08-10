#include<iostream>
using namespace  std;
void printWave(int arr[][4], int n, int m){

    for(int col=0; col<m ; col++){
        if(col&1){
            //for odd indexed col 
            //print bottom to top
            for(int row = n-1 ; row>=0 ;row--){
                cout<<arr[row][col]<<" ";
            }
        }
        else{
            //for even col
            //print top to bottom
            for(int row=0; row<n ; row++){
                cout<<arr[row][col]<<" ";
            }
        }
    }
}

int main(){
    int arr[3][4];
    for(int row =0 ; row<3 ;row++){
        for(int col =0; col<4 ;col++){
            cin>>arr[row][col];
        }
    }

    printWave(arr,3,4);
}