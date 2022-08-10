#include <iostream>

using namespace std;

class stack{
    int * data;
    int first;
    int capacity;
    public:
    stack(){
        data = new int[4];
        first = -1;
        capacity = 4;
    }
    
    int size(){
        return first+1;
    }
    
    bool isEmpty(){
        return first==-1;
    }
    
    void push(int num){
        if(size()== capacity){
            int *newData = new int[2* capacity];
            for(int i=0 ;i<capacity;i++){
                newData[i] = data[i];
            }
            capacity *=2;
            delete[] data;
            newData = data;
        }
        
        else{
            first++;
            data[first]= num;
        }
    }
    
    int pop(){
        if(first== -1){
            cout<<"stack is empty";
        }
        int temp= data[first];
        first--;
        return temp;
    }
    
    int top(){
        if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return -1;
        }
        return data[first];
    }
    
};



int main()
{
  stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.top()<<endl;
  s.pop();

  cout<<s.size()<<endl;
  cout<<s.isEmpty()<<endl;

  stack s2;
  for(int i=1;i<=10;i++){
    s2.push(i);
  }
  /// print content of stack
  while(!s2.isEmpty()){
    cout<<s2.top()<<endl;
    s2.pop();
  }
  cout<<s2.size()<<endl;
  return 0;
}
