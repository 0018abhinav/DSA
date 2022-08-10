#include <bits/stdc++.h>

using namespace std;

// int tripletSum(int *input, int n, int x)
// {
// 	//Write your code here
//     int count =0;
//     for(int i=0; i<n-2;i++){
//         for(int j=i+1; j<n-1;j++){
//             for(int k=j+1; k<n ;k++){
//                 if(input[i] + input[j]+ input[k] == x){
//                     cout<<"("<<i<<","<<j<<","<<k<<")";
//                     count ++;
//                 }
//             }
//         }
//     }
//     return count;
// }

//optimised by two pointer approach

void tripletSum(int *arr, int n, int x){
    sort(arr,arr+n);
    int i=0; 
    while(i<n-3){
        int left= i+1;
        int right = n-1;
        int newtarget = x - arr[i];

        while (left<right)
        {
            if(arr[left] + arr[right] == newtarget){
                cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right]<<endl;
                left++;
                right--;
            }
            else if(arr[left] + arr[right] > newtarget){
                right--;
            }
            else if(arr[left] + arr[right] < newtarget){
                left++;
            }
        }
        i++;
        
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    tripletSum(arr,n,x);
    //cout<<ans;


    return 0;
}
