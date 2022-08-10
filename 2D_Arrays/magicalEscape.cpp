#include <iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    char arr[n][m];
    int minStrength;
    cin>>minStrength;
    int currStr;
    cin>>currStr;
    for(int row =0; row<n ;row++){
        for(int col=0; col<m ;col++){
            cin>>arr[row][col];
        }
    }

    bool isEsc = false;

    int row =0 ;
    while(row < n){
        int col = 0;
        while(col < m){
            if(arr[n][m] == '.' && currStr >= minStrength){
                col++;
                currStr = currStr - 2;
                currStr = currStr -1;
            }
            else if(arr[n][m] == '*' && currStr >= minStrength){
                col++;
                currStr = currStr + 5;
                currStr = currStr -1;
            }
            else if(arr[n][m] == '#' && currStr >= minStrength){
                // currStr--;
                //row++;
                break;
            }
        }
        // if(arr[n][m]=='\0'){
        row++;  
    }
    cout<<currStr<<endl;
    if(currStr >= minStrength){
        isEsc = true;
    }
    if(isEsc){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}