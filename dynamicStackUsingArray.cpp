#include<iostream>
using namespace std;

class stackUsingArray{
    int* data;
    int capacity;
    int nextPointer;

private:
        void resize(){
            int newCapacity = capacity*2;
            int* temp = data;
            data = new int[newCapacity];
            for(int i=0;i<=nextPointer;i++){
                data[i] = temp[i];
            }
            delete[] temp;
            capacity = newCapacity;

        }

public:
    stackUsingArray(){
        this->capacity = 4;
        data = new int[capacity];
        nextPointer = -1;
    }

    void push(int a){
        if(nextPointer == capacity-1){
            resize();
        }
    
        data[++nextPointer] = a;
        
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
    stackUsingArray st;
    cout<<"size: "<<st.size()<<endl;
    cout<<"isEmpty: "<<st.isEmpty()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<"isEmpty: "<<st.isEmpty()<<endl;
    while(!st.isEmpty()){
        cout<<st.pop()<<" ";
    }
    cout<<endl;
    


    return 0;
}