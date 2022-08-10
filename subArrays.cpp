//in this que we have to find non decreasing sub arrays
#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T>0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0 ;i<n;i++){
            cin>>arr[i];
        }
        int num = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[j] == arr[i]+1){
                    cout<<arr[i]<<" "<<arr[j]<<endl;
                    num++;
                    break;
                }
            }
        }
        T--;
        cout<<num;
    }

}