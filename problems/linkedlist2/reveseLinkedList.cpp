#include "../linkedlist1/linkedLIstOperations.cpp"



Node* reverse(Node* head){
    
    if(head ==NULL || head->next ==NULL)
        return head;

    if(head->next->next == NULL){
        Node* temp2 = head->next;
        head->next = head->next->next;
        temp2->next = head;
        return temp2;
    }
    
    Node* rest = reverse(head->next);
    
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return rest;

}

int main(){
    Node* head = new Node(1);

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

    

    head = reverse(head);
    print(head);
    return 0;
}