#include<iostream>
using namespace std;

template <typename T> class stackUsingArray{
    T* data;
    T capacity;
    T nextPoTer;

private:
        void resize(){
            T newCapacity = capacity*2;
            T* temp = data;
            data = new T[newCapacity];
            for(T i=0;i<=nextPoTer;i++){
                data[i] = temp[i];
            }
            delete[] temp;
            capacity = newCapacity;

        }

public:
    stackUsingArray(){
        this->capacity = 4;
        data = new T[capacity];
        nextPoTer = -1;
    }

    void push(T a){
        if(nextPoTer == capacity-1){
            resize();
        }
    
        data[++nextPoTer] = a;
        
    }

    T pop(){
        T ret = data[nextPoTer];
        if(nextPoTer != -1){
            nextPoTer--;
        }
        return ret;
    }

    bool isEmpty(){
        return nextPoTer == -1;
    }

    T size(){
        return capacity;
    }

    T top(){
        
        if(nextPoTer != -1){
            return data[nextPoTer]; 
        }
    }
};


int main(){
    stackUsingArray<int> st;
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