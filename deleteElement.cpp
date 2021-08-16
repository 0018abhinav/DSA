#include <iostream>

using namespace std;

int main()
{
   int a[5]={1,2,3,4,5};
   int pos,i;
   cout<<"Enter the position:";
   cin>>pos;
   for(int i=pos-1;i<5;i++){
       a[i]=a[i-1];
       
   }
 for(int i=0;i<4;i++){
     cout<<a[i]+"";
     }
    return 0;
}