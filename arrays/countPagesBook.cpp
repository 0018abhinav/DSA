#include<bits/stdc++.h>
using namespace std;

int minCount(int arr[] ,int n , int k){
    int minS = 1;
    int minE =1;
    int i=0; 
    int j =n-1;
    while(i<=j){
        if(arr[i]!=k && arr[j]!=k){
            i++;
            minS++;
            j--;
            minE++;
        }
        if(arr[i]==k && arr[j]!=k){
            
            return minS;
        }
        if(arr[i]!=k && arr[j]==k){
            return minE;
        }
    }

}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    int ans =minCount(arr,n,k);
    cout<<ans;
}