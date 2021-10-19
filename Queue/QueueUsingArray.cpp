#include<iostream>
using namespace std;

class QueueUsingArray{
    int * data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s){
        data = new int[s];
        nextIndex=0;
        firstIndex= -1;
        size = 0;
        s = capacity;
    }

    int front(){
        if(isEmpty()){
            cout<<"queue empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    void enqueue(int elem){
        if(size==capacity){
            int * newData = new int[2* capacity];
            int j=0;
            for(int i=firstIndex; i<capacity;i++){
                newData[j]= data[i];
                j++;
            }
            for(int i=0; i<firstIndex;i++){
                newData[j]= data[i];
                j++;
            }
            delete[] data;
            data=newData;
            firstIndex=0;
            nextIndex= capacity;
            capacity*=2;
            // cout<<"Queue full !"<<endl;
            // return;
        }
        data[nextIndex] = elem;
        nextIndex= (nextIndex+1) % capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        int temp = data[firstIndex];
        firstIndex= (firstIndex+1) % capacity;
        size--;
        if(size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return temp;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;

    }

};

int main(){
    QueueUsingArray q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

}