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

    int top(){
        if(nextPointer != -1){
            return data[nextPointer]; 
        }
    }
};


int main(){
    stackUsingArray st(20);
    cout<<"size: "<<st.size()<<endl;
    cout<<"isEmpty: "<<st.isEmpty()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<"isEmpty: "<<st.isEmpty()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;


    return 0;
}