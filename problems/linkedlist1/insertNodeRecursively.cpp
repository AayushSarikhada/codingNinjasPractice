#include<iostream>
#include "linkedListOperations.cpp"
using namespace std;

//insert recursively
Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(head == NULL)
        return head;
    
    if(i == 0){
        Node* temp = new Node(data);
        temp->next = head;
        return temp;
    }
    
    head->next = insertNode(head->next,--i,data);
    return head;
}

int main(){

    
    Node* head = readInput();

    print(head);
   
    append(head,new Node(23));
    print(head);
   
    head = insertAtFront(head,new Node(56));
    print(head);

    head = insertAt(head,new Node(100),2);
    print(head);

    head = insertAt(head,new Node(100),0);
    print(head);

    head = insertAt(head,new Node(100),25);
    print(head);

    head = deleteAt(head,3);
    print(head);

    head = deleteAt(head,0);
    print(head);

    head = deleteAt(head,25);
    print(head);
    return 0;
}

