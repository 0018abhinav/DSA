#include <iostream>
#include<vector>

using namespace std;

int main()
{   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    int ans[10];
    int j=0;
    for(int i=1; i<=n ;i++){
        if(arr[i]== i){
            ans[j] = i;
        }
    }
    for(int i=0; i<10; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}