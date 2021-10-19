#include <iostream>
using namespace std;


class stackUsingArray{
    int* data;
    int top;
    int capacity;
    public:

    stackUsingArray(){
        data = new int[4];
        top=-1;
        int capacity= 4;
    }

    int size(){
        return top +1;
    }
    
    bool isEmpty(){
        return top== -1;
    }

    int top(){
        return data[top];
    }
    
    void push(int elem){
        if(top>size()-1){
            int * newData = new int[2 * capacity];
            for(int i=0; i<capacity;i++){
                newData[i] = data[i];
            }
            capacity*=2;
            delete [] data;
            data = newData;
        }
        top++;
        data[top]= elem;
    }

    int pop(){
        if(size()==0){
            cout<<"stack is empty";
        }
        int temp= data[top];
        top--;
        return temp;
    }

};
int main(){
    stackUsingArray * s1= new stackUsingArray();
    for(int i=0; i<5;i++){
        s1->push(i);
    }
    for(int i=0; i<5;i++){
        cout<<s1->pop();
    }
    return 0;
}