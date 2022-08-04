#include<iostream>
using namespace std;

template <typename T>
class stackUsingLL{
    class Node{
        public:
            T data;
            Node* next;
             Node(T data){
                this->data = data;
                this->next = NULL;
            }
        };

    Node* head;
    int sizee;

    public:
        
        stackUsingLL(){
            head = NULL;
            sizee = 0;
        }

    void push(T a){
        Node* temp = new Node(a);
        temp->next = head;
        head = temp;
        sizee++;
    }

    T pop(){
        T ret = 0;
        if(head != NULL){
            ret = head->data;
            Node* temp = head;
            head = head->next;
            sizee--;
            delete temp;
        }
        return ret;
    }

    T top(){
        T ret = 0;
        if(head != NULL){
            ret = head->data;
        }
        return ret;
    }

    int size(){
        return sizee;
    }

    bool isEmpty(){
        return head == NULL;
    }
};

int main(){
    stackUsingLL<int> st;
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