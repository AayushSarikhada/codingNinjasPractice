#include "linkedListOperations.cpp"




Node *removeDuplicates(Node *head)
{
    //Write your code here
    Node* temp = head;
    while(temp!=NULL){
        
        if(temp->next != NULL && temp->data == temp->next->data){
            
            Node* temp2 = temp->next;
            Node* temp3 = temp2;
            
            while(temp3->next != NULL && temp3->data == temp3->next->data){
                temp3 = temp3->next;
            }
            
            temp->next = temp3->next;
            temp3->next = NULL;
          
            
            
            while(temp2 != NULL){
                Node *temp4 = temp2;
                temp2 = temp2->next;
                delete temp4;
            }
            
        }
    
        temp = temp->next;
    }
    
    return head;
}

int main(){

    
    // Node* head = readInput();

    // print(head);
   
    // append(head,new Node(23));
    // print(head);
   
    // head = insertAtFront(head,new Node(56));
    // print(head);

    // head = insertAt(head,new Node(100),2);
    // print(head);

    // head = insertAt(head,new Node(100),0);
    // print(head);

    // head = insertAt(head,new Node(100),25);
    // print(head);

    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);

    print(head);

    


    head = removeDuplicates(head);
    print(head);
    return 0;
}

