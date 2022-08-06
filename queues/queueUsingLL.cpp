#include<iostream>
using namespace std;
template<typename T>
class Node{
    public:
        T data;
        Node<T> * next;
        
        Node(T d){
            this->data = d;
            next = NULL;
        }

};

template <typename T>
class QueueUsingLL{
    Node<T>* head;
    Node<T>* tail;
    int size;

    public:
        QueueUsingLL(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        int getSize(){
            return size;
        }

        T front(){
            if(head !=NULL) return head->data;
            return 0;
        }

        void enqueue(T d){
            Node<T> newNode = new Node<T>(d);
            if(head == NULL){
                head = newNode;
                tail = head;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
            size++;
        }

        void dequeue(){
            if(head != NULL){
                Node* temp = head;
                if(head->next ==NULL){
                    head = NULL;
                    tail = NULL;
                }else{
                    head = head->next;
                }
                delete temp;
            }
        }
 
};

int main(){
    return 0;
}