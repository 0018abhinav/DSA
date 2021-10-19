#include <iostream>
using namespace std;

class test{

    int *arr ,n;
    public:
    test(){
        cin>>n;
        arr = new int[n];
    }
    void create(){
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
    }
    
    void countingSort(){
        int count[10];
        for(int i=0; i<10;i++){
            count[i] = 0;
        }
        for(int i=0;i<n ;i++){
            count[arr[i]]++;
        }
        // for(int i=0;i<10; i++){
        //     cout<<count[i]<<" ";
            
        // }
        // cout<<endl;
        
        // modify the count array

        for(int k=1; k<10;k++){
            count[k] = count[k] + count[k-1];
        } 
        
        // for(int i=0;i<10; i++){
        //     cout<<count[i]<<" ";
            
        // }
        // cout<<endl;

        int * barr =new int[n];

        for(int i=0; i<n ;i++){
            barr[--count[arr[i]]] = arr[i];
        }

        
        //at the end copy barr in arr
        for(int i=0; i<n ;i++){
            arr[i] = barr[i];
        }
    }
    
    void display(){
        for(int i=0;i<n; i++){
            cout<<arr[i]<<" ";
        }
    }

};

int main(){
    test s1;
    s1.create();
    s1.countingSort();
    s1.display();
    return 0;
}