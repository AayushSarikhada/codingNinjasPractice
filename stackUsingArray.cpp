#include<iostream>
using namespace std;

class stackUsingArray{
    int* data;
    int capacity;
    int nextPointer;

public:
    stackUsingArray(int size=10){
        this->capacity = size;
        data = new int[size];
        nextPointer = -1;
    }

    void push(int a){
        if(nextPointer != capacity-1){
            data[++nextPointer] = a;
        }
    }

    int pop(){
        int ret = data[nextPointer];
        if(nextPointer != -1){
            nextPointer--;
        }
        return ret;
    }

    bool isEmpty(){
        return nextPointer == -1;
    }

    int size(){
        return capacity;
    }
};


int main(){


    return 0;
}