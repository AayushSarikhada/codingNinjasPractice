#include<iostream>
using namespace std;
template <typename T>
class queueUsingArray{
    T* data;
    int size;
    int capacity;
    int nextIndex;
    int frontIndex;

    public:
        queueUsingArray(int size=5){
            data = new T[size];
            this->size = 0;
            nextIndex = 0;
            frontIndex = -1;
            capacity = size;
        } 

        void resize(){
            int old = capacity;
            capacity *= 2;
            T* temp = new T[capacity];
            int j =0;
            for(int i = frontIndex;i<old;i++){
                temp[j] = data[i];
                j++;
            }
            for(int i=0;i<frontIndex;i++){
                temp[j] = data[i];
                j++;
            }
            frontIndex = 0;
            nextIndex = old;
            T* temp2 = data;
            data = temp;
            delete[] temp2;
        }

        T front(){
            if(frontIndex==-1 )return 0; 
            return data[frontIndex];
        }

        void enqueue(T d){
            if(size==capacity){
                resize();
            }
            data[nextIndex] = d;
            nextIndex = (nextIndex+1)%capacity;
            if(frontIndex == -1) frontIndex = 0;
            size++;
               

        }

        bool dequeue(){
            if(isEmpty()){
                return false;
            }
            
            frontIndex = (frontIndex+1)%capacity;
            size--;
            if(size==0){
                frontIndex = -1;
                nextIndex = 0;
            }
            return true;

        }

        int getSize(){
            return size;
        }

        int getCapacity(){
            return capacity;
        }

        bool isEmpty(){
            return size==0;
        }
    

};

int main(){

    queueUsingArray<int> arr;
    arr.enqueue(10);
    arr.enqueue(20);
    arr.enqueue(30);
    arr.enqueue(40);
    arr.enqueue(50);
    
    cout<<arr.getSize()<<endl;
    cout<<arr.getCapacity()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.isEmpty()<<endl;
    
    arr.enqueue(60);


    cout<<arr.getSize()<<endl;
    cout<<arr.getCapacity()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.isEmpty()<<endl;
    
    arr.dequeue();
    cout<<arr.getSize()<<endl;
    cout<<arr.getCapacity()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.isEmpty()<<endl;
    
    return 0;
}