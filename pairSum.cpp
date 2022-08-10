#include<bits/stdc++.h>
using namespace std;

//APPROACH 1 (two pointer approach)

// void targetSum(int arr[], int n, int target)
// {
//         sort(arr,arr+n);
//         int left= 0;
//         int right = n-1;
        

//         while (left<right)
//         {
//             if(arr[left] + arr[right] == target){
//                 cout<<arr[left]<<" and "<<arr[right]<<endl;
//                 left++;
//                 right--;
//             }
//             else if(arr[left] + arr[right] > target){
//                 right--;
//             }
//             else if(arr[left] + arr[right] < target){
//                 left++;
//             }
//         }
// }

// APPROACH 2(using hashMaps)
//this function is returning indexes of no.s which contribute to target
vector<int> targetSum(int arr[] , int n , int x){
    unordered_map<int,int> idxMap;
    for(int currIdx = 0; currIdx<n ;currIdx++){
        int targetNum = x - arr[currIdx];
        if(idxMap.count(targetNum)){
            return {currIdx, idxMap[targetNum]};
        }
        else{
            idxMap[arr[currIdx]] = currIdx;
        }
    }
    return {};
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    
	int x;
	cin>>x;
	vector<int>ans = targetSum(arr,n,x);
    for(auto i:ans){
        cout<<i<<" ";
    }
	return 0;
}