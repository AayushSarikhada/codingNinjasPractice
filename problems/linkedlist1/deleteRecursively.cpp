#include "linkedListOperations.cpp"


//insert recursively
Node* deleteNode(Node *head, int i) {
	// Write your code here
    if(head == NULL)
        return head;
    
    if(i == 0){
        Node* temp = head->next;
        delete head;
        return temp;
    }
    
    head->next = deleteNode(head->next,--i);
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

    head = deleteNode(head,3);
    print(head);
    return 0;
}

