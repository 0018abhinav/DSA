#include<iostream>
using namespace std;

int main(){
    int n;
    //hum generally row major form me 2d array store krte hain
    //int arr[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}};
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //this will take input row wise

    //char arr[4][4] = {{'A' ,'B','C','\0'}, {'D', 'E', 'F', '\0'} , {'G', 'E', 'H','\0'}};

    //Print using for loop

    // for(int i=0; i<3 ;i++){
    //     for(int j=0; j<3; j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }

    //Print using While Loop

    int i=0 ;
    while(i<3){
        int j=0;
        while(j<3){
            cout<<arr[i][j]<<" ";
            j++;
        }
        cout<<endl;
        i++;      
    }
    cout<<arr<<endl;    //pointer point to first element of first row of arr
    cout<<&arr[0][0]<<endl; //address of first element of first array of arrays 
    cout<<arr[0]<<endl; //address of first array of arrays i.e. of first row
    cout<<arr[1]<<endl; //address of second array of arrays i.e. of second row
    cout<<arr[2]<<endl; //address of third array of arrays i.e. of third row

    //character ke case me +1 byte hota h , next ka address nikalne ke liye
    //int  ke case me +4 byte hota h , next ka address nikalne ke liye

    cout<<"search element"<< endl;
    for(int i=0; i<3 ;i++){
        for(int j=0 ;j<3 ;j++){
            if(arr[i][j]==6){
                cout<<i<<","<<j;
                break;
            }
        }
    }

}
