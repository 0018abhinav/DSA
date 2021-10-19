#include <iostream>
using namespace std;

void merging(int arr[], int p,int q, int r ){
    int x=p;
    int n1= q-p+1;
    int n2= r-q;
    int L[10];
    int R[10];
    for(int i=0; i<n1; i++){
        L[i] = arr[x];
        x++;
    }

    for(int j=0; j<n2; j++){
        R[j] = arr[q+1];
        q++;
    }

    int k=p;
    int i=0;
    int j=0;
    while(i< n1 && j< n2){
        if(L[i]<= R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }
        if(R[j]<= L[i]){
            arr[k]= R[j];
            j++;
            k++;
        }
    }
    if(i==n1){
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    if(j== n2){
        while(i< n1){
            arr[k] = L[i];
            i++;
            k++;
        }
    }
    
}

void mergeSort(int arr[], int p, int r){
    int q;
    if(p< r){
        q = (p+r)/2;
        mergeSort(arr ,p ,q);
        mergeSort(arr, q+1, r);
        merging(arr, p, q, r);
    }
}


int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int p=0;
    mergeSort(arr,p,n);

    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    

}