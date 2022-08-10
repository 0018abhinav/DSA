#include <iostream>
#include<limits.h>
using namespace std;

//function me hme arr pass krte hue col size dena pdta h , wrna error deta hai
void rowSum(int arr[][4] , int row , int col){

    for(int row =0; row< 3; row++){
        int sum=0;
        for(int col =0 ; col< 4; col++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
}

void colSum(int arr[][4] , int row , int col){

    for(int col =0; col< 4; col++){
        int sum=0;
        for(int row =0 ; row< 3; row++){
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
}

int largestRowSum(int arr[][4] , int rows, int cols){
    int maxi = INT_MIN;
    int rowIndex = -1;
    for(int row =0; row< 3; row++){
        int sum=0;
        for(int col =0 ; col< 4; col++){
            sum += arr[row][col];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = row;
        }
    }
    cout<<"max row sum is "<<maxi<<endl;
    return rowIndex;
}

int main(){
    int arr[3][4];
    for(int row =0 ; row<3 ;row++){
        for(int col =0; col<4 ;col++){
            cin>>arr[row][col];
        }
    }
    cout<<"sum row wise "<<endl;
    rowSum(arr,3,4);
    cout<<endl;
    cout<<"sum col wise "<<endl;
    colSum(arr,3,4);
    cout<<endl;
    
    int ansIndex = largestRowSum(arr , 3 , 4);
    cout<<"row index of largest sum is "<<ansIndex;
}