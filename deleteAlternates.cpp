#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

void deleteAlternateNodes(Node *head) {
    //Write your code here
    if(head == NULL) return;
    
    Node* temp = head;
    while(temp!= NULL && temp->next != NULL){
        
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = NULL;
        delete temp1;
        temp = temp->next;
        
    }
}

void print(Node* head){
    Node* temp =head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    
    print(head);
    deleteAlternateNodes(head);
    print(head);

    return 0;
}