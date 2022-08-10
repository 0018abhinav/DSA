#include <iostream>
using namespace std;
#include <vector>

vector<int> allduplicates(vector<int> nums){
    int arr[100] ={0};
    
    vector<int>res;
    for(auto i:nums){
        if(arr[i]==0){
            arr[i]++;
        }
        else{
            res.push_back(i);
        }
    }
    return res;
    
}

int main(){
    vector<int> nums = {1,2,4,1,3,2,5};
    vector<int> ans = allduplicates(nums);
    for(auto i: ans){
        cout<<i<<" ";
    }


}    